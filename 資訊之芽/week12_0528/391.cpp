#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define X first
#define Y second
#define pb push_back

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        ll n,m,s,e,f;
        cin >> n >> m >> s >> e >> f;
        vector<pii> v[n+1];
        ll dis[n+1];
        bool used[n+1];
        while(m--){
            ll a,b,c,d,c2;
            cin >> a >> b >> c >> d >> c2;
            if(d>f){
                v[a].pb({b,c*f});
            }
            else{
                v[a].pb({b,min(c*f,c*d+(f-d)*c2)});
            }
        }
        for(int i=1; i<=n; i++) dis[i]=LONG_MAX/5;
        for(int i=1; i<=n; i++) used[i]=0;
        dis[s]=0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push({dis[s],s});
        while(!pq.empty()){
            ll t=pq.top().second;
            pq.pop();
            if(used[t]) continue;
            used[t]=1;
            for(pii p:v[t]){
                if(used[p.first]) continue;
                if(dis[p.first]>dis[t]+p.second){
                    dis[p.first]=dis[t]+p.second;
                    pq.push({dis[p.first],p.first});
                }
            }
        }
        cout<< dis[e] << '\n';
    }
    return 0;
}
