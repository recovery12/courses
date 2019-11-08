# of size k with maximum possible GCD. 
import math 

# function to find GCD of sub sequence 
# of size k with max GCD in the array 
def findMaxGCD(arr, n, k): 

    # Computing highest element 
    high = max(arr)     
    # Array to store the count of 
    # divisors i.e. Potential GCDs 
    divisors = [0] * (high + 1)     
    # Iterating over every element 
    for i in range(n) :     
    	# Calculating all the divisors 
    	for j in range(1, int(math.sqrt(arr[i])) + 1):     
    		# Divisor found 
    		if (arr[i] % j == 0):     
    			# Incrementing count for divisor 
    			divisors[j] += 1    
    			# Element/divisor is also a divisor 
    			# Checking if both divisors are 
    			# not same 
    			if (j != arr[i] // j): 
    				divisors[arr[i] // j] += 1
    return divisors

# Driver code 
if __name__ == "__main__":
	n, k = map(int, input().split())
	arr = list(map(int, input().split()))

	n = len(arr)
	div = list()
	for i in range(1, k+1):
		tmp = findMaxGCD(arr, n, i)
		div.extend(tmp)
	print(len(set(div))-1) 


