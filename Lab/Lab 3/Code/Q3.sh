#!/bin/bash

while :
do
    read -p "Enter number: " num

    # Exit if num is equal to 0 
    zero=0;
    if [[ $num -eq $zero ]]; then
        echo "Exit!";
        exit;
    fi

    # Result
    sum=0
    rev=0
    while [ $num -gt 0 ]
    do
        remain=$(( $num % 10 ))
        sum=$(( $sum + $remain ))
        rev=$(( $rev * 10 + $remain ))
        num=$(( $num / 10 ))
    done
    echo "Reversed number: $rev"
    echo "Sum of digits: $sum"
    echo ""
done

$SHELL