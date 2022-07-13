#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define X first
#define Y second
#define pb push_back

pll operator+(const pll &p1, const pll &p2){
    return pll(p1.X+p2.X, p1.Y+p2.Y);
}
pll operator-(const pll &p1, const pll &p2){
    return pll(p1.X-p2.X, p1.Y-p2.Y);
}
ll operator*(const pll &p1, const pll &p2){
    return p1.X*p2.X+p1.Y*p2.Y;
}
ll operator^(const pll &p1, const pll &p2){
    return p1.X*p2.Y-p1.Y*p2.X;
}

map<ll,ll> mp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    pll arr[n];
    for(int i=0; i<n; i++) cin >> arr[i].X >> arr[i].Y;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ll k=(arr[i]-arr[j])*(arr[i]-arr[j]);
            if(mp.find(k)==mp.end()) mp.insert({k,1});
            else mp.find(k)->Y++;
        }
    }
    ll cnt=0;
    for(auto k:mp){
        if(k.Y>=2) cnt+=k.Y*(k.Y-1)/2;
    }
    cout << cnt << '\n';
    return 0;
}
