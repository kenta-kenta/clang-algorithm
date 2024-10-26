//1
#include<stdio.h>

int main(void) {
    double x, g, t;
    g = 9.8;
    for (double k = 0; k <= 50; k++) {
        t = k / 10;
        x = 0.5 * g * t * t;
        printf("%3.1f %7.3f\n", t, x);
    }

}

void matmul(int a[3][3], int b[3][3], int c[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = (a[i][0] * b[0][j])
                        + (a[i][1] * b[1][j])
                        + (a[i][2] * b[2][j]);
        }
    }
};

void primes(int n){
    for (int i = 2; i < n; i++) {
        int k = 0;
        for (int j = 2; j < i; j++) {
            if (i % j == 0){
                k = 1;
            }
        }
        if(k == 0) {
            printf("%d\n", i);
        }
    }
};