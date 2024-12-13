#include <iostream>
#include <vector>
#include <algorithm>

int maxSubsetSum(const std::vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    // Quy hoạch động: dp[i] là tổng lớn nhất của tập con kết thúc tại i
    std::vector<int> dp(n, 0);
    dp[0] = std::max(0, arr[0]);

    for (int i = 1; i < n; ++i) {
        dp[i] = std::max(dp[i - 1], dp[i - 1] + arr[i]);
    }

    return dp[n - 1];
}

int main() {
    std::vector<int> arr = {1, 2, 3, -1, 4}; 
 
    std::cout << "Tổng lớn nhất của tập con là: " << maxSubsetSum(arr) << std::endl;

    return 0;
}
