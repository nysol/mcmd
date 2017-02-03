#!/bin/bash

. ../env

#name_kg_mcmd window

${pfxc}mxml2csv i=./indat/dat1.xml  o=./outdat/out1.csv k=/a/b f=@att:b_att,c@p:c_p,c@p%f:c_p_f,d:d,/a:a                  
${pfxc}mxml2csv i=./indat/dat1.xml  o=./outdat/out2.csv k=/a/b f=/a/b@att:b_att,/a/b/c@p:c_p,/a/b/c@p%f:c_p_f,/a/b/d:d,/a:a 
${pfxc}mxml2csv i=./indat/dat1.xml  o=./outdat/out3.csv k=/a   f=/a/b@att:b_att,/a/b/c@p:c_p,/a/b/c@p%f:c_p_f,/a/b/d:d,/a:a 

