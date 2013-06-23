//
//  ___FILENAME___
//  ___PROJECTNAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//  ___COPYRIGHT___
//

//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
class ___VARIABLE_className:identifier___ : public ___VARIABLE_baseClass:identifier___
{
public:
	___VARIABLE_className:identifier___ () : ___VARIABLE_baseClass:identifier___ () {}
	virtual ~___VARIABLE_className:identifier___ () {}

	virtual MStatus doIt (const MArgList &args) ;
	virtual MStatus redoIt () ;
	virtual MStatus undoIt () ;

	//- This method tells Maya this command is undoable. It is added to the undo 
	//- queue if it is. Return false if you don't want the command to be undoable.
	virtual bool isUndoable () const { return (true) ; }

	static void *creator () { return new ___VARIABLE_className:identifier___ () ; }
	static MStatus registerMe (MFnPlugin &plugin) ;
	static MStatus unregisterMe (MFnPlugin &plugin) ;

} ;
