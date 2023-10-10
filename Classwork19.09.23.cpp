#include <iostream>
#include <memory>
#include <optional>

std::unique_ptr<double> disk(double a, double b, double c)
{
    double D = b * b - 4 * a * c;
    if (D < 0)
        return nullptr;
    return std::make_unique<double>(std::sqrt(D));
}

std::unique_ptr<double> xPlus(double a, double b, double c)
{
    std::unique_ptr<double> d = disk(a, b, c);
    if (!d)
    {
        std::cout << "Корней нет" << std::endl;
        return nullptr;
    }
    if (*d == 0)
        return std::make_unique<double>(-c / b);
    return std::make_unique<double>((-b + *d) / (2 * a));
}

std::unique_ptr<double> xMinus(double a, double b, double c)
{
    std::unique_ptr<double> d = disk(a, b, c);
    if (!d)
    {
        std::cout << "Корней нет" << std::endl;
        return nullptr;
    }
    if (*d == 0)
        return nullptr;
    return std::make_unique<double>((-b - *d) / (2 * a));
}

int main()
{
    std::unique_ptr<double> a(new double);
    std::unique_ptr<double> b(new double);
    std::unique_ptr<double> c(new double);
    std::cout << "Решение квадратного уравнения" << std::endl << "Введите переменные a, b и c" << std::endl;
    std::cin >> *a >> *b >> *c;
    std::unique_ptr<double> x1 = xPlus(*a, *b, *c);
    std::unique_ptr<double> x2 = xMinus(*a, *b, *c);
    if (x1)
        std::cout << "первый корень = " << *x1 << std::endl;
    if (x2)
        std::cout << "второй корень = " << *x2 << std::endl;
    return 0;
}
