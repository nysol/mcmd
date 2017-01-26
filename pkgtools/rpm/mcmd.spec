%define debug_package %{nil}
%define _prefix /usr/local

Summary: tools for processing very large CSV data
Name: nysol_mcmd
Version: ##VERSION##
Release: 0
Group: Applications/Database
Source: ##SOURCEFILE##
License: refer to http://nysol.jp
Packager: Nysol corporation <info@nysol.jp>
Vendor: Nysol corporation
URL: http://nysol.jp/
BuildRoot: %{_topdir}/BUILD/nysol

%description
"MCMD" is a software library and a set of commands that contains a set of modular data processing functions designed for retrieving and processing large datasets (in CSV format) efficiently for data extraction, cleansing, report generation and data mining, thus offering a seamless and integrated process for users to manage data with maximum flexiblity. All codes are written in C++ with "boost library". This package contains a shared library (libmcmd) and more than 60 commands. This package is maintained by Nysol corporation, Japan.

%prep

#QA_SKIP_BUILD_ROOT=1
rm -rf  $RPM_BUILD_ROOT

%setup

%build
./configure
make prefix=%{_prefix}

%install
mkdir -p $RPM_BUILD_ROOT
mkdir $RPM_BUILD_ROOT/tmp
make DESTDIR=$RPM_BUILD_ROOT prefix=%{_prefix} install


%clean
rm -rf $RPM_BUILD_ROOT

%post
#!/bin/bash
sudo /sbin/ldconfig 


%files
%{_prefix}/bin/m*
%{_prefix}/lib/libkgmod*
%{_prefix}/lib/libmcmd*

