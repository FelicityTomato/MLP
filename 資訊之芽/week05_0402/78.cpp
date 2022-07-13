#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int arr[6];
        for(int i=0; i<6; i++) cin >> arr[i];
        int cnt=arr[5]+arr[4];
        arr[0]=max(0, arr[0]-11*arr[4]);
        cnt+=arr[3];
        while(arr[3]--){
            if(arr[1]>=5) arr[1]-=5;
            else{
                arr[0]=max(0,arr[0]-(5-arr[1])*4);
                arr[1]=0;
            }
        }
        cnt+=arr[2]/4;
        arr[2]%=4;
        if(arr[2]) cnt++;
        if(arr[2]==3){
            if(arr[1]){
                arr[1]--;
                arr[0]=max(arr[0]-5,0);
            }
            else arr[0]=max(0, arr[0]-9);
        }
        else if(arr[2]==2){
            if(arr[1]>=3){
                arr[1]-=3;
                arr[0]=max(0, arr[0]-6);
            }
            else{
                arr[0]=max(0, arr[0]-(18-arr[1]*4));
                arr[1]=0;
            }
        }
        else if(arr[2]==1){
            if(arr[1]>=5){
                arr[1]-=5;
                arr[0]=max(arr[0]-7,0);
            }
            else{
                arr[0]=max(arr[0]-(27-arr[1]*4),0);
                arr[1]=0;
            }
        }
        cnt+=arr[1]/9;
        arr[1]%=9;
        if(arr[1]){
            cnt++;
            arr[0]=max(0, arr[0]-(36-arr[1]*4));
        }
        cnt+=arr[0]/36;
        arr[0]%=36;
        if(arr[0]) cnt++;
        cout << cnt << '\n';

    }
    return 0;
}