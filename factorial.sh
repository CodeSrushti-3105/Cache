echo "Enter the number.."
read num

factorial=1
for((i=1;i<=$num;i++)); do
factorial=$((factorial*i))
done

is_prime=1
if [ $num -le 1 ]; then
is_prime=0
else
 for((i=2;i<=((num/2));i++)); do
 if [ $((num%i)) -eq 0 ]; then
 break
 fi
 done
 fi

echo "Entered no. is $num" > factorial.txt
echo "Factorial is $factorial" >> factorial.txt

if [ $is_prime -eq 1 ]; then
echo "Number is Prime" >> factorial.txt
fi

echo "Result saved in 'factorial.txt':"
cat factorial.txt

