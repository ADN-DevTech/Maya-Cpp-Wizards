//- Copyright (c) Autodesk, Inc. All rights reserved.
//- by Cyrille Fauvel - Autodesk Developer Technical Services

function OnFinish (selProj, selObj) {
	var oCM ;
	try {
		oCM	=selProj.CodeModel ;

		var strClassName =wizard.FindSymbol ("CLASS_NAME") ;
		var strNodeName =wizard.FindSymbol ("NODENAME") ;
		if ( strNodeName == "" ) {
		    strNodeName =strClassName ;
		    wizard.AddSymbol ("NODENAME", strNodeName) ;
		}

		var L_TransactionName_Text ="Adds a class that inherits from Maya to your project " ;
		oCM.StartTransaction (L_TransactionName_Text + strClassName) ;

		var strProjectPath =wizard.FindSymbol ("PROJECT_PATH") ;
		var strTemplatePath =wizard.FindSymbol ("TEMPLATES_PATH") ;
		var strIncludeHeader =wizard.FindSymbol ("INCLUDE_HEADER") ;
		var strHeaderFile =wizard.FindSymbol ("HEADER_FILE") ;
		var strImplFile =wizard.FindSymbol ("IMPL_FILE") ;
		var strTemplateHeader =wizard.FindSymbol ("TEMPLATE_HEADER") ;
		var strTemplateImpl =wizard.FindSymbol ("TEMPLATE_IMPL") ;
		var strBaseClass =wizard.FindSymbol ("BASE_CLASS") ;
		var strProjectCPP =GetProjectFile (selProj, "CPP", false, true) ;
		
		var strProjectName =wizard.FindSymbol ("PROJECT_NAME") ;
		wizard.AddSymbol ("SAFE_PROJECT_NAME", CreateSafeName (strProjectName)) ;
		var szUprProjectName =CreateSafeName (strProjectName.toUpperCase ()) ;
		wizard.AddSymbol ("UPPER_CASE_SAFE_PROJECT_NAME", szUprProjectName) ;

		RenderAddTemplate (wizard, strTemplateHeader, strHeaderFile, selObj, true) ;
		RenderAddTemplate (wizard, strTemplateImpl, strImplFile, selObj, false) ;

		oCM.CommitTransaction () ;
				
		ShowTextPoint (oCM.Classes.Find (strClassName).StartPoint) ;
	} catch ( e ) {
		if ( oCM )
			oCM.AbortTransaction () ;

		if ( e.description.length != 0 )
			SetErrorInfo (e) ;
		return (e.number) ;
	}
}
