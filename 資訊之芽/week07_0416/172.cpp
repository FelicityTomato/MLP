#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[105];
ll dp[105][105][105];

ll f(int i, int x, int y){
    if(i<0) return 0;
    else if(dp[i][x][y]!=0) return dp[i][x][y];
    dp[]
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) for(int k=0; k<n; k++) dp[i][j][k]=0;
        
    }
    return 0;
}