echo "Enter first number"
read n1
echo "Enter second number"
read n2
if [ $n1 -gt $n2 ]
then 
echo "$n1 is large number"
else
echo "$n2 is large number"
fi