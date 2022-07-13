#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int arr[112345];

bool can(int x){
    int now=0;
    for(int i=0; i<m; i++){
        int k=x;
        if(i) k+=arr[now-1];
        int idx=upper_bound(arr, arr+n, k)-arr; 
        if(idx==n) return true;
        now=idx;
        //cout << now  << ' ' << arr[now] << '\n';
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(i) arr[i]+=arr[i-1];
        }
        
        int l=0, r=INT_MAX;
        while(r-l>1){
            int m=l+(r-l)/2;
            if(can(m)) r=m;
            else l=m;
        }
        cout << r << '\n'; 
        //cout << can(5) << '\n';
    }
    return 0;
}