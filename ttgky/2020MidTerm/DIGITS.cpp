#include <iostream>
using namespace std;
int x[7];
int visited[10];
int T, n, ans;
void solution(){
    int HUST = x[0] * 1000 + x[1] * 100 + x[2] * 10 + x[3];
    int SOICT = x[2] * 10000 + x[4] * 1000 + x[5] * 100 + x[6] * 10 + x[3];
    if(HUST + SOICT == n){
        ans++;
    }
}

bool check(int v, int k){
    if(k == 0 && v == 0) return false;
    if(k == 2 && v == 0) return false;
    if(visited[v]) return false;
    return true;
}

void TRY(int k){
    for(int v = 0; v <= 9; v++){
        if(check(v, k)){
            x[k] = v;
            visited[v] = 1;
            if(k == 6){
                solution();
            } else {
                TRY(k+1);
            }
            visited[v] = 0;
        }
    }
}

int main(){
    cin >> T;
    while (T--) {
        cin >> n;
        ans = 0;

        for (int i = 0; i < 10; i++) {
            visited[i] = false;
        }

        TRY(0);
        
        cout << ans << endl;
    }
    return 0;
}