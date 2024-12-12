#include <iostream>
#include <vector>
#include <climits>
/*
Để tìm kiếm chồng là một anh chàng khoa học máy tính, công chúa của một đất nước ra một đề toán như sau:
Cho n số nguyên, hãy chọn một tập con của tập n số nguyên này sao cho tổng của các số nguyên được chọn
không vượt qua M cho trước và hiệu giữa M và tổng của những số nguyên được chọn là nhỏ nhất.
Đầu vào
· Dòng 1: Số nguyên n (1 <= n <= 20)
· Dòng 2: n số nguyên cách nhau bởi dấu cách, giá trị của các số nguyên này nằm từ 1 tới 1000
· Dòng 3: Số nguyên M (1 <= M <= 100000)
Đầu ra
· Một số tự nhiên là hiệu của M và tổng của các số nguyên được chọn nhỏ nhất.
*/
using namespace std;

int n, M;
vector<int> numbers;
int best = INT_MAX;

void branch_and_bound(int index, int curSum) {
    if (index == n) {
        if (curSum <= M) {
            best = min(best, M - curSum);
        }
        return;
    }

    branch_and_bound(index + 1, curSum);

    if (curSum + numbers[index] <= M) {
        branch_and_bound(index + 1, curSum + numbers[index]);
    }
}

int main() {
    cin >> n;
    numbers.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    cin >> M;

    branch_and_bound(0, 0);

    cout << best << endl;

    return 0;
}
