#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

ll n,m ,k, p=1e9+33;
struct mat{
    ll A[1505][1505];
};
mat a,b,c,r,q;
void f(mat &B, mat &C, int x, int y){
    
    for(int i=0; i<x; i++) q.A[i][0]=0;
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            //for (int l=0; l<y; l++){
                q.A[i][0]+=(B.A[i][j] * C.A[j][0]) % p;
                q.A[i][0]=(q.A[i][0]+p)%p;
            //}
        }
    }
    
    //return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> a.A[i][j];
    for(int i=0; i<m; i++) for(int j=0; j<k; j++) cin >> b.A[i][j];
    for(int i=0; i<n; i++) for(int j=0; j<k; j++) cin >> c.A[i][j];
    for(int i=0; i<k; i++){
        r.A[i][0]=rand()%INT_MAX;
    }
    f(b,r,m,k);
    b=q;
    f(a,b,n,m);
    a=q;
    f(c,r,n,k);
    c=q;
    bool bol=0;
    for(int i=0; i<n; i++){
        if(a.A[i][0]!=c.A[i][0]){
            bol=1;
            break;
        }
    }
    if(bol) cout << "No\n";
    else cout << "Yes\n"; 

    return 0;
}
