#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int n,m;
int c[105], k[105];
bool dp[2][20005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i=1; i<=n; i++) cin >> c[i] >> k[i];
        for(int i=0; i<2; i++) for(int j=0; j<=m; j++) dp[i][j]=0;
        dp[0][0]=dp[1][0]=1;
        queue<int> q[105][205];
        q[1][0].push(0);
        for(int i=1; i<=n; i++){
            for(int j=0; j<=m; j++){
                int t=j%c[i];
                while(q[i][t].size() && q[i][t].front()<j-c[i]*k[i]) q[i][t].pop();
                if(dp[(i+1)%2][j] || (q[i][t].size() && q[i][t].front()<=j)){
                    dp[i%2][j]=1;
                    if(i!=n) q[i+1][j%c[i+1]].push(j);
                }
            }
        }
        if(dp[0][m] || dp[1][m]) cout << "Yes\n";
        else cout << "No\n";
        //for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) cout << dp[i][j] << " \n"[j==m];
    }
    return 0;
}