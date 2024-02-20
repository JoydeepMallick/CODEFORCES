/*
   __________________________
   |  Written by silent_Joy  |
   ---------~u~---------  

*/
#include"bits/stdc++.h"
using namespace std;

/*____________________________________MACRO DEFINATIONS_______________________________________*/

#define ul unsigned long int // 0 to 2^32 - 1
#define ll long long // -2^63 to 2^63 - 1
#define ull unsigned long long // 0 to 2^64 - 1
#define ld long double // 12 bytes (12*8 bits)

//vector macro
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vvll vector<vector<long, long> >

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
#define watch(x) cout << #x << " = " << x << endl //simple debugger 

//loop constructs shortened using macro defination
#define fori(a, n) for (ul i = a; i < (ul)n; i++)
#define forj(a, n) for (ul j = a; j < (ul)n; j++)
#define fork(a, n) for (ul k = a; k < (ul)n; k++)
//note in place of decrement please put negative values only
#define foridec(n, a, dec) for (ul i = n; i > (ul)a; i+=dec) 
#define forjdec(n, a, dec) for (ul j = n; j > (ul)a; j+=dec)
#define forkdec(n, a, dec) for (ul k = n; k > (ul)a; k+=dec)

#define yes cout<<"YES\n"
#define no cout<<"NO\n"

/*____________________________________CONSTANTS FREQUENTLY USED____________________________________*/

const int mod = 1000000007;//10^9+7
const ll PI   = 3.141592653589793238462;


/*_______________________________ FUNCTION DEFINATIONS ___________________________________*/


  template <typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
bool isPowerOfTwo(T x)
{    
  return (x != 0) && ((x & (x - 1)) == 0);
}

  template <typename T_all>//string,float,int,.... all types
bool isPalindrome(T_all s)
{
  string new_s;
  new_s = s;
  int n = len(new_s);
  fori(0,n/2)
  {
    if (new_s[i] != new_s[n - i - 1])
      return false;
  }
  return true;
}

#define eni(x) template< class c > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
    template< class c > struct rge { c b, e; };
    template< class c > rge<c> range(c i, c j) { return rge<c>{i, j}; }
    template< class c > auto dud(c* x) -> decltype(cerr << *x, 0);
    template< class c > char dud(...);
    struct debug {

#ifndef ONLINE_JUDGE
      ~debug() { cerr << endl; }
      eni(!=) cerr << boolalpha << i; return * this; 
    }
    eni(==) return * this << range(begin(i), end(i)); 
  }

template < class c, class b > debug & operator <<(pair < b, c > d) {
  return * this << "(" << d.first << ", " << d.second << ")";
}

template < class c > debug & operator <<(rge<c> d) {
  *this << "{";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  return * this << "}";
}
#else
template < class c > debug & operator <<(const c&) { return * this; }
#endif
};


#define dbg(...) "" << #__VA_ARGS__ " = " << (__VA_ARGS__) << "\n"

ll lcm(ll x, ll y){return x*y/std::__gcd(x,y);} // LCM OF TWO NUMBERS


/*_________________________________WRITE YOUR CODE FOR EACH TEST CASE BELOW____________________________________*/

void test(){
  ull n;
  cin >> n;
  //calculate the factors of n;
  //since the ai^pi is simply the multiplication of all factors raised to some powers
  //we here find all prime factors 
  vector<pair<int, int>> all; //vector of prime factors and their powers
  for (int p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      int raisedto = 0;
      while (n % p == 0) {
        raisedto++;
        n /= p;
      }
      all.emplace_back(p, raisedto);
    }
  } 
  if(n>1){
    all.emplace_back(n, 1);//if n is prime itself
  }
/* debug() << dbg(all);//limited to only one operator */
/* debug() << dbg(n); */
  /*
   * assume n = 2*2*2*3*3*3*7*7*17
   * so 2,3   3,3   7,2  17,1
   *
   * hence max summation ai * pi  =  when ai = [2*3*7*17, 2*3*7, 2*3],[1,1,1]
   * hence taking one at a time to maximize the prime factor product and then the powers will be left to 1. 
   *
   * e.g. 2*2*2*3*3*3*7*7 = n let
   *
   * so a = [2*3*7, 2*3*7,2*3] p = [1,1,1] and p can never be more than 1 else it violates distict prime factor product property
   * 
   */
  /*
   * loop again and again through all until its pairs second valu that is power is reduced to 0 for all i.e. use them all 
   *
   * each loop will product all the different factors once provided its power is not 0
   */
  ull s = 0;
  while(true){
    ull prod = 1;
    for(pii& factor : all){// we need to update this in current position hence access their addresses
      if(factor.second > 0){
        prod *= factor.first;
        factor.second--;
      }
    }
    if(prod == 1) break;
    s += prod;
  }

  cout << s << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t = 1;//if test case is 1 only please comment out cin statement below
  cin >> t;
  auto t1 = std::chrono::high_resolution_clock::now();
  while(t--){
#ifndef ONLINE_JUDGE
    cout << "__________________________________________________________" << endl;
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

