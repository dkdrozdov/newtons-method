#include <iostream>
#include <vector>
#include <math.h>

const bool SHOW_ITERATIONS = false;

//class polynomial
//{
//   std::vector<double> *coefficients;
//
//public:
//   polynomial()
//   {
//      coefficients = new std::vector<double>();
//      input();
//   }
//
//   double f(double x)
//   {
//      double sum = 0;
//      int d = 0;
//      for (double c : *coefficients)
//      {
//         if (c != 0)
//            sum += c * pow(x, d);
//         ++d;
//      }
//      return sum;
//   }
//
//   double df(double x, double dx)
//   {
//      return (f(x + dx) - f(x)) / dx;
//   }
//
//   void input()
//   {
//      int d = 0;
//      std::cin >> d;
//      double c = 0;
//      for (int i = 0; i < d; i++)
//      {
//         std::cin >> c;
//         coefficients->push_back(c);
//      }
//      std::reverse(coefficients->begin(), coefficients->end());
//   }
//
//   void output()
//   {
//      bool first = true;
//
//      for (int d = (int)coefficients->size() - 1; d >= 0; d--)
//      {
//         double c = (*coefficients)[d];
//         if (c != 0)
//         {
//            if (!first)std::cout << " + ";
//            if (d != 0)
//            {
//               if (c != 1) std::cout << c << "*";
//               std::cout << "x^" << d;
//            } else
//               std::cout << c;
//            first = false;
//         }
//      }
//      if (first)
//         std::cout << "0";
//      std::cout << std::endl;
//   }
//};

//double solve(polynomial *p,
//             double x0, double accuracy,
//             int maxIterations, double dx)
//{
//   double prev = x0, root = x0 - p->f(x0) / p->df(x0, dx);
//
//   std::cout << "x1 = " << x0 << " - " << p->f(x0) << "/" << p->df(x0, dx) << std::endl;
//
//   for (int i = 0; abs(prev - root) > accuracy && i < maxIterations; i++)
//   {
//      std::cout << abs(prev - root) << " > " << accuracy << "; ";
//      prev = root;
//      root = prev - p->f(prev) / p->df(prev, dx);
//      std::cout << "x" << i + 1 << " = " << x0 << " - " << p->f(x0) << "/" << p->df(x0, dx) << std::endl;
//   }
//
//   std::cout << abs(prev - root) << (abs(prev - root) > accuracy ? " > " : " < ") << accuracy << "; ";
//
//   return root;
//}

double solve(double f(double), double df(double, double),
             double x0, double accuracy,
             int maxIterations, double dx, int *iterations)
{
   double prev = x0, root = x0 - f(x0) / df(x0, dx);

   std::cout << "root = " << root << abs(prev - root) << accuracy << std::endl;
   int i = 0;
   for ( ; abs(prev - root) > accuracy && i < maxIterations; i++)
   {
      prev = root;
      root = prev - f(prev) / df(prev, dx);      
   }
   *iterations = i+1;
   return root;
}

double func(double x)
{
   double result = sin(x);
   std::cout << "f = " << result << std::endl;

   return result;
}

double dfunc(double x, double dx)
{
   double result = ((func(x + dx) - func(x)) / dx);
   std::cout << "df = " << result << std::endl;

   return result;
}

int main()
{
   double dx = 0, x0 = 0, accuracy = 0;
   int maxIterations = 0;
   std::cin >> dx >> x0 >> accuracy >> maxIterations;

   //polynomial *p = new polynomial();

   //std::cout << "y = ";
   //p->output();
   //std::cout << "x0 = " << x0 << std::endl;
   //std::cout << "accuracy = " << accuracy << std::endl;
   int i = 0;
   std::cout << solve(func, dfunc, x0, accuracy, maxIterations, dx, &i) /*<< "\n" << i << " iterations"*/;
}