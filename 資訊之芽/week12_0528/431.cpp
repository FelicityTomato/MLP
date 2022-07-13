#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define X first
#define Y second
#define pb push_back

int n,m,q;
vector<pii> v[200005];
vector<pii> v2[200005];
ll dis1[200005], dis2[200005];
bool used[200005]={0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].pb({b,c});
        v2[b].pb({a,c});
    }
    for(int i=1; i<=n; i++) dis1[i]=LONG_MAX/5;
    dis1[1]=0;
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.push({dis1[1],1});
    while(!pq.empty()){
        int t=pq.top().second;
        pq.pop();
        if(used[t]) continue;
        used[t]=1;
        for(pii p:v[t]){
            if(used[p.first]) continue;
            if(dis1[p.first]>dis1[t]+p.second){
                dis1[p.first]=dis1[t]+p.second;
                pq.push({dis1[p.first],p.first});
            }
        }
    }
    for(int i=1; i<=n; i++) used[i]=0;
    for(int i=1; i<=n; i++) dis2[i]=LONG_MAX/5;
    dis2[n]=0;
    pq.push({dis2[n],n});
    while(!pq.empty()){
        int t=pq.top().second;
        pq.pop();
        if(used[t]) continue;
        used[t]=1;
        for(pii p:v2[t]){
            if(used[p.first]) continue;
            if(dis2[p.first]>dis2[t]+p.second){
                dis2[p.first]=dis2[t]+p.second;
                pq.push({dis2[p.first],p.first});
            }
        }
    }
    while(q--){
        int c,d;
        cin >> c >> d;
        cout << min(dis1[n], dis1[c]+dis2[d]+1) << '\n';
    }
    return 0;
}
/*
sample 1

6 5 3
1 2 1
2 3 1
3 4 1
4 5 1 
5 6 1
2 5
1 6
3 2

sample 2
8 9 5
1 2 1
1 3 1
2 4 1
2 6 1
3 5 1
4 7 1
5 6 1
6 8 1
7 8 1
6 1
1 6 
1 2
5 8
2 8

sample 3
5 8 4
1 1 1000000000
2 1 3
1 3 5
1 4 9
4 5 8
5 4 2
3 4 3
4 5 1
2 2
1 5
1 4
3 4
*/