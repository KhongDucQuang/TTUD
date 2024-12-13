#include <iostream>
#include <vector>

using namespace std;

int n, M, k;

int countSub(const vector<int>& arr){
    int count = 0;
    int curSum = 0;
    int left = 0, right  = k - 1;
    for(int i = left; i <= right; i++){
        curSum += arr[i];
    }
    if(curSum == M) count++;
    
    while(right <= n - 1){
        curSum -= arr[left++];
        curSum += arr[++right];
        if(curSum == M) count++;
    }
    return count;
}

int main(){
    cin >> n >> k >> M;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << countSub(arr);
    return 0;
}