#!/bin/bash

read -p "Enter first number: " num1
read -p "Enter second number: " num2

# invalid number
re='^[0-9]+$'
if ! [[ $num1 =~ $re && $num2 =~ $re ]] ;
    then echo "Error! Only numbers are valid as input"; $SHELL
fi

# Input type of operation
echo "+"
echo "-"
echo "*"
echo "/"
read -p "Select operator: " operator


# Result
case $operator in
  '+') result=$((num1 + num2))
  ;;
  '-') result=$((num1 - num2))
  ;;
  '*') result=$((num1 * num2))
  ;;
  '/') result=$((num1 / num2))
  ;;
esac
echo "Result : $result"

$SHELL