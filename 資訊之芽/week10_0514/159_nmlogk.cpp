#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int n,m;
vector<int> c,k;
bool dp[1000][20005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        cin >> n >> m;
        c.pb(0); k.pb(0);
        for(int i=1; i<=n; i++){
            int a, b; cin >> a >> b;
            c.pb(a);
            k.pb(b);
        }
        for(int i=1; i<=n; i++){
            int t=1;
            while(k[i]>t){
                //cout << t << '\n';
                c.pb(t*c[i]);
                k[i]-=t;
                t=(t<<1);
            }
            c[i]*=k[i];
        }
        //for(int i=0; i<c.size(); i++) cout << c[i] << ' '; cout << '\n';
        for(int i=0; i<c.size(); i++) for(int j=0; j<=m; j++) dp[i][j]=0;
        for(int i=0; i<c.size(); i++) dp[i][0]=1;
        for(int i=1; i<c.size(); i++){
            for(int j=0; j<=m; j++){
                if(j-c[i]>=0) dp[i][j] |= dp[i-1][j-c[i]];
                dp[i][j]|=dp[i-1][j];
            }
        }
        if(dp[c.size()-1][m]==1) cout << "Yes\n";
        else cout << "No\n";
        //for(int i=0; i<c.size(); i++) for(int j=0; j<=m; j++) cout << dp[i][j] << " \n"[j==m];
        c.clear();
        k.clear();
    }
    return 0;
}