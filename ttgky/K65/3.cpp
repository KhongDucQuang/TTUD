#include <iostream>
#include <vector>
using namespace std;

int n, A, B;

int countSub(const vector<int>& arr, int index, int curSum){
    if(index == arr.size()){
        if(curSum >= A && curSum <= B) return 1;
        else return 0;
    }

    int exclude = countSub(arr, index + 1, curSum);
    int include = countSub(arr, index + 1, curSum + arr[index]);

    return exclude + include;
}

int main(){
    cin >> n >> A >> B;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << countSub(arr, 0, 0);
    return 0;
}