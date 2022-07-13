#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k,q; cin >> k >> q;
    int arr[q];
    int idx=0;
    while(q--){
        string s;
        cin >> s;
        if(s=="Add"){
            int x; cin >> x;
            arr[idx]=x;
            idx++;
        }
        else if(s=="Remove"){
            for(int i=idx/2+1; i<idx; i++) arr[i-1]=arr[i];
            idx--;
        }
        else if(s=="Mod"){
            for(int i=0; i<idx; i++) arr[i]%=k;
        }
        else if(s=="Reverse"){
            int tmp[idx];
            for(int i=0; i<idx; i++) tmp[idx-i-1]=arr[i];
            for(int i=0; i<idx; i++) arr[i]=tmp[i];
        }
    }
    for(int i=0; i<idx; i++) cout << arr[i] <<' '; cout << '\n';
    return 0;
}