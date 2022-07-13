#include<bits/stdc++.h>
using namespace std;

int n,m; 
int idx=0;
struct que{
    int q[112345][2];
    int shop[105][2];
    void start(){
        for(int i=1; i<n; i++){
            shop[i][0]=i;
            shop[i][1]=i;
        }
    }
    void add(int i, int v){
        q[idx][0]=v;
        q[shop[i][1]][1]=idx;
        shop[i][1]=idx;
        idx++;
    }
    int leave(int i){
        if(shop[i][0]==shop[i][1]) return 0;
        shop[i][0]=q[shop[i][0]][1];
        return 1;
    }
    void join(int i, int j){
        q[shop[j][1]][1]=shop[i][0];
        shop[j][1]=shop[i][1];
        shop[i][0]=idx;
        idx++;
        shop[i][1]=shop[i][0];
    }
    void print(){
        for(int i=1; i<=n; i++){
            cout << "queue " << i << ": ";
            if(shop[i][0]==shop[i][1]) cout << "empty\n";
            else{
                while(1){
                    cout << q[shop[i][0]][0] << ' ';
                    shop[i][0]=q[shop[i][0]][1];
                }
                cout << '\n';
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(m--){
        string s;
        cin >> s;
        que q;
        if(s=="ADD"){
            int a,b; cin >> a >> b;
            q.add(a,b);
        }
        else if(s=="LEAVE"){
            int a; cin >> a;
            if(q.leave(a)==0) cout << "queue " << a << " is empty!\n";
        }
        else{
            int a,b; cin >> a >> b;
            q.join(a,b);
        }
    }
    q.print();
    return 0;
}