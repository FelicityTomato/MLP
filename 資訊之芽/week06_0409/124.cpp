#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define X first 
#define Y second
#define pb push_back

int arr[2000][2000];
int p[4][2]={0,0,1,1,0,1,1,0};
#ifdef FELICITY
void Report(int a, int b, int c, int d, int e , int f){
    cout << a << ' ' << b << ' ' << c << ' ';
    cout << d << ' ' << e << ' ' << f << '\n';
}
#endif

void dc(int x, int y, int big){
    if(big==2){
        vector<pii> v;
        for(int i=x; i<x+2; i++){
            for(int j=y; j<y+2; j++){
                if(arr[i][j]==0){
                    arr[i][j]=-1;
                    v.pb({i,j});
                }
            }
        }
        Report(v[0].X+1, v[0].Y+1, v[1].X+1, v[1].Y+1, v[2].X+1, v[2].Y+1);
        return;
    }
    for(int i=x; i<x+big; i++){
        for(int j=y; j<y+big; j++){
            if(arr[i][j]==-1){
                int x1=x,y1=y;
                if(i>=x+big/2) x1=x+big/2;
                if(j>=y+big/2) y1=y+big/2;
                dc(x1, y1, big/2);
                vector<pii> v;
                
                for(int k=0; k<4; k++){
                    if(x1!=x+(big/2)*p[k][0] || y1!=y+(big/2)*p[k][1]){
                        arr[x+big/2-1+p[k][0]][y+big/2-1+p[k][1]]=-1;
                        v.pb({x+big/2-1+p[k][0], y+big/2-1+p[k][1]});
                        dc(x+(big/2)*p[k][0], y+(big/2)*p[k][1], big/2);
                    }
                }
                Report(v[0].X+1, v[0].Y+1, v[1].X+1, v[1].Y+1, v[2].X+1, v[2].Y+1);
                return;
            }
        }
    }
}

void solve(int n, int x, int y){
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) arr[i][j]=0;
    arr[x-1][y-1]=-1;
    dc(0,0,n);
}
#ifdef FELICITY
int main(){
    int n,x,y;
    cin >> n >> x >> y;
    solve(n,x,y);
    return 0;
}
#endif