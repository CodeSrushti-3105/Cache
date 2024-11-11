echo "Enter the first number.."
read num1
echo "Enter the second number.."
read num2

add=$((num1 + num2))
sub=$((num1 - num2))
mul=$((num1 * num2))

if [ $num2 -gt 0 ]; then
div=$((num1 / num2))
else
echo "Invalid entries.."
fi

echo "Addition of two numbers is $add = $num1 + $num2" > arithmatic.txt
echo "Subtraction of two numbers is $sub = $num1 - $num2" >>arithmatic.txt
echo "Multiplication of two numbers is $mul = $num1 * $num2" >>arithmatic.txt
echo "Division of two numbers is $div = $num1 / $num2" >>arithmatic.txt

echo "Result is saved in 'arithmatic.txt':"
cat arithmatic.txt