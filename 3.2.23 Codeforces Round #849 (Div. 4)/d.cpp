/*
   __________________________
   |  Written by silent_Joy  |
   ---------~u~---------  
   */
#include"bits/stdc++.h"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
using namespace std;

/*______________________MACRO DEFINATIONS______________________*/

#define ll long long // -2^63 to 2^63 - 1
#define ull unsigned long long // 0 to 2^64 - 1
#define ld long double // 12 bytes (12*8 bits)

//vector macro
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vvll vector<vector<long long> >

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

//loop constructs shortened using macro defination
#define fori(a, n) for (ull i = a; i < (ull)n; i++)
#define forj(a, n) for (ull j = a; j < (ull)n; j++)
#define fork(a, n) for (ull k = a; k < (ull)n; k++)

#define yes cout<<"YES\n"
#define no cout<<"NO\n"

/*_________________CONSTANTS FREQUENTLY USED__________________*/

const int mod = 1000000007;//10^9+7
const ull PI   = 3.141592653589793238462;

/*__________________ FUNCTION DEFINATIONS _____________________*/


ull lcm(ull x, ull y){return x*y/std::__gcd(x,y);} // LCM OF TWO NUMBERS using inbuilt function __gcd(x,y)

/*__________________________ DEBUGGER _________________________*/

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _do() {cerr << " \n";}

template <typename T, typename... V>
void _do(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _do(v...);}

#ifndef ONLINE_JUDGE
#define dbg(...) cerr <<"JOY_DBG active :- " <<  #__VA_ARGS__ << " = "; _do(__VA_ARGS__);
#else
#define dbg(...)
#endif

/*_________________________________WRITE YOUR CODE FOR EACH TEST CASE BELOW____________________________________*/


void test(){
    int n;
    string s;
    cin >> n >> s;
    //use std::array over normal array since its is defined over a fixed size as array but when passed as a pointer to a function it retains its size identity 
    //this is declared under <array> header file.
    array<int, 26> cntl{}, cntr{};//giving a bracket intializes all elements to 0 
/* dbg(cntl); */
    int res = 0;
    for(auto c : s){
        /*
         * below not logical operator has a very interesting application
         *
         * it basically helps in counting all distinct no. of elements in s 
         * whenever a new element is found its intial value at array will be 0 hence !0 = 1 added to res.
         *
         * now value at array gets updated since its post increment
         *
         * next time the same value is encontered we know that its value is >= 1 hence not operation will always give a 0 hence not counted again in result
         */
        res += !cntr[c-'a']++;
/* dbg(!cntr[c-'a']); */
    }
    int ans = res;//this is assumed to be result when a='' and b = s 
    for(auto c : s){
        /*
         * cntl -> left part of s i.e. a which increases in size till a = s 
         * cntr ->b i.e. right side of s that reduces in size till b =''
         *
         * here we go on adding one element to a and reduce it from b and at the same time increase our result only if the element entered in a is new i.e. cntl[ele] = 0 ,
         * and decrease our result if after deleting the element in b that got into a our new b is void of that specific element .i.e. cntr[ele] = 0.
         */
        res += !cntl[c-'a']++;//add one element to left part i.e. a
        res -= !--cntr[c-'a']; // remove one element beforehand calculating the result
/* dbg(cntl, cntr); */
        ans = max(ans, res);
    }

    cout << ans << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;//if test case is 1 only please comment out cin statement below
    cin >> t;
    auto t1 = std::chrono::high_resolution_clock::now();
    int temp = t;
    while(t--){
#ifndef ONLINE_JUDGE
        cout << "\n________________________ TEST CASE #" << temp-t << " ________________________\n" << endl;
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


