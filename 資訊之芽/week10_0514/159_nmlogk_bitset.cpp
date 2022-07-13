#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int n,m;
vector<int> c,k;
bitset<20005> dp = {1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        cin >> n >> m;
        c.pb(0); k.pb(0);
        for(int i=1; i<=n; i++){
            int a, b; cin >> a >> b;
            c.pb(a);
            k.pb(b);
        }
        for(int i=1; i<=n; i++){
            int t=1;
            while(k[i]>t){
                c.pb(t*c[i]);
                k[i]-=t;
                t=(t<<1);
            }
            c[i]*=k[i];
        }
        //for(int i=1; i<c.size(); i++) cout << c[i] << ' '; cout << '\n'; 
        for(int i=1; i<c.size(); i++){
            dp |= dp<< c[i];
        }
        if(dp.test(m)) cout << "Yes\n";
        else cout << "No\n";
        c.clear();
        k.clear();
        dp.reset();
        dp.set(0);
    }
    return 0;
}