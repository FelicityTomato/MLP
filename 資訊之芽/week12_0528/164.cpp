// 參考https://mirrorshih.blogspot.com/2019/08/zj-b058-3_28.html
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int n,m;
ll val[100005], deg[100005]={0}, mx[100005]={0};
bool tag[100005]={0};
vector<ll> v[100005];
vector<ll> par[100005];

ll dfs(int idx){
    int r=0;
    if(tag[idx]) return 0;
    tag[idx]=1;
    for(auto u:par[idx]) r+=dfs(u);
    r++;
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> val[i];
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        v[a].pb(b);
        deg[b]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(deg[i]==0){
            q.push(i);
            mx[i]=val[i];
        }
    }
    vector<int> back;
    int r=0;
    while(q.size()){
        int k=q.front();
        q.pop();
        if(!v[k].size() && mx[k]>=r){
            if(r<mx[k]) back.clear();
            r=mx[k];
            back.pb(k);
        }
        for(auto u:v[k]){
            deg[u]--;
            if(mx[u]< mx[k]+val[u]){
                par[u].clear();
                mx[u]=mx[k]+val[u];
                par[u].pb(k);
            }
            if(deg[u]==0) q.push(u);
        }
    }
    ll ans=0;
    for(auto u:back) ans+=dfs(u);
    cout << ans << '\n';
    return 0;
}
