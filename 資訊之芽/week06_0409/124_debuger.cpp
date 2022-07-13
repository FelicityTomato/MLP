#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define X first 
#define Y second
#define pb push_back

int arr[1024][1024]={0};

int main(){
    int n; cin >> n;
    for(int i=1; i<=(n*n-1)/3; i++){
        int a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        arr[a-1][b-1]=i;
        arr[c-1][d-1]=i;
        arr[e-1][f-1]=i;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << ' ';
            if(arr[i][j]<10) cout << ' ';
            if(arr[i][j]<100) cout << ' ';
        }
        cout << '\n'; 
    }
}