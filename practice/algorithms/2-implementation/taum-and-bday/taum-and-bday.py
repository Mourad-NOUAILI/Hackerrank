for _ in range(input()):
    e,o = map(int,raw_input().split())
    x,y,z = map(int,raw_input().split())
    print min(e*x + o*y,x*(e+o) + o*z,y*(e+o) + e*z)
