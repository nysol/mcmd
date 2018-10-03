#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# generate　configure :
# run 
#  aclocal ; autoreconf -i ; automake --add-missing 
#  or
#  autoreconf -i ; automake --add-missing

#AC_PREREQ([2.69])
AC_INIT(nysol_mcmd, 3.0, info@nysol.jp)
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/cmd/m2cross.cpp])

# Checks for programs.
AC_PROG_AWK
AC_PROG_CXX
AC_PROG_CC
AC_PROG_LN_S
AC_PROG_LIBTOOL

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h stdlib.h string.h sys/time.h termios.h unistd.h wchar.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([floor isascii memset mkdir mkfifo modf pow select setlocale sqrt strchr strerror strstr])


# kgmod
AC_SUBST([CORE_MAJOR_VERSION], ["3"])
AC_SUBST([CORE_SO_VERSION], ["1:0:0"])

# mcmd
AC_SUBST([MOD_MAJOR_VERSION], ["3"])
AC_SUBST([MOD_SO_VERSION], ["1:0:0"])



AC_ARG_WITH([libxml2],
  AC_HELP_STRING(
    [--with-libxml2=PATH],[PATH is path to libxml2 library]),
  [XML2LIB="-L$with_libxml2 -lxml2"],[XML2LIB=`xml2-config --libs`])

AC_ARG_WITH([libxml2header],
  AC_HELP_STRING(
    [--with-libxml2header=PATH],[PATH is path to libxml2 header]),
  [XML2HEAD="-I$with_libxml2header"],[XML2HEAD=`xml2-config --cflags`])

AC_SUBST(XML2HEAD)
AC_SUBST(XML2LIB)

# BOOST PATH　指定
AC_ARG_WITH([boost],
  AC_HELP_STRING(
    [--with-boost=PATH],[PATH is path to boost library]),
  [BOOSTPATH=$with_boost],[BOOSTPATH=/usr/local])

CXXFLAGS="-I$BOOSTPATH/include -L$BOOSTPATH/lib $CXXFLAGS"
CFLAGS="-I$BOOSTPATH/include -L$BOOSTPATH/lib $CFLAGS"

AC_SUBST([BOOSTPATH], [$BOOSTPATH])




AC_CHECK_LIB(pthread, pthread_create)
AC_CHECK_LIB([boost_regex], [main], [], [echo "Error. You need to have libboost";exit -1])
AC_CHECK_LIB([boost_system], [main], [], [echo "Error. You need to have libboost";exit -1])
AC_CHECK_LIB([boost_filesystem], [main], [], [echo "Error. You need to have libboost";exit -1])


#OSチェック
AM_CONDITIONAL(DARWIN_CERT, false)
AC_CANONICAL_HOST
case $host_os in
  darwin* )
		#証明書チェック
		AS_IF([test "x$(security find-identity -p codesigning -v | grep nysol-cert | head -n 1)" != x],
			[AM_CONDITIONAL(DARWIN_CERT, true)]
		)
		;;
  cygwin)
		AC_LIBTOOL_WIN32_DLL
    ;;
esac

# configure parameter
AC_ARG_ENABLE([jpnformat],
	[AS_HELP_STRING([--enable-jpnformat],
	    [jpnformat (default is yes)])],
	[],
	[enable_jpnformat=yes] 
)
AS_IF([test "x$enable_jpnformat" != xno],
    [AC_DEFINE([JPN_FORMAT], [1], [jpnformat])]
)

AC_CONFIG_FILES([Makefile
								 src/Makefile
                 src/cmd/Makefile
                 src/kgmod/Makefile
                 src/mod/Makefile])
AC_OUTPUT
