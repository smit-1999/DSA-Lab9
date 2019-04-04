#include <stdio.h>
#include <math.h>
int count = 0;

int max (int a, int b){
    if (a >= b) return a;
    else return b;
}

void calculate(double N){
    if (N == 1) {
        printf("%d\n", count + 1);
        return;
    }
    int a = sqrt(N);
    int b = 1;

    int n = N;
    while (n%a != 0){
        if (a == n) break;
        else a ++;
    }

    b = n/a;

    count ++;
    if (max(a,b) == n) calculate(n-1);
    else calculate(max(a,b));
}

int main(){
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++){
        double n;
        scanf("%lf", &n);
        count = 0;
        calculate(n);

    }
}

