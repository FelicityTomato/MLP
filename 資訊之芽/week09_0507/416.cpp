#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

const int mod=1000000007;
ll dp[2005][2005]={0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b,k;
    cin >> n >> a >> b >> k;
    dp[0][a]=1;
    for(int i=0; i<k; i++){
        for(int j=1; j<=n; j++){
            if(j==b) continue;
            int t=abs(b-j);
            if(j<b){
                dp[i+1][max(1, j-t+1)]+=dp[i][j];
                dp[i+1][b]-=dp[i][j];
            }
            else{
                dp[i+1][b+1]+=dp[i][j];
                dp[i+1][min(j+t, n+1)]-=dp[i][j];
            }
            dp[i+1][j]-=dp[i][j];
            dp[i+1][j+1]+=dp[i][j];
        }
        for(int j=1; j<=n; j++){
            dp[i+1][j]+=dp[i+1][j-1];
            dp[i+1][j]%=mod;
        }
    }
    ll cnt=0;
    for(int i=1; i<=n; i++) {
        cnt+=dp[k][i];
        cnt%=mod;
    }
    cout << (cnt+mod)%mod << '\n';
    /*
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++) cout << dp[i][j] << ' ';
        cout << '\n';
    }
    */
    return 0;
}