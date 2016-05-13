#ifndef COMPLEX_H
#define COMPLEX_H


class Complex
{
    private:
        friend bool operator==(const Complex& a, const Complex&b)
        {
            return true;
        }
        double real, imaginary;
    public:
        Complex(double r, double i=0) : real(r), imaginary(i)
        {
        }

};

#endif // COMPLEX_H
