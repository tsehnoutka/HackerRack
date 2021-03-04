//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a, b;
    void input(string s)
    {
        int v1 = 0;
        int i = 0;
        while (s[i] != '+'){  //  convert the frist number to integer
            v1 = v1 * 10 + s[i] - '0';
            i++;
        }
        while (s[i] == ' ' || s[i] == '+' || s[i] == 'i') { //  move past spaces, plses ot 'i's
            i++;
        }
        int v2 = 0;
        while (i < s.length()){  //  get second part of complex number
            v2 = v2 * 10 + s[i] - '0';  
            i++;
        }
        a = v1;
        b = v2;
    }
};

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator+(const Complex& lhs, const Complex& rhs) {
    return { lhs.a + rhs.a, lhs.b + rhs.b };
}
std::ostream& operator << (std::ostream& os, Complex& c) {
    return std::cout << c.a << (c.b > 0 ? '+' : '-') << "i" << c.b;
}

int main()
{
    Complex x, y;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    x.input(s1);
    y.input(s2);
    Complex z = x + y;
    cout << z << endl;
}
