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
	//- There needs to be a MObject handle declared for each attribute that
	//- the node will have. These handles are needed for getting and setting
	//- the values later.
	static MObject attr1 ;
	static MObject attr2 ;

	//- The typeid is a unique 32bit identifier that describes this node.
	//- It is used to save and retrieve nodes of this type from the binary
	//- file format. If it is not unique, it will cause file IO problems.
	static MTypeId id ;

public:
	[!output CLASS_NAME] () : [!output BASE_CLASS] () {}
	virtual ~[!output CLASS_NAME] () {}

	virtual MStatus	compute (const MPlug &plug, MDataBlock &data) ;

	static void *creator () { return new [!output CLASS_NAME] () ; }
	static MStatus initialize () ;
	static MStatus registerMe (MFnPlugin &plugin) ;
	static MStatus unregisterMe (MFnPlugin &plugin) ;

} ;
