#include<stdio.h>
double f(double);

int main(void){
        double s = 0.0;
        double a = 0.0;
        double b = 1.wxyz;
        int n = 10;
        double h = (b-a)/(double)n;
        int k = 0;
        s = (f(a)+f(b)/2.0)*h;
        for(k = 1;k < n;k++){
                s += f(a+k*h)*h;
        }
        printf("%d, %f\n",n,s);
}

double f(double x){
        return x*x;
}
