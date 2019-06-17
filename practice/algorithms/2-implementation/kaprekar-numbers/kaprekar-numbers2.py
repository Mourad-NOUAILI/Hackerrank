def kaprekar(i):
    if i == 1:
        return True
    s = i**2
    s = str(s)
    length = len(s)
    if len(s) <= 1:
        return False
    temp = int(s[0:length/2]) + int(s[length/2:])
    if temp == i:
        return True
    else:
        return False
a = input()
b = input()
l = []
for i in range(a,b+1):
    if kaprekar(i):
        l.append(i)
if not l:
    print "INVALID RANGE"
else:
    print " ".join(map(str,l))

