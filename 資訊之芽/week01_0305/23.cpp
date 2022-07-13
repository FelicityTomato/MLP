#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int N, int order[]){
    stack<int> s1,s2;
    int j=1;
    set<int> st1,st2;
    for(int i=0; i<N; i++){
        if(st1.find(order[i])!=st1.end()){
            while(s1.top()!=order[i]){
                st1.erase(s1.top());
                st2.insert(s1.top());
                s2.push(s1.top());
                s1.pop();
                move_station_1_to_2();
            }
            st1.erase(s1.top());
            s1.pop();
            move_station_1_to_2();
            pop_train();
        }
        else if(st2.find(order[i])!=st2.end()){
            while(s2.top()!=order[i]){
                st2.erase(s2.top());
                st1.insert(s2.top());
                s1.push(s2.top());
                s2.pop();
                move_station_2_to_1();
            }
            st2.erase(s2.top());
            s2.pop();
            pop_train();
        }
        else{
            while(j!=order[i]){
                st1.insert(j);
                s1.push(j);
                j++;
                push_train();
            }
            push_train();
            move_station_1_to_2();
            pop_train();
            j++;
        }
    }
}