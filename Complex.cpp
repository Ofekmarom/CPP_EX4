//ID : 208336701
//mail : ofekmarom9@gmail.com


#include "Complex.hpp"

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}


        //arithmetic operators

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag,
                   real * other.imag + imag * other.real);
}

Complex Complex::operator/(const Complex& other) const {
    double denom = other.real * other.real + other.imag * other.imag;
    return Complex((real * other.real + imag * other.imag) / denom,
                   (imag * other.real - real * other.imag) / denom);
}


            // comparison operators

bool Complex::operator==(const Complex& other) const {
    return (real == other.real) && (imag == other.imag);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

bool Complex::operator<(const Complex& other) const {
    double valThis = real * real + imag * imag;
    double valOther = other.real * other.real + other.imag * other.imag;
    return sqrt(valThis) < sqrt(valOther);
}

bool Complex::operator>(const Complex& other) const {
    double valThis = real * real + imag * imag;
    double valOther = other.real * other.real + other.imag * other.imag;
    return sqrt(valThis) > sqrt(valOther);
}


            //output of the complex numnber
std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << complex.real;
    if (complex.imag >= 0)
        os << " + " << complex.imag << "i";
    else
        os << " - " << -complex.imag << "i";
    return os;
}
