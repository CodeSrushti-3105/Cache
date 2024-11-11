#!/bin/bash

# Create or clear the output file
> output.txt

# Loop through the lines
for i in {1..4}
do
  # Initialize an empty string for each line
  line=""

  # Loop to add numbers with spaces in the current line
  for ((j=1; j<=i; j++))
  do
    # Add the correct odd number to the line
    number=$((2*j - 1))
    line="$line$number "
  done

  # Write the result of the current line to the file
  echo "$line" >> output.txt
done

# Display the content of output.txt
cat output.txt
