for i in range( int(input())):
    n = int(input())
    a = [int(i)%2 for i in input().split()] # concerned with even odd

    if a == [1]*n or a == [0]*n:
        print("YES")
    else: # aternating sequecnes allowed
        flag = 0
        for i in range(n-1):
            if a[i]==a[i+1]:
                flag = 1
                break
        if flag == 1:
            print("NO")
        else:
            print("YES")


