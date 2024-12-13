#include <iostream>
#include <vector>
using namespace std;

long long countEvenSubarrays(const vector<int>& arr) {
    long long count = 0;

    // Số lượng tiền tố chẵn và lẻ
    int evenCount = 1; // Tổng trống ban đầu được coi là chẵn
    int oddCount = 0;
    int prefixSum = 0;

    for (int num : arr) {
        prefixSum += num;

        // Kiểm tra chẵn/lẻ của tổng tiền tố
        if (prefixSum % 2 == 0) {
            count += oddCount; // Cộng số lượng tiền tố chẵn trước đó
            evenCount++;
        } else {
            count += evenCount; // Cộng số lượng tiền tố lẻ trước đó
            oddCount++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << countEvenSubarrays(arr) << endl;
    return 0;
}
