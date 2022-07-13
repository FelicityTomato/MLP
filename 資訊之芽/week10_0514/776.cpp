#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

const int mod=1e9+7;
struct mat{
    ll a[105][105];
};
mat arr;
mat k(mat b, mat c){
    mat q;
    for(int i=0; i<105; i++) for(int j=0; j<105; j++) q.a[i][j]=0;
    for (int i=0; i<105; i++){
        for (int j=0; j<105; j++){
            for (int k=0; k<105; k++){
                q.a[i][j]+=(b.a[i][k] * c.a[k][j]) % mod;
                q.a[i][j]=(q.a[i][j]+mod)%mod;
            }
        }
    }
    return q;
}

mat f(int n){
    if(n==1) return arr;
    mat q=f(n/2);
    q=k(q,q);
    if(n&1) return k(q,arr);
    else return q;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, l; cin >> n >> m >> l;
    for(int i=0; i<105; i++) for(int j=0; j<105; j++) arr.a[i][j]=0;
    while(m--){
        int x,y;
        cin >> x >> y;
        arr.a[x][y]=1;
    }
    mat t=f(l);
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cout << t.a[i][j] << " \n"[j==n];
    return 0;
}