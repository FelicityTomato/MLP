#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define X first
#define Y second

bool cmp(pii a, pii b){
    if(a.Y>b.Y) return true;
    else if(a.Y==b.Y && a.X>b.X) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        //if(n==0) return 0;
        pii arr[n];
        for(int i=0; i<n; i++) cin >> arr[i].X >> arr[i].Y;
        sort(arr,arr+n,cmp);
        //for(int i=0; i<n; i++) cout << arr[i].X << ' ' <<  arr[i].Y << '\n';
        ll now=0, eat=0;
        for(int i=0; i<n; i++){
            now+=arr[i].X;
            eat-=arr[i].X;
            eat=max(eat,arr[i].Y);
            //cout <<eat << '\n';
        }
        cout << now+eat << '\n';
    }
    return 0;
}