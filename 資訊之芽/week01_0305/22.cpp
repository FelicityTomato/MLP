//  單調隊列 / dp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        stack<pii> s;
        ll cnt=0;
        for(int i=0; i<n; i++){
            ll tmp=0;
            while(!s.empty() && arr[i]>s.top().X){
                cnt+=s.top().Y;
                s.pop();
            }
            if(!s.empty() && arr[i]==s.top().X){
                cnt+=s.top().Y;
                tmp+=s.top().Y;
                s.pop();
            }
            if(!s.empty()) cnt++;
            s.push({arr[i], tmp+1});
        }
        cout << cnt << '\n';
    }
    return 0;
}