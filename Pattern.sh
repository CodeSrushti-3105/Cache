#!/bin/bash

# File to store the results
output_file="pattern_results.txt"

# Read 25 marks from the user
echo "Enter the first 25 marks (separate each by space):"
read -a marks

# Validate that exactly 25 marks were entered
if [ ${#marks[@]} -ne 25 ]; then
    echo "Error: You must enter exactly 25 marks!"
    exit 1
fi

# Write header to the file
echo "Pattern of Marks:" > "$output_file"

# Print the pattern of marks and write to the file
index=0
for ((i=1; i<=5; i++)); do
    line=""
    for ((j=1; j<=i; j++)); do
        line+="${marks[index]} "
        index=$((index + 1))
        if [ $index -ge 25 ]; then
            break 2  # Exit both loops if we've used all 25 marks
        fi
    done
    echo "$line" >> "$output_file"  # Write line to file
    echo "$line"                    # Print line to terminal
done

# Display the results saved in the file
echo "Pattern has been saved to $output_file:"
cat "$output_file"
