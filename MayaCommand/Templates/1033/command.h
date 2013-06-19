//
//  Copyright 2012 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//

//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
class [!output CLASS_NAME] : public [!output BASE_CLASS]
{
public:
	[!output CLASS_NAME] () : [!output BASE_CLASS] () {}
	virtual ~[!output CLASS_NAME] () {}

	virtual MStatus doIt (const MArgList &args) ;
	virtual MStatus redoIt () ;
	virtual MStatus undoIt () ;

	//- This method tells Maya this command is undoable. It is added to the undo 
	//- queue if it is. Return false if you don't want the command to be undoable.
	virtual bool isUndoable () const { return (true) ; }

	static void *creator () { return new [!output CLASS_NAME] () ; }
	static MStatus registerMe (MFnPlugin &plugin) ;
	static MStatus unregisterMe (MFnPlugin &plugin) ;

} ;
