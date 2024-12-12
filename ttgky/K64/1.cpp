#include <iostream>
#define MAX 1000001
using namespace std;
int n;
int arr[MAX], s[MAX];

int maxLong(){
    s[1] = 1;
    int res = s[1];
    for(int i = 2; i <= n; i++){
        s[i] = 1;
        for(int j = 1; j <= i - 1; j++){
            if(arr[j] < arr[i]){
                if(s[i] < s[j] + 1){
                    s[i] = s[j] + 1;
                }
            }
        }
        if(res < s[i]) res = s[i];
    }
    return res;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cout << maxLong();
    return 0;
}