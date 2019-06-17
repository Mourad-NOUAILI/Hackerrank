from math import floor
n = input()
n = int(n)

shares = 5
totalShares = 0
for i in range(n):
    likes = floor(shares/2)
    shares = likes * 3
    totalShares += likes
print (totalShares)
