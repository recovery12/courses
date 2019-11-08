gcd_sub = dict()
 
def generate_subarray(A):
	"""
		function to generate subarrays
	"""
	ans = []
	for i in range(len(A)):
		for j in range(i + 1, len(A) + 1):
			ans.append(A[i:j])
	return ans
 
def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)
	
def find_gcd(sub_array):
	"""
		Calculate gcd of given subarray
	"""
	gcd_sub_array = sub_array[0]
	for i in range(1, len(sub_array)):
		gcd_sub_array = gcd(sub_array[i], gcd_sub_array) 
	return gcd_sub_array
	
def main():
	n, k = map(int, input().split())
	A = list(map(int, input().split()))
	sub_arrays = generate_subarray(A)
	
	for sub_array in sub_arrays:
		# For every subarray of length greater than 1
		if len(sub_array) > 1:
			gcd_sub[tuple(sub_array)] = find_gcd(sub_array)
	# Prints
	# {(7, 3): 1, (7, 3, 12): 1, (7, 3, 12, 7): 1, (7, 3, 12, 7, 2): 1, (3, 12): 3, (3, 12, 7): 1, (3, 12, 7, 2): 1, (12, 7): 1, (12, 7, 2): 1, (7, 2): 1}
	print(gcd_sub)
		
	
if __name__ == "__main__":
	main()