#include <iostream>
#include <climits>
#define MAX 100000

using namespace std;
int x[MAX];
int main(){
    int n; cin >> n;
    int ans = 0;
    cin >> x[0];
    for(int i = 1; i < n; i++){
        cin >> x[i];
        if(x[i] <= x[i-1]) ans++;
    }
    cout << ans + 1;
    return 0;
}