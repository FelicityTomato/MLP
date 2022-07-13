#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int W[105],V[105];
ll dp[1005][105];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m,k; 
        cin >> n >> m >> k;
        for(int i=0; i<n; i++) cin >> W[i] >> V[i];
        for(int i=0; i<=m; i++) for(int j=0; j<=k; j++) dp[i][j]=0;
        for(int i=0; i<n; i++){
            for(int j=m; j>=0; j--){
                for(int l=k; l>0; l--){
                    if(j>=W[i]) dp[j][l]=max(dp[j][l],dp[j-W[i]][l-1]+V[i]);
                }
            }
        }
        ll mx=0;
        for(int i=0; i<=m; i++) for(int j=0; j<=k; j++) mx=max(mx, dp[i][j]);
        cout << mx << '\n';
    }
    return 0;
}