#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    int arr[n+1];
    for(int i=1; i<=n; i++) cin >> arr[i];
    queue<int> a,b;
    int i=1;
    for(int j=1; j<=n; j++){
        if(arr[i]==j && (a.empty()||b.empty())){
            i++;
            continue;
        }
        else if(arr[i]==j && !a.empty()&& !b.empty()){
            cout << "No\n";
            return 0;
        }
        if(!a.empty() && a.front()==arr[i]){
            a.pop();
            i++;
            j--;
        }
        else if(!b.empty() && b.front()==arr[i]){
            b.pop();
            i++;
            j--;
        }
        else if(!a.empty()){
            a.push(j);
        }
        else{
            b.push(j);
        }
    }
    if(!a.empty() || !b.empty()) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}