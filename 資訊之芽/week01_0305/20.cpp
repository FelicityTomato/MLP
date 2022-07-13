#include<bits/stdc++.h>
using namespace std;
int MAX=10005;
int group[1000005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    for(int w=1; w<=t; w++){
        cout << "Line #" << w << '\n';
        int n; cin >> n;
        for(int i=0; i<1000005; i++) group[i]=-1;
        for(int i=0; i<n; i++){
            int a; cin >> a;
            for(int j=0; j<a; j++){
                int k; cin >> k;
                group[k]=i;
            }
        }
        //for(int i=0; i<10; i++) cout << group[i] << ' ';
        vector< queue<int> > q(MAX+5, queue<int>());
        //queue<int> q[5005];
        int head=0, tail=0;
        int a; cin >> a;
        for(int i=0; i<a; i++){
            string s;
            cin >> s;
            if(s=="ENQUEUE"){
                int k; cin >> k;
                if(group[k]==-1){
                    if(q[tail].empty() || group[q[tail].front()]==-1) q[tail].push(k);
                    else{
                        q[++tail].push(k);
                        if(tail==MAX) tail=0;
                    }
                    
                }
                else{
                    if(q[tail].empty()){
                        q[tail].push(k);
                        continue;
                    }
                    bool b=0;
                    for(int j=head; j<=tail; j++){
                        if(group[q[j].front()]==group[k]){
                            q[j].push(k);
                            b=1;
                            break;
                        }
                    }
                    if(b==0){
                        q[++tail].push(k);
                        if(tail==MAX) tail=0;
                    }
                    
                }
            }
            else if(s=="DEQUEUE"){
                cout << q[head].front() <<'\n';
                q[head].pop();
                if(q[head].empty()){
                    if(head==MAX) head=0;
                    else if(head!=tail) head++;
                }
            }
        }
    }
    return 0;
}