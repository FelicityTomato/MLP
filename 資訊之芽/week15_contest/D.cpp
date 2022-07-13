#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

const int MAX=1e9+7;
ll hsh[500005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    for(int i=0; i<500005; i++){
        hsh[i]=rand()%MAX;
    }
    int n,m,q;
    cin >> n >> m>> q;
    ll arr[n+5][m+5], fs[n+5][m+5];
    for(int i=0; i<n+5; i++){
        for(int j=0; j<m+5; j++){
            arr[i][j]=fs[i][j]=0;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
            arr[i][j]=hsh[arr[i][j]];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            fs[i][j]=fs[i-1][j]+fs[i][j-1]-fs[i-1][j-1]+arr[i][j];
        }
    }
    while(q--){
        int x,y; cin >> x >> y;
        x++; y++;
        int i;
        for(i=1; i<n; i++){
            if(fs[x+i][y+i]-fs[x-i-1][y+i]-fs[x+i][y-i-1]+fs[x-i-1][y-i-1]!=arr[x][y]*(2*i+1)*(2*i+1)){
                //cout << i << '\n';
                break;
            }
        }
        cout << 2*i-1<< '\n';;
    }
    return 0;
}
