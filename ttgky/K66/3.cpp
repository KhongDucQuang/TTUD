#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Treasure {
    int x, y, gold;
};

void updateFenwick(vector<long long>& fenwick, int idx, long long value) {
    while (idx < fenwick.size()) {
        fenwick[idx] = max(fenwick[idx], value);
        idx += idx & -idx;
    }
}

long long queryFenwick(const vector<long long>& fenwick, int idx) {
    long long maxValue = 0;
    while (idx > 0) {
        maxValue = max(maxValue, fenwick[idx]);
        idx -= idx & -idx;
    }
    return maxValue;
}

int main() {
    int n;
    cin >> n;

    vector<Treasure> treasures(n);
    vector<int> ys;

    for (int i = 0; i < n; i++) {
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].gold;
        ys.push_back(treasures[i].y);
    }

    // Nén tọa độ y để sử dụng Fenwick Tree
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    auto getCompressedY = [&](int y) {
        return lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1;
    };

    // Sắp xếp các kho báu theo x tăng dần, nếu x bằng thì y tăng dần
    sort(treasures.begin(), treasures.end(), [](const Treasure& a, const Treasure& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    // Fenwick Tree để lưu giá trị dp lớn nhất
    vector<long long> fenwick(ys.size() + 1, 0);

    long long maxGold = 0;

    for (const auto& treasure : treasures) {
        // Lấy chỉ số y đã nén
        int compressedY = getCompressedY(treasure.y);

        // Truy vấn giá trị dp lớn nhất ở các kho báu trước đó
        long long bestPrevious = queryFenwick(fenwick, compressedY);

        // Cập nhật dp cho kho báu hiện tại
        long long currentGold = bestPrevious + treasure.gold;

        // Cập nhật Fenwick Tree với giá trị mới
        updateFenwick(fenwick, compressedY, currentGold);

        // Cập nhật kết quả tổng lớn nhất
        maxGold = max(maxGold, currentGold);
    }

    cout << maxGold << endl;

    return 0;
}
