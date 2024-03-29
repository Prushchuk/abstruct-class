#include <iostream>
#include <cmath>
using namespace std;

class Equation
{
public:
    virtual void solve() = 0;
};

class LinearEquation : public Equation
{
private:
    double a, b;
public:
    LinearEquation(double a_, double b_) : a{ a_ }, b{ b_ }{}

    void solve() override {
        if (a == 0) {
            if (b == 0) {
                cout << "The equation has many solutions." << endl;
            }
            else {
                cout << "The equation hasn`t got solutions." << endl;
            } 
        }
        else {
            double x = -b / a;
            cout << "The equation have got only one solution x: " << x << endl;
        }
    }
};

class QuadraticEquation : public Equation
{
private:
    double a, b, c;
public:
    QuadraticEquation(double a_, double b_, double c_) : a{ a_ }, b{ b_ }, c{ c_ } {}
    
    void solve() override {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "The equation have got two solutions: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
        else if (discriminant == 0) {
            double x = -b / (2 * a);
            cout << "The equation have got only one solution: x = " << x << endl;
        }
        else {
            cout << "Equation haven`t got a solution" << endl;
        }
    }
};

int main()
{
    Equation* equation1 = new LinearEquation(2, -4);
    Equation* equation2 = new QuadraticEquation(1, -3, 2);

    equation1->solve();
    equation2->solve();

    delete equation1;
    delete equation2;
}