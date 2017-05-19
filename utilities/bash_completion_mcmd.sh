
#############################
# M-command bash completion
comp_mcmd_version=1.0
# 1.0: initial release
#############################

#############################
# initialization for mcmd completion
# 1. add "," as a word break
__comp_mcmd_initialize() {
	COMP_WORDBREAKS=${COMP_WORDBREAKS##*,}
	if [[ "${COMP_WORDBREAKS}" != "*,*" ]] ; then
		COMP_WORDBREAKS=",${COMP_WORDBREAKS}"
	fi
}

#############################
# finalization for mcmd completion
__comp_mcmd_finalize() {
	return 0
}

#############################
# change a delimiter of arguments "$@" from $1 to SPACE
__comp_mcmd_split() {
	sp=$1
	shift
	echo "$@" | tr -s "${sp}" ' '
}

#############################
# find keyword $1 in the rest of arguments, and return the value for the keyword.
__comp_mcmd_getval() {
	kw=$1
	#echo kw:${kw} >&2
	shift
	argv=($@)
	for kv in ${argv[@]} ;do
		#echo ${kv%%=*} >&2
		#if [ "$kw" = "${kv%%=*}=" ] ; then
		if [[ "$kv" == ${kw}* ]] ; then
			echo ${kv#*=}
		fi
	done
	echo ""
}

#############################
# Return field names of the CSV file $1, which will be delimited by space.
# If there is a space in a field name, this function may not work as expected.
# $1: csv filename
__comp_mcmd_getflds() {
	# retunr nil if the filename $1 is nill
	if [[ "$1" == "" ]] ; then
		echo ""

	# Return field names of the CSV file $1, which will be delimited by space.
	# If there is a space in a field name, this function may not work as expected.
	else
		header=`head -1 $1`
		echo `__comp_mcmd_split "," $header`
	fi
}

#############################
# boolean function
# return 0(true) if string $1 is a purly part of string in $opts[@], else 1
__comp_mcmd_isHead() {
	local inp opts opt
	inp=$1; shift
	opts=$@
	for opt in ${opts[@]} ; do
		if [[ "$opt" == "$inp"* ]] ; then
			if [[ "$opt" == "$inp" ]] ; then
				return 1
			fi
			return 0
		fi
	done
	return 1
}

#############################
# generate keyword list of all parameters in help document
# $1: command name (will be run with --help)
#__comp_mcmd_getOpt() {
#	echo `$1 --help 2>&1 |
#	awk '/Format/,/Parameters/' |
#	sed 's/^Format//' |
#	sed 's/Parameters//' |
# grep '^.' |
# tr -d '\n' |
# tr '[' ' ' |
# tr ']' ' ' |
# sed -e s/$1// |
#sed -e 's/ +/ /g'`
#}

#############################
# generate keyword list of all parameters in help document
# $1: command name (will be run with -params)
__comp_mcmd_getOpt() {
  echo `$1 -params`
}

#############################
# completion for input file name
# $1: "i="
# $2: current word. ex)"i=aaa"
__comp_mcmd_ifile() {
	local inp
	inp=$(__comp_mcmd_getval $1 $2) # remove "i="
	echo $(compgen -f ${inp}) # file or directory name completion
}

#############################
# completion for output file name
# $1: "o="
# $2: current word. ex)"o=aaa"
__comp_mcmd_ofile() {
	local inp
	inp=$(__comp_mcmd_getval $1 $2) # remove "o="
	echo $(compgen -f ${inp}) # file or directory name completion
}

#############################
# completion of field name on csv file
#  1.get current field name
#  2.get field name list
#  3.generate copletion name list matching with the current field name
# $1: keyword. ex)"f="
# $2: current word. ex)"f=xxx,yyy,aaa"
# $3: keyword for input file. ex)"i="
# $4: all arguments ex)"i=aaa.csv k=kkkk f=xxx,yyy,aaa"
__comp_mcmd_field() {
	local kw cw ikw inp flds iFile
	kw=$1 ; shift
	cw=$1 ; shift
	ikw=$1 ; shift
	inp=$(__comp_mcmd_getval $kw $cw)    # remove "f="
	inp=${inp##*,}             # remove front elements("xxx,oo"=>"oo")
	iFile=$(__comp_mcmd_getval $ikw $@)  # file name specified with i=
	mFile=$(__comp_mcmd_getval $ikw $@)  # file name specified with m=
	flds=$(__comp_mcmd_getflds ${iFile}) # get field names on the input file
	echo $(compgen -W "${flds}" -- ${inp})
}

#############################
# completion by string list
#  1.get current field name
#  2.get field name list
#  3.generate copletion name list matching with the current field name
# $1: keyword. ex)"c="
# $2: current word. ex)"c=xxx,yyy,aaa"
# $3: string list. ex)"lift support hamming ..."
__comp_mcmd_slist() {
	local inp
	inp=$(__comp_mcmd_getval $1 $2)
	inp=${inp##*,}
	echo $(compgen -W "$3" -- ${inp})
}

#############################
__comp_msum() {
	local opt cur prev cword
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

#echo cmd:${cmd} >xxlog
#echo cur:${cur} >>xxlog
#echo prev:${prev} >>xxlog
#echo cword:${cword} >>xxlog
#echo cword:${cword} >>xxlog
#echo COMP_WORDBREAKS:$COMP_WORDBREAKS >>xxlog
#echo COMP_POINT:$COMP_POINT >>xxlog
#echo COMP_LINE:$COMP_LINE >>xxlog
#echo COMP_WORDS:${COMP_WORDS[@]} >>xxlog

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		#echo head match x${cur}x >>xxlog
		#echo head opt ${opt} >>xxlog
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_msim() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_c="covar ucovar pearson spearman kendall euclid cosine cityblock hamming chi phi jaccard supportr lift confMax confMin yuleQ yuleY kappa oddsRatio convMax convMin"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			c=*) COMPREPLY=( $(__comp_mcmd_slist "c=" ${cur} "${par_c}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mcut() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
} 

#############################
__comp_mstats() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_c="sum mean count ucount devsq var uvar sd usd USD cv min qtile1 median qtile3 max range qrange mode skew uskew kurt ukurt"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			c=*) COMPREPLY=( $(__comp_mcmd_slist "c=" ${cur} "${par_c}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_m2cross() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_c="sum mean count ucount devsq var uvar sd usd USD cv min qtile1 median qtile3 max range qrange mode skew uskew kurt ukurt"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			s=*) COMPREPLY=( $(__comp_mcmd_field "s=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_maccum() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_c="sum mean count ucount devsq var uvar sd usd USD cv min qtile1 median qtile3 max range qrange mode skew uskew kurt ukurt"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			s=*) COMPREPLY=( $(__comp_mcmd_field "s=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_marff2csv() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mavg() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_c="sum mean count ucount devsq var uvar sd usd USD cv min qtile1 median qtile3 max range qrange mode skew uskew kurt ukurt"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mbest() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_c="sum mean count ucount devsq var uvar sd usd USD cv min qtile1 median qtile3 max range qrange mode skew uskew kurt ukurt"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			s=*) COMPREPLY=( $(__comp_mcmd_field "s=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mbucket() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_F="0 1 2"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			F=*) COMPREPLY=( $(__comp_mcmd_slist "F=" ${cur} "${par_F}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mcal() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

#par_c="0d 0t 0b ${} $s{} $d{} $t{} $b{} #{} #s{} #d{} #t{} #b{} + - * / % ^ == != > < >= <= && || ^^ sum avg sqsum min max product factorial gdc lcm sqrt abs sign int fract round floor ceil power exp log ln log2 log10 dist distgps heron rand randi nrand pi() e() format acos asin atan atan2 cos sin tan degree radian cosh sinh tanh cat length fixlen fight left mid toupper tolower capitalize match hasspace regexm regexs regexrep regexlen regexpos regexstr regexpfx regexsfx today() now() tseconfds leapyear year month day week dow time date hour minute second age diff uxt julian and or not if line() top() bottom() fldsize() argsize nulln() nulls() nulld() nullt() nullb() isnull countnull s2n b2n n2s d2s t2s b2s s2d t2d s2t d2t n2b s2b"
# cannot use string start from "*" or "$".
par_c="0d 0t 0b #{} #s{} #d{} #t{} #b{} + - / % ^ == != > < >= <= && || ^^ sum avg sqsum min max product factorial gdc lcm sqrt abs sign int fract round floor ceil power exp log ln log2 log10 dist distgps heron rand randi nrand pi() e() format acos asin atan atan2 cos sin tan degree radian cosh sinh tanh cat length fixlen fight left mid toupper tolower capitalize match hasspace regexm regexs regexrep regexlen regexpos regexstr regexpfx regexsfx today() now() tseconfds leapyear year month day week dow time date hour minute second age diff uxt julian and or not if line() top() bottom() fldsize() argsize nulln() nulls() nulld() nullt() nullb() isnull countnull s2n b2n n2s d2s t2s b2s s2d t2d s2t d2t n2b s2b"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			c=*) COMPREPLY=( $(__comp_mcmd_slist "c=" ${cur} "${par_c}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mcat() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mchgnum() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_R="MIN MAX"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			R=*) COMPREPLY=( $(__comp_mcmd_slist "R=" ${cur} "${par_R}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mchgstr() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mchkcsv() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mcombi() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			s=*) COMPREPLY=( $(__comp_mcmd_field "s=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mcommon() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			m=*) COMPREPLY=( $(__comp_mcmd_ifile "m=" ${cur}) ) ;;
			K=*) COMPREPLY=( $(__comp_mcmd_field "K=" ${cur} "m=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mcount() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mcross() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			s=*) COMPREPLY=( $(__comp_mcmd_field "s=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mcsv2arff() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			n=*) COMPREPLY=( $(__comp_mcmd_field "n=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			D=*) COMPREPLY=( $(__comp_mcmd_field "D=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			d=*) COMPREPLY=( $(__comp_mcmd_field "d=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			s=*) COMPREPLY=( $(__comp_mcmd_field "s=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mdelnull() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mdformat() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_c="%Y %y %m %d %H %M %S"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			c=*) COMPREPLY=( $(__comp_mcmd_slist "c=" ${cur} "${par_c}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mduprec() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mfldname() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mfsort() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mhashavg() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mhashsum() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mjoin() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "m=" "${COMP_WORDS[@]}") );;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			m=*) COMPREPLY=( $(__comp_mcmd_ifile "m=" ${cur}) ) ;;
			K=*) COMPREPLY=( $(__comp_mcmd_field "K=" ${cur} "m=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mkeybreak() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			s=*) COMPREPLY=( $(__comp_mcmd_field "s=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mmbucket() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_F="0 1 2"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			F=*) COMPREPLY=( $(__comp_mcmd_slist "F=" ${cur} "${par_F}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mmvavg() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_c="sum mean count ucount devsq var uvar sd usd USD cv min qtile1 median qtile3 max range qrange mode skew uskew kurt ukurt"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			s=*) COMPREPLY=( $(__comp_mcmd_field "s=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mmvsim() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_c="covar ucovar pearson spearman kendall euclid cosine cityblock hamming chi phi jaccard supportr lift confMax confMin yuleQ yuleY kappa oddsRatio convMax convMin"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			c=*) COMPREPLY=( $(__comp_mcmd_slist "c=" ${cur} "${par_c}") );;
			s=*) COMPREPLY=( $(__comp_mcmd_field "s=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mmvstats() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_c="sum mean count ucount devsq var uvar sd usd USD cv min qtile1 median qtile3 max range qrange mode skew uskew kurt ukurt"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			c=*) COMPREPLY=( $(__comp_mcmd_slist "c=" ${cur} "${par_c}") );;
			s=*) COMPREPLY=( $(__comp_mcmd_field "s=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mnewnumber() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mnewrand() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mnewstr() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mnjoin() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "m=" "${COMP_WORDS[@]}") );;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			m=*) COMPREPLY=( $(__comp_mcmd_ifile "m=" ${cur}) ) ;;
			K=*) COMPREPLY=( $(__comp_mcmd_field "K=" ${cur} "m=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mnormalize() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_c="z Z range"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			c=*) COMPREPLY=( $(__comp_mcmd_slist "c=" ${cur} "${par_c}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mnrcommon() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			m=*) COMPREPLY=( $(__comp_mcmd_ifile "m=" ${cur}) ) ;;
			K=*) COMPREPLY=( $(__comp_mcmd_field "K=" ${cur} "m=" "${COMP_WORDS[@]}") );;
			R=*) COMPREPLY=( $(__comp_mcmd_field "R=" ${cur} "m=" "${COMP_WORDS[@]}") );;
			r=*) COMPREPLY=( $(__comp_mcmd_field "r=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mnrjoin() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			m=*) COMPREPLY=( $(__comp_mcmd_ifile "m=" ${cur}) ) ;;
			K=*) COMPREPLY=( $(__comp_mcmd_field "K=" ${cur} "m=" "${COMP_WORDS[@]}") );;
			R=*) COMPREPLY=( $(__comp_mcmd_field "R=" ${cur} "m=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "m=" "${COMP_WORDS[@]}") );;
			r=*) COMPREPLY=( $(__comp_mcmd_field "r=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mnullto() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mnumber() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	par_e="seq same skip"

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			e=*) COMPREPLY=( $(__comp_mcmd_slist "e=" ${cur} "${par_e}") );;
			s=*) COMPREPLY=( $(__comp_mcmd_field "s=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mpadding() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mpaste() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			m=*) COMPREPLY=( $(__comp_mcmd_ifile "m=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "m=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mproduct() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			m=*) COMPREPLY=( $(__comp_mcmd_ifile "m=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "m=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mrand() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mrjoin() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "m=" "${COMP_WORDS[@]}") );;
			r=*) COMPREPLY=( $(__comp_mcmd_field "r=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			m=*) COMPREPLY=( $(__comp_mcmd_ifile "m=" ${cur}) ) ;;
			K=*) COMPREPLY=( $(__comp_mcmd_field "K=" ${cur} "m=" "${COMP_WORDS[@]}") );;
			R=*) COMPREPLY=( $(__comp_mcmd_field "R=" ${cur} "m=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_msed() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_msel() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mselnum() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mselrand() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_mselstr() {
	local opt cur prev cword par_c
	__comp_mcmd_initialize
	cmd=${1##*/} # command name
	opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
	_get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

	## completion of keywords (i= -assertion etc.)
	__comp_mcmd_isHead "${cur}" "$opt"
	if [[ $? -eq 0 ]] ; then
		COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

	## when the current position is just next to a keyword
	else
		case "${cur}" in
			i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
		esac
	fi
	__comp_mcmd_finalize
}

#############################
__comp_msep() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_msep2() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_msetstr() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mshare() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mshuffle() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mslide() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			s=*) COMPREPLY=( $(__comp_mcmd_field "s=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_msortf() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_msplit() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_msummary() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
	par_c="sum mean count ucount devsq var uvar sd usd cv min qtile1 median qtile3 max range qrange mode skew uskew kurt ukurt"

  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			c=*) COMPREPLY=( $(__comp_mcmd_slist "c=" ${cur} "${par_c}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mtab2csv() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mtee() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mtonull() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mtra() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			s=*) COMPREPLY=( $(__comp_mcmd_field "s=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mtrafld() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mtraflg() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_muniq() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mvcat() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.
  
  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			vf=*) COMPREPLY=( $(__comp_mcmd_field "vf=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mvcommon() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			vf=*) COMPREPLY=( $(__comp_mcmd_field "vf=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			m=*) COMPREPLY=( $(__comp_mcmd_ifile "m=" ${cur}) ) ;;
			K=*) COMPREPLY=( $(__comp_mcmd_field "K=" ${cur} "m=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mvcount() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			vf=*) COMPREPLY=( $(__comp_mcmd_field "vf=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mvdelim() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			vf=*) COMPREPLY=( $(__comp_mcmd_field "vf=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mvdelnull() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			vf=*) COMPREPLY=( $(__comp_mcmd_field "vf=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mvjoin() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			vf=*) COMPREPLY=( $(__comp_mcmd_field "vf=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			m=*) COMPREPLY=( $(__comp_mcmd_ifile "m=" ${cur}) ) ;;
			K=*) COMPREPLY=( $(__comp_mcmd_field "K=" ${cur} "m=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "m=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mvnullto() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			vf=*) COMPREPLY=( $(__comp_mcmd_field "vf=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mvreplace() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			vf=*) COMPREPLY=( $(__comp_mcmd_field "vf=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			m=*) COMPREPLY=( $(__comp_mcmd_ifile "m=" ${cur}) ) ;;
			K=*) COMPREPLY=( $(__comp_mcmd_field "K=" ${cur} "m=" "${COMP_WORDS[@]}") );;
			f=*) COMPREPLY=( $(__comp_mcmd_field "f=" ${cur} "m=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mvsort() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			vf=*) COMPREPLY=( $(__comp_mcmd_field "vf=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mvuniq() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			vf=*) COMPREPLY=( $(__comp_mcmd_field "vf=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mwindow() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
			wk=*) COMPREPLY=( $(__comp_mcmd_field "wk=" ${cur} "i=" "${COMP_WORDS[@]}") );;
			k=*) COMPREPLY=( $(__comp_mcmd_field "k=" ${cur} "i=" "${COMP_WORDS[@]}") );;
    esac
  fi
  __comp_mcmd_finalize
}

#############################
__comp_mxml2csv() {
  local opt cur prev cword par_c
  __comp_mcmd_initialize
  cmd=${1##*/} # command name
  opt=$(__comp_mcmd_getOpt $cmd) # get all keywords of parameters in a help document
  _get_comp_words_by_ref -n : cur prev cword  # get word on current position, etc.

  ## completion of keywords (i= -assertion etc.)
  __comp_mcmd_isHead "${cur}" "$opt"
  if [[ $? -eq 0 ]] ; then
    COMPREPLY=( $(compgen -W "${opt}" -- ${cur}) )

  ## when the current position is just next to a keyword
  else
    case "${cur}" in
      i=*) COMPREPLY=( $(__comp_mcmd_ifile "i=" ${cur}) ) ;;
      o=*) COMPREPLY=( $(__comp_mcmd_ofile "o=" ${cur}) ) ;;
    esac
  fi
  __comp_mcmd_finalize
}


#############################
#############################
complete -F __comp_msum msum
complete -F __comp_msim msim
complete -F __comp_mcut mcut
complete -F __comp_mstats mstats
#ここから1から順に追加
complete -F __comp_m2cross m2cross
complete -F __comp_maccum maccum
complete -F __comp_marff2csv marff2csv
complete -F __comp_mavg mavg
complete -F __comp_mbest mbest
complete -F __comp_mbucket mbucket
complete -F __comp_mcal mcal
complete -F __comp_mcat mcat
complete -F __comp_mchgnum mchgnum
complete -F __comp_mchgstr mchgstr
complete -F __comp_mchkcsv mchkcsv
complete -F __comp_mcombi mcombi
complete -F __comp_mcommon mcommon
complete -F __comp_mcount mcount
complete -F __comp_mcross mcross
complete -F __comp_mcsv2arff mcsv2arff
complete -F __comp_mdelnull mdelnull
complete -F __comp_mdformat mdformat
complete -F __comp_mduprec mduprec
complete -F __comp_mfldname mfldname
complete -F __comp_mfsort mfsort
complete -F __comp_mhashavg mhashavg
complete -F __comp_mhashsum mhashsum
complete -F __comp_mjoin mjoin
complete -F __comp_mkeybreak mkeybreak
complete -F __comp_mmbucket mmbucket
complete -F __comp_mmvavg mmvavg
complete -F __comp_mmvsim mmvsim
complete -F __comp_mmvstats mmvstats
complete -F __comp_mnewnumber mnewnumber
complete -F __comp_mnewrand mnewrand
complete -F __comp_mnewstr mnewstr
complete -F __comp_mnjoin mnjoin
complete -F __comp_mnormalize mnormalize
complete -F __comp_mnrcommon mnrcommon
complete -F __comp_mnrjoin mnrjoin
complete -F __comp_mnullto mnullto
complete -F __comp_mnumber mnumber
complete -F __comp_mpadding mpadding
complete -F __comp_mpaste mpaste
complete -F __comp_mproduct mproduct
complete -F __comp_mrand mrand
complete -F __comp_mrjoin mrjoin
complete -F __comp_msed msed
complete -F __comp_msel msel
complete -F __comp_mselnum mselnum
complete -F __comp_mselrand mselrand
complete -F __comp_mselstr mselstr
complete -F __comp_msep msep
complete -F __comp_msep2 msep2
complete -F __comp_msetstr msetstr
complete -F __comp_mshare mshare
complete -F __comp_mshuffle mshuffle
complete -F __comp_mslide mslide
complete -F __comp_msortf msortf
complete -F __comp_msplit msplit
complete -F __comp_msummary msummary
complete -F __comp_mtab2csv mtab2csv
complete -F __comp_mtee mtee
complete -F __comp_mtonull mtonull
complete -F __comp_mtra mtra
complete -F __comp_mtrafld mtrafld
complete -F __comp_mtraflg mtraflg
complete -F __comp_muniq muniq
complete -F __comp_mvcat mvcat
complete -F __comp_mvcommon mvcommon
complete -F __comp_mvcount mvcount
complete -F __comp_mvdelim mvdelim
complete -F __comp_mvdelnull mvdelnull
complete -F __comp_mvjoin mvjoin
complete -F __comp_mvnullto mvnullto
complete -F __comp_mvreplace mvreplace
complete -F __comp_mvsort mvsort
complete -F __comp_mvuniq mvuniq
complete -F __comp_mwindow mwindow
complete -F __comp_mxml2csv mxml2csv

