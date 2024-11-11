#!/bin/bash

# Prompt user for input
echo "Enter the year (e.g., 2024):"
read year

echo "Enter the month (1-12):"
read month

# Validate if the month is between 1 and 12
if [ $month -lt 1 ] || [ $month -gt 12 ]; then
    echo "Error: Invalid month! Please enter a number between 1 and 12."
    exit 1
fi

if [ $year -gt 2024 ]; then
    echo "Error: Invalid year! Please enter a year before 2024."
    exit 2
fi


# Display the calendar for the given year and month using the 'cal' command
echo "Displaying calendar for $month/$year:"
cal $month $year
