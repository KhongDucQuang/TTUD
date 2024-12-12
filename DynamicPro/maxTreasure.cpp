#include <bits/stdc++.h>
using namespace std;

struct Treasure {
    int x, y, c;
};

int main() {
    int n;
    cin >> n;
    vector<Treasure> treasures(n);

    for (int i = 0; i < n; ++i) {
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].c;
    }

    sort(treasures.begin(), treasures.end(), [](const Treasure& a, const Treasure& b) {
        return (a.x < b.x) || (a.x == b.x && a.y < b.y);
    });

    vector<long long> dp(n);

    long long maxGold = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = treasures[i].c; 
        for (int j = 0; j < i; ++j) {

            if (treasures[j].x <= treasures[i].x && treasures[j].y <= treasures[i].y) {
                dp[i] = max(dp[i], dp[j] + treasures[i].c);
            }
        }
        maxGold = max(maxGold, dp[i]);
    }

    cout << maxGold << endl;

    return 0;
}
