#!/bin/bash

ARGS=1
E_BADARGS=65
E_NOFILE=66

if [ $# -ne "$ARGS" ]
then
        echo "The number of parameters entered is incorrect."
        exit $E_BADARGS
fi

if [ ! -f "$1" ]
then
        touch "$1"
fi

for file in `ls *.c`
do
    	gcc $file -o ${file%.*}
	./${file%.*}
	./${file%.*} >> $1
	
done

cd "./more_files"

for file in `ls *.c`
do
        gcc $file -o ${file%.*}
	./${file%.*}
	./${file%.*} >> ../$1
done

