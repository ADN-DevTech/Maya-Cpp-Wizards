#-
# Copyright 2012 Autodesk, Inc.  All rights reserved.
# 
# Use of this software is subject to the terms of the Autodesk license
# agreement provided at the time of installation or download, or which
# otherwise accompanies this software in either electronic or hard copy form.
#+

ifndef INCL_BUILDRULES

# Include platform specific build settings
TOP := .
SRCDIR := $(TOP)/..
DSTDIR := $(TOP)
include $(TOP)/buildrules

# Always build the local plug-in when make is invoked from the directory.
all: plugins

endif

# Include the optional per-plugin Makefile.inc
#
#    The file can contain macro definitions such as:
#       {pluginName}_EXTRA_CFLAGS
#       {pluginName}_EXTRA_C++FLAGS
#       {pluginName}_EXTRA_INCLUDES
#       {pluginName}_EXTRA_LIBS
-include $(TOP)/Makefile.inc

# Variable definitions
[!output PROJECT_NAME]_SOURCES := $(SRCDIR)/[!output PROJECT_NAME].cpp
[!output PROJECT_NAME]_OBJECTS := $(DSTDIR)/[!output PROJECT_NAME].o 
[!output PROJECT_NAME]_PLUGIN := $(DSTDIR)/[!output PROJECT_NAME].$(EXT)
[!output PROJECT_NAME]_MAKEFILE := $(DSTDIR)/Makefile

# Set target specific flags.
$([!output PROJECT_NAME]_OBJECTS): CFLAGS   := $(CFLAGS) $([!output PROJECT_NAME]_EXTRA_CFLAGS)
$([!output PROJECT_NAME]_OBJECTS): C++FLAGS := $(C++FLAGS) $([!output PROJECT_NAME]_EXTRA_C++FLAGS)
$([!output PROJECT_NAME]_OBJECTS): INCLUDES := $(INCLUDES) $([!output PROJECT_NAME]_EXTRA_INCLUDES)

depend_[!output PROJECT_NAME]:     INCLUDES := $(INCLUDES) $([!output PROJECT_NAME]_EXTRA_INCLUDES)

$([!output PROJECT_NAME]_PLUGIN):  LFLAGS   := $(LFLAGS) $([!output PROJECT_NAME]_EXTRA_LFLAGS) 
$([!output PROJECT_NAME]_PLUGIN):  LIBS     := $(LIBS) -lOpenMaya -lFoundation -lOpenMayaRender -lOpenMayaUI $([!output PROJECT_NAME]_EXTRA_LIBS) 

# Rules definitions
.PHONY: depend_[!output PROJECT_NAME] clean_[!output PROJECT_NAME] Clean_[!output PROJECT_NAME]

$([!output PROJECT_NAME]_PLUGIN): $([!output PROJECT_NAME]_OBJECTS) 
	-rm -f $@
	$(LD) -o $@ $(LFLAGS) $^ $(LIBS)

depend_[!output PROJECT_NAME]:
	makedepend $(INCLUDES) $(MDFLAGS) -f$(DSTDIR)/Makefile $([!output PROJECT_NAME]_SOURCES)

clean_[!output PROJECT_NAME]:
	-rm -f $([!output PROJECT_NAME]_OBJECTS)

Clean_[!output PROJECT_NAME]:
	-rm -f $([!output PROJECT_NAME]_MAKEFILE).bak $([!output PROJECT_NAME]_OBJECTS) $([!output PROJECT_NAME]_PLUGIN)

plugins: $([!output PROJECT_NAME]_PLUGIN)
depend: depend_[!output PROJECT_NAME]
clean: clean_[!output PROJECT_NAME]
Clean: Clean_[!output PROJECT_NAME]
