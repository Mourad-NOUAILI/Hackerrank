for _ in range(input()):
    a=input()
    count = 0
    for i in list(str(a)):
        if int(i)!=0 and a%int(i)==0:
            count+=1
    print count
