#Long Python
for _ in range(input()):
    n,k = map(int,raw_input().split())
    arr = map(int,raw_input().split())
    count = 0
    for i in arr:
        if i<=0:
            count += 1
    if count < k:
        print "YES"
    else:
        print "NO"
