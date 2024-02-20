'''
for i in range( int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    if n<3:
        print(-1)
    else:
        flag = 0
        distinct = set(a)
        for i in distinct:
            if a.count(i)>=3:
                print(i)
                flag = 1
                break
        if flag == 0:
            print(-1)
'''

for i in range( int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    a.sort()
    if n<3:
        print(-1)
    else:
        c = 1
        ele = a[0]
        for i in range(1,n):
            if ele == a[i]:
                c+=1
            else:
                ele = a[i]
                c = 1
            if c==3:
                break
            
        if c == 3:
            print(ele)
        else:
            print(-1)
