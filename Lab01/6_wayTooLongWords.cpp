#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    while (n > 0){
        string s; cin >> s;
        int length = s.length();
        if(length < 10){
            cout << s << endl;
            continue;
        }
        cout << s[0] << length - 2 << s[length - 1] << endl;
    }
    return 0;
}