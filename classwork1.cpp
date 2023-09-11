#include <iostream>
#include <cmath>
using namespace std;

void printstr(string s)
{
  cout << s << endl;
}
double sum(double * a, double * b)
{
  return *a + *b;
}
double mul(double * a, double * b)
{
  return *a * *b;
}
double sub(double * a, double * b)
{
  return *a - *b;
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
  double a = 0.0,
         b = 0.0,
         c = 0.0;
  cout << "Введите а" << endl;
  cin >> a;
  cout << "Введите b" << endl;
  cin >> b;
  cout << "Введите c" << endl;
  cin >> c;
  printstr("Привет мир!");
  cout << "a = " << a << endl 
       << "a^2 = " << a * a << endl;
  cout << "a + b + c = " << a + b + c << endl;
  cout << "a * b * c = " << a * b * c << endl;  
  cout << "a + b = " << sum(&a, &b) << endl;
  cout << "a - b = " << sub(&a, &b) << endl;
  cout << "a * b = " << mul(&a, &b) << endl;
  cout << "Вывод числе от 1 до 10 с шагом 1:" << endl;
  for (int i = 1; i < 11; ++i)
    cout << i << endl;
  cout << "Программная погрешность double = " << err_double() << endl;
  cout << "Программная погрешность float = " << err_float() << endl;
}