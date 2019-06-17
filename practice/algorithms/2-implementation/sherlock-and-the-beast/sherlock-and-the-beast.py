Testcase = input()

for _ in range(Testcase):
    n = input()
    c = 5*(2*n%3)
    if c > n:
        print -1
    else:
        print '5' * (n-c) + '3'*c
