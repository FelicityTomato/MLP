#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int V,r,m;
vector<int> v[2000];

void m0(int idx){
    cout << idx << ' ';
    if(v[idx].size()>0) m0(v[idx][0]);
    if(v[idx].size()==2) m0(v[idx][1]);
}
void m1(int idx){
    if(v[idx].size()>0) m1(v[idx][0]);
    cout << idx << ' ';
    if(v[idx].size()==2) m1(v[idx][1]);
}
void m2(int idx){
    if(v[idx].size()>0) m2(v[idx][0]);
    if(v[idx].size()==2) m2(v[idx][1]);
    cout << idx << ' ';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> r >> m;
    for(int i=0; i<V-2; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        if(v[a].size()==2 && v[a][0]>v[a][1]) swap(v[a][0],v[a][1]);
    }
    if(m==0) m0(r);
    else if(m==1) m1(r);
    else m2(r);
    return 0;
}
