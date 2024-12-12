#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, K, Q; // n: số lượng khách hàng, K: số lượng xe tải, Q: dung lượng xe tải
vector<int> d;  // Mảng yêu cầu của khách hàng
vector<vector<int>> c;  // Ma trận khoảng cách
vector<pair<int, int>> F;  // Danh sách các cặp khách hàng không thể phục vụ cùng nhau

// Hàm tính tổng quãng đường di chuyển của các xe tải
int calculateDistance(const vector<vector<int>>& routes) {
    int totalDistance = 0;
    for (const auto& route : routes) {
        int routeDistance = 0;
        for (int i = 0; i < route.size() - 1; ++i) {
            routeDistance += c[route[i]][route[i+1]];
        }
        routeDistance += c[route.back()][0];  // Trở lại depot
        totalDistance += routeDistance;
    }
    return totalDistance;
}

// Hàm kiểm tra nếu có xung đột giữa các khách hàng trong cùng một lộ trình
bool checkConflicts(const vector<vector<int>>& routes) {
    for (const auto& route : routes) {
        for (size_t i = 0; i < route.size(); ++i) {
            for (size_t j = i + 1; j < route.size(); ++j) {
                if (find(F.begin(), F.end(), make_pair(route[i], route[j])) != F.end() ||
                    find(F.begin(), F.end(), make_pair(route[j], route[i])) != F.end()) {
                    return true;  // Có xung đột
                }
            }
        }
    }
    return false;
}

// Hàm quay lui để thử phân chia khách hàng vào các xe tải
int solve(int truckCount, vector<vector<int>>& routes, vector<int>& routeLoads, vector<int>& clientAssignment) {
    if (truckCount == K) {  // Nếu đã phân chia hết khách hàng
        int distance = calculateDistance(routes);
        if (checkConflicts(routes)) {
            return -1;  // Có xung đột, trả về -1
        }
        return distance;
    }
    
    int minDistance = INT_MAX;
    
    // Thử phân chia khách hàng cho các xe tải
    for (int i = 0; i < n; ++i) {
        if (clientAssignment[i] == -1) {  // Nếu khách hàng chưa được phân công
            for (int truck = 0; truck < K; ++truck) {
                if (routeLoads[truck] + d[i] <= Q) {  // Nếu xe tải có thể nhận thêm khách hàng này
                    clientAssignment[i] = truck;
                    routes[truck].push_back(i);
                    routeLoads[truck] += d[i];
                    
                    // Tiếp tục phân chia cho khách hàng còn lại
                    int distance = solve(truckCount + (routeLoads[truck] == d[i]), routes, routeLoads, clientAssignment);
                    if (distance != -1) {
                        minDistance = min(minDistance, distance);
                    }
                    
                    // Quay lại trạng thái trước đó
                    routes[truck].pop_back();
                    routeLoads[truck] -= d[i];
                    clientAssignment[i] = -1;
                }
            }
        }
    }
    
    return minDistance;
}

int main() {
    cin >> n >> K >> Q;
    d.resize(n);
    c.resize(n + 1, vector<int>(n + 1));
    
    // Đọc yêu cầu của khách hàng
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    
    // Đọc ma trận khoảng cách
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> c[i][j];
        }
    }
    
    int M;
    cin >> M;
    F.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> F[i].first >> F[i].second;
    }
    
    vector<vector<int>> routes(K);  // Các lộ trình của các xe tải
    vector<int> routeLoads(K, 0);  // Tải của từng xe tải
    vector<int> clientAssignment(n, -1);  // Lưu trữ khách hàng đã được phân công cho xe tải nào
    
    int result = solve(0, routes, routeLoads, clientAssignment);
    
    cout << result << endl;
    return 0;
}
