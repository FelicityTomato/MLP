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
    int n,m,q;
    cin >> n >> m>> q;
    int arr[n+5][m+5];
    int c1[n+5][m+5], c2[n+5][m+5];
    for(int i=0; i<n+5; i++){
        for(int j=0; j<m+5; j++){
            arr[i][j]=c1[i][j]=c2[i][j]=0;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            c1[i][j]=1;
            if(arr[i-1][j]==arr[i][j] && arr[i][j-1]==arr[i][j]) c1[i][j]=min(c1[i-1][j], c1[i][j-1])+1;
        }
    }
    for(int i=n; i>0; i--){
        for(int j=m; j>0; j--){
            c2[i][j]=1;
            if(arr[i+1][j]==arr[i][j] && arr[i][j+1]==arr[i][j]) c2[i][j]=min(c2[i+1][j], c2[i][j+1])+1;
        }
    }
    while(q--){
        int x,y; cin >> x >> y;
        x++; y++;
        bool b=0;
        int mx=1;
        for(int i=1; i<min(n,m) ; i++){
            //cout << i << ' ' << mx << '\n';
            if(arr[x][y]==arr[x+i][y+i] && arr[x][y]==arr[x-i][y-i]){
                mx=max(mx,min(c1[x+i][y+i], c2[x-i][y-i]));
            }
            else break;
        }
        cout << mx << '\n';
    }
    return 0;
}
