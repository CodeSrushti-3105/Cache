#!/bin/bash

echo "Enter the string"
read input_string

# Clean the string by removing spaces and converting to lowercase
cleaned_string=$(echo "$input_string" | tr -d '[:space:]' | tr '[:upper:]' '[:lower:]')

# Reverse the cleaned string
reversed_string=$(echo "$cleaned_string" | rev)

# Check if the cleaned string is equal to the reversed string
if [[ "$cleaned_string" == "$reversed_string" ]]; then
  echo "Entered string is palindrome!"
else
  echo "Not palindrome"
fi
