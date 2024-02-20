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
    /*With any positive integer x, there is at least one square number in [x,2x]
   *https://math.stackexchange.com/questions/1190737/proving-that-there-is-a-perfect-square-between-n-and-2n

   Second thread solution is more readable than than the one in tutorial
    */
    int n; cin >> n;
    int a[n];
    int start = 0, toplace = n-1;
    while(pow(start,2) < toplace) start++;
    //get the value of start such that start^2 >= n
    
    /*
     * we try to complete the array in subgroups
     * first fill all places with the values such that value+index=start*start
     * here start squared means the highest sqaure number <= n(fill always
     * starting from higher value to lower value i.e from lowest allowed index
     * to higher up e.g.when you need 9 at indices 4,5 first place a[9-5] = 5 then a[9-4] = 4)
     * when all such combinations are done, we move next smaller squared number
     * chain.
     * e.g. if elements are 6 indices are 0 1 2 3 4 5
     * least highest power greater than equal to 5 is 9 = 3*3
     * first fill all possible 9 combinations - - - - 5 4
     * then fill all possible 4(2*2) combinations - 3 2 1 5 4
     * then fill all possible 1(1*1) combinations - 3 2 1 5 4(no option)
     * then fill all possible 0 combinations 0 3 2 1 5 4
     */
    int wasat = n, nextchainend = n, curindex;
    while(toplace >= 0){//until all elements are placed
        curindex = pow(start,2) - toplace;
        if(curindex >= wasat){
            start--;
            wasat = nextchainend;
            continue;
        }
        a[curindex] = toplace--;
        nextchainend = min(nextchainend, curindex);
    }
    fori(0,n) cout << a[i] << " ";
    cout << endl;

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

