n, m = map(int, input().split())
spaceCities = map(int, input().split())

arr = [0] * n

for val in spaceCities:
    arr[val] = 1

maxi = 0;
dp = [0] * n

for i in range(n):
    if arr[i] == 1:
        dp[i] = 0
    else:
        if i == 0:
            dp[i] = 10**9
        else:
            dp[i] = dp[i-1] + 1
    maxi = max(maxi,dp[i])
print (maxi)


