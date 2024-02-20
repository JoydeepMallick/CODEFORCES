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

template<typename T> void _do(T x){cerr << x << "\n";}
template<typename T, typename ...U> void _do(T x, U ...y){cerr << x << ", "; _do(y...);}
#define dbg(...) cerr << #__VA_ARGS__ << " = "; _do(__VA_ARGS__);

 // use the inbuilt function of C++ std::__gcd(x,y) (2 underscores)

ll lcm(ll x, ll y){return x*y/std::__gcd(x,y);} // LCM OF TWO NUMBERS


/*_________________________________WRITE YOUR CODE FOR EACH TEST CASE BELOW____________________________________*/

void test(){
    int n,m,k;
    cin >> n >> m >> k;
    int a[m];
    fori(0,m){
      cin >> a[i];
    }
/* i-th color must be used exactly ai times, and for every k consecutive cells, their colors have to be distincta. 
 
   we can conclude that after k cells repeatition of same pattern is possible
   if k = 5
   A B C D E A B C.......
   hence ABCDE, BCDEA, CDEAB,........distinct 5 consequitive cells
   we actually need atleast 5 different colors to satisfy criteria
 */
    //given k<=n
 
  if(m == k){
    //no. of times pattern of k terms needs to repeat completely
    int comp_repeat = n/k;//this is min value for each element in a
  /* how many leftover colors if any for a incomplete k pattern at last */
    int incomplete = n%k;//this is the no of elements in array a that must have
                       //value at least comp_repeat + 1
    int incomplete_count = 0;
    for(int val : a){
      if(val < comp_repeat){
        no;
        return;
      }
      else if(val >= comp_repeat+1) incomplete_count++;
    }
    if(incomplete_count >= incomplete) yes;
    else no;
  }

  if(m > k){
    //no. of times pattern of k terms needs to repeat completely
    int comp_repeat = n/k;//this is min value for each element in a
  /* how many leftover colors if any for a incomplete k pattern at last */
    int incomplete = n%k;//this is the no of elements in array a that must have
                       //value at least comp_repeat + 1
    int incomplete_count = 0,compensation = 0;
    set<int> compensation_set;
    fori(0,m){
      if(a[i] < comp_repeat){
        compensation = comp_repeat - a[i];//an extra color needed with amount = compensation
        compensation_set.insert(0);
        a[i] = 0;
      }
      else {
        a[i] = comp_repeat - a[i];
      }
      if(a[i]) incomplete_count++;
    }
    
    fori(0,m){

    }

  }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int t = 1;//if test case is 1 only please comment out cin statement below
	cin >> t;
    auto t1 = std::chrono::high_resolution_clock::now();
        while(t--)
            test();
    auto t2 = std::chrono::high_resolution_clock::now();

#ifndef ONLINE_JUDGE
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    cout << ms_double.count() << "ms\n";
#endif
	return 0;
}

