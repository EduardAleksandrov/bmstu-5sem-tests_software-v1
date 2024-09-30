
#ifndef ONE_INTEGRAL_H
#define ONE_INTEGRAL_H

#include <iostream>

double functionY(double x)
{
    double y;
    y = 0;
    // if(x)
        return y = x*x;
    throw "division by zero";
}

void integral_three_cases(double hConst, double xmin, double xmax, double& f1, double& f2, double& f3)
{
    f1 = 0;
    f2 = 0;
    f3 = 0;
    double xnew = xmin;
    double h = hConst;
    double x;
    while(xnew<xmax)
    {
        x = xnew;
        if (xmax - xmin == h || xnew + h >= xmax)
        {
            xnew+= h;
            break;
        }
        
        f1+=((x + h) - x)*functionY(x);
        f2+=((x + h) - x)*functionY(x + h);
        f3+=(functionY(x) + functionY(x + h))/2*((x + h) - x);
        xnew+= h;
    }
    if(xnew>=xmax)
    {
        f1+=(xmax - x)*functionY(x);
        f2+=(xmax - x)*functionY(xmax);
        f3+=(functionY(x) + functionY(xmax))/2*(xmax - x);
        // std::cout << "(Метод левых прямоугольников): Площадь равна: "<< f1 << std::endl;
        // std::cout << "(Метод правых прямоугольников): Площадь равна: "<< f2 << std::endl;
        // std::cout << "(Метод трапеций): Площадь равна: "<< f3 << std::endl;
    }
}


#endif // ONE_INTEGRAL_H