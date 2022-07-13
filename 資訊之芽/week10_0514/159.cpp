#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int n,m;
int c[105], k[105];
bool dp[105][20005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i=1; i<=n; i++) cin >> c[i] >> k[i];
        for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) dp[i][j]=0;
        for(int i=0; i<=n; i++) dp[i][0]=1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=m; j++){
                for(int w=0; w<=k[i]; w++){
                    if(w>m) break;
                    if(j-c[i]*w>=0 && dp[i-1][j-c[i]*w]){
                        dp[i][j]=1;
                        break;
                    }
                }
            }
        }
        if(dp[n][m]==1) cout << "Yes\n";
        else cout << "No\n";
        //for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) cout << dp[i][j] << " \n"[j==m];
    }
    return 0;
}