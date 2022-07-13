#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int M[105],V[105];
ll dp[10005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m; 
        cin >> n >> m;
        for(int i=0; i<n; i++) cin >> M[i] >> V[i];
        for(int i=0; i<10005; i++) dp[i]=INT_MAX;
        dp[0]=0;
        for(int i=0; i<n; i++){
            for(int j=10005; j>=0; j--){
                if(j>=V[i] && dp[j-V[i]]+M[i]<=m) dp[j]=min(dp[j], dp[j-V[i]]+M[i]);
                //cout << i << ' ' << j << ' ' << dp[j] << '\n';
            }
        }
        for(int i=10004; i>=0; i--){
            if(dp[i]<=m){
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}