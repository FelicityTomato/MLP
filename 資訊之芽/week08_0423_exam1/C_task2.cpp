#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
int n, m, k;
pii arr[1000005];

bool can(int mid){
    int r=0, t=k;
    for(int i=0; i<m; i++){
        if(t<0) return false;
        if(arr[i].X<=r) r=max(r, arr[i].Y);
        else if(arr[i].X-r>mid) return false;
        else{
            r=max(r, arr[i].Y+mid);
            t--;
        }
    }
    if(r!=n){
        if(n-r>mid || t==0) return false;
    }
    if(t<0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<m; i++) cin >> arr[i].X >> arr[i].Y;
    sort(arr, arr+m);
    int l=0, r=n+1;
    while(l+1<r){
        int mid=l+(r-l)/2;
        if(can(mid)) r=mid;
        else l=mid;
    }
    cout << r << '\n';
    return 0;
}