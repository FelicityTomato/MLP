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
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<int> v[n];
        int indeg[n];
        for(int i=0; i<n; i++) indeg[i]=0;
        for(int i=0; i<m; i++){
            int a,b;
            cin >> a >> b;
            v[a].pb(b);
            indeg[b]++;
        }
        priority_queue<int, vector<int>, greater<int> > q;
        vector<int> ans;
        for(int i=0; i<n; i++) if(indeg[i]==0) q.push(i);
        while(q.size()){
            int k=q.top();
            q.pop();
            ans.pb(k);
            for(int u:v[k]){
                indeg[u]--;
                if(indeg[u]==0) q.push(u);
            }
        }
        if(ans.size()!=n) cout << "QAQ\n";
        else{
            for(int i=0; i<n; i++) cout << ans[i] << " \n"[i==n-1];
        }
    }
    return 0;
}
