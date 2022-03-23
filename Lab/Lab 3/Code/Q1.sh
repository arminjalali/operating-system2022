#!/bin/bash

read -p "Enter first number: " num1
read -p "Enter second number: " num2

# invalid number
re='^[0-9]+$'
if ! [[ $num1 =~ $re && $num2 =~ $re ]];
    then echo "Error! Only numbers are valid as input"; $SHELL
fi

# sum
sum=$((num1 + num2))
echo "Sum: $sum"

# greater
if [ $num1 -gt $num2 ]
    then echo "Greater number is: $num1"
else echo "Greater number is: $num2"
fi

$SHELL