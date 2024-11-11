echo "Enter the marks of first subject:"
read m1
echo "Enter the marks of second subject:"
read m2
echo "Enter the marks of third subject:"
read m3

total=$((m1+m2+m3))
average=$((total/3))

case $average in
    [9]*)
        grade="A" ;;
    [7-8]*)
        grade="B" ;;
    [5-6]*)
        grade="C" ;;
    *)
        grade="Fail" ;;
esac



echo "Total Marks is $total" > student_results.txt
echo "Average is $average" >> student_results.txt
echo "Grade is $grade" >> student_results.txt

echo "Result of student is saved in 'student_results.txt':"
cat student_results.txt



