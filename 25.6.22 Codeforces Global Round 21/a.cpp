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
/* note check for gcd(2,3) it automatically becomes gcd(3,2) then no need to check if x>y or so, hence cool😁😁😁(Euclid's GCD)
 *
 * you may use the inbuilt function of C++ __gcd(x,y) (2 underscores) also*/

ll lcm(ll x, ll y){return x*y/__gcd(x,y);} // LCM OF TWO NUMBERS

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
  auto t1 = std::chrono::high_resolution_clock::now();
	while(t--)
		test();
  auto t2 = std::chrono::high_resolution_clock::now();
/*
 * for more efficient ways for calculating execution time visit
 * https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c
*/
#ifndef ONLINE_JUDGE
  std::chrono::duration<double, std::milli> ms_double = t2 - t1;
  cout << ms_double.count() << "ms\n";
#endif

	return 0;
}

