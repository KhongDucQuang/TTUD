#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000007
using namespace std;

int n, Q;

int countSub3(const vector<int>&  arr){
    int res = 0;
    vector<int> copyArr = arr;
    sort(copyArr.begin(), copyArr.end());

    for(int i = 0; i < n - 2; i++){
        
        int left = i + 1;
        int right = n - 1;
        while(left < right){
            int curSum = copyArr[i] + copyArr[left] + copyArr[right];
            if(curSum == Q){
                res = (res + 1) % MOD;
                left++;
                right--;
            } else if (curSum < Q){
                left++;
            } else {
                right--;
            }
        } 
    }

    return res;
}

int main(){
    cin >> n >> Q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << countSub3(arr);
    return 0;
}