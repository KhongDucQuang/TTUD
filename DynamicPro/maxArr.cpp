#include <iostream>
#include <climits>
#define MAX 100
using namespace std;

int n; 
int arr[MAX], s[MAX];

int findMaxArr(){
    s[1] = arr[1];
    int res = s[1];
    for(int i = 2; i <= n; i++){
        if(s[i-1] > 0){
            s[i] = s[i-1] + arr[i];
        } else {
            s[i] = arr[i];
        }
        if(s[i] > res) res = s[i];
    }
    return res;
}

int main(){
    cin >> n; 
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cout << findMaxArr();
    return 0;
}