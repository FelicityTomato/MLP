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
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        v.clear();
        for(int i=0; i<n; i++){
            pll p;
            cin >> p.X >> p.Y;
            v.pb(p);
        }
        sort(v.begin(), v.end());
        //for(int i=0; i<v.size(); i++) cout << v[i].X << ' ' << v[i].Y << '\n';
        vector<pll> stk(1, v[0]);
        for(int i=1; i<v.size(); ++i){
            while(stk.size()>1 && ori(stk[stk.size()-2], stk.back(), v[i]) <=0) stk.pop_back();
            stk.pb(v[i]);
        }
        int t=stk.size();
        for(int i=v.size()-2; i>=0; --i){
            while(stk.size()>t && ori(stk[stk.size()-2], stk.back(), v[i]) <=0) stk.pop_back();
            stk.pb(v[i]);
        }
        stk.pop_back();
        //for(int i=0; i<stk.size(); i++) cout << stk[i].X << ' ' << stk[i].Y << '\n';
        ll cnt=0;
        for(int i=1; i<stk.size(); i++){
            cnt+=stk[i-1]^stk[i];
        }
        cnt+=stk[stk.size()-1]^stk[0];
        if(cnt&1) cout << cnt/2 << ".5\n";
        else cout << cnt/2 << ".0\n";
    }
    return 0;
}
