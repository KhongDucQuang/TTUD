#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define MAX 100000
int c[MAX];
int main(){
    int n; cin >> n;
    stack<int> chuong;
    int k;
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    for(int i = n - 1; i >= 0; i--){
        chuong.push(c[i]);
    }
    string s; cin >> s;
    queue<int> hanhlang;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'C'){
            if(chuong.empty()) continue;
            hanhlang.push(chuong.top());
            chuong.pop();
        } else {
            if(hanhlang.empty()) continue;
            chuong.push(hanhlang.front());
            hanhlang.pop();
        }
    }
    while(!chuong.empty()){
        cout << chuong.top() << " ";
        chuong.pop();
    }
    return 0;
}