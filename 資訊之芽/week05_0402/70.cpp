#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll cnt=0;
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        ll a;
        for(int i=0; i<n; i++){
            cin >> a;
            pq.push(a);
        }
        while(pq.size()>1){
            ll k=pq.top(); pq.pop();
            k+=pq.top(); pq.pop();
            cnt+=k;
            pq.push(k);
        }
        cout << cnt << '\n';
    }
    return 0;
}