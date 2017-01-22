
AM_CXXFLAGS = -I../ -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DKGLIB_VERSON=\"$(CORE_MAJOR_VERSION):$(CORE_SO_VERSION)\"

## Define a libtool archive target "libexample-@EXAMPLE_API_VERSION@.la", with
## @EXAMPLE_API_VERSION@ substituted into the generated Makefile at configure
## time.
## The libtool archive file (.la) will be installed into the directory named
## by the predefined variable $(bindir), along with the actual shared library
## file (.so).
lib_LTLIBRARIES = libkgmod@CORE_MAJOR_VERSION@.la


## Instruct libtool to include ABI version information in the generated shared
## library file (.so).  The library ABI version is defined in configure.ac, so
## that all version information is kept in one place.

libkgmod@CORE_MAJOR_VERSION@_la_LDFLAGS = -version-info $(CORE_SO_VERSION) -single_module 
libkgmod@CORE_MAJOR_VERSION@_la_SOURCES = \
kgArgFld.cpp \
kgArgs.cpp \
kgCSV.cpp \
kgCSVout.cpp \
kgCSVutils.cpp \
kgEnv.cpp \
kgError.cpp \
kgFldBuffer.cpp \
kgFldHash.cpp \
kgFunction.cpp \
kgMessage.cpp \
kgMethod.cpp \
kgRange.cpp \
kgTempfile.cpp \
kgVal.cpp \
kgWildcard.cpp \
kgmodincludesort.cpp \
kgSortf.cpp \
kgmod.cpp \
kgArgFld.h \
kgArgs.h \
kgCSV.h \
kgCSVout.h \
kgCSVutils.h \
kgCalParser.h \
kgEnv.h \
kgError.h \
kgFldBuffer.h \
kgFldHash.h \
kgFunction.h \
kgMessage.h \
kgMethod.h \
kgRange.h \
kgTempfile.h \
kgVal.h \
kgWildcard.h \
kgItermios.h \
kgTextarea.h \
kgmodincludesort.h \
kgSortf.h \
kgConfig.h \
../help/jp/kgsortfHelp.h \
../help/en/kgsortfHelp.h \
kgmod.h 

pkgconfigdir = $(libdir)/pkgconfig


