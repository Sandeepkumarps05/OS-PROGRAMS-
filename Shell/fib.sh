echo "Enter the limit for fibonnaci series"
read lim
n1=0
n2=1
var=0
echo "Fibanocci series is"
echo "$n1"
echo "$n2"
limit=`expr $lim - 2`
while [ $var -lt $limit ]
do
n3=`expr $n1 + $n2`
n1=`expr $n2`
n2=`expr $n3`
var=`expr $var + 1`
echo "$n2"
done
