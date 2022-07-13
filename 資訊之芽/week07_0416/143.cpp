#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; 
int arr[105];
ll dp[105][105];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1; i<=n; i++) cin >> arr[i];
        for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) dp[i][j]=INT_MAX;
        for(int i=2; i<=n; i++) arr[i]+=arr[i-1];
        for(int i=1; i<=n; i++) dp[i][i]=0;
        for(int j=1; j<n; j++){
            for(int i=1; i+j<=n; i++){
                //dp[i][i+j]=dp[i+1][i+j]+dp[i][i+j-1]-dp[i+1][i+j-1];
                for(int x=i; x<i+j; x++){
                    dp[i][i+j]=min(dp[i][i+j], dp[i][x]+dp[x+1][i+j]);
                }
                dp[i][i+j]+=arr[i+j]-arr[i-1];
            }
        }
        /*
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++) cout << dp[i][j] << ' ';
            cout << '\n';
        }
        */
        cout << dp[1][n] << '\n';
    }
    return 0;
}