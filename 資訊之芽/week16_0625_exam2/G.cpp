#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define X first
#define Y second
#define pb push_back

const double eps=1e-12;
int n;
vector<pll> v;

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
    if(fabs(a)<eps) return 0;
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
    int n;
    for(int i=0; i<n; i++) cin >> v[i].X >> v[i].Y;
    return 0;
}
