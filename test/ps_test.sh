CNT=500
LIMIT=5500
INDEX=0
ITER=100
NUM_OVER=0
MAX=$LIMIT
ARG=`jot -r $CNT -2147483647 2147483647 | tr "\n" " "`
NUM=`../ps/push_swap $ARG | wc -l`
 
while [ $INDEX -lt $ITER ]
do
echo "$INDEX    :    $NUM"
if [ $NUM -ge $LIMIT ]; then
NUM_OVER=`expr $NUM_OVER + 1`
fi
if [ $NUM -gt $MAX ]; then
MAX=$NUM
fi
ARG=`jot -r $CNT -21474836 21474836 | tr "\n" " "`
NUM=`../ps/push_swap $ARG | wc -l`
INDEX=`expr $INDEX + 1`
done
echo "$NUM_OVER overred operations for $ITER times"
if [ $NUM_OVER -gt 0 ]; then
echo "Biggest operation number : $MAX"
echo "fix it!!!!!!!!!!"
fi
