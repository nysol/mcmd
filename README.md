# MCMD (M-Command): a set of commands for handling large scale CSV data
[[in japanese]](https://github.com/nysol/mcmd/wiki)

* [News](#news)
* [Abstract](#abstract)
* [Reference_Manual](#reference_manual)
* [Installation](#installation)
* [Tutorial](#tutorial)
* [References](#references)
* [Acknowledgements](#acknowledgements)

# News
* Apr. 2017: release version 3.0

# Abstract
**MCMD** (called as M-Command) is a set of commands that are developed
 for the purpose of high-speed processing of
 large-scale structured tabular data in CSV format.
It is possible to efficiently process large scale data
 with hundred millions row of records on a standard PC.
 Its origin can be traced back to the early 1990s.
 Y. Matsuda developed this data processing methodology
 and commands for large-scale system development projects
 which was implemented in some companies.
 The “M” in M-Command stands for his initial.

MCMD provides about 70 different commands
 where each command is specific to a single function
 (For example, sort or join tables).
 The basic tenets of what all commands have in common
 is it reads CSV data from standard input,
 and carry out a very simple processing method
 and write the results to standard output.
 It achieves a variety of processing functions
 by connecting individual commands with an inter-process stream
 called "pipe", thus the output of each process feeds directly
 as input to the next one.
 These features are the same as the UNIX philosophy,
 and an information system can be created
 solely using commands on a UNIX platform.

# Reference_Manual
* [Japanese Reference Manual (NYSOL Package Current Release: Ver. 3.0)](https://github.com/nysol/mcmd/files/1332817/mcmd.pdf)　Last Updated;2017/09/27
* [English Reference Manual (NYSOL Package Current Release: Ver. 3.0)](https://github.com/nysol/mcmd/files/1381427/mcmd2.pdf)    Last Updated;2017/10/13

# Installation

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
* [boost C++ library](http://www.boost.org/)
* [lib2xml Library](http://xmlsoft.org/)

## compile and install
### MacOS X
```sh
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
$ automake --add-missing
$ ./configure
$ make
$ sudo make install
```

### CentOS
```sh
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
```

### Ubuntu,Bash on Windows
```sh
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
$ echo "/usr/local/lib" | sudo tee /etc/ld.so.conf.d/mcmd.conf
$ sudo ldconfig 
```

# Tutorial
Let’s start with a simple example.
 If you have already installed MCMD,
 confirm the following example by typing the same
 at the command line.
 Sample data is required in order to proceed with the tutorial.
 For MCMD, **mdata** command can be used to create different kinds
 of data set.
 In the following example, the data is saved to the file
 **man0.csv** by redirection.

```sh
$ mdata -man0_en >man0.csv
#END# kgData -man0_en; ;
$ more man0.csv
customer,amount
A,5200
B,4000
B,3500
A,2000
B,800
```

After MCMD command is executed successfully,
 it returns a status message starting with #END#.
 In addition, **more** command is a UNIX command
 to display the contents of the file one page
 at a time which allows forward navigation of the file.

Input data is a CSV text file consisting of five records,
 and each record consist of two fields namely **customer** and **amount**. 
The next example below shows summarization of **amount** field
 by a key field **customer**. The **customer** field has a suffix
 of "%0", which means that the output data is sorted by this field
 (the number followed by **%** represents priority
 in multi-fields sorting.

```sh
$ msum k=customer f=amount i=man0.csv o=output.csv
#END# kgsum f=amount k=customer o=output.csv
$ more output.csv
customer%0,amount
A,7200
B,8300
```

Let’s explore a more complex example below.
 It displays the product and corresponding quantity
 by each customer in a matrix format.
 Line comments begin with “#”.
 The function of **mcut** command only extract the specified field,
 the **mcount** command counts the number of rows,
 and **mcross** command performs cross tabulation on the data.
 Rather than dictating detailed processes of each command,
 the following example shows how the input data is processed
 in each command.
 MCMD consist of over 70 commands,
 a variety of data processing can be carried out flexibly
 by combining multiple commands.

```sh
$ mdata -man1_en >man1.csv
#END# kgData -man1_en; ;
$ more man1.csv
customer,date,item
A,20130916,a
A,20130916,c
A,20130917,a
A,20130917,e
B,20130916,d
B,20130917,a
B,20130917,d
B,20130917,f
$ mcut f=customer,item i=man1.csv o=xxa
#END# kgcut f=customer,item i=man1.csv o=xxa; IN=8 OUT=8
$ more xxa
customer,item
A,a
A,c
A,a
A,e
B,d
B,a
B,d
B,f
# Count the number of rows by customer and product.
$ mcount k=customer,item a=freq i=xxa o=xxb
#END# kgcount a=freq i=xxa k=customer,item o=xxb; IN=8 OUT=6
$ more xxb
customer%0,item%1,freq
A,a,2
A,c,1
A,e,1
B,a,1
B,d,2
B,f,1
# Perform a cross tabulation by the item of product. The number of the item that is not purchased gives 0.
$ mcross k=customer s=item f=freq v=0 i=xxb o=xxc
#END# kgcross f=freq i=xxb k=customer o=xxc s=item v=0; IN=6 OUT=2
$ more xxc
customer%0,fld,a,c,d,e,f
A,freq,2,1,0,1,0
B,freq,1,0,2,0,1
# remove extra field "fld".
$ mcut f=fld -r i=xxc o=output.csv
#END# kgcut -r f=fld i=xxc o=output.csv; IN=2 OUT=2
$ more output.csv 
customer%0,a,c,d,e,f
A,2,1,0,1,0
B,1,0,2,0,1
```

The above example, each command outputs the result to the workfiles
 (xxa,xxb,xxc), but it can be run it without them
 by using **pipe** (connect the multiple commands
 with "|" in that order).
 Using pipe, the output of one command become the input for the next command.

```sh
$ mdata man1_en | mcut f=customer,item | mcount k=customer,item a=freq | mcross k=customer s=item f=freq v=0 | mcut f=fld -r o=output.csv
#END# kgData -man1_en; ;
#END# kgcut f=customer,item; IN=8 OUT=8;
#END# kgcount a=freq k=customer,item; IN=8 OUT=6;
#END# kgcross f=freq k=customer s=item v=0; IN=6 OUT=2;
#END# kgcut -r f=fld o=output.csv; IN=2 OUT=2;
$ more output.csv
customer%0,a,c,d,e,f
A,2,1,0,1,0
B,1,0,2,0,1
```

# References
## papers
* [T. Nakahara,M. Nakamoto,Y.Hamuro, NYSOL: Data Analysis Tool for Big Data - performance evaluation, parallel processing and business applications, Operations Research, vol.61, No1, pp.11-18 (in Japanese).](http://www.orsj.or.jp/archive2/or61-1/or61_1_11.pdf)
* [Stephane Cheung, Masakazu Nakamoto, and Yukinobu Hamuro, "NYSOL: A User-Centric Framework for Knowledge Discovery in Big Data," International Journal of Knowledge Engineering vol. 1, no. 3, pp. 214-218, 2015.](http://www.ijke.org/show-39-75-1.html)

## web site
* <a href="http://www.nysol.jp/en/home">NYSOL web page for the old versions</a>
* <a href="http://www.nysol.biz/" target="_blank">NYSOL for business (in Japanese)</a>

# Acknowledgements
The project was partially carried out under the following research fund.
* JST CREST Grant Number JPMJCR1401, Japan
* JST ERATO Minato Discrete Structure Manipulation System Project, Japan
* the ISM Cooperative Research Program(2015- ISM・CRP - 1031), Japan

