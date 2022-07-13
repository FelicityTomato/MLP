#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=INT_MAX;

vector<int> v[100005];
int dis[100005];
bool used[100005]={0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=2; i<=n; i++) dis[i]=inf;
    dis[1]=0;
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.push({dis[1],1});
    while(!pq.empty()){
        int t=pq.top().second;
        pq.pop();
        if(used[t]) continue;
        used[t]=1;
        for(int p:v[t]){
            if(used[p]) continue;
            if(dis[p]>dis[t]+1){
                dis[p]=dis[t]+1;
                pq.push({dis[p],p});
            }
        }
    }
    int q; cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << dis[b] << '\n';
    }
    return 0;
}