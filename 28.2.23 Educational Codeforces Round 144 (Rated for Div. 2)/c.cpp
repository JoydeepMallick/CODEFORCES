/*
   __________________________
   |  Written by silent_Joy  |
   ---------~u~---------  
   */
#include"bits/stdc++.h"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") //intel pentium porcessors released post 2020 support avx2, unfortunately my Pentium 2020M doesn't 
using namespace std;

/*______________________MACRO DEFINATIONS______________________*/

#define ll long long // -2^63 to 2^63 - 1
#define ull unsigned long long // 0 to 2^64 - 1
#define ld long double // 12 bytes (12*8 bits)

//vector macro
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vvll vector<vector<long long> >

//map macro
#define mii map<int, int>
#define mis map<int, string>
#define mss map<string, string>
#define msi map<string, int>

//pair macro
#define pii pair<int, int>
#define pis pair<int, string>
#define pss pair<string, string>

//priority queue
#define mxheap priority_queue<ll>
#define mnheap priority_queue<ll,vector<ll>,greater<ll>>

typedef char* ptr;

//some useful functions as macro
#define len(str) str.length();
#define all(a) a.begin(), a.end() 
#define allrev(a) a.rbegin(), a.rend()
#define endl "\n"

//loop constructs shortened using macro defination
#define fori(a, n) for (ull i = a; i < (ull)n; i++)
#define forj(a, n) for (ull j = a; j < (ull)n; j++)
#define fork(a, n) for (ull k = a; k < (ull)n; k++)

#define yes cout<<"YES\n"
#define no cout<<"NO\n"

/*_________________CONSTANTS FREQUENTLY USED__________________*/

const int mod = 998244353;
const ull PI   = 3.141592653589793238462;

/*__________________ FUNCTION DEFINATIONS _____________________*/


ull lcm(ull x, ull y){return x*y/std::__gcd(x,y);} // LCM OF TWO NUMBERS using inbuilt function __gcd(x,y)

/*__________________________ DEBUGGER _________________________*/

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _do() {cerr << " \n";}

template <typename T, typename... V>
void _do(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _do(v...);}

#ifndef ONLINE_JUDGE
#define dbg(...) cerr <<"JOY_DBG active :- " <<  #__VA_ARGS__ << " = "; _do(__VA_ARGS__);
#else
#define dbg(...)//arrays can't be debugged with this, use std::array instead
#endif

/*_________________________________WRITE YOUR CODE FOR EACH TEST CASE BELOW____________________________________*/

unsigned long long power(unsigned long long x, int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0) {
 
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2, p);
}
unsigned long long mul(unsigned long long x,unsigned long long y, int p)
{
    return x * 1ull * y % p;
}
unsigned long long divide(unsigned long long x,unsigned long long y, int p)
{
    return mul(x, modInverse(y, p), p);
}
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
    // if n-r is less calculate nCn-r
    if (n - r < r)
        return nCrModPFermat(n, n - r, p);
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long res = 1;
    // keep multipling numarator terms and deviding denominator terms in res
    for (int i = r; i >= 1; i--)
        res = divide(mul(res, n - i + 1, p), i, p);
    return res;
}


void test(){
    ull l,r;
    cin >> l >> r;
    /*
     *  beatiful set of any number is like {x, 2x, 2*2x,2*2*2x ,...........}  as much as permitted hence x to get maximum length of such a set will always be x = l or then we can check if l+1, l+2 have a similar size
     *
     *  but its sure that x= l will have max set size.
     *  if {x,2x,2*2x,.....} satisfy then {x,2*2x, 2*2*2x,.......} can also satisy.
     */
    ull maxpowof2 = log2(r/l);
    ull maxsetsize = maxpowof2 + 1; //account for l * 2^0
    ull cnt = 0;
    fori(l, r+1){
        if(i*pow(2,maxpowof2) <= r) {
            //check for greater multiples if present in range which may satisfy condition
            ull j = maxpowof2+1;
            while(i*pow(2, j) <= r) j++;
            cnt += nCrModPFermat(j, maxpowof2, mod)%mod; // j C maxpowof2 combinations possible
        }
        else break;
    }
    cout << maxsetsize << " " << cnt << endl;

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t = 1;//if test case is 1 only please comment out cin statement below
  cin >> t;
  auto t1 = std::chrono::high_resolution_clock::now();
  int temp = t;
  while(t--){
#ifndef ONLINE_JUDGE
    cout << "________________________ TEST CASE #" << temp-t << " ________________________" << endl;
#endif
    test();
  }
  auto t2 = std::chrono::high_resolution_clock::now();

#ifndef ONLINE_JUDGE
  std::chrono::duration<double, std::milli> ms_double = t2 - t1;
  cout << ms_double.count() << "ms\n";
#endif
  return 0;
}


