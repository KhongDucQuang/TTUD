#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    string cmd;
    while(true){
        cin >> cmd;
        if(cmd == "*") break;
        else if(cmd == "insert"){
            int k; 
            cin >> k;
            pq.push(k);
        } else if(cmd == "delete-max"){
            if(!pq.empty()){
                cout << pq.top() << endl;
                pq.pop();
            } else {
                cout << "ERROR!";
            }
        }
    }
    return 0;
}