#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back
const double eps=1e-12;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    double arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    //for(int i=0; i<n; i++) cout << arr[i] << ' '; cout << '\n';
    ll cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(fabs(arr[i]+arr[j]-arr[k])<=eps) cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
