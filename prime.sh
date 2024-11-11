#!/bin/bash

# Prompt user to enter 25 numbers
echo "Enter 25 numbers:"
for i in {1..25}
do
    read num[$i]
done

# Initialize counters and arrays
even_count=0
odd_count=0
prime_count=0
even_numbers=()
odd_numbers=()
prime_numbers=()

# Check each number
for num in ${num[@]}; do
    # Check if even
    if [ $((num % 2)) -eq 0 ] && [ $even_count -lt 5 ]; then
        even_numbers+=($num)
        ((even_count++))
    # Check if odd
    elif [ $((num % 2)) -ne 0 ] && [ $odd_count -lt 5 ]; then
        odd_numbers+=($num)
        ((odd_count++))
    # Check if prime
    elif [ $num -gt 1 ]; then
        is_prime=1
        for ((i=2; i<=$((num / 2)); i++)); do
            if [ $((num % i)) -eq 0 ]; then
                is_prime=0
                break
            fi
        done
        if [ $is_prime -eq 1 ] && [ $prime_count -lt 5 ]; then
            prime_numbers+=($num)
            ((prime_count++))
        fi
    fi
    # Stop if we have found 5 of each
    if [ $even_count -eq 5 ] && [ $odd_count -eq 5 ] && [ $prime_count -eq 5 ]; then
        break
    fi
done

# Save results to a file
echo "First five even numbers: ${even_numbers[@]}" > numbers_results.txt
echo "First five odd numbers: ${odd_numbers[@]}" >> numbers_results.txt
echo "First five prime numbers: ${prime_numbers[@]}" >> numbers_results.txt

# Display the results
echo "Results saved in 'numbers_results.txt':"
cat numbers_results.txt
