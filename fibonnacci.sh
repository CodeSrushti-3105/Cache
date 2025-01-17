#!/bin/bash 
 
# Function to calculate Fibonacci series 
fibonacci() { 
    n=$1 
    a=0 
    b=1 
    i=2 
 
    echo "Fibonacci Series up to $n terms:" 
    echo -n "$a " 
    echo -n "$b " 
 
    while [ $i -lt $n ] 
    do 
        c=$((a + b)) 
        echo -n "$c " 
        a=$b 
        b=$c 
        i=$((i + 1)) 
    done 
 
    echo "" 
} 
 
# Read input from user 
echo -n "Enter the number of terms for Fibonacci series: " 
read num 
 
# Call function with user input 
fibonacci $num