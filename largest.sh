echo "Enter the numbers...."
read num1
read num2
read num3

if [ $num1 -ge $num2 ] && [ $num1 -ge $num3 ]; then
largest=$num1
elif [ $num2 -ge $num1 ] && [ $num2 -ge $num3 ]; then
largest=$num2
else
largest=$num3
fi

echo "Entered no.s are $num1,$num2,$num3" > largest.txt
echo "Largest number is $largest" >> largest.txt

echo "Result is saved in 'largest.txt':"
cat largest.txt