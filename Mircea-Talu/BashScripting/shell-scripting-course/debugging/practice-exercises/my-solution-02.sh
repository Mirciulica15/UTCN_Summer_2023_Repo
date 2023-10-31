#!/bin/bash -x

echo "$1"

ls .

ls solution-03.sh 2> ERRORCODE

if [ "$ERRORCODE" != 0 ]

then "$(cat ERRORCODE)"

fi

ls ..
