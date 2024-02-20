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
  int n;cin >> n;
  int a[n];
  /*
   *The problem asks us to make all its elements become 0 in some operations. And for each operation, we subtract each elements in an subarray by 1. Thus, every largest elements of the array have to be decreased in at least M operations. And also because of that, min(f(p)) over all permutations p of a is never less than M.

Every permutations p of a such that f(p)=M have the same construction. That is, they can be divided into 2 subarrays where the left subarray is sorted in non-decreasing order, and the right subarray is sorted in non-increasing order. In other words, the elements of the array should form a mountain.

Process :-  This is how to perform the operations: assign l equal to the index of the leftmost element whose value is not 0, and assign r equal to the index of the rightmost element whose value is also not 0
  - -
 -   - 
0      - 0 0
____________ 8 elements in array at different levels
 l     r -->avoiding 0

then subtract each element al,al+1,…,ar by 1. Repeat the operation until all elements become 0. The thing is each element of the array is always greater or equal than every elements in the left side or the right side of it so it can never become negative at some point of performing the operations. Besides, all the largest elements are also included in each operation that we perform, which mean we've achieved the goal to make all elements of the array become 0 in M operations.

 Well, we can define preLen equal to the length of the longest prefix which is sorted in non-decreasing order. Then define sufLen equal to the length of the longest suffix which is sorted in non-increasing order. If preLen+sufLen≥n

, the answer is YES.

Time complexity: O(n)

NOTE :- DID YOU THINK OF V-SHAPED VALEY???

Its not the optimised way and might require more than m operations as once you get 0s in any part the suffix prefixpart actually is no more connected!!!!hence we need to work on  them seperately needing more than m operations
   */
  fori(0,n) cin >> a[i];
  int preLen = 1;
  //checks till how many elements from start is the array non decreasing
  while(preLen < n && a[preLen-1] <= a[preLen]){
    ++preLen;
    //dbg(preLen)
  }
  //once preLen hits n we can assure all elements have been checked
  int sufLen = 1;
  //checks till how many elements from end is the array non increasing
  while(sufLen < n && a[n - sufLen -1] >= a[n - sufLen]){
    ++sufLen;
    //dbg(sufLen)
  }
  //dbg(preLen,sufLen);
  //it can surely be said a valid mountain must have overlapping peaks
  if(preLen + sufLen > n) yes;
  else no;
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

