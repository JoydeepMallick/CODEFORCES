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
  int n,q;//,j;
  li x;//,sm = 0;
  cin >> n >> q;
  int a[n],sumtillai[n];
  //memset(sumtillai, 0, sizeof(sumtillai)); // all elements set to 0
  
  fori(0,n)
    cin >> a[i];
  sort(a,a+n,greater<int>()); //sort array in descending order
  
  sumtillai[0] = a[0];
  fori(1,n)
    sumtillai[i] = sumtillai[i-1] + a[i];
  //fori(1,n)
  //  a[i]+=a[i-1];
  while(q--)
  {
    cin >> x;
    //using binary search to reduce time
    int mid, l = 1,r = n, ans = -1;//if not found then -1
    while(l<=r)
    {
      mid = (l+r)/2; //integer floor value
      if (sumtillai[mid-1] >= x)
      {
        ans = mid;
        r = mid -1; // if l was 0 r = -1 then error
      }
      else
        l = mid + 1; //2nd half
    }
    cout << ans <<"\n";
    /*
    //greedy approach by prefix sum but slow
    for(j=0;j<n;j++)
    {
      if(sumtillai[j] >= x)
        break;
    }
    //brute force
    sm = 0;  // intialised to 0  for each query
    for(j = 0;j<n;j++)
    {
      sm += a[j];
      if(sm >= x)
        break;
    }
    
    if(j==n) // after i = n-1 if break not works
      cout << "-1\n";
    else
      cout << j+1 << "\n";
      */
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

