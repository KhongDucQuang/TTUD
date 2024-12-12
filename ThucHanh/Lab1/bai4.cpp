#include <iostream>
#include <stack>
#include <vector>
#include <climits>
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
long long findMaxRectangle(vector<vector<int>> matrix){
    int maxValue = INT_MIN;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(i == 0) matrix[i][j] = matrix[i][j];
            else{
                if(matrix[i][j] == 1) matrix[i][j] += matrix[i-1][j];
            }
        }
        long long res = largestRectangleArea(matrix[i]);
        if(res > maxValue) maxValue = res;
    }
    return maxValue;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    cout << findMaxRectangle(matrix);
    return 0;
}
