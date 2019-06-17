in1=map(int,raw_input().split())
N=in1[0]
T=in1[1]
assert N<=100000
assert N>=1
assert T<=1000
assert T>=1
a=map(int,raw_input().split())
assert max(a)<=3 
assert min(a)>=1
for i in range(0,T):
    index=map(int,raw_input().split())
    assert index[0]>=0
    assert index[1]<N
    assert index[1]>index[0]
    print min(a[index[0]:index[1]+1])
