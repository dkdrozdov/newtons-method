#include <iostream>
#include <vector>
#include <math.h>

class polynomial
{
   std::vector<double> *coefficients;

public:
   polynomial()
   {
      coefficients = new std::vector<double>();
      input();
   }

   double f(double x)
   {
      double sum = 0;
      int d = 0;
      for (double c : *coefficients)
      {
         if (c != 0)
            sum += c * pow(x, d);
         ++d;
      }
      return sum;
   }

   double df(double x)
   {
      double sum = 0;
      int d = 0;
      for (double c : *coefficients)
      {
         if (c != 0 && d - 1 >= 0)
            sum += c * d * pow(x, d - 1);
         ++d;
      }
      return sum;
   }

   void input()
   {
      int d = 0;
      std::cin >> d;
      double c = 0;
      for (int i = 0; i < d; i++)
      {
         std::cin >> c;
         coefficients->push_back(c);
      }
      std::reverse(coefficients->begin(), coefficients->end());
   }

   void output()
   {
      bool first = true;

      for (int d = (int)coefficients->size() - 1; d >= 0; d--)
      {
         double c = (*coefficients)[d];
         if (c != 0)
         {
            if (!first)std::cout << " + ";
            if (d != 0)
            {
               if (c != 1) std::cout << c << "*";
               std::cout << "x^" << d;
            } else
               std::cout << c;
            first = false;
         }
      }
      if (first)
         std::cout << "0";
      std::cout << std::endl;
   }
};

double solve(polynomial *p,
             double x0, double accuracy,
             int maxIterations)
{
   double prev = x0, root = x0 - p->f(x0) / p->df(x0);

   std::cout << "x1 = " << x0 << " - " << p->f(x0) << "/" << p->df(x0) << std::endl;

   for (int i = 0; abs(prev - root) > accuracy && i < maxIterations; i++)
   {
      std::cout << abs(prev - root) << " > " << accuracy << "; ";
      prev = root;
      root = prev - p->f(prev) / p->df(prev);
      std::cout << "x" << i + 1 << " = " << x0 << " - " << p->f(x0) << "/" << p->df(x0) << std::endl;
   }

   std::cout << abs(prev - root) << (abs(prev - root) > accuracy ? " > " : " < ") << accuracy << "; ";

   return root;
}

int main()
{
   double x0 = 0, accuracy = 0;
   int maxIterations = 0;
   std::cin >> x0 >> accuracy >> maxIterations;

   polynomial *p = new polynomial();

   std::cout << "y = ";
   p->output();
   std::cout << "x0 = " << x0 << std::endl;
   std::cout << "accuracy = " << accuracy << std::endl;
   std::cout << solve(p, x0, accuracy, maxIterations);
}