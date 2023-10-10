#include <iostream>
#include <cmath>
#include <memory>
const double N = 50;
std::unique_ptr<double> fun(const std::unique_ptr<double>& x)
{
  return std::make_unique<double>(sin(*x) - cos(*x));
}

std::unique_ptr<double> EXPT(const std::unique_ptr<double>& x)
{
    double sum = 0.0, an = 1.0;
    for (int i = 1; i < N; ++i)
    {
        sum += an;
        an *= *x / i;
    }
    return std::make_unique<double>(sum);
}

std::unique_ptr<double> SINT(const std::unique_ptr<double>& x)
{
    double sum = 0.0, an = *x;
    for (int i = 1; i < N; ++i)
    {
        sum += an;
        an *= -(*x) * (*x) / ((2.0 * i) * (2.0 * i + 1.0));
    }
    return std::make_unique<double>(sum);
}

std::unique_ptr<double> COST(const std::unique_ptr<double>& x)
{
    double sum = 1.0, an = 1.0;
    for (int i = 1; i < N; ++i)
    {
        an *= -(*x) * (*x) / (2.0 * i * (2.0 * i - 1.0));
        sum += an;
    }
    return std::make_unique<double>(sum);
}


double dih(const std::unique_ptr<double>& a, const std::unique_ptr<double>& b)
{
    double an = *a, bn = *b, c = 0.0;
    if (*fun(std::make_unique<double>(an)) * *fun(std::make_unique<double>(bn)) > 0)
        return 0.0;
    for (int i = 0; i < N; ++i)
    {
        c = (an + bn) * 0.5;
        if (*fun(std::make_unique<double>(c)) * *fun(std::make_unique<double>(an)) <= 0)
            bn = c;
        if (*fun(std::make_unique<double>(c)) * *fun(std::make_unique<double>(bn)) <= 0)
            an = c;
    }
    return (an + bn) * 0.5;
}

int main()
{
    std::unique_ptr<double> x(new double(1.0));
    std::cout << "EXPT(" << *x << ") = " << *EXPT(x) << std::endl;
    std::cout << "SINT(" << *x << ") = " << *SINT(x) << std::endl;
    std::cout << "COST(" << *x << ") = " << *COST(x) << std::endl;
  
    std::unique_ptr<double> a(new double(-1000));
    std::unique_ptr<double> b(new double(1000));
    std::unique_ptr<double> m(new double(-(*b) / (2 * (*a))));
    std::cout << dih(a, m) << " " << dih(m, b) << std::endl;
    return 0;
}
