#include<bits/stdc++.h>
using namespace std;
 
int main(){
int n;
    string s;
    cin >> s;
    n = sizeof(s);
    if (n<7)
        cout<<"NO";
    else{
        int flag = 0,c = 0;
        for(int i = 0; i< (n-1); i++){
            if (s[i] == s[i+1])
                c ++;
            else{
                if (c >= 6){ // 6 adjacent comparisons must turn equal i.e. 7 min adjacent same
                    flag = 1;
                    break;
                }
                else
                    c = 0;
            }
        }
        if (flag == 1)
            cout<<"YES";
        else
            cout<<"NO";
    }
}
 
