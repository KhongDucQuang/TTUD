#include <iostream>
#include <climits>
#define MAX 1000000
using namespace std;

long long arr[MAX], n;

void findMax() {
    long long best = LONG_LONG_MIN, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        
        // Nếu tổng là số chẵn, cập nhật `best`
        if (sum % 2 == 0) {
            best = max(best, sum);
        }
        
        // Nếu tổng hiện tại âm, đặt lại tổng về 0
        if (sum < 0) {
            sum = 0;
        }
    }

    // In kết quả
    if (best == INT_MIN) {
        cout << "NOT_FOUND\n";
    } else {
        cout << best << "\n";
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    findMax();
}
