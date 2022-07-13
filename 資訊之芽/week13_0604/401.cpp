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

bool banana(const pll &p1, const pll &p2, const pll &p3, const pll &p4){
    ll a123=ori(p1,p2,p3);
    ll a124=ori(p1,p2,p4);
    ll a341=ori(p3,p4,p1);
    ll a342=ori(p3,p4,p2);
    if(a123==0 && a124==0){
        return btw(p1,p2,p3) || btw(p1,p2,p4) || btw(p3,p4,p1) || btw(p3,p4,p2);
    }
    return a123*a124<=0 && a341*a342<=0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        pll a,b,c,d;
        cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y >> d.X >> d.Y;
        if(banana(a,b,c,d)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
