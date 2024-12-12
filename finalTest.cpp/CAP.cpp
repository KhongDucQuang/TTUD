#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    int T; cin >> T;
    while(T--){
        int n, m;
        cin >> n;
        int k;
        unordered_map<int, bool> mark;
        for(int i = 0; i < n; i++){
            cin >> k;
            if(mark[k]) continue;
            else mark[k] = true;
        }
        cin >> m;
        int count = 0;
        for(int i = 0; i < m; i++){
            cin >> k;
            if(!mark[k]) continue;
            else count++;
        }
        cout << count << endl;
    }
    return 0;
}