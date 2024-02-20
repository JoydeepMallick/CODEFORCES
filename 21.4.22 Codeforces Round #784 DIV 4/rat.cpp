#include<bits/stdc++.h>
using namespace std;
int main()
{
  long int t,rat;
  int div = 0;
  cin >> t;
  while(t--)
  {
    cin >> rat;
    if (rat >= 1900)
      div = 1;
    else if (rat>=1600 && rat<=1899)
      div = 2;
    else if (rat>=1400 && rat<=1599)
      div = 3;
    else if (rat<=1399)
      div = 4;
    cout<<"Division "<<div<<"\n"; 
  }
}
