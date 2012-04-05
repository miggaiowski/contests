# 2007-08-24 

def fact(n):
    if n==1:
        return 1
    
    return n * fact(n-1)


t = input();
while(t):
    t=t-1
    n = input()
    fat = fact(n)
    print fat
