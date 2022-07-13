#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int n, q;
vector<int> v[200005];
int arr[200005];
int ans[200005];

pii f(int par, int idx){
    pii p;
    if(v[idx].size()==1 && par!=-1){
        p.X=p.Y=arr[idx];
    }
    else{
        p.X=arr[idx]; p.Y=arr[idx];
        for(int u:v[idx]){
            if(u!=par){
                pii t=f(idx, u);
                p.X=max(p.X, t.X);
                p.Y=min(p.Y, t.Y);
            }
        }
    }
    ans[idx]=p.X-p.Y;
    return p;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int i=1; i<=n; i++) cin >> arr[i];
    pii t=f(-1, 1);
    while(q--){
        int a; cin >> a;
        cout << ans[a] << '\n';
    }
    return 0;
}