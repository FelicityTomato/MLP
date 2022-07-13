#include <bits/stdc++.h>
using namespace std;

int arr[15], ans[6], n;

void combine (int now , int idx){
    if (idx==6){
        for(int i=0; i<5; i++) cout << ans[i] << " ";
        cout << ans[5] << endl;
        return;
    }
    for (int i=now; i<n ;i++){
        ans[idx]=arr[i];
        combine (i+1, idx+1);
    }
}

int main() {
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];
        combine(0, 0);        
    }
    return 0;
}