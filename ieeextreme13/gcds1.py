gcd_sub = set()
 
def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)
 
	
def main():
	n, k = map(int, input().split())
	arr = list(map(int, input().split()))

	dp = [[-1 for _ in range(len(arr))] for _ in range(len(arr))]
	
	# Set GCD of single element as the leemnt itself
	for i in range(len(arr)):
		dp[i][i] = arr[i]
		
	# For every other subarrays of length l
	# Calculate gcd using  length l - 1
	for i in range(0, len(arr)):
		for j in range(i+1, len(arr)):
			# print(A[i:j], A[j])
			dp[i][j] = gcd(dp[i][j - 1], arr[j])
			gcd_sub.add(dp[i][j])
	print(dp)
	print(gcd_sub)
			
if __name__ == "__main__":
	main()