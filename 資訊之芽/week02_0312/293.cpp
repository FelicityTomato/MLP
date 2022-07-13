#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int MAX=112345;
vector<int> v[MAX];
int n;
int cnt[MAX], degree[MAX];

int f(int p, int idx){
    int sum=0, mx=0;
    for(int u:v[idx]){
        if(u!=p){
            int k=f(idx, u);
            sum+=k;
            mx=max(mx, k);
        }
    }
    cnt[idx]=max(mx,n-sum-1);
    return sum+1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n; 
        for(int i=0; i<n; i++) v[i].clear();
        for(int i=0; i<n; i++) cnt[i]=0;
        for(int i=0; i<n; i++) degree[i]=0;
        for(int i=0; i<n-1; i++){
            int a,b; cin >> a >> b;
            v[a].pb(b);
            v[b].pb(a);
            degree[a]++; degree[b]++;
        }
        for(int i=0; i<n; i++){
            if(degree[i]==1){
                //cout << i << '\n';
                int k=f(-1,i);
                int mn=MAX, idx;
                //for(int i=0; i<n; i++) cout << cnt[i] << ' '; cout << endl;
                for(int i=0; i<n; i++){
                    if(cnt[i]<mn){
                        mn=cnt[i];
                        idx=i;
                    }
                }
                cout << idx << '\n';
                break;
            }
        }
    }
    return 0;
}