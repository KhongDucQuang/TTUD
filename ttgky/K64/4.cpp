#include <iostream>
#include <vector>

using namespace std;
int n, target;

int countRes(const vector<int>& arr, int index, int curSum){
    if(index == arr.size()){
        if(curSum == target){
            return 1; 
        }
        return 0;
    }
    int exclude = countRes(arr, index + 1, curSum + arr[index]);
    int include = countRes(arr, index + 1, curSum - arr[index]);

    return exclude + include;
}

int main(){
    cin >> n >> target;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << countRes(arr, 1, arr[0]);
    return 0;
}

