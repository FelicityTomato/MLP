#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back

const int MAX=100005;
vector<int> ch[MAX];
bool p[MAX];
int sz[MAX];

int dfs(int i){
    if(ch[i].size()==0){
        sz[i]=1;
    }
    else{
        int cnt=0;
        for(int u:ch[i]){
            cnt+=dfs(u);
        }
        sz[i]=cnt+1;
    }
    return sz[i];
}
int main(){
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        for(int i=1; i<=n; i++) p[i]=0;
        for(int i=1; i<=n; i++) sz[i]=1;
        for(int i=1; i<=n; i++) ch[i].clear();
        int x,y;
        while(m--){
            cin >> x >> y;
            p[y]=1;
            ch[x].pb(y);
        }
        int k;
        for(int i=1; i<=n; i++){
            if(p[i]==0) k=dfs(i);
        }
        int q,a; cin >> q;
        while(q--){
            cin >> a;
            cout << sz[a] << '\n';
        }
    }
}