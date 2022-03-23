#!/bin/bash

echo "1. Numbers"
echo "2. Diamond"
echo "3. Stair"
read -p "Enter number: " num

case $num in
  1)
    for (( i=1; i<=5 ; i++))
    do
        for (( j=1; j<=$i; j++ ))
        do
            echo -n "$i"
        done
        echo ""
    done
  ;;
  2)
    for (( i=1; i<=6 ; i++))
    do

        for (( j=6; j>=i; j-- ))
        do echo -n " "
        done

        for (( k=1; k<=i; k++ ))
        do echo -n " *"
        done

        echo ""
    done


    for (( i=5; i>=1; i--))
    do

        for (( j=i; j<=5; j++ ))
        do
            if [ $j -eq 5 ]
                then echo -n " "
            fi

            echo -n " "
        done

        for (( k=1; k<=i; k++ ))
        do echo -n " *"
        done

        echo ""
    done
  ;;
  3)
    for (( i=1; i<=5 ; i++))
    do  
        for (( j=0; j<$i; j++ ))
        do  
            echo -n "|"

            if ! [ $j -eq $(($i - 1)) ]
            then
                echo -n " "
            fi

        done
        echo "_"
    done
  ;;
esac

$SHELL