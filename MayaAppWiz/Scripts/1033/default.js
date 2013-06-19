//- Copyright (c) Autodesk, Inc. All rights reserved.
//- by Cyrille Fauvel - Autodesk Developer Technical Services

//wizard.OkCancelAlert(""); return;
//config.InheritedPropertySheets = 'Fullpath\x.vsprops;';
// http://msdn.microsoft.com/en-us/library/aa291835(v=VS.71).aspx
// http://msdn.microsoft.com/en-us/library/microsoft.visualstudio.vswizard.vcwizctlclass_members.aspx

function OnFinish (selProj, selObj) {
    try {
		var strProjectPath =wizard.FindSymbol ('PROJECT_PATH') ;
		var strProjectName =wizard.FindSymbol ('PROJECT_NAME') ;
		wizard.AddSymbol ("UPPER_CASE_PROJECT_NAME", strProjectName.toUpperCase ()) ;
		wizard.AddSymbol ("SAFE_PROJECT_NAME", CreateSafeName (strProjectName)) ;
		wizard.AddSymbol ("UPPER_CASE_SAFE_PROJECT_NAME", CreateSafeName (strProjectName.toUpperCase ())) ;
		wizard.AddSymbol ("RC_FILE_NAME",CreateSafeRCFileName (strProjectName) + ".rc") ;
		
		wizard.AddSymbol ("MAYA_MFC_SUPPORT", 'false') ;
		wizard.AddSymbol ("MAYA_ATL_SUPPORT", 'false') ;
		wizard.AddSymbol ("MAYA_CLR_SUPPORT", 'false') ;
		
		var bAppType =wizard.FindSymbol ('APP_PLUGIN_TYPE') ;
		if ( bAppType ) {
			wizard.AddSymbol ("PRJ_TYPE_APP", 'plugin') ;
			CopyPropsFile ( 'plugin.props', strProjectName) ;
		} else {
			wizard.AddSymbol ("PRJ_TYPE_APP", 'standalone') ;
			var bExe =wizard.FindSymbol ('APP_STANDALONE_EXE') ;
			if ( bExe )
				wizard.AddSymbol ("PRJ_STANDALONE_TYPE", 'Application') ;
			else
				wizard.AddSymbol ("PRJ_STANDALONE_TYPE", 'DynamicLibrary') ;
			CopyPropsFile ( 'standalone.props', strProjectName) ;
		}
		CopyPropsFile ( 'Autodesk.maya-2013.props', strProjectName) ;
		CopyPropsFile ( 'Autodesk.maya-2013-5.props', strProjectName) ;
		CopyPropsFile ( 'Autodesk.maya-2014.props', strProjectName) ;
		CopyPropsFile ( 'Release.props', strProjectName) ;
		CopyPropsFile ( 'Debug.props', strProjectName) ;
		
		CopyMakefileFile ('linux_plugin.map', strProjectName, 'Linux2013') ;
		CopyMakefileFile ('buildconfig', strProjectName, 'Linux2013') ;
		CopyMakefileFile ('buildrules', strProjectName, 'Linux2013') ;
		CopyMakefileFile ('Makefile', strProjectName, 'Linux2013') ;
		CopyMakefileFile ('linux_plugin.map', strProjectName, 'Linux2013.5') ;
		CopyMakefileFile ('buildconfig', strProjectName, 'Linux2013.5') ;
		CopyMakefileFile ('buildrules', strProjectName, 'Linux2013.5') ;
		CopyMakefileFile ('Makefile', strProjectName, 'Linux2013.5') ;

		CopyMakefileFile ('buildconfig', strProjectName, 'Mac2013') ;
		CopyMakefileFile ('buildrules', strProjectName, 'Mac2013') ;
		CopyMakefileFile ('Makefile', strProjectName, 'Mac2013') ;
		CopyMakefileFile ('buildconfig', strProjectName, 'Mac2013.5') ;
		CopyMakefileFile ('buildrules', strProjectName, 'Mac2013.5') ;
		CopyMakefileFile ('Makefile', strProjectName, 'Mac2013.5') ;	

		//selProj =CreateProject (strProjectName, strProjectPath) ; //- Use the default Win32 only project template from Visual Studio
		var strProjTemplate =RenderPrjToTemporaryFile () ;
		selProj =CreateMayaProject (strProjectName, strProjectPath, strProjTemplate) ;
		SetupFilters (selProj) ;
		AddFilesToNewProjectWithInfFile (selProj, strProjectName) ;
		
		selProj.Object.Save () ;
	} catch (e) {
		if ( e.description.length != 0 )
			SetErrorInfo (e) ;
		return (e.number) ;
	}
}

//-----------------------------------------------------------------------------
function CreateMayaProject (strProjectName, strProjectPath, strProjTemplate) {
	try {
		//var strProjTemplatePath =wizard.FindSymbol ("ABSOLUTE_PATH") ;
		//var strProjTemplate =strProjTemplatePath + "\\Templates\\1033\\x64win32.vcxproj" ;

		var Solution =dte.Solution ;
		var strSolutionName ="" ;
		if ( wizard.FindSymbol ("CLOSE_SOLUTION") ) {
			Solution.Close () ;
			strSolutionName =wizard.FindSymbol ("VS_SOLUTION_NAME") ;
			if ( strSolutionName.length ) {
				var strSolutionPath =strProjectPath.substr (0, strProjectPath.length - strProjectName.length) ;
				Solution.Create (strSolutionPath, strSolutionName) ;
			}
		}

		var strProjectNameWithExt =strProjectName + ".vcxproj" ;
		var oTarget =wizard.FindSymbol ("TARGET") ;
		var oProj ;
		if ( wizard.FindSymbol ("WIZARD_TYPE") == vsWizardAddSubProject ) {  // vsWizardAddSubProject
			var prjItem =oTarget.AddFromTemplate (strProjTemplate, strProjectPath + "\\" + strProjectNameWithExt) ;
			oProj = prjItem.SubProject ;
		} else {
			oProj =oTarget.AddFromTemplate (strProjTemplate, strProjectPath, strProjectNameWithExt) ;
		}
		return (oProj) ;
	} catch ( e ) {
		throw e ;
	}
}

//-----------------------------------------------------------------------------
function GetTargetName (strName, strProjectName) {
	try {
		//----- Set the name of the rendered file based on the template filename
		var strTarget =strName ;
		if ( strName.substr (0, 4) == 'root' )
			strTarget =strProjectName + strName.substr (4, strName.length - 4) ;
		if ( strName == 'standalone.cpp' || strName == 'plugin.cpp' )
			strTarget =strProjectName + '.cpp' ;
		return (strTarget) ;
	} catch (e) {
		throw e ;
	}
}

function SetFileProperties (projfile, strName) {
}

//-----------------------------------------------------------------------------
function RenderPrjToTemporaryFile () {
	var strProjTemplatePath =wizard.FindSymbol ("ABSOLUTE_PATH") ;
	var strProjTemplate =strProjTemplatePath + "\\Templates\\1033\\x64win32.vcxproj" ;

	var TemporaryFolder =2 ;
	var oFSO =new ActiveXObject ("Scripting.FileSystemObject") ;
	var oFolder =oFSO.GetSpecialFolder (TemporaryFolder) ;
	var strTempFile =oFSO.GetAbsolutePathName (oFolder.Path) + "\\" + oFSO.GetTempName() + ".vcxproj" ;
	var strTempFileContents =wizard.RenderTemplateToString (strProjTemplate) ;
	var oStream ;
	oStream =oFSO.CreateTextFile (strTempFile, true, false /*ANSI*/) ;
	oStream.Write (strTempFileContents) ;
	oStream.Close () ;
	return (strTempFile) ;
}

//-----------------------------------------------------------------------------
function CopyPropsFile (strName, strProjectName) {
		var strTemplatePath =wizard.FindSymbol ('TEMPLATES_PATH') ;
		var strTarget =GetTargetName (strName, strProjectName) ;
		var strTemplate =strTemplatePath + '\\' + strName ;
		wizard.RenderTemplate (strTemplate, strTarget, true, true) ;
}

//-----------------------------------------------------------------------------
function CopyMakefileFile (strName, strProjectName, strFolder) {
		var strTemplatePath =wizard.FindSymbol ('TEMPLATES_PATH') ;
		var strTarget =strFolder + '\\' + GetTargetName (strName, strProjectName) ;
		var strTemplate =strTemplatePath + '\\' + strFolder + '\\' + strName ;
		wizard.RenderTemplate (strTemplate, strTarget, false, true) ;
}

