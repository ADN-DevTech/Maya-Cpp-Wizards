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
	___VARIABLE_className:identifier___ () : ___VARIABLE_baseClass:identifier___ () {}
	virtual ~___VARIABLE_className:identifier___ () {}

	virtual MStatus	compute (const MPlug &plug, MDataBlock &data) ;

	static void *creator () { return new ___VARIABLE_className:identifier___ () ; }
	static MStatus initialize () ;
	static MStatus registerMe (MFnPlugin &plugin) ;
	static MStatus unregisterMe (MFnPlugin &plugin) ;

} ;
