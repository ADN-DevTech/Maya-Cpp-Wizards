//
//  ___FILENAME___
//  ___PROJECTNAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//___COPYRIGHT___
//

//-----------------------------------------------------------------------------
#include "StdAfx.h"
#define MNoVersionString
#define MNoPluginEntry
#include <maya/MFnPlugin.h>
#include "___FILEBASENAME___.h"

//-----------------------------------------------------------------------------
MStatus ___VARIABLE_className:identifier___::registerMe (MFnPlugin &plugin) {
	return (plugin.registerCommand (_T("___VARIABLE_commandName___"), ___VARIABLE_className:identifier___::creator)) ;
}

MStatus ___VARIABLE_className:identifier___::unregisterMe (MFnPlugin &plugin) {
	return (plugin.deregisterCommand (_T("___VARIABLE_commandName___"))) ;
}

//-----------------------------------------------------------------------------
MStatus ___VARIABLE_className:identifier___::doIt (const MArgList &args) {
	//- implements the MEL ___VARIABLE_commandName___ command.
	//-		args - the argument list that was passes to the command from MEL
	//- Return Value:
	//-		MS::kSuccess - command succeeded
	//-		MS::kFailure - command failed (returning this value will cause the 
	//-                     MEL script that is being run to terminate unless the
	//-                     error is caught using a "catch" statement.
	//- Typically, the doIt() method only collects the information required
	//- to do/undo the action and then stores it in class members. The 
	//- redo method is then called to do the actual work. This prevents
	//- code duplication.
	return (redoIt ()) ;
}

MStatus ___VARIABLE_className:identifier___::redoIt () {
	//- Implements redo for the MEL ___VARIABLE_commandName___ command. 
	//- This method is called when the user has undone a command of this type
	//- and then redoes it. No arguments are passed in as all of the necessary
	//- information is cached by the doIt method.
	//-	Return Value:
	//-		MS::kSuccess - command succeeded
	//-		MS::kFailure - redoIt failed.  this is a serious problem that will
	//-                     likely cause the undo queue to be purged
	//- Since this class is derived off of MPxCommand, you can use the 
	//- inherited methods to return values and set error messages
	setResult (_T("___VARIABLE_commandName___ command executed!\n")) ;
	return (MS::kSuccess) ;
}

MStatus ___VARIABLE_className:identifier___::undoIt () {
	//- Implements undo for the MEL ___VARIABLE_commandName___ command.  
	//- This method is called to undo a previous command of this type.  The 
	//- system should be returned to the exact state that it was it previous 
	//- to this command being executed.  That includes the selection state.
	//- Return Value:
	//-		MS::kSuccess - command succeeded
	//-		MS::kFailure - redoIt failed.  this is a serious problem that will
	//-                     likely cause the undo queue to be purged
	//- You can also display information to the command window via MGlobal
	MGlobal::displayInfo (_T("___VARIABLE_commandName___ command undone!\n")) ;
	return (MS::kSuccess) ;
}
