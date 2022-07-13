#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(t--){
        int n; cin >> n;
        if(n==1){
            int k; cin >> k;
            pq.push(k);
        }
        else{
            if(pq.empty()) cout << "empty!\n";
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
    return 0;
}
