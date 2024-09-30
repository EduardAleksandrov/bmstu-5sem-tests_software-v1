
#ifndef ONE_INTEGRAL_CLASS_H
#define ONE_INTEGRAL_CLASS_H

#include <iostream>

class FunY_interface
{
    public:
    virtual double functionY(double)=0;
};

class FunY: public FunY_interface
{
    public:
    double functionY(double x) override
    {
        double y;
        y = 0;
        // if(x)
            return y = x*x;
        throw "division by zero";
    }
};

class Integral_cases
{
    private:
        double (FunY_interface::*functionY)(double);
        FunY_interface* provider_;
    public:
    explicit Integral_cases(FunY_interface* provider ,double (FunY_interface::*func)(double)): functionY(func), provider_(provider)
    {
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
            
            f1+=((x + h) - x)*provider_->functionY(x);
            f2+=((x + h) - x)*provider_->functionY(x + h);
            f3+=(provider_->functionY(x) + provider_->functionY(x + h))/2*((x + h) - x);
            xnew+= h;
        }
        if(xnew>=xmax)
        {
            f1+=(xmax - x)*provider_->functionY(x);
            f2+=(xmax - x)*provider_->functionY(xmax);
            f3+=(provider_->functionY(x) + provider_->functionY(xmax))/2*(xmax - x);
            // std::cout << "(Метод левых прямоугольников): Площадь равна: "<< f1 << std::endl;
            // std::cout << "(Метод правых прямоугольников): Площадь равна: "<< f2 << std::endl;
            // std::cout << "(Метод трапеций): Площадь равна: "<< f3 << std::endl;
        }
    }
};



#endif // ONE_INTEGRAL_CLASS_H