#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    stack<int> s;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        if(a>0) s.push(a);
        else{
            if(s.empty() || s.top()!=-a){
                cout << "lose light light\n";
                return 0;
            }
            else s.pop();
        }
    }
    if(s.empty()) cout << "weed\n";
    else cout << "lose light light\n";
    return 0;
}   
