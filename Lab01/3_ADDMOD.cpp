#include <iostream>
const int MOD = 1000000007;
using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;
    cout << (a % MOD + b % MOD) % MOD;
}