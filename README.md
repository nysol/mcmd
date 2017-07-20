# MCMD (M-Command): a set of commands for handling large scale CSV data
* [news](#news)
* [abstract](#abstract)
* [install](#install)
* [tutorial](#tutorial)
* [reference](#reference)
* [[reference manual|https://docs.google.com/viewer?a=v&pid=sites&srcid=bnlzb2wuanB8cHViMnxneDo3NjIyODMzMDI2NDk3YjM3]]
* [acknowledgement](#acknowledgement)

# news
* Apr. 2017: release version 3.0

# abstract
MCMD (called as M-Command) is a set of commands that are developed for the purpose of high-speed processing (CSV) of large-scale structured data tables.
It is possible to efficiently process large scale data with hundred millions row of records on a standard PC with M-Command using a standard PC. Its origin can be traced back to the early 1990s. Yasuyuki Matsuda developed this data processing methodology and commands for large-scale system development projects which was implemented in big companies. The “M” in M-Command stands for his initial.

M-Command provides about 70 different commands where each command is specific to a single function (For example, sort or join tables). The basic tenets of what all commands have in common is it reads CSV data from standard input, and carry out a very simple processing method and write the results to standard output. It achieves a variety of processing functions by connecting individual commands with an inter-process stream called "pipe", thus the output of each process feeds directly as input to the next one. These features are the same as the UNIX philosophy. With M-Command, an information system can be created based solely using M-Command and UNIX utilities on a UNIX platform.

# install

## requirements
### target OS
We confirmed that MCMD run on the following operating systems.
* MacOS 10.9.5(Marverics)以上
* CentOS 7.3 1611
* Ubuntu 16.04 LTS
* Bash on Ubuntu on Windows(Windows 10)

### necessary tools/libraries for compilation
* c++ compiler
* autotools
* [[boost C++ library|http://www.boost.org/]]
* [[lib2xml Library|http://xmlsoft.org/]]

## compile and install
### MacOS X
    ## install autotools and boost if not installed
    $ brew install autoconf
    $ brew install automake
    $ brew install libtool
    $ brew install boost

    ## download the sources
    $ git clone https://github.com/nysol/mcmd.git
    $ cd mcmd

    ## compile and install
    $ aclocal
    $ autoreconf -i
    $ automake --add-mising
    $ ./configure
    $ make
    $ sudo make install

### CentOS
    ## install autotools,boost,libxml2 if not installed
    $ sudo yum update
    $ sudo yum groupinstall "Development Tools"
    $ sudo yum install boost-devel
    $ sudo yum install libxml2-devel

    ## compile and install
    $ git clone https://github.com/nysol/mcmd.git
    $ cd mcmd

    ## compile and install
    $ aclocal
    $ autoreconf -i
    $ ./configure
    $ make
    $ sudo make install

### Ubuntu,Bash on Windows
    ## install autotools,boost,libxml2 if not installed
    $ sudo apt-get update
    $ sudo apt-get upgrade
    $ sudo apt-get install build-essential
    $ sudo apt-get install git
    $ sudo apt-get install libboost-all-dev
    $ sudo apt-get install libxml2-dev

    ## download the sources
    $ git clone https://github.com/nysol/mcmd.git
    $ cd mcmd/

    ## compile and install
    $ aclocal
    $ autoreconf -i
    $ ./configure
    $ make
    $ sudo make install

    # setting a shared library path
    # write it in .bash_profile if you like to activated it automatically.
    $ export LD_LIBRARY_PATH=/usr/local/lib

