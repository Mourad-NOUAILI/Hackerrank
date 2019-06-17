def fact(n):
    if n<2:
        return 1
    else:
        return n*fact(n-1)
 
n = input()
print fact(n) 
