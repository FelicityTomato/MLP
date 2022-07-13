#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000005];
/*
int  GetVal(int m, int i){
    cout << m << ' ' << i << '\n';
    cin >> m;
    return m;
}

void Report(int k){cout << k << '\n';}
*/
void dc(int l, int r, int L, int R){
    ll mx=0, idx; 
    ll m=l+(r-l)/2;
    //if(arr[m]!=-1) return; 
    //cout << m << ' ' << L << ' ' << R << '\n';
    for(int i=L; i<=R; i++){ 
        ll k=GetVal(m,i);
        if(k>mx){
            mx=k;
            idx=i;
        }
    }
    arr[m]=idx;
    //cout << idx << '\n';
    if(l<=m-1) dc(l, m-1, L, idx-1);
    if(m+1<=r) dc(m+1, r, idx+1, R);
}

void solve(int n, int m){
    //for(int i=1; i<=n; i++) arr[i]=-1;
    dc(1, n, 1, m);
    for(int i=1; i<=n; i++) Report(arr[i]);
}
/*
int main(){
    int a,b; cin >> a >> b;
    solve(a,b);
}
*/