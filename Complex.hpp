//ID : 208336701
//mail : ofekmarom9@gmail.com


#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double real, double imag);

    double getReal() const;
    double getImag() const;
         //arithmetic operators
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
         // comparison operators
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator>(const Complex& other) const;
        //output of the complex numnber
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
};

#endif // COMPLEX_HPP
