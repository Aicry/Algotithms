/*#include<iostream>

using namespace std;

class Complex {

    friend istream& operator>>(istream&, Complex&);

    friend ostream& operator<<(ostream&, const Complex&);

public:

    Complex() {} Complex(int a, int b) { real = a, imag = b; }

private:

    int real; int imag;

};

istream& operator>>(istream& in, Complex& c) {

    in >> c.real >> c.imag;

    return in;

}

ostream& operator<<(ostream& os, const Complex& c)

{

  

    os << "( " << c.real << " , " << c.imag << " )" << endl; 

        return os;

}

                                                                         

int main()

{

    Complex c; cin >> c; cout << c; return 0;

}*/

#include <iostream>

using namespace std;

class Complex

{

public:

    Complex(double r = 0.0, double i = 0.0)

    {

        real = r; imag = i;

    }

    Complex operator + (Complex& c2);

    // 运算符“+”重载为成员函数

    Complex operator -(Complex& c2);

    // 运算符“-”重载为成员函数

    Complex operator *(Complex& c2);

    Complex operator /(Complex& c2);

    void display();       // 复数输出

private:

    double real;

    double imag;

};

Complex Complex::operator+(Complex& c2)

{

    Complex  c;

    c.real = real + c2.real;

    c.imag = imag + c2.imag;

    return c;

}

Complex Complex::operator-(Complex& c2)

{

    Complex  c;

    c.real = real - c2.real;

    c.imag = imag - c2.imag;

    return c;

}

Complex Complex::operator*(Complex& c2)

{

    Complex  c;

    c.real = real * c2.real-imag*c2.imag;

    c.imag = real*c2.imag + imag*c2.real;

    return c;

}

Complex Complex::operator/(Complex& c2)

{

    Complex  c;

    c.real = (real * c2.real + imag * c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);

    c.imag = (imag * c2.real-real*c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);

    return c;

}

void Complex::display()

{

    cout << real;

    if (imag > 0) {

        cout << "+";

        cout << imag << "i" << endl;

    }

}

int main()

{

    Complex c1(5, 10), c2(4, 2), c3;

    cout << "c1=";

    c1.display();

    cout << "c2=";

    c2.display();

    c3 = c1 + c2;          //c1+c2解释为c1.operator+(c2) 

    cout << "c1+c2=";

    c3.display();

    cout << "c1-c2=";

    (c1 - c2).display(); //c1-c2解释为c1.operator-(c2)

    cout << "c1*c2=";

    (c1 * c2).display(); 

    cout << "c1/c2=";

    (c1 / c2).display();

    return 0;

}