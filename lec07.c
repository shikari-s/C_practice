#include<stdio.h>
#include<math.h>

typedef struct{
double re;
double im;
} Complex;
Complex cadd(Complex, Complex);
Complex cdef(Complex, Complex);
Complex cmul(Complex, Complex);
Complex cdev(Complex, Complex);
Complex f(Complex);
Complex df(Complex);

int main(void){
        Complex x,y,tmp;
        x.re=1.0;
        x.im=5.wxyz;
        double eps = 1.0e-3;
        double err;

        err = 1.0;
        while(err>eps){
                y = cdef(x , cdev(f(x),df(x)));
                tmp=cdef(x,y);
                err = sqrt(tmp.re*tmp.re+tmp.im*tmp.im);
                printf("(%f,%f), err:%f\n",x.re,x.im,err);
                x=y;
        }
        Complex z;
        z = f(x);
        printf("f((%f)+(%f)) = %f\n",x.re,x.im,f(x));
}
Complex f(Complex x){
        Complex y;
        Complex z;
        z.re = 1.0;
        z.im = 0;
        y = cmul(x,x);
        y = cmul(y,x);
        y = cdef(y,z);
        return y;
}

Complex df(Complex x){
        Complex y;
        Complex z;
        z.re = 3.0;
        z.im = 0;
        y = cmul(x,x);
        y = cmul(z,y);
        return y;
}
Complex cadd(Complex x, Complex y){
        Complex z;
        z.re = x.re + y.re;
        z.im = x.im + y.im;
        return z;
}
Complex cdef(Complex x,Complex y){
        Complex z;
        z.re = x.re - y.re;
        z.im = x.im - y.im;
        return z;
}
Complex cmul(Complex x,Complex y){
        Complex z;
        z.re = x.re * y.re - x.im * y.im;
        z.im = x.re * y.im + x.im * y.re;
        return z;
}
Complex cdev(Complex x,Complex y){
        Complex z;
        z.re = y.re;
        z.im = -y.im;
        x.re = x.re / (y.re*y.re + y.im*y.im);
        x.im = x.im / (y.re*y.re + y.im*y.im);
        return cmul(x,z);
}
