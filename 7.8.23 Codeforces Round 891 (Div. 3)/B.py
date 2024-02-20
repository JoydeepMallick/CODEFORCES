import math

'''
#it advisable to type math.log2(n) than below function as a practice
def powerOfTwo(n):
    return math.log2(n)
'''
def isPowerOfTwo(x):#checks if a number is a power of 2
    return (x and not(x & x-1))
'''
    cnt = 0
    while n > 0:
        if n & 1 == 1:
            cnt = cnt + 1
        n = n >> 1
    if cnt == 1 : 
        return 1
    return 0
'''

def sumSquare(n):#checks if a number is sum of squres of 2 natural numbers
    s = []
    for i in range(n):
        if i * i > n:
            break
        s.append(i*i)
        if (n - i * i) in s:
            # print((n - i * i)**(1 / 2),"^2 +", i, "^2")
            return True
    return False

def sieveOfEratosthenes(n):#finds all prime numbers from 2 till n
    primes = [0,0] + [1]*(n-2)
    # 0 and 1 not prime
    p = 2
    while(p**2 <= n):
        if primes[p]:#if true
            for i in range(p**2, n+1, p):#update all multiples of p to 0
                primes[i] = 0;
        p+=1
    return primes

'''
#use inbuilt math functions math.gcd(x,y) and math.lcm(x,y)
def gcd(x, y):
    while(y):
       x, y = y, x % y
    return abs(x)
'''  
if __name__ == '__main__':
    for T in range(int(input())):
        s = input()
        ans = s

        for ind in range(len(s)-1, 0, -1):
            if(int(ans[ind]) < 5):
                continue
            else:
                toadd = int('1' + '0'*(len(s)-ind))
                ans = str(int(s[0:ind] + '0'*(len(s)-ind)) + toadd)


        #handle first index 
        if int(ans[0]) >= 5 :
            ans = '1' + '0'*len(ans);

        print(ans)


