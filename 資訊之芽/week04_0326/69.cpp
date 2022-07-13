#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10005], b[10005], c[10005], t[10005], n, k;

bool can_win(ll day){
    int cnt=0;
    for(int i=0; i<n; i++) t[i]=a[i]+day*b[i];
    sort(t,t+n);
    int i=n-1, j=n-1;
    for(; i>=0 && j>=0; j--){
        if(t[i]>c[j]){
            cnt++;
            i--;
        }
    }
    //cout << cnt << '\n';
    if(cnt>=k) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        cin >> n >> k;
        for(int i=0; i<n; i++) cin >> a[i] >> b[i];
        for(int i=0; i<n; i++) cin >> c[i];
        sort(c,c+n);
        ll l=0,r=1e14;
        if(!can_win(r)){
            cout << -1 << '\n';
            continue;
        }
        while(l<r){
            ll m=l+(r-l)/2;
            //cout << r << '\n';
            if(can_win(m)) r=m;
            else l=m+1;
        }
        cout << l << '\n';
    }
    return 0;
}