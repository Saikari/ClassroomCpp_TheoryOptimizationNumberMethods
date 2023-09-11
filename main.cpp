#include <iostream>
#include <cmath>

long double finddeterminant(const long double * a, const long double * b, const long double * c)
{
    return *b * *b - 4.0L * *a * *c;
}
long double fx(const long double * a, const long double * b, const long double * c, const long double * x)
{
    return *a * *x * *x + *b * *x + *c;
}
long double xadd(const long double * a, const long double * b, const long double * determinant)
{
    return (-*b + sqrtl(*determinant)) / (2.0L * *a);
}
long double xsub(const long double * a, const long double * b, const long double * determinant)
{
    return (-*b - sqrtl(*determinant)) / (2.0L * *a);
}
long double sign(const long double * value)
{
    return *value < 0.0L ? -1.0L : 1.0L;
}
long double finx1(const long double * a, const long double * b, const long double * determinant)
{
    return - (*b + sign(&*b) * sqrtl(*determinant)) / (2.0L * *a);
}
long double finx2(const long double * a, const long double * c, const long double * x1)
{
    return *c / (*a * *x1);
}
void calculate(const long double * a, const long double * b, const long double * c)
{
    long double determinant = finddeterminant(&*a, &*b, &*c);
    long double * x = new long double[2];
    std::cout << "Корни квадратного уравнения :" << std::endl;
    if (*a != 0.0L)
    {
        x[0] = finx1(&*a, &*b, &determinant);
        x[1] = finx2(&*a, &*c, &x[0]);
        std::cout << "x[1]="<< std::fixed << x[0] << "\t" << "x[2]="<< x[1] << std::endl;
        std::cout << "f(x[1])=" << fx(&*a, &*b, &*c, &x[0]) << "\t" << "f(x[2])="<< fx(&*a, &*b, &*c, &x[1]);
    }
    std::cout << std::endl;
    delete[] x;
}
int main() {
    std::cout.precision(11);
    long double a, b, c;
    std::cout << "Случай 1:" << std::endl;
    a = 1.0L;
    b = std::pow(-10.0L,5.0L);
    c = 1.0L;
    calculate(&a, &b, &c);
   std::cout << "Случай 2:" << std::endl;
    a = 6.0L;
    b = 5.0L;
    c = -4.0L;
    calculate(&a, &b, &c);
    std::cout << "Случай 3:" << std::endl;
    a = 6.0L * pow(10.0L,30.0L);
    b = 5.0L * pow(10.0L,30.0L);
    c = -4.0L * pow(10.0L,30.0L);
    calculate(&a, &b, &c);
    std::cout << "Случай 4:" << std::endl;
    a = pow(10.0L,-30.0L);
    b = pow(-10.0L,30.0L);
    c = pow(10.0L,30.0L);
    calculate(&a, &b, &c);
    std::cout << "Случай 5:" << std::endl;
    a = 1.0000000L;
    b = -4.0000000L;
    c = 3.9999999L;
    calculate(&a, &b, &c);
    return 0;
}
