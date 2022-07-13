#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define X first
#define Y second
#define pb push_back

int n;
pll arr[212345];

ll d(pll l, pll r){
    return (r.X-l.X)*(r.X-l.X)+(r.Y-l.Y)*(r.Y-l.Y);
}

ll f(ll l, ll r){
    if(l+1==r){
        if(arr[l].Y>arr[r].Y) swap(arr[l], arr[r]);
        return d(arr[l], arr[r]);
    }
    if(l==r) return 5e18;
    ll m=l+(r-l)/2,k=arr[m].X;
    ll mn=min(f(l,m),f(m+1,r));
    vector<pll> v;
    int j=m+1;
    for(int i=l; i<=m; i++){
        while(j<=r && arr[j].Y<arr[i].Y){
            v.pb(arr[j++]);
        }
        v.pb(arr[i]);
    }
    for(int i=l; i<j; i++) arr[i]=v[i-l];
    //cout << l <<' ' << r << ": ";
    //for(int i=l; i<=r; i++) cout << arr[i].X <<' ' << arr[i].Y << '\n'; cout << '\n';
    v.clear();
    for(int i=l; i<=r; i++) if((arr[i].X-k)*(arr[i].X-k) <=mn) v.pb(arr[i]);
    for(int i=0; i<v.size(); i++){
        for(j=i+1; j<v.size(); j++){
            mn=min(mn, d(v[i], v[j]));
            if((v[j].Y-v[i].Y)*(v[j].Y-v[i].Y)>mn) break;
        }
    }
    return mn;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i].X >> arr[i].Y;
    sort(arr, arr+n);
    cout << f(0, n-1) << '\n';
    return 0;
}