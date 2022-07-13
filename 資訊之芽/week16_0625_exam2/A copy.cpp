#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,C; 
    cin >> n >> m >> C;
    ll mx=0,cnt=0;
    for(int i=0; i<m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        ll t=C-a;
        if(t<0) continue;
        else{
            ll k=(t/b)*c;
            if(k>mx){
                mx=k, cnt=1;
            }
            else if(k==mx) cnt++;
        }
    }
    cout << mx << ' ' << cnt << '\n';
    return 0;
}