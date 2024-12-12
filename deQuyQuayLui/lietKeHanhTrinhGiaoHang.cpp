#include <iostream>
#define MAX 100
using namespace std;

int n;
int path[MAX], visited[MAX];

void solution(){
    for(int i = 1; i <= n; i++){
        cout << path[i] << " ";
    }
    cout << endl;
}

bool check(int v, int k){
    return visited[v];
}

void TRY(int k){
    for(int v = 1; v <= n; v++){
        if(!check(v, k)){
            path[k] = v;
            visited[v] = 1;
            if(k == n) solution();
            else TRY(k+1);
            visited[v] = 0;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        visited[i] = 0;
    }
    TRY(1);
    return 0;
}