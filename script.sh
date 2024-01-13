#!/bin/bash

filename=.blabla000

touch $filename
i=1
while [[ i -le 100000 ]]
do
A=($(seq 0 500 | sort -R | head -n 100))
./push_swap "${A[@]}" | wc -l | awk '{if ($1 > 5500) printf("%d ***************************\n", $1); else print $1 }' >> $filename
./push_swap "${A[@]}" | ./checker_Mac "${A[@]}" >> $filename
(( i += 1 ))
done


KO=$(cat $filename | grep -c KO)
cat $filename | grep -v OK | awk '{print $1}' > .blabla001
rm -f $filename

filename=.blabla001
sum=0
count=0
min=
max=

while IFS= read -r line; do
    if [[ "$line" =~ ^[0-9]+$ ]]; then
        sum=$((sum + line))
        count=$((count + 1))

        if [ -z "$min" ] || [ "$line" -lt "$min" ]; then
            min=$line
        fi

        if [ -z "$max" ] || [ "$line" -gt "$max" ]; then
            max=$line
        fi
    else
        echo "Warning: Skipping invalid number on line '$line'"
    fi
done < "$filename"

if [ "$count" -eq 0 ]; then
    echo "Error: No valid numbers found in the file."
    exit 1
fi

average=$(( $sum / $count ))

rm -f $filename
echo "KO: $KO"
echo "Count: $count"
echo "Min: $min"
echo "Average: $average"
echo "Max: $max"