#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
int n, k;
// Hàm tìm trung bình cộng lớn nhất
double findMax(const vector<int>& arr, int index, int curSum, int countSelected) {
    if (index == arr.size()) {
        // Nếu có ít nhất 1 phần tử được chọn, tính trung bình cộng
        if (countSelected != 0 && countSelected >= k) {
            return (double)curSum / countSelected;
        }
        return 0; // Không có phần tử nào được chọn
    }

    // Không chọn phần tử tại chỉ số `index`
    double exclude = findMax(arr, index + 1, curSum, countSelected);

    // Chọn phần tử tại chỉ số `index`
    double include = findMax(arr, index + 1, curSum + arr[index], countSelected + 1);

    // Trả về giá trị lớn nhất giữa hai nhánh
    return max(exclude, include);
}

int main() {
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Khởi tạo gọi hàm findMax với tham số ban đầu
    double result = findMax(arr, 0, 0, 0);

    // In ra kết quả với độ chính xác 6 chữ số thập phân
    cout << fixed << setprecision(6) << result << endl;

    return 0;
}
