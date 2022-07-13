#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct str{
    int num;
    char ty;
    char up;
    char down;
};

bool cmp(str a, str b){
    if(a.ty==b.ty) return a.num<b.num;
    else return a.ty<b.ty;
}

vector<str> v;
vector<str> l;

void output(){
    sort(v.begin(),v.end(),cmp);
    for(int i=0; i<13; i++){
        if(v[i].num!=100) cout << v[i].num;
    }
    for(int i=l.size()-1; i>=0; i--) cout << l[i].up;
    cout << '\n';
    for(int i=0; i<13; i++){
        if(v[i].num!=100) cout << v[i].ty;
    }
    for(int i=l.size()-1; i>=0; i--) cout << l[i].down;
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int w; cin >> w;
    while(w--){
        l.clear();
        v.resize(13);
        for(int i=0; i<13; i++){
            string s;
            cin >> s;
            v[i].num=s[0]-'0';
            v[i].ty=s[1];
        }
        output();
        int q; cin >> q;
        for(int i=0; i<q; i++){
            string a,b,c,d;
            cin >> a >> b >> c >> d;
            if(a=="insert"){
                for(int i=0; i<13; i++){
                    if(v[i].num==d[0]-'0' && v[i].ty==d[1]){
                        v[i].num=b[0]-'0';
                        v[i].ty=b[1];
                        break;
                    }
                }
            }
            else if(a=="pon"){
                string e,f;
                cin >> e >> f;
                for(int i=0; i<13; i++){
                    if(v[i].num==f[0]-'0'&& v[i].ty==f[1]){
                        v[i].num=100;
                        break;
                    }
                }
                int x=0;
                for(int i=0; i<13; i++){
                    if(v[i].num==b[0]-'0' && v[i].ty==b[1]){
                        v[i].num=100;
                        x++;
                    }
                    if(x==2) break;
                }
                if(d=="left"){
                    str t;
                    t.up=b[0]; t.down=b[1];
                    l.push_back(t); l.push_back(t);
                    t.up='.'; t.down=b[1];
                    l.push_back(t);
                    t.down=b[0];
                    l.push_back(t);
                }
                else if(d=="opposite"){
                    str t;
                    t.up=b[0]; t.down=b[1];
                    l.push_back(t);
                    t.up='.'; t.down=b[1];
                    l.push_back(t);
                    t.down=b[0];
                    l.push_back(t);
                    t.up=b[0]; t.down=b[1];
                    l.push_back(t);
                }
                else{
                    str t;
                    t.up='.'; t.down=b[1];
                    l.push_back(t);
                    t.down=b[0];
                    l.push_back(t);
                    t.up=b[0]; t.down=b[1];
                    l.push_back(t); l.push_back(t);
                }
            }
            else{
                string e,f,g,h;
                cin >> e >> f >> g >> h;
                for(int i=0; i<13; i++){
                    if(v[i].num==d[0]-'0'&& v[i].ty==d[1]){
                        v[i].num=100;
                        break;
                    }
                }
                for(int i=0; i<13; i++){
                    if(v[i].num==f[0]-'0'&& v[i].ty==f[1]){
                        v[i].num=100;
                        break;
                    }
                }
                for(int i=0; i<13; i++){
                    if(v[i].num==h[0]-'0'&& v[i].ty==h[1]){
                        v[i].num=100;
                        break;
                    }
                }
                if(d[0]>f[0]) swap(d,f);
                str t;
                t.up=f[0]; t.down=f[1];
                l.push_back(t);
                t.up=d[0];
                l.push_back(t);
                t.up='.';
                l.push_back(t);
                t.down=b[0];
                l.push_back(t);

            }
            output();
        }
    }
    return 0;
}