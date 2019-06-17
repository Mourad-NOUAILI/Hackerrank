from math import *
t = input()
assert t<=100
for _ in range(t):
    a,b=[int(x) for x in raw_input().split()]
    assert a<=10**9 and b<=10**9 and a>=1 and b>=1
    a=ceil(sqrt(a));b=floor(sqrt(b))
    print int(b-a)+1

