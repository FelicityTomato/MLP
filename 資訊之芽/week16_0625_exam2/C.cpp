#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

int n,m;
vector<pii> v[200005];
ll dis[200005];
bool used[200005]={0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>> a >> b >> c;
        v[a].pb({b,c});
        v[b].pb({a,c});
    }
    for(int i=0; i<=n; i++) dis[i]=INT_MAX;
    dis[1]=0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({dis[1],1});
    while(pq.size()){
        int t=pq.top().second;
        pq.pop();
        if(used[t]) continue;
        used[t]=1;
        for(pair<int,int> p:v[t]){
            if(used[p.X]) continue;
            if(dis[p.X] > p.Y){
                dis[p.X]=p.Y;
                pq.push({dis[p.X], p.X});
            }
        }
    }
    ll cnt=0;
    for(int i=1; i<=n; i++) cnt+=dis[i];
    cout << cnt << '\n';
    return 0;
}