//
//  Copyright 2012 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//

//-----------------------------------------------------------------------------
#include "StdAfx.h"
#define MNoVersionString
#define MNoPluginEntry
#include <maya/MFnPlugin.h>
#include "[!output HEADER_FILE]"

//-----------------------------------------------------------------------------
MStatus [!output CLASS_NAME]::registerMe (MFnPlugin &plugin) {
	return (plugin.registerCommand (_T("[!output CMD_NAME]"), [!output CLASS_NAME]::creator)) ;
}

MStatus [!output CLASS_NAME]::unregisterMe (MFnPlugin &plugin) {
	return (plugin.deregisterCommand (_T("[!output CMD_NAME]"))) ;
}

//-----------------------------------------------------------------------------
MStatus [!output CLASS_NAME]::doIt (const MArgList &args) {
	//- implements the MEL [!output CMD_NAME] command.
	//-		args - the argument list that was passes to the command from MEL
	//- Return Value:
	//-		MS::kSuccess - command succeeded
	//-		MS::kFailure - command failed (returning this value will cause the 
	//-                     MEL script that is being run to terminate unless the
	//-                     error is caught using a "catch" statement.
	//- Typically, the doIt() method only collects the infomation required
	//- to do/undo the action and then stores it in class members. The 
	//- redo method is then called to do the actuall work. This prevents
	//- code duplication.
	return (redoIt ()) ;
}

MStatus [!output CLASS_NAME]::redoIt () {
	//- Implements redo for the MEL [!output CMD_NAME] command. 
	//- This method is called when the user has undone a command of this type
	//- and then redoes it. No arguments are passed in as all of the necessary
	//- information is cached by the doIt method.
	//-	Return Value:
	//-		MS::kSuccess - command succeeded
	//-		MS::kFailure - redoIt failed.  this is a serious problem that will
	//-                     likely cause the undo queue to be purged
	//- Since this class is derived off of MPxCommand, you can use the 
	//- inherited methods to return values and set error messages
	setResult (_T("[!output CMD_NAME] command executed!\n")) ;
	return (MStatus::kSuccess) ;
}

MStatus [!output CLASS_NAME]::undoIt () {
	//- Implements undo for the MEL [!output CMD_NAME] command.  
	//- This method is called to undo a previous command of this type.  The 
	//- system should be returned to the exact state that it was it previous 
	//- to this command being executed.  That includes the selection state.
	//- Return Value:
	//-		MS::kSuccess - command succeeded
	//-		MS::kFailure - redoIt failed.  this is a serious problem that will
	//-                     likely cause the undo queue to be purged
	//- You can also display information to the command window via MGlobal
    MGlobal::displayInfo (_T("[!output CMD_NAME] command undone!\n")) ;
	return (MStatus::kSuccess) ;
}
