#include <iostream>
#define MAX 100
using namespace std;

int n, m;
int arr[MAX];
int T;

void solution(){
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool check(int v, int k){
    if(k < n) return true;
    return T + v == m;
}

void TRY(int k){
    for(int v = 1; v <= m - T - n + k; v++){
        if(check(v, k)){
            arr[k] = v;
            T = T + arr[k];
            if(k == n) solution();
            else TRY(k+1);
            T = T - arr[k];
        }
    }
}

int main(){
    cin >> n >> m;
    T = 0;
    TRY(1);
    return 0;
}