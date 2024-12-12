#include <iostream>
using namespace std;
const int MOD = 1000000007;
long long expMod(int a, int b){
    int result = 1;
    a = a % MOD;
    while (b > 0){
        if (b % 2 == 1) result = (result * a) % MOD;
        b = b / 2;
        a = (a * a) % MOD;
    }
    return result;
}