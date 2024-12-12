#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 20;
int n, K;                         
int dist[2 * MAX + 1][2 * MAX + 1]; 
int load = 0;                      
int f = 0, f_best = INT_MAX;      
int Cmin = INT_MAX;                
int X[2 * MAX + 1];                
bool visited[2 * MAX + 1];         

bool check(int v, int k) {
    if (visited[v]) return false;
    if (v > n && !visited[v - n]) return false;  
    if (v <= n && load + 1 > K) return false;   
    return true;
}

void updateBest() {
    if (f + dist[X[2 * n]][0] < f_best) {
        f_best = f + dist[X[2 * n]][0];  
    }
}

void tryRoute(int k) {
    for (int v = 1; v <= 2 * n; v++) {
        if (check(v, k)) {
            X[k] = v;
            f += dist[X[k - 1]][X[k]];
            visited[v] = true;

            if (v <= n) load++;  
            else load--;         

            if (k == 2 * n) {
                updateBest(); 
            } else {
                if (f + Cmin * (2 * n + 1 - k) < f_best) {
                    tryRoute(k + 1); 
                }
            }

            if (v <= n) load--;  
            else load++;         

            f -= dist[X[k - 1]][X[k]];
            visited[v] = false;
        }
    }
}

int main() {
    cin >> n;
    cin >> K;
    
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> dist[i][j];
            if (i != j) {
                Cmin = min(Cmin, dist[i][j]);
            }
        }
    }

    for (int i = 0; i <= 2 * n; i++) {
        visited[i] = false;
    }

    X[0] = 0;
    visited[0] = true;

    tryRoute(1);

    cout << f_best << endl;

    return 0;
}
