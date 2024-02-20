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

const int mod = 1000000007;//10^9+7
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

void test(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    /*
Count two arrays big and small, such that big[i] contains the number of occurrences of ith letter of the alphabet in the string in upper case, while small[i]

— in lower case.

Let's add all existing pairs to the answer, so let's add min(small[i],big[i])
to it for each letter. Subtract this minimum from small[i] and big[i]

to get the number of unpaired identical letters.

Next, we will act greedily: if there is some set of at least two identical letters in the same case, we can apply the operation to half of them and get new pairs. Therefore, for each letter we will add min(k,max(small[i],big[i]))2
to the answer and decrease k by that amount.

aAaaBACacbE     small = {a = 4, b = 1,  c = 1 ......}        ..... indicates all other letters as 0
                  big = {A = 2, B = 1,  C = 1,...., E = 1,.....}

                  hence intial answer  = 2 + 1 + 1 + 0 + 0 + .....(min of each) = 4  

                  now k=2 operations allowed 

                  first we reduce our arrays from the the min and then sort out the remaining values 
                  
                  small = {a = 2, b = 0,  c = 0 ......}        ..... indicates all other letters as 0
                  big = {A = 0, B = 0,  C = 0,...., E = 0,.....}

                  if at least the remaining is even and k > 0(we avoid this by taking min of max and k since we use the same loop to calculate the answer without any operations) then only we can convert case and increase our final answer

                  min(k, max(small[a], big[A])/2   )  = min(1,1) = 1 so we add 1 to ans and reduce one from k
                  we perform this for each element if any time max/2 is greater than k it takes the min value.


                  hence final answer = 5 since no other operation was possible.

     */

    array<int, 26> big{}, small{};//empty braces means intialize all default values to 0
    for(char c : s){
      if('A' <= c && c <= 'Z') big[c-'A']++;
      else small[c-'a']++;
    }
dbg(small, big);
    int ans = 0;
    fori(0, 26){
      int paircnt = min(small[i], big[i]);
      ans += paircnt;
      big[i] -= paircnt;
      small[i] -= paircnt;
      int possibleop = min(k, max(small[i], big[i])/2 );
      ans += possibleop;
      k -= possibleop;

    }
    cout << ans << endl;

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


