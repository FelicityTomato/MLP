#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    set<int> st;
    while(n--){
        string s; cin >> s;
        int a; cin >> a;
        if(s=="insert"){
            if(st.find(a)==st.end())st.insert(a);
        }
        else if(s=="delete"){
            st.erase(a);
        }
        else{
            auto it=st.lower_bound(a);
            if(it==st.begin()){
                cout << *(it) << '\n';
                continue;
            }
            if(it==st.end()){
                cout << *(--it) << '\n';
                continue;
            }
            int k=*it;
            int q=*(--it);
            if((a-q)==(k-a)) cout << q << ' ' << k << '\n';
            else if(a-q<k-a) cout << q << '\n';
            else cout << k << '\n';
        }
    }
    return 0;
}