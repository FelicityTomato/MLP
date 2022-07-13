#include <bits/stdc++.h>
using namespace std;

int n,m; 
int con[512345], arr[512345];
bool can(int k){
    bool b[k];
    priority_queue<int> pq;
    for(int i=0; i<k; i++) b[i]=0;
    for(int i=0; i<n; i++) pq.push(con[i]);
    int cnt=0;
    for(int j=k-1; j>=0; j--){
        if(b[j]==0 && pq.top()>=arr[j]){
            b[j]=1;
            int p=pq.top()-arr[j];
            pq.pop();
            pq.push(p);
            cnt++;
        }
    }
    //cout << k << ' ' << cnt << '\n';
    if(cnt==k) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++) cin >> con[i];
        for(int i=0; i<m; i++) cin >> arr[i];
        sort(con, con+n);
        sort(arr, arr+m);
        //for(int i=0; i<m; i++) cout << arr[i] << ' '; cout << '\n';
        if(can(m)){
            cout << m << '\n';
            continue;
        }
        int l=0, r=m;
        while(r-l>1){
            int M=l+(r-l)/2;
            if(can(M)) l=M;
            else r=M;
        }
        cout << l << '\n';
        //cout << can(1) << '\n';
    }
    return 0;
}