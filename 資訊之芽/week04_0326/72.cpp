#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; 
double arr[305][3];
double mx(double t){
    double MX=0.0;
    for(int i=0; i<n; i++) MX=max(MX, arr[i][0]*(t-arr[i][1])*(t-arr[i][1])+arr[i][2]);
    return MX;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        cin >> n;
        for(int i=0; i<n; i++) for(int j=0; j<3; j++) cin >> arr[i][j];
        //for(int i=0; i<n; i++) for(int j=0; j<3; j++) cout << arr[i][j] << ' '; cout << endl;
        double l=0.0, r=300.0;
        while(r-l>0.000000000001){
            double a=l+(r-l)/3.0, b=l+(r-l)*2.0/3.0;
            //cout << l << ' ' << r << ' ' << mx(a) << ' ' << mx(b) << endl;
            if(mx(a)>mx(b)) l=a;
            else r=b;
        }
        cout << fixed << setprecision(15) << mx(l) << '\n';
    }
    return 0;
}