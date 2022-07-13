#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define X first
#define Y second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n==1){
            cout << 1 << '\n';
            continue;
        }
        ll k=0, b=1;
        int i=9;
        while(i>1){
            if(n%i==0){
                n/=i;
                k+=b*i;
                b*=10;
            }
            else i--;
        }
        if(n>1) cout << -1 << '\n';
        else cout << k << '\n';
    }
    return 0;
}