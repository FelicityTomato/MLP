#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

ll b=256, p=1e9+9;
map<ll, ll> mp;

ll hsh(string s){
    ll k=0;
    for(int i=0; i<s.size(); i++){
        k=(k*b+s[i])%p;
    }
    return k;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        ll k=hsh(s);
        if(mp.find(k)==mp.end()) mp.insert({k,1});
        else mp.find(k)->Y++;
    }
    for(int i=0; i<m; i++){
        cin >> s;
        ll k=hsh(s);
        if(mp.find(k)!=mp.end()) cout << mp.find(k)->Y << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}