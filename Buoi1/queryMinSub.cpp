#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int maxN = 1099;
vector<int> a

void build(){
    for(int i = 0; i < n; i++){
        segTree[i+n] = a[i];
    }
    for(int i = n - 1; i > 0; i--){
        segTree[i] = min(segTree[i * 2], segTree[i * 2 + 1]);
    }
}

int query(int l, int r){
    int res = INT_MAX;
    l += n; r += n;
    while(l < r){
        if(l&1) res = min(res, segTree[l++]);
        if(r&1) res = min(res, segTree[--r]);
        l >>= 1;
        r >>= 1;
    }
    return res;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    build();
    int m; cin >> m;
    int sum = 0;
    while(m > 0){
        int i, j; cin >> i >> j;
        sum += query(i, j);
        m--;
    }
    cout << sum;
    return 0;
}
