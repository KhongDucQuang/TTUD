#include <iostream>
#include <stack>
#include <vector>
using namespace std;

long long largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    heights.push_back(0); // Thêm 1 cột 0 vào cuối để đảm bảo tính hết tất cả các hình chữ nhật
    long long maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i < n; ++i) {
        // Nếu cột hiện tại nhỏ hơn cột ở đỉnh stack, ta tính diện tích
        while (!s.empty() && heights[s.top()] > heights[i]) {
            int h = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : (i - s.top() - 1);
            maxArea = max(maxArea, (long long)h * width);
        }
        s.push(i);
    }
    return maxArea;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break; // Kết thúc khi gặp số 0

        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }

        cout << largestRectangleArea(heights) << endl;
    }
    return 0;
}
