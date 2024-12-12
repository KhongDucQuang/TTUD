#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int maxN = 1099;
const int oo = 1e9 + 7;
int a[maxN][maxN], m, n, r, c, d[maxN][maxN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pii> q;

int solve(){
    q.push(pii(r, c)); d[r][c] = 0; a[r][c] = 0;
    while(!q.empty()){
        pii u = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int x = u.first + dx[i];
            int y = u.second + dy[i];
            if(x < 1 || x > m || y < 1 || y > n) return d[u.first][u.second] + 1;
            if(a[x][y] != 1){
                q.push(pii(x, y));
                d[x][y] = d[u.first][u.second] + 1;
                a[x][y] = 1;
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> r >> c;
    for(int  i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int ans = solve();
    cout << ans;
    return 0;
}
