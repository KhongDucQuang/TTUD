#include <iostream>
using namespace std;
const int MOD = 1000000000 + 7;

int main(){
    int n; cin >> n;
    int res;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        res = (res + k % MOD) % MOD;
    }
    cout << res << endl;
    cout << MOD;
}