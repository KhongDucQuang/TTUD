/*
Description
Given a material having the shape rectangle with height H and width W.
We need to cut this material into n smaller rectangle submaterials of
size (h1,w1), (h2, w2), ..., (hn, wn). Write a program to check if we can perform this cut.
Input
Line 1: contains two positive integers H, W (1 <= H, W <= 10)
Line 2: contains a positive integer n (1 <= n <= 10)
Line i+2 (i= 1,...,n): contains two positive integer hi and wi (1 <= hi, wi <= 10)
Output
Write 1 if we can perform the cut and write 0, otherwise.
*/
#include <iostream>
#include <vector>

using namespace std;

const int MAX_W = 10;  
const int MAX_H = 10;

int W, H, n;
int w[MAX_W], h[MAX_H];  
int x[MAX_W], y[MAX_H], o[MAX_H];  
bool mark[MAX_H][MAX_W];  

bool check(int vo, int vx, int vy, int k) {
    int wk = w[k], hk = h[k];
    if (vo == 1) {
        swap(wk, hk);  
    }

    if (vx + wk > W || vy + hk > H) {
        return false;
    }

    for (int i = vx; i < vx + wk; i++) {
        for (int j = vy; j < vy + hk; j++) {
            if (mark[j][i]) {
                return false;  
            }
        }
    }
    return true;  
}

void doMark(int vo, int vx, int vy, int k, bool value) {
    int wk = w[k], hk = h[k];
    if (vo == 1) {
        swap(wk, hk);  
    }
    for (int i = vx; i < vx + wk; i++) {
        for (int j = vy; j < vy + hk; j++) {
            mark[j][i] = value;
        }
    }
}

bool Try(int k) {
    if (k == n) { 
        return true; 
    }

    for (int vo = 0; vo < 2; vo++) {  
        for (int vx = 0; vx <= W - 1; vx++) {  
            for (int vy = 0; vy <= H - 1; vy++) {  
                if (check(vo, vx, vy, k)) {  
                    x[k] = vx; y[k] = vy; o[k] = vo;  
                    doMark(vo, vx, vy, k, true);  
                    if (Try(k + 1)) { 
                        return true;
                    }
                    doMark(vo, vx, vy, k, false);
                }
            }
        }
    }
    return false; 
}

int main() {
    cin >> H >> W;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i] >> w[i];
    }

    if (Try(0)) {
        cout << 1;  
    } else {
        cout << 0;  
    }

    return 0;
}
