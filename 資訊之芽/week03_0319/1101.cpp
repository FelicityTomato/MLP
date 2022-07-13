#include<bits/stdc++.h>
using namespace std;

vector<int> v[112345];
int col[112345];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        for(int i=0; i<n; i++){
            v[i].clear();
            col[i]=-1;
        }
        for(int i=0; i<m; i++){
            int a,b; cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        queue<int> q;
        bool b=0;
        for(int i=0; i<n; i++){
            if(col[i]==-1){
                q.push(i);
                col[i]=0;
                while(!q.empty()){
                    int p=q.front();
                    q.pop();
                    for(int j=0; j<v[p].size(); j++){
                        int u=v[p][j];
                        if(col[u]==-1){
                            col[u]=1-col[p];
                            q.push(u);
                        }
                        else if(col[u]==col[p]){
                            //cout << p  << ' ' << u << '\n';
                            cout << "RAINBOW.";
                            b=1;
                            break;
                        }
                    }
                    if(b) break;
                }
                if(b) break;
            }
        }
        if(b==0) cout << "NORMAL.";
        //else cout << "RAINBOW.";
        //for(int i=0; i<n; i++) cout << col[i] << ' '; cout << '\n';
        cout << '\n';
    }
    return 0;
}
