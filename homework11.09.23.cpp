#include <iostream>
#include <cmath>
#include <memory>

std::unique_ptr<double> sum(const std::unique_ptr<double>& a, const std::unique_ptr<double>& b)
{
  return std::make_unique<double>(*a + *b);
}

std::unique_ptr<double> mul(const std::unique_ptr<double>& a, const std::unique_ptr<double>& b)
{
  return std::make_unique<double>(*a * *b);
}

std::unique_ptr<double> sub(const std::unique_ptr<double>& a, const std::unique_ptr<double>& b)
{
  return std::make_unique<double>(*a - *b);
}

double err_double()
{
  double A = sqrt(2.0);
  const double e_= 2.0;
  double eps = 1.0;
  for (; A + eps > A; eps /= e_ )
  {
  }
  return eps;
}

float err_float()
{
  float A = sqrtf(2.0F);
  const float e_= 2.0F;
  float eps = 1.0F;
  for (; A + eps > A; eps /= e_ )
  {
  }
  return eps;
}

int main() {
  std::unique_ptr<double> a(new double(0.0));
  std::unique_ptr<double> b(new double(0.0));
  std::unique_ptr<double> c(new double(0.0));
  std::cout << "Введите а" << std::endl;
  std::cin >> *a;
  std::cout << "Введите b" << std::endl;
  std::cin >> *b;
  std::cout << "Введите c" << std::endl;
  std::cin >> *c;
  std::cout << "Привет мир!" << std::endl;
  std::cout << "a = " << *a << std::endl 
       << "a^2 = " << *a * *a << std::endl;
  std::cout << "a + b + c = " << *a + *b + *c << std::endl;
  std::cout << "a * b * c = " << *a * *b * *c << std::endl;  
  std::cout << "a + b = " << *sum(a, b) << std::endl;
  std::cout << "a - b = " << *sub(a, b) << std::endl;
  std::cout << "a * b = " << *mul(a, b) << std::endl;
  std::cout << "Вывод числе от 1 до 10 с шагом 1:" << std::endl;
  for (int i = 1; i < 11; ++i)
    std::cout << i << std::endl;
  std::cout << "Программная погрешность double = " << err_double() << std::endl;
  std::cout << "Программная погрешность float = " << err_float() << std::endl;
  return 0;
}
