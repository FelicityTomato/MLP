#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1000007;
ll dp[100005][3][3]={0}; // n, start , your

ll f(int n, int s, int y){
    if(n<1) return 0;
    if(dp[n][s][y]!=0) return dp[n][s][y];
    if(y==0) dp[n][s][0]=(f(n-1,s,0)+f(n-1,s,1)+f(n-1,s,2))%mod;
    if(y==1) dp[n][s][1]=(f(n-1,s,0)+f(n-1,s,1))%mod;
    if(y==2) dp[n][s][2]=(f(n-1,s,0)+f(n-1,s,2))%mod;
    return dp[n][s][y];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp[1][0][0]=dp[1][1][1]=dp[1][2][2]=1;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll sum=f(n, 0, 0)+f(n, 0, 1)+f(n, 0, 2)+f(n, 1, 0)+f(n, 1, 1)+f(n, 2, 0)+f(n, 2, 2);
        cout << sum%mod << '\n';
    }
}