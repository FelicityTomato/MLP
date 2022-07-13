#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[112345];
ll dp[112345];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++) dp[i]=0;
        for(int i=0; i<k; i++) dp[i]=arr[i];
        ll mx=0;
        for(int i=k; i<n; i++){
            mx=max(mx, dp[i-k]);
            dp[i]=mx+arr[i];
        }
        for(int i=0; i<n; i++) mx=max(mx, dp[i]);
        cout << mx << '\n';
    }
    return 0;
}