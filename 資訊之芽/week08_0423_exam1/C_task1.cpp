#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n+2];
    for(int i=0; i<n+2; i++) arr[i]=0;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a]++;
        arr[b+1]--;
    }
    for(int i=1; i<n+2; i++) arr[i]+=arr[i-1];
    int mx=0, cnt=0, start=-1;
    for(int i=0; i<=n; i++){
        if(arr[i]>0){
            mx=max(mx, cnt);
            if(start==-1){
                start=cnt;
            }
            cnt=0;
        }
        else cnt++;
    }
    cout << max((mx+1)/2, max(start,cnt)) << '\n';
    return 0;
}