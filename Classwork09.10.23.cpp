#include <iostream>
#include <cmath>
#include <memory>

std::unique_ptr<double> fun(const std::unique_ptr<double>& x)
{
  return std::make_unique<double>(sin(*x));
}

std::unique_ptr<double> prFun(const std::unique_ptr<double>& x)
{
  return std::make_unique<double>(cos(*x));
}

double N = 15;

double MethodNewton(double x)
{
    double xn = x;
    double xn1 = 0;
    for (int i = 0; i < N; ++i)
    { 
        std::unique_ptr<double> pr = prFun(std::make_unique<double>(xn));
        if (std::abs(*pr) <= 1.e-6)
        {
            std::cout << "Ошибка деление на нуль" << std::endl;
            return 0.0;
        }
        xn1 = xn - *fun(std::make_unique<double>(xn)) / *pr;
        xn = xn1;
        std::cout << i << " ) " << "xn = " << xn << "\tфункция равна = " << *fun(std::make_unique<double>(xn)) << std::endl;
    }
    return 0.0;
}

double MethodNewtonS(double x0, double x1)
{
    double xn = x0, xn1 = x1, xn2;
    double pfun = (*fun(std::make_unique<double>(x1)) - *fun(std::make_unique<double>(x0))) / (x1 - x0);
    for (int i = 0; i < N; ++i)
    {
        if (std::abs(xn1 - xn) <= 1.e-15)
        {
            std::cout << "Ошибка деление на нуль" << std::endl;
            return 0.0;
        }
        xn2 = xn1 - *fun(std::make_unique<double>(xn1)) / pfun;
        xn = xn1;
        xn1 = xn2;
        pfun = (*fun(std::make_unique<double>(xn1)) - *fun(std::make_unique<double>(xn))) / (xn1 - xn);
        std::cout << i << " ) " << "xn = " << xn1 << "\tфункция равна = " << *fun(std::make_unique<double>(xn1)) << std::endl;
    }
    return xn1;
}

double Simple(double a, double b)
{
    double an = a, bn = b, c = 0.0;
    double k1, k2;
    std::unique_ptr<double> funa = fun(std::make_unique<double>(an));
    std::unique_ptr<double> funb = fun(std::make_unique<double>(bn));
    if (*funa * *funb > 0)
    {
        std::cout << "Функция не меняет знак на интервале а и б" << std::endl;
        return 0.0;
    }
    for (int i = 0; i < N; ++i)
    {
        k1 = *funb / (b - a);
        k2 = *funa / (a - b);
        c = (k1 * a + k2 * b) / (k1 + k2);
        std::unique_ptr<double> func = fun(std::make_unique<double>(c));
        if (*funa * *func <= 0)
            bn = c;
        if (*funb * *func <= 0)
            an = c;
        std::cout << i << " ) " << "x = " << c << "\tфункция равна = " << *func << std::endl;
    }
    return c;
}

int main()
{
    Simple(-1,0.5);
    return 0;
}
