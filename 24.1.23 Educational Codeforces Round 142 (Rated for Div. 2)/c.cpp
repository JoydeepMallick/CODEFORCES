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
	//write code here
    int n;
    cin >> n;
    int p[n+1],indexof[n+1];
/* bool sorted = true; */
    fori(1,n+1){
         cin >> p[i];
         indexof[p[i]] = i;
/* if(p[i] != i) sorted = false; */
    }
/*    int steps = 0;
   if(!sorted || n > 1){
        /*
         odd no of elements 

         1 5 4 2 3
            
         first chose 2 and 4,   2 1 5 3 4
         then chose 1 and 5,    1 2 3 4 5


         for even no of elements

         2 1 4 3

         first chose 2 and 3, but they are alread placed in the required postion

         then chose 1 and 4,      1 2 3 4


steps :-

................................
................................
................................
3rd last move   take 3 and n-2
2nd last move   take 2 and n-1
last move       take 1 and n


now can there be a move when last move sorts out the entire arry ????????????

        
1 3 2 

take 1 and 3,  1 2 3



1 2 4 3   or 2 1 4 3   or   4 2 3 1

take 1 and 4,   1 2 3 4


4 3 2 1

take 3 2,    2 4 1 3
take 1 4,    1 2 3 4


assume n = 10         3  4  5  6  7  8
                    1   9     2    10   

for the above example just 2 moves is enough as rest of array is already sorted...

hence starting from index of the value n/2 we move to its left and right and check if vlue on left is smaller than mid and right is greater than mid.



// my logic below
for each element x check if index of x-1 is before it and x+1 is after it, if not for each increase the ans.

since we are done checking these 3, avoid these and check for others

my logic fails for 2 1 4 3

where in 2 and 1 and  4 and 3 are misplaced by on ooperation can repair both


*/

/*        set<int> checkdone;
        fori(1, n+1){
            int cur_ele = p[i];
            if( checkdone.find(cur_ele) == checkdone.end())
                checkdone.insert(cur_ele);

            if(cur_ele == 1){
                if(indexof[2] > i || checkdone.find(2) != checkdone.end()) continue;
                else steps++;

                checkdone.insert(2);
            }

            else if(cur_ele == n){
                if(indexof[n-1] < i || checkdone.find(n-1) != checkdone.end()) continue;
                else steps++;

                checkdone.insert(n-1);
            }

            else{
                if(indexof[cur_ele + 1] < i && checkdone.find(cur_ele+1) == checkdone.end()){

             steps++;
             checkdone.insert(cur_ele+1);
            }
                if(indexof[cur_ele-1] > i && checkdone.find(cur_ele-1) == checkdone.end()) {
                    steps++;
                    checkdone.insert(cur_ele-1);
                
                }
            }
        }
    }
    cout << steps << endl;
*/


    if(n==1){
        cout << 0 << endl;
        return;
    }
    else{
        int L = (n+1)/2;
        int R = (n+2)/2;
        int ans = (n+1)/2;//worst case
        while(L >= 1 && (L == R || (indexof[L] < indexof[L+1] && indexof[R] > indexof[R-1]))){
            L--;
            R++;
            ans--;
        }
        cout << ans << endl;
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

