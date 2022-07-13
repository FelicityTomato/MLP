#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int n,k,c;
ll val[100005], dp[100005], t[100005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        cin >> n >> k >> c;
        for(int i=0; i<n; i++) cin >> val[i];
        for(int i=0; i<n; i++) dp[i]=0;
        dp[0]=val[0];
        t[0]=dp[0];
        deque<int> q;
        q.push_back(0);
        for(int i=1; i<n; i++){
            while(q.size() && q.front()<i-k) q.pop_front();
            dp[i]=val[i]+max((ll)0,-c*i+t[q.front()]);
            t[i]=dp[i]+c*i;
            while(q.size() && t[q.back()]<=t[i]) q.pop_back();
            q.push_back(i);
        }
        ll mx=0;
        for(int i=0; i<n; i++) mx=max(mx, dp[i]);
        cout << mx << '\n';
    }
    return 0;
}