import math

n,m = input().split()
n,m = [int(n),int(m)]

spaceCities = [int(sci) for sci in input().strip().split(' ')]

maxi = 0
for i in range(n):
    if i not in spaceCities:
        mini = math.inf
        for sci in spaceCities:
            mini = min(mini,abs(i-sci))
        maxi = max(maxi,mini)
print (maxi)
