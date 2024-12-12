#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMaxAverageSubsequence(const vector<int>& arr, int k) {
    int n = arr.size();
    double maxAvg = -1e9;
    for (int i = 0; i <= n - k; ++i) {
        int sum = 0;

        for (int j = i; j < n; ++j) {
            sum += arr[j];

            if (j - i + 1 >= k) {
                double avg = sum * 1.0 / (j - i + 1);
                maxAvg = max(maxAvg, avg);
            }
        }
    }
    
    return maxAvg;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << findMaxAverageSubsequence(arr, k) << endl;
    
    return 0;
}
