#include<stdio.h>

int main()
{
    double x[3],y[3],z[3],c[3],d,dx,dy,dz,valueX,valueY,valueZ;
    printf("Equation Format\n");
    printf("x1+y1+z1=c1\nx2+y2+z2=c2\nx3+y3+z3=c3\n");


    for(int i=0; i<3; i++)
    {
        printf("for equation %d\n",i+1);
        printf("Enter the value of x%d,y%d,z%d,c%d\n",i+1,i+1,i+1,i+1);
        scanf("%lf %lf %lf %lf",&x[i],&y[i],&z[i],&c[i]);
    }

    //using cramer's rule
    d = ( x[0]*( ( y[1]*z[2] )-( y[2]*z[1] ) ) ) - ( y[0]*( (x[1]*z[2] ) - ( x[2]*z[1] ) ) ) + ( z[0]*( (x[1]*y[2] ) - ( x[2]*y[1] ) ) );

    dx = ( c[0]*( ( y[1]*z[2] )-( y[2]*z[1] ) ) ) - ( y[0]*( (c[1]*z[2] ) - ( c[2]*z[1] ) ) ) + ( z[0]*( (c[1]*y[2] ) - ( c[2]*y[1] ) ) );

    dy = ( x[0]*( ( c[1]*z[2] )-( c[2]*z[1] ) ) ) - ( c[0]*( (x[1]*z[2] ) - ( x[2]*z[1] ) ) ) + ( z[0]*( (x[1]*c[2] ) - ( x[2]*c[1] ) ) );

    dz = ( x[0]*( ( y[1]*c[2] )-( y[2]*c[1] ) ) ) - ( y[0]*( (x[1]*c[2] ) - ( x[2]*c[1] ) ) ) + ( c[0]*( (x[1]*y[2] ) - ( x[2]*y[1] ) ) );


    valueX=dx/d;
    valueY=dy/d;
    valueZ=dz/d;

    printf("value of x,y,z are: %lf %lf %lf: ",valueX,valueY,valueZ);

    return 0;

}
