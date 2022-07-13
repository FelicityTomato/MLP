#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define X first
#define Y second
#define pb push_back

const double eps=1e-12;

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

int sign(ll a){
    if(a==0) return 0;
    return a>0 ? 1 : -1;
}

int ori(const pll &o, const pll &a, const pll &b){
    ll cross=(a-o)^(b-o);
    return sign(cross);
}

bool btw(const pll &a, const pll &b, const pll &o){
    if(ori(a,b,o)!=0) return 0;
    return sign((o-a)*(o-b))<=0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    pll arr[n];
    for(int i=0; i<n; i++) cin >> arr[i].X >> arr[i].Y;
    ll l=0, r=0, b=0;
    for(int i=1; i<n-1; i++){
        int k=ori(arr[i], arr[i+1], arr[i-1]);
        if(k<0) r++;
        else if(k>0) l++;
        else if(btw(arr[i-1], arr[i], arr[i+1]) || btw(arr[i], arr[i+1], arr[i-1])) b++;
    }
    cout << l << ' ' << r << ' ' << b << '\n';
    return 0;
}
