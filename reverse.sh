echo "Enter the number:"
read num

reversed=""
original=$num

for(( ;num>0;num/=10))
do
   digit=$((num%10))
   reversed=($reversed$digit)
done

echo "Original number is $original" > reversed_number.txt
echo "Reversed number is $reversed" >> reversed_number.txt

echo "Reversed number is saved in 'reversed_number.txt':"
cat reversed_number.txt