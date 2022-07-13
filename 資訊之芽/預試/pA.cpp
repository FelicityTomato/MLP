#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m,k;
    cin >> n >> m >> k;
    //cout << n << m << k;
    if(k==0){
        ll cnt=n*m/6;
        if((n*m)%6!=0) cnt++;
        cout << cnt << '\n';
    }
    else{
        ll arr[k];
        for(int i=0; i<k; i++){
            int a,b;
            cin >> a >> b;
            if(a&1) arr[i]=(a-1)*m+b;
            else arr[i]=(a-1)*m+m-b+1;
            //cout << arr[i] << ' ';
        }
        //for(int i=0; i<k; i++) cout << arr[i]<< endl;
        sort(arr,arr+k);
        //for(int i=0; i<k; i++) cout << arr[i] << endl;
        for(int i=0; i<k; i++){
            bool b=0;
            for(int j=1; j<6; j++){
                if(arr[i+j]!=arr[i]+j){
                    b=1;
                    break;
                }
            }
            if(b==0){
                cout << -1 << '\n';
                return 0;
            }
        }
        //cout << 1 << endl;
        int cnt=0;
        int now=0, idx=0;
        while(now<n*m){
            //cout << now << endl;
            while(arr[idx]<now && idx<k) idx++;
            if(idx<k){
                int step=arr[idx]-now-1;
                now+=(step/6)*6;
                cnt+=step/6;
                //cout << now << ' ' << cnt << '\n';
            }
            int mx=0, j=0;
            for(int i=1; i<=6; i++){
                if(now+i==arr[idx+j]) j++;
                else{
                    idx+=j;
                    j=0;
                    mx=i;
                }
            }
            now+=mx;
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}