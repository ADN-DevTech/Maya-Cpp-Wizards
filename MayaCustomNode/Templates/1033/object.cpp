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
//- The id is a 32bit value used to identify this type of node in the binary file format.
//-
//- For plug-ins that will forever be internal to your site use the constructor that takes 
//- a single unsigned int parameter. The numeric range 0 - 0x7ffff (524288 ids) has been 
//- reserved for such plug-ins.
//- The example plug-ins provided with Maya in the plug-in development kit will use ids in 
//- the range 0x80000 - 0xfffff (524288 ids). If you customize one of these example plug-ins, 
//- you should change the id to avoid future conflicts.
//- Plug-ins that are intended to be shared between sites will need to have a globally unique 
//- id. The Autodesk Developer Network (ADN) will provide such id's in blocks of 64/128/256 or 
//- 512. You will be assigned one or more 24-bit prefixes. Once this has been obtained, used 
//- the MTypeId constructor that takes 2 unsigned int parameters. The prefix goes in the first 
//- parameter, and you are responsible for managing the allocation of the 256 ids that go into 
//- the second parameter.
//- Get your reserved ID Block from http://www.autodesk.com/developmaya
MTypeId [!output CLASS_NAME]::id([!output NODEID]) ;

//-----------------------------------------------------------------------------
//- Attributes
MObject [!output CLASS_NAME]::attr1 ;
MObject [!output CLASS_NAME]::attr2 ;

MStatus [!output CLASS_NAME]::initialize () {
	//- This method is called to create and initialize all of the attributes
	//- and attribute dependencies for this node type. This is only called 
	//- once when the node type is registered with Maya.

	//- This sample creates a single input float attribute and a single output float attribute.
	MFnNumericAttribute nAttr ;

	attr1 =nAttr.create (_T("input"), _T("in"), MFnNumericData::kFloat, 0.0) ;
	nAttr.setStorable (true) ; //- Attribute will be written to files when this type of node is stored
	nAttr.setKeyable (true) ; //- Attribute is keyable and will show up in the channel box
	MayaOk (addAttribute (attr1), _T("addAttribute")) ; //- Add the attributes we have created to the node

	attr2 =nAttr.create (_T("output"), _T("out"), MFnNumericData::kFloat, 0.0) ;
	nAttr.setWritable (false) ; //- Attribute is read-only because it is an output attribute
	nAttr.setStorable (false) ; //- Attribute will not be written to files when this type of node is stored
	MayaOk (addAttribute (attr2), _T("addAttribute")) ; //- Add the attributes we have created to the node

	//- Set up a dependency between the input and the output. This will cause
	//- the output to be marked dirty when the input changes. The output will
	//- then be recomputed the next time the value of the output is requested.
	MayaOk (attributeAffects (attr1, attr2), _T("attributeAffects")) ;

	return (MStatus::kSuccess) ;
}

MStatus [!output CLASS_NAME]::registerMe (MFnPlugin &plugin) {
	return (plugin.registerNode (_T("[!output NODENAME]"), [!output CLASS_NAME]::id, [!output CLASS_NAME]::creator, [!output CLASS_NAME]::initialize)) ;
}

MStatus [!output CLASS_NAME]::unregisterMe (MFnPlugin &plugin) {
	return (plugin.deregisterNode ([!output CLASS_NAME]::id)) ;
}

//-----------------------------------------------------------------------------
MStatus [!output CLASS_NAME]::compute (const MPlug &plug, MDataBlock &data) {
	//- This method computes the value of the given output plug based
	//- on the values of the input attributes.
	//-		plug - the plug to compute
	//-		data - object that provides access to the attributes for this node
 
	//- Check which output attribute we have been asked to compute. If this 
	//- node doesn't know how to compute it, we must return MS::kUnknownParameter
	MStatus returnStatus =MStatus::kUnknownParameter ;
	if ( plug == attr2 ) {
		//- Get a handle to the input attribute that we will need for the
		//- computation. If the value is being supplied via a connection 
		//- in the dependency graph, then this call will cause all upstream  
		//- connections to be evaluated so that the correct value is supplied.
		MDataHandle attr1Data =data.inputValue (attr1, &returnStatus) ;
		if ( returnStatus == MStatus::kSuccess ) {
			//- Read the input value from the handle.
			float result =attr1Data.asFloat () ;
			//- Get a handle to the output attribute. This is similar to the
			//- "inputValue" call above except that no dependency graph 
			//- computation will be done as a result of this call.
			MDataHandle attr2Handle =data.outputValue (attr2) ;
			//- This sample just copies the input value through to the output.  
			attr2Handle.set (result) ;
			//- Mark the destination plug as being clean. This will prevent the
			//- dependency graph from repeating this calculation until an input 
			//- of this node changes.
			data.setClean (plug) ;
		}
	}
	return (returnStatus) ;
}
