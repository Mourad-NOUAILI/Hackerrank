#short python
for _ in range(input()):
    n,k = map(int,raw_input().split())
    a1 = filter(lambda x:x<=0,map(int,raw_input().split()))
    print ["YES","NO"][len(a1) >= k]

