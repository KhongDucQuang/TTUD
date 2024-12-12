#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int SUBSEQMAX(const vector<int> &arr){
    int max_current = arr[0];
    int max_global = arr[0];
    int n = arr.size();
    for(int i = 1; i < n; i++){
        max_current = max(arr[i], max_current + arr[i]);

        if(max_current > max_global && max_current % 2 == 0){
            max_global = max_current;
        }
    }
    return max_global;
}
int main(){
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        arr.push_back(k);
    }
    int max = SUBSEQMAX(arr);
    cout << max;
}