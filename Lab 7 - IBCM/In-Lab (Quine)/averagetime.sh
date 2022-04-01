#!/bin/bash 
#Nathaniel Goldammer (wsn8pk) - 3/22/2022 - averagetime.sh

#Prompt the user to input the an exponent for counter.cpp
echo 'enter an exponent for counter.cpp:'
read exponent

#If exponent = quit, then terminate the shell script
if [[ $exponent = "quit" ]] ; then
	exit 1
fi

#Let TOTAL = the total execution time of 5 iterations (0 by default)
TOTAL=0

#For each integer i from 0 to 4
for i in {0..4} ; do 
	#Display which iteration is being executed
	echo 'Running iteration ' $i '...'

	#Let RUNTIME = the execution time of the i'th iteration
	RUNTIME=`./a.out "$exponent" | tail -1`

	#Display the execution time of the i'th iteration
	echo 'time taken: ' $RUNTIME

	#Increment TOTAL by RUNTIME
	TOTAL=$((TOTAL + RUNTIME))
done

#Display the total execution time of 5 iterations
echo '5 iterations took ' $TOTAL

#Let AVERAGE = the average execution time of 5 the iterations
AVERAGE=$((TOTAL / 5))

#Display the average execution time of 5 the iterations
echo 'Average time was ' $AVERAGE