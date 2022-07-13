#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[112345];
ll dp[112345];

ll f(int i){
    if(i<0) return 0;
    if(dp[i]!=0) return dp[i];
    dp[i]=max(f(i-2), f(i-3))+arr[i];
    return dp[i];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++) dp[i]=0;
        cout << max(f(n-1), f(n-2)) << '\n';
    }
}