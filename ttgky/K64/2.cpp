#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

int n;

int res = 0;

void countEvenSub(const vector<int>& arr, int index, int curSum){
    if(index == arr.size()){
        if(curSum % 2 == 0){
            res++;
        }
    }

    countEvenSub(arr, index + 1, curSum);
    countEvenSub(arr, index + 1, curSum + arr[index]);
}

int main(){
    
}