#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    int arr[n][m];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> arr[i][j];
    int l=0,r=m-1,u=0,d=n-1;
    while(q--){
        string op;
        int k;
        cin >> op >> k;
        if(op=="L"){
            for(int i=u; i<=d; i++){
                for(int j=0; j<k; j++){
                    arr[i][l+2*k-j-1]+=arr[i][l+j];
                    arr[i][l+j]=0;
                }
            }
            l+=k;
        }
        else if(op=="R"){
            for(int i=u; i<=d; i++){
                for(int j=0; j<k; j++){
                    arr[i][r-2*k+j+1]+=arr[i][r-j];
                    arr[i][r-j]=0;
                }
            }
            r-=k;
        }
        else if(op=="D"){
            for(int j=l; j<=r; j++){
                for(int i=0; i<k; i++){
                    arr[d-2*k+i+1][j]+=arr[d-i][j];
                    arr[d-i][j]=0;
                }
            }
            d-=k;
        }
        else if(op=="U"){
            for(int j=l; j<=r; j++){
                for(int i=0; i<k; i++){
                    arr[u+2*k-i-1][j]+=arr[u+i][j];
                    arr[u+i][j]=0;
                }
            }
            u+=k;
        }
        else if(op=="LD"){
            for(int i=d-k+1; i<=d; i++){
                for(int j=0; d-i+j<k; j++){
                    arr[d-k+j][l+k-d+i]+=arr[i][j];
                    arr[i][j]=0;
                }
            }
        }
        else if(op=="LU"){
            for(int i=0; i<k; i++){
                for(int j=0; i+j<k; j++){
                    arr[k-j][k-i]+=arr[i][j];
                    arr[i][j]=0;
                }
            }
        }
        else if(op=="RD"){
            for(int i=d-k+1; i<=d; i++){
                for(int j=r; d-i+r-j<k; j--){
                    arr[d-k+r-j][r-k+d-i]+=arr[i][j];
                    arr[i][j]=0;
                }
            }
        }
        else if(op=="RU"){
            for(int i=0; i<k; i++){
                for(int j=r; i+r-j<k; j--){
                    arr[k-(r-j)][r-k+i]+=arr[i][j];
                    arr[i][j]=0;
                }
            }
        }
    }
    cout << d-u+1 << ' ' << r-l+1 << '\n';
    for(int i=u; i<=d; i++){
        for(int j=l; j<=r; j++) cout << arr[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}