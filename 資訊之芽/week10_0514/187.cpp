#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int n;
ll dis[20][20], dp[20][(1<<16)+5];
int p[(1<<16)];

bool cmp(int a, int b){
    if(__builtin_popcount(a)<__builtin_popcount(b)) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<(1<<16); i++) p[i]=i;
    stable_sort(p,p+(1<<16), cmp);
    int T; cin >> T;
    while(T--){
        cin >> n;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                cin >> dis[i][j];
                dis[j][i]=dis[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<(1<<n); j++){
                dp[i][j]=INT_MAX;
            }
        }
        dp[0][1]=0;
        for(int j=1; j<(1<<16); j++){
            if(p[j]>=(1<<n)) continue;
            for(int i=0; i<n; i++){
                if((p[j]&(1<<i))==0) continue;
                //cout << i << ' ' << p[j] << '\n';
                for(int k=0; k<n; k++){
                    if(i!=k && (p[j]&(1<<k))!=0){
                        //cout << i << ' ' << p[j] << '\n';
                        //cout << i << ' ' << p[j] << ' ' << k <<' '<< p[j]-(1<<i) << ' '<< dp[k][p[j]-(1<<i)] << ' '<< dis[k][i]<< endl;
                        dp[i][p[j]]=min(dp[i][p[j]], dp[k][p[j]-(1<<i)]+dis[k][i]);
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            dp[0][(1<<n)-1]=min(dp[0][(1<<n)-1], dp[i][(1<<n)-1]+dis[i][0]);
        }
        cout << dp[0][(1<<n)-1] << endl;
        /*
        for(int i=0; i<n; i++){
            for(int j=0; j<(1<< n); j++) cout << dp[i][j] << ' ';
            cout << '\n';
        }
        */
    }
    return 0;
}