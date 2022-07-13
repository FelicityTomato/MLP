#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n]; 
        for(int i=0; i<n; i++) cin >> arr[i];
        int cnt=0, tail=0;
        bool b=0;
        for(int i=0; i<n; i++){
            if(b==0){
                if(arr[i]<tail) tail=arr[i];
                if(arr[i]>tail){
                    b=1;
                    tail=arr[i];
                    cnt++;
                }
            }
            else{
                if(arr[i]>tail) tail=arr[i];
                if(arr[i]<tail){
                    b=0;
                    tail=arr[i];
                    cnt++;
                }
            }
        }
        if(b==0) cnt--;
        cout << cnt << '\n';
    }
    return 0;
}