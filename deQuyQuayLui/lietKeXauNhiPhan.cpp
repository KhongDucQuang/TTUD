#include <iostream>
using namespace std;
#define MAX 100

int n;
int arr[MAX];


void solution(){
    for(int i = 1; i <= n; i++){
        cout << arr[i];
    }
    cout << endl;
}

bool check(int v, int k){
    if(v == 1 && arr[k-1] == 1) return false;
    if(v == 0 && arr[k-1] == 0) return false;
    return true;
}

void TRY(int k){
    for(int v = 0; v <= 1; v++){
        if(check(v, k)){
            arr[k] = v;
            if(k == n) solution();
            else TRY(k+1);
        }
    }
}

int main(){
    cin >> n;
    arr[0] = 3;
    TRY(1);
    return 0;
}