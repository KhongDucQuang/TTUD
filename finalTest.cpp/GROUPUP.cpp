#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<int> arr;
        int k;
        for(int i = 0; i < n; i++){
            cin >> k;
            arr.push_back(k);
        }
        k = n;
        int sumTime = 0;

        while(true){
            int maxTime = INT_MIN;
            if(k <= 1) break;
            
            if(k&1){
                int tmp = arr[k-1];
                for(int i = 0, j = 0, p = 1; p < k - 1; i++, p+=2){
                    arr[i] = arr[j] + arr[p];
                    if(arr[i] > maxTime) maxTime = arr[i];
                    j = p + 1;
                }
                arr[k / 2] = tmp; 
            } else {
                for(int i = 0, j = 0, p = 1; p < k; i++, p+=2){
                    arr[i] = arr[j] + arr[p];
                    if(arr[i] > maxTime) maxTime = arr[i];
                    j = p + 1;
                }
            }
            sumTime += maxTime;
            k = static_cast<int>(ceil(k / 2.0));
        }
        cout << sumTime << endl;
    }
    return 0;
}