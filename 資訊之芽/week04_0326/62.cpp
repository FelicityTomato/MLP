#include <bits/stdc++.h>
using namespace std;

int puz[9][9];
bool b;
bool check(int i, int j){
    for(int x=0; x<9; x++) if(x!=i && puz[x][j]==puz[i][j]) return false;
    for(int x=0; x<9; x++) if(x!=j && puz[i][x]==puz[i][j]) return false;
    for(int k=(i/3)*3; k<(i/3)*3+3; k++){
        for(int w=(j/3)*3; w<(j/3)*3+3; w++){
            //cout << k << ' ' << w << '\n';
            if((k!=i || w!=j) && puz[k][w]==puz[i][j]){
                //cout <<"-----" << k << ' ' << w << ' ' << puz[k][w] << '\n';
                return false;
            }
        }
    }
    return true;
}
void print(){
    for(int x=0; x<9; x++) for(int y=0; y<9; y++) cout << puz[x][y]; cout << '\n'; 
    b=1;
}
void f(int i, int j){
    if(b==1) return;
    if(puz[i][j]==0){
        for(int k=1; k<=9; k++){
            puz[i][j]=k;
            //cout << k << " check("<< i << ", " << j << "):" << check(i,j) << endl ; 
            if(check(i,j)){
                //cout  << i << ' ' << j << ' ' << k << '\n';
                //print();
                if(i==8 && j==8){
                    print();
                    return;
                }
                f(i+((j+1)/9), (j+1)%9);
            }
        }
        puz[i][j]=0;
    }
    else{
        if(check(i,j)==0) return;
        if(i==8 && j==8){
            print();
            return;
        }
        f(i+((j+1)/9), (j+1)%9);
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(s[i*9+j]=='.') puz[i][j]=0;
                else puz[i][j]=s[i*9+j]-'0';
            }
        }
        b=0;
        f(0,0);
        if(b==0) cout << "No solution.\n";
    }
    return 0;
}