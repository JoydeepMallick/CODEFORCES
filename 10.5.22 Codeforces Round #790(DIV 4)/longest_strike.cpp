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

//some useful functions as macro
#define len(str) str.length();
#define all(a) a.begin(), a.end() //used as parameter to sort a vector in ascending order
//#define allrev(a) a.begin(), a.end(), greater<int>() //used as parameter to sort a vector in descending order(note: do change int as and when required)
/*sorting a array is rather easy hence skipped in macro i.e. sort(arr, arr+ n) where n denotes number of elements of the array*/
#define allrev(a) a.rbegin(), a.rend()
#define cielDiv(n, k) (n) / (k) + ((n) % (k) > 0) // always upper value considered
#define noOfElements(arr) sizeof(arr)/sizeof(arr[0]) // seldom used

#define endl "\n"; //avoid flushing of output buffer everytime endl is called
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





/*______________________________________________________________________________*/
void test(){
	//write code here0
  int n,k;
  cin >> n >> k;
  vi v(n);
  fori(0,n) cin >> v[i];
  sort(all(v));
  bool ok = 0;
  int ans = 0,l = 0,r = 0, x = 0, freq = 0;
  int i = 0;// i has been declared global to void test so that it  can be used even outside body of the loop
  for(; i < n; i++)
  {
    if(i == 0)
      freq++;
    else
    {
      if(v[i] == v[i-1])
        freq++;
      else
      {
        if(v[i] - v[i-1] > 1 || freq < k)
          l = i;
        freq = 1;
      }

      if(freq >= k)
      {
        ok = 1;
        if(ans <= v[i]-v[l])
        {
          ans = v[i] - v[l];
          x = v[l], r = v[i];
        }
      }
    }
  }
  
  if(freq >= k && ans <= v[i-1] - v[l])
  {
    ok = 1;
    x = v[l], r = v[i-1];
  }
  
  /*
   use curly brackets in if else to avoid ambiguity 

SOURCE :- https://stackoverflow.com/questions/2125066/is-it-a-bad-practice-to-use-an-if-statement-without-curly-braces
   */
  if(ok)
  {
    cout << x << " " << r << endl;
  }
  else
  {
    cout << "-1\n";
  }
}

int main(){
  //disables synchronization between C and C++ standard streams
  //prevents mixing of C and C++ code ensuring better performance
  ios_base::sync_with_stdio(false);
  
  //use only when you dont need immediate flushing(avoid in interactive problems)
  cin.tie(NULL);

	int t;
	cin >> t;
	while(t--)
		test();
	return 0;
}

