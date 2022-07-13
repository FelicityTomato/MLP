#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m,q;
    cin >> n >> m >> q;
    int cnt=0;
    while(q--){
        ll a[6];
        for(int i=0; i<6; i++) cin >> a[i]; 
        if(a[0]==a[2] && a[1]==a[3]) cnt++;
        else if(a[0]==a[2]){
            if(a[4]==a[0]) cnt++;
        }
        else if(a[1]==a[3]){
            if(a[5]==a[1]) cnt++;
        }
        else if(a[0]==a[4] && a[3]==a[5]) cnt++;
        else if(a[1]==a[5] && a[2]==a[4]) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}