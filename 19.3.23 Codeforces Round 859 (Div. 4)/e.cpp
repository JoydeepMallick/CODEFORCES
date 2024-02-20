#include "bits/stdc++.h"
using ll=long long;
using ld=long double;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define sz(a) (int)a.size()
#define CODE_START  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll t,n,a[2000005],pref[2000005];
int32_t main(){
    //CODE_START;
#ifdef LOCAL
    //ifstream cin("input.txt");
#endif
    cin>>t;
    while(t--){
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            pref[i]=pref[i-1]+a[i];
        }
        ll l=1,r=n,ans=0;
        while(l<=r){
            ll mid=l+ (r-l)/2;
            cout<<"? "<<(mid-l+1)<<' ';
            for(ll i=l;i<=mid;i++)
            {
                cout<<i<<' ';
            }
            cout<<endl<<flush;
            ll x=0;
            cin>>x;
            if(x==pref[mid]-pref[l-1]){
                l=mid+1;
            }else {
                r=mid-1;
                ans=mid;
            }
        }
        cout<<"! "<<ans<<endl<<flush;
    }
}
