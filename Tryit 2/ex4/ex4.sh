#!/bin/bash

ARGS=2
E_BADARGS=65
E_NOFILE=66

if [ $# -ne "$ARGS" ]
then
	echo "The number of parameters entered is incorrect."
	exit $E_BADARGS
fi

if [ ! -f "$1" ]
then
   	echo "File \"$1\" does not exist."
   	exit $E_NOFILE
fi

if [ ! -f "$2" ]
then
 	touch "$2"
fi

cat $1 > $2

printf "%s\n" "$(<$1)"

fileLines=`sed -n '$=' $1`
wordNums=($(wc -w $1))
echo "This file contains $wordNums words and $fileLines lines." >> $2
printf "This file contains %d words and %d lines.\n" $wordNums $fileLines

