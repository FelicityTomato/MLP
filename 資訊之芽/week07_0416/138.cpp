#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[512345]={0};

int main(){
    ll p=3;
    dp[2]=3;
    for(int i=4; i<=100005; i+=2){
        dp[i]=(dp[i-2]+2*p+2)%1000007;
        p+=dp[i];
        p%=1000007;
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}