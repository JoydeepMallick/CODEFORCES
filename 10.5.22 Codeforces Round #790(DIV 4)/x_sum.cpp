/*
 *
Timur's grandfather gifted him a chessboard to practice his chess skills. This chessboard is a grid a with n rows and m

columns with each cell having a non-negative integer written on it.

Timur's challenge is to place a bishop on the board such that the sum of all cells attacked by the bishop is maximal. The bishop attacks in all directions diagonally, and there is no limit to the distance which the bishop can attack. Note that the cell on which the bishop is placed is also considered attacked. Help him find the maximal sum he can get.
Input

The first line of the input contains a single integer t
(1≤t≤1000

) — the number of test cases. The description of test cases follows.

The first line of each test case contains the integers n
and m (1≤n≤200, 1≤m≤200

).

The following n
lines contain m integers each, the j-th element of the i-th line aij is the number written in the j-th cell of the i-th row (0≤aij≤106)

It is guaranteed that the sum of n⋅m
over all test cases does not exceed 4⋅104

.
Output

For each test case output a single integer, the maximum sum over all possible placements of the bishop.
Example
Input
Copy

4
4 4
1 2 2 1
2 4 2 4
2 2 3 1
2 4 2 4
2 1
1
0
3 3
1 1 1
1 1 1
1 1 1
3 3
0 1 1
1 0 1
1 1 0

Output
Copy

20
1
5
3

Note

For the first test case here the best sum is achieved by the bishop being in this position:

 
 *
 *
 * solution:-
 Find sum of all possible left and right diagonals and then find all possible intersections and sum them up and then fins the max of sum of intersections .
*/
/*
 __________________________
|  Written by silent_Joy  |
   ---------~u~---------  

*/

#include<bits/stdc++.h>

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

using namespace std;

//some useful functions as macro
#define len(str) str.length();
#define all(a) a.begin(), a.end()
#define allrev(a) a.rbegin(), a.rend()
#define cielDiv(n, k) (n) / (k) + ((n) % (k) > 0) // always upper value considered

//loop constructs shortened using macro defination
#define fori(a, n) for (int i = a; i < n; i++)
#define forj(a, n) for (int j = a; j < n; j++)
#define fork(a, n) for (int k = a; k < n; k++)


void test(){
	//write code here
  int n,m,mx_sum = 0;// mx_sum intialised 0 since its the base case when allelements are 0
  cin >> n >> m;
  int a[n][m],diag_rt[n+m-1],diag_lt[n+m-1];//right diagonals \,left diaginals /
  memset(diag_rt, 0, sizeof(diag_rt));
  memset(diag_lt, 0, sizeof(diag_lt));

  fori(0,n)
  {
    forj(0,m)
    {
      cin >> a[i][j];
      diag_rt[i+j] += a[i][j];//sum of each possible right diagonals 
      diag_lt[n-i-1+j] += a[i][j];//sum of each possible left diagonals
    }
  }
  fori(0,n)
    forj(0,m)
      mx_sum = max(mx_sum, diag_rt[i+j]+diag_lt[n-i-1+j] - a[i][j]);//-a[i][j] since its repeated twice when summing up the diagonals

  cout << mx_sum <<"\n";
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

