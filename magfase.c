#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void)
{
    float p1r = 0.96;
    float p2r = 0.965;
    float p3r = 0.97;

    float r1, i1, r2, i2,r3,i3, A, B;
    float a1,a2,a3,b1,b2,b3;
    float r22, i22, r33, i33;
    float R, I;

    int N = 1000;
    double PI = 3.14159265358979323846;
    FILE * flee;
    FILE * flee2;
   flee = fopen ("fespec.dat", "w+");
    // if (flee = NULL)
    // {
    //     printf("Error opening file\n");
    //     exit(1);
    // }
    flee2 = fopen("fespec2.dat", "w+");
    // if (flee2 = NULL)
    // {
    //     printf("Error opening file\n");
    //     exit(1);
    // }
    int lng=2*N;
    a1=0.96*cos(86*PI/180);
    b1=0.96*sin(86*PI/180);
    a2=0.965*cos(94*PI/180);
    b2=0.965*sin(94*PI/180);
    a3=0.97*cos(90*PI/180);
    b3=0.97*sin(90*PI/180);
    float H[2000];
    float phi[2000];
    float dw = PI / N;
    for (int w = 0; w <= lng; w++)
    {
        R = 0;
        I = 0;
        A = cos(6 * w * dw);
        B = sin(6 * w * dw);
        r1 = cos(2 * w * dw) -2*a1*cos(w*dw)+a1*a1+b1*b1;
        i1 = sin(2 * w * dw)-2*a1*sin(w*dw);
        r2 = cos(2 * w * dw) -2*a2*cos(w*dw)+a2*a2+b2*b2;
        i2 = sin(2 * w * dw)-2*a2*sin(w*dw);
        r3 = cos(2 * w * dw) -2*a3*cos(w*dw)+a3*a3+b3*b3;
        i3 = sin(2 * w * dw)-2*a3*sin(w*dw);
        r22 = r1 * r2 - i1*i2;
        i22 = i1 * r2 + r1 * i2;
        r33 = r22 * r3 - i22 * i3;
        i33 = i22 * r3 + r22 * i3;
        R = (A * r33 + B * i33) / (r33*r33 + i33*i33);
        I = (-A * i33 + B * r33) / (r33*r33 + i33*i33);

        H[w] = sqrt(R * R + I * I);
        phi[w] = atan(I/R);
        fprintf(flee, "%6.6f \t %6.6f \n", w*dw,H[w]);
        fprintf(flee2, "%6.6f \t %6.6f \n", w*dw, phi[w]);
    }
    fclose(flee);
    fclose(flee2);
    // system("gnuplot -p 'grafgnuplot.gp' ");
}
