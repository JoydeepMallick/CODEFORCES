/*
 __________________________
|  Written by silent_Joy  |
   ---------~u~---------  

*/

//#include<bits/stdc++.h>
#include"bits/stdc++.h"
using namespace std;

/*____________________________________MACRO DEFINATIONS_______________________________________*/

/*
 side note : - 

 For a macro to "return a value", the macro itself has to be an expression. Your macro is a statement block, which cannot evaluate to an expression.You really ought to write an inline function. It will be just as fast and far more maintainable.

SOURCE :- https://stackoverflow.com/questions/2679182/have-macro-return-a-value
*/

//int can be mentioned with long or skipped as you wish

#define si short int // -2^15 to 2^15 - 1
#define usi unsigned short int // 0 to 2^16 - 1
#define ui unsigned int // 0 to 2^32 - 1
#define li long int // -2^31 to 2^31 - 1
#define ul unsigned long int // 0 to 2^32 - 1
#define ll long long // -2^63 to 2^63 - 1
#define ull unsigned long long // 0 to 2^64 - 1
#define ld long double // 12 bytes (12*8 bits)
#define us unsigned char // 0 to 2^8 - 1

//vector macro
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#define vvi vector<vector<int> >
#define vvll vector<vector<long, long> >
#define vvcc vector<vector<char, char> >

//map macro
#define mii map<int, int>
#define mis map<int, string>
#define mss map<string, string>
#define msi map<string, int>
#define mci map<char, int>
#define mcc map<char, char>

//pair macro
#define pii pair<int, int>
#define pis pair<int, string>
#define pss pair<string, string>

/*____________Please go through the links to know why typedef is preferred for pointer declaration______________*/
typedef char* ptr;
/*
https://www.geeksforgeeks.org/typedef-versus-define-c/#:~:text=Difference%20between%20typedef%20and%20%23define,%2C%203.14%20as%20PI%2C%20etc.

https://stackoverflow.com/questions/1666353/are-typedef-and-define-the-same-in-c#:~:text=Most%20of%20the%20answers%20indicate,be%20more%20advantageous%20than%20%23define%20.
_________________________________________________________________________________________________________________*/

//some useful functions as macro
#define len(str) str.length();
#define all(a) a.begin(), a.end() //used as parameter to sort a vector in ascending order
//#define allrev(a) a.begin(), a.end(), greater<int>() //used as parameter to sort a vector in descending order(note: do change int as and when required)
/*sorting a array is rather easy hence skipped in macro i.e. sort(arr, arr+ n) where n denotes number of elements of the array*/
#define allrev(a) a.rbegin(), a.rend()
#define cielDiv(n, k) (n) / (k) + ((n) % (k) > 0) // always upper value considered
#define noOfElements(arr) sizeof(arr)/sizeof(arr[0]) // seldom used

#define endl "\n"; //avoid flushing of output buffer everytime engl is called
#define watch(x) cout << #x << " = " << x << endl //simple debugger 

//loop constructs shortened using macro defination
#define fori(a, n) for (ul i = a; i < (ul)n; i++)
#define forj(a, n) for (ul j = a; j < (ul)n; j++)
#define fork(a, n) for (ul k = a; k < (ul)n; k++)

/*____________________________________CONSTANTS FREQUENTLY USED____________________________________*/

const int mod = 1000000007;//10^9+7
const ll PI   = 3.141592653589793238462;


/*_______________________________TEMPLATIZED FUNCTION DEFINATIONS___________________________________*/


template <typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
bool isPowerOfTwo(T x)
{
    /*either add the below code to throw error of Integral required else above
     * condition in typename works fine*/

    //static_assert(std::is_integral<T>::value, "Integral required.");
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


/*____________________________________FUNCTION DEFINATIONS_________________________________________*/

//some useful functions for competitve programming to save time

/*
 side note : -

if you are using a loop or an if, you can do it without curly braces if there is only a single statement in it
BUT
it doesn't work for functions

REASON : -
C++ needs it to disambiguate some constructs:

void Foo::bar() const int i = 5;

Now does the const belong to bar or i ?

SOURCE : https://stackoverflow.com/questions/25846938/why-cant-you-create-a-1-statement-function-without-curly-braces
*/

ll gcd(ll x, ll y){return (!y) ? x : gcd(y, x%y);} // GCD OF TWO NUMBERS
// note check for gcd(2,3) it automatically becomes gcd(3,2) then
// no need to check if x>y or so, hence cool😁😁😁

ll lcm(ll x, ll y){return x*y/gcd(x,y);} // LCM OF TWO NUMBERS

/*---------------modular arithmetic functions------------------*/
/*
// Power under mod (a ^ b) % mod
int modpow(int a, int b, int m = mod)
{
    a = a & m;
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % m;
        }
        b = b >> 1;
        a = (a * a) % m;
    }
    return ans;
}

// Inverse Mod (1 / a) % mod
int modinv(int a, int m = mod)
{
    return modpow(a, m - 2);
}

// Modular Arithmetic
int modadd(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}

int modsub(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

int modmul(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}

int moddiv(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (modmul(a, modinv(b, m), m) + m) % m;
}
*/
/*_________________________________WRITE YOUR CODE FOR EACH TEST CASE BELOW____________________________________*/

void test(){
	//write code here
  int n;
  cin >> n;
  int x[n];
  fori(0,n)
  {
    cin >> x[i];
  }
  /*
   *Explanation

   Think of how many times your money is multiplied by 2 when you encounter a positive
   and how many times your money is halved when encounter a negative.

   when storing mutiplying factor here it preferred to store power of 2 rather than the entire factor itself since 2^100 or 2^-100 can be very long and difficult to store eleading to precision errors in calculation

Solution :-

* Brute force for which number to pick
*
* then try to know when was the prefix sum the least
*
* e.g.      8  8  8  9  9  6  6  9  6  6
*        0 -1 -2 -3 -4 -5 -4 -3 -4 -3 -2
* whenever we find a siz we increase the sum  by 1 else we decrese it by 1

*we can get the power of 2 for 6 by simply subtrating -2 from -5(before the first index of 6)

Note :-

above brute force method for prefix sum cant be done directly since then we need to store such array for each and every elements ie. an array of n elements where each elemet is an array of n+1 elemwnts --NOT FEASIBLE--

Above concept can be acomplished via HashMap of TreeSet in Java and map of sets in C++
   */
  map<int, set<int>> gMap;//stores index of each unique element repeatition
  fori(0,n)
  {
    //if(gMap.find(x[i]) != gMap.end())//key not found then insert key
    gMap[x[i]].insert(i);
  }
/*
  for (auto it = gMap.begin(); it != gMap.end(); it++) 
  {
        // Key is integer
        cout << it->first << " => ";
        // Value is a set of indices 
        set<int> st = it->second;
        // printed in sorted order as set
        for (auto _it = st.begin(); _it != st.end(); _it++) 
        {
            cout << (*_it) << ' ';
        }
        cout << '\n';
    }
*/
  int ans = 1;//stores the number of times it multiplies by two, on first correct guess it will surely be multiplied by two hence intial value is 1 
  int ansl = 0, ansr = 1,ansval = x[0];
  for(auto it = gMap.begin(); it != gMap.end(); it++)
  {
    set<int> st = it->second;//stores the set for the current key og gMap 
    //int val = x[*(st.begin())];//stores element of x[ first value of each set everytime]
    int val = (it->first);//same as above stores the key

    int minL = 0, minSum = 0;//calculate worst sum ever was and we will subtract it
    int curL = 0, curSum =0;//current value of sum
    
    //for(auto _it = st.begin(); _it != st.end(); _it++)
    for(int i : st)
    {//we are prcessing all negatives at once 
      //int i = (*_it);//current value at set
      curSum -= i - curL;
      curL = i;//current value in set
      if (minSum > curSum)
      {
        minSum = curSum;
        minL = curL;
      }
    //assuming current key as the answer
      curSum++;
      curL = i+1;

    //we will take the (current value of sum - worst value of sum before that) 
     if(curSum - minSum > ans)
     {
       ans = curSum - minSum;
       ansl = minL;
       ansr = curL;
       ansval = val;
     }
    }
  }
  cout << ansval << " " << (ansl+1) << " " << (ansr) << endl;
}


int main(){
  //disables synchronization between C and C++ standard streams
  //prevents mixing of C and C++ code ensuring better performance
  ios_base::sync_with_stdio(false);
  
  //use only when you dont need immediate flushing(avoid in interactive problems)
  cin.tie(NULL);
/*
 cin.tie(0)->sync_with_stdio(0);
 */
	int t = 1;//if test case is 1 only please comment out cin statement below
	cin >> t;
	while(t--)
		test();
//old c++11 way to calculate execution time,less accurate😌
/*
 * for more efficient ways visit
 * https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c
*/
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed: " << (1000.0 * clock()) / CLOCKS_PER_SEC << " ms \n";
#endif

	return 0;
}

