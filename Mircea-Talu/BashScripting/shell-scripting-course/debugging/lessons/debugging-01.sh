#!/bin/bash -x

if [ -e /bin/bash ]
then
    TEST_VAR="test"
    echo "$TEST_VAR"
else
    echo "Surprise"
fi

for i in 1 2
do
    echo $i
done

COLORS="red green blue"

for i in $COLORS
do
    echo "$i"
done

echo "This is the first argument: $1"

for i in "$@"
do
    echo "This is user: $i"
done

read -r -p "Write your name: " NAME

echo "$NAME"

LIST=$(ls)

for i in "${LIST[@]}"
do
    echo "$i"
done