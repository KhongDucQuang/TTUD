

#include <iostream>
#include <climits>
#include <vector> 
#include <cmath>
using namespace std;
int n;
int M[100][1000000];
int a[1000000];
void processing(){
    for(int i = 0; i < n; i++){
        M[0][i] = i;
    }
    for(int j = 1; (1 << j) <= n; j++){
        for(int i = 0; i + (1 << j) - 1 < n; i++){
            if(a[M[j-1][i]] < a[M[j-1][i + (1 << (j-1))]]){
                M[j][i] = M[j-1][i];
            } else {
                M[j][i] = M[j-1][i+(1 << (j-1))];
            }
        }
    }
}
int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
    
    processing();
    
    int K; cin >> K;
    
    long long sum = 0;
    while(K > 0){
        int i, j; cin >> i >> j;
        int k = log2(j - i + 1);
        int min;
        if(a[M[k][i]] <= a[M[k][j - (1 << k) + 1]]){
            min = M[k][i];
        } else {
            min = M[k][j - (1 << k) + 1];
        }
        sum += a[min];
        K--;
    }
    cout << sum;
    return 0;
}
