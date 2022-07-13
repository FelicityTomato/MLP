#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define X first
#define Y second
int p[4][2]={1,0,-1,0,0,1,0,-1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        int arr[n][m];
        queue<pii> q;
        for(int i=0; i<n; i++){
            string s; cin >> s;
            for(int j=0; j<m; j++){
                if(s[j]=='#') arr[i][j]=-1;
                else if(s[j]=='@') arr[i][j]=-2;
                else{
                    arr[i][j]=0;
                    if(s[j]=='K') q.push({i,j});
                }
            }
        }
        bool b=0;
        while(!q.empty() && !b){
            int x=q.front().X, y=q.front().Y;
            q.pop();
            for(int k=0; k<4; k++){
                if(arr[x+p[k][0]][y+p[k][1]]==-2){
                    cout << arr[x][y]+1 << '\n';
                    b=1;
                    break;
                }
                else if(arr[x+p[k][0]][y+p[k][1]]==0){
                    arr[x+p[k][0]][y+p[k][1]]=arr[x][y]+1;
                    q.push({x+p[k][0],y+p[k][1]});
                }
            }
        }
        if(b==0) cout << "= =" << '"' << '\n' ;
    }
    return 0;
}
