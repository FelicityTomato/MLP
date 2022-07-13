#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define X first
#define Y second

int n; 
int arr[1005][1005][5];
int p[8][2]={1,1,1,0,1,-1,0,1,0,-1,-1,1,-1,0,-1,-1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) for(int k=1; k<=4; k++) arr[i][j][k]=0;
        queue<pii> q[5];
        for(int i=0; i<3; i++){
            char a; int b,c;
            cin >> a >> b >> c;
            if(a=='Y'){
                arr[b][c][1]=1;
                q[1].push({b,c});
            }
            else if(a=='B'){
                arr[b][c][2]=1;
                q[2].push({b,c});
            }
            else{
                arr[b][c][4]=1;
                q[4].push({b,c});
            }
        }
        char c; cin >> c;
        int k;
        if(c=='Y') k=1;
        else if(c=='B') k=2;
        else if(c=='G') k=3;
        else if(c=='R') k=4;
        else if(c=='O') k=5;
        else if(c=='P') k=6;
        else k=7;
        int mx=0, cnt=0;
        if(k==1 || k==2 || k==4) cnt=mx=1;

        while(!q[1].empty() || !q[2].empty() || !q[4].empty()){
            //cout << q.front().X << ' ' << q.front().Y << ' ' << arr[q.front().X][q.front().Y] << '\n';
            for(int j=1; j<=4; j++){
                if(q[j].empty()) continue;
                int tmp=arr[q[j].front().X][q[j].front().Y][j];
                while(!q[j].empty() && arr[q[j].front().X][q[j].front().Y][j]==tmp){
                    for(int i=0; i<8; i++){
                        int x=q[j].front().X+p[i][0], y=q[j].front().Y+p[i][1];
                        if(x>=0 && x<n && y>=0 && y<n && arr[x][y][j]==0){
                            if(((arr[x][y][1]>0 ? 1 : 0) | (2*(arr[x][y][2]>0 ? 1 : 0)) | (4*(arr[x][y][4]>0 ? 1 : 0)))==k) cnt--;
                            arr[x][y][j]=arr[q[j].front().X][q[j].front().Y][j]+1;
                            if(((arr[x][y][1]>0 ? 1 : 0) | (2*(arr[x][y][2]>0 ? 1 : 0)) | (4*(arr[x][y][4]>0 ? 1 : 0)))==k) cnt++;
                            q[j].push({x,y});
                        }
                    }
                    q[j].pop();
                }
            }
            //cout << cnt << '\n';
            mx=max(mx,cnt);
            /*
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++) cout << arr[i][j][1];
                cout << '\n';
            }
            cout << '\n';
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++) cout << arr[i][j][2];
                cout << '\n';
            }
            cout << '\n';
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++) cout << arr[i][j][4];
                cout << '\n';
            }
            cout << '\n';
            */
        }
        cout << mx << '\n';
    }
    return 0;
}
