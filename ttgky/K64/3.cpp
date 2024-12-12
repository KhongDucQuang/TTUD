#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int M;
    cin >> M;

    unordered_set<string> dictionary;
    for (int i = 0; i < M; i++) {
        string word;
        cin >> word;
        dictionary.insert(word);
    }

    int count = 0;

    // Duyệt qua từng hàng trong bảng
    for (const string& row : board) {
        int rowLeng = row.size();
        // Liệt kê tất cả các dãy con liên tiếp
        for (int start = 0; start < rowLeng; start++) {
            string sub = "";
            for (int end = start; end < rowLeng; end++) {
                sub += row[end];
                // Kiểm tra xem dãy con có trong tập D không
                if (dictionary.find(sub) != dictionary.end()) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
