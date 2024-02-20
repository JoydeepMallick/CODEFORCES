/*
 
You are given a integer n (n>0). Find any integer s

which satisfies these conditions, or report that there are no such numbers:

In the decimal representation of s

:

    s>0

,
s
consists of n
digits,
no digit in s
equals 0
,
s

    is not divisible by any of it's digits. 

Input

The input consists of multiple test cases. The first line of the input contains a single integer t
(1≤t≤400), the number of test cases. The next t

lines each describe a test case.

Each test case contains one positive integer n
(1≤n≤105

).

It is guaranteed that the sum of n
for all test cases does not exceed 105

.
Output

For each test case, print an integer s
which satisfies the conditions described above, or "-1" (without quotes), if no such number exists. If there are multiple possible solutions for s

, print any solution.
Example
Input
Copy

4
1
2
3
4

Output
Copy

-1
57
239
6789

Note

In the first test case, there are no possible solutions for s

consisting of one digit, because any such solution is divisible by itself.

For the second test case, the possible solutions are: 23
, 27, 29, 34, 37, 38, 43, 46, 47, 49, 53, 54, 56, 57, 58, 59, 67, 68, 69, 73, 74, 76, 78, 79, 83, 86, 87, 89, 94, 97, and 98

.

For the third test case, one possible solution is 239
because 239 is not divisible by 2, 3 or 9

and has three digits (none of which equals zero).



 */







/*
 __________________________
|  Written by silent_Joy  |
   ---------~u~---------  

*/

#include<bits/stdc++.h>
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
#define fori(a, n) for (int i = a; i < n; i++)
#define forj(a, n) for (int j = a; j < n; j++)
#define fork(a, n) for (int k = a; k < n; k++)


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





/*__________________________CONSTANTS FREQUENTLY USED____________________________*/

const int mod = 1000000007;//10^9+7
const ll PI   = 3.141592653589793238462;

/*______________________________________________________________________________*/
void test(){
	//write code here
  ll n;
  cin >> n;
  /*
  Possible solutions :-

  when n = 1 , s always not possible ie -1

  else 
  
  43,443,4443,....
  
  98,998,9998,....
  
  23,233,2333,....
  
  if(n-1)%3 !=0--->73,773,77773,....
  else 733,7777733,....
   */

  if(n==1)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << 2; 
    fori(1,n) cout << 3;
    cout << endl;
  }
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
	int t;
	cin >> t;
	while(t--)
		test();
	return 0;
}

