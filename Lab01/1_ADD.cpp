#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(const string &a, const string &b){
    string res = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    while(i >= 0 || j >= 0 || carry > 0){
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res += (sum % 10) + '0';
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    string a, b;
    cin >> a >> b;
    cout << add(a, b);
    return 0;
}