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
        int arr[n+2][m+2];
        for(int i=0; i<=n+1; i++) for(int j=0; j<=m+1; j++) arr[i][j]=-1;
        for(int i=1; i<=n; i++){
            string s; cin >> s; //cout << s << '\n';
            for(int j=0; j<m; j++){
                if(s[j]=='.'){
                        //cout << i << ' ' << j<< '\n';
                    arr[i][j+1]=0;
                }
            }
        }
        int cnt=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(arr[i][j]==0){
                    cnt++;
                    //cout << cnt << '\n';
                    queue<pii> q;
                    q.push({i,j});
                    arr[i][j]=1;
                    while(!q.empty()){
                        int x=q.front().X, y=q.front().Y;
                        q.pop();
                        for(int k=0; k<4; k++){
                            if(arr[x+p[k][0]][y+p[k][1]]==0){
                                arr[x+p[k][0]][y+p[k][1]]=1;
                                q.push({x+p[k][0],y+p[k][1]});
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
