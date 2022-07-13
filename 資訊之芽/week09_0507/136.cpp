#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back

//void Report(int i){cout << i << ' ';}
bool dp(ll a[], int idx, ll w, int n){
    if(w==0) return 1;
    if(idx==n) return 0;
    bool b=0;
    if(w>=a[idx] && dp(a, idx+1, w-a[idx],n)){
        Report(idx+1);
        return 1;
    }
    else if(dp(a, idx+1, w,n)) return 1;
    return 0;
}

void solve(int n, ll k, ll a[]){
    dp(a,0,k,n);
    Report(-1);
}
/*
int main(){
    ll a[3]={6,8,9};
    solve(3,17,a);
    return 0;
}
*/