#include <bits/stdc++.h>
#define MAX_N 100
#define MAX_M 30
using namespace std;
// input data structures
int N;// number of course
int M;// number of teachers
int sz[MAX_N];// sz[c] is the number of possible teachers for course c
int t[MAX_N][MAX_M];// t[c][i]: the ith teacher that can teach course c
int h[MAX_N];// h[c] is the number of hours of course c each week
int A[MAX_N][MAX_N];// A[i][j] = 1 indicates that course i and j are
int f[MAX_M];
int cnt; // number of solutions;
// variables
int X[MAX_N];
void input(){
cin >> N >> M;
for(int i = 1; i <= N; i++)
cin >> h[i];
for(int i = 1; i <= N; i++){
    cin >> sz[i];
    for(int j = 0; j < sz[i]; j++)
        cin >> t[i][j];

}
for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++)
        cin >> A[i][j];
}
}
int check(int v, int k){
    for(int i = 1; i <= k-1; i++){
        if(A[i][k] && v == X[i]) return 0;
    }
    return 1;
}
void solution(){
    cnt++;
}
void TRY(int k){
    for(int i = 0; i < sz[k]; i++){
        int v = t[k][i];
        if(check(v,k)){
            X[k] = v;
            f[v] += h[k];
            if(k == N){
                solution();
            } else {
                TRY(k+1);
            }
            f[v] -= h[k];
        }
    }
}
void solve(){
    for(int i = 1; i <= M; i++) f[i] = 0;
        cnt = 0;
    TRY(1);
}
int main(){
    input();
    solve();    
    cout << cnt;
}