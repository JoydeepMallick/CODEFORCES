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
int winner(int a,int b){
    int index;
    cout << "? " << a << " " << b << endl;
    //cout.flush();
    cin >> index;
    return (int[]){-1,a,b}[index];//we return a for 1 , b for 2 else -1 as it is
}

void solve(vi &alive){
    if(alive.size() == 1){
        cout << "! " << alive[0] << endl;
        return;
    }
    else if (alive.size() == 2){//base case length wont be less than 2 as n>=1
        int champ = winner(alive[0], alive[1]);
        cout <<"! " << champ << endl;
        return;
    }
 //split into continuous groups of 4 and perform 2 operations to get
//winner from each group of 4 and save these winners for next operation
    vi nextalive;
    for(int i = 0; i < alive.size(); i+=4){
        int a = alive[i];
        int b = alive[i+1];
        int c = alive[i+2];
        int d = alive[i+3];
        //find winner among and a and c and plan accordingly
        int acwinner = winner(a,c);
        //its known who has finally won so if 2 have same winning then both
        //aint winner since winner will always have highest win streaks
        if(acwinner == -1) nextalive.push_back(winner(b,d));
        else if(acwinner == a) nextalive.push_back(winner(a,d));//b c losers
        else if(acwinner == c) nextalive.push_back(winner(b,c));//a d losers
    }
    solve(nextalive);// (1/4) of players still remain to be removed
   
}
void test(){
    /*
    Naive approach would be to query through each and every tournament and find winner of each and then proceed to the next tournament. this will take  2^n - 1 queries 
    BUT
    we are limited to (1/3) * 2 ^(n+1) queries only.

LOGIC :-

suppose :-
player woncount
0       0
1       1
2       0
3       2
if we check 0,2 then we can come to know more.Here since both are same we recieve 0 hence we are sure enough either of them is not a winner. consider another example

0       1   X
1       0 X
2       0 X
3       2
here check 0,2 we get 1 as answer that is 0 has more wins.This implies that 2 is a loser in the game at some point(definitely not the winner)
 now we can also see that even if 2 won against 3(assume) but 0 wins agains 2 implies that 0 must have won against 1 for sure,since its win count is more hence 1 is also not a winner.
 Again we perform same case with 0,3 and find winner
 Hence in 4 players we need 2 queries in order to eliminate 3 elements
 Hence to remove 1 element we need 2/3 of a query
 
 hence to remove 2^n elements we need (2/3) of 2^n queries which is same as (1/3)*2^(n+1) 

NOTE:- only in 1st query we have the freedom to remove 2 elements at once but then players might have 1,2,3,... wins hence predicting wins will become more difficult and we need to proceed further eith one at a time

*/
    int n; cin >> n;
    vi alive;//size 2^n 
    fori(1,(1<<n)+1) alive.push_back(i);
    solve(alive);//we sort out all winners of 1st level and again
                      //recursively do the same task until finally get the answer
}


int main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);

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

