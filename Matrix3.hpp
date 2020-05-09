#include "Vector.hpp"
#ifndef MATRIX3_H
#define MATRIX3_H
class Matrix3D{
private:
    static const int n=3;
    double** x;
public:
    Matrix3D();
    Matrix3D(double a0, double a1, double a2, double a3,double a4, double a5, double a6, double a7, double a8);
    ~Matrix3D();

    double getValue(unsigned int i, unsigned j) const;
    void setValue(unsigned int i, unsigned int j, double value);
    int getSize()const;

    Matrix3D operator +(const Matrix3D& m1) const;
    Matrix3D operator -(const Matrix3D& m1) const;
    Matrix3D operator *(const int& b) const;
    Matrix3D operator *(const Matrix3D& m1) const;
    Vector3D operator *(const Vector3D& v) const;

    double det();
};


Matrix3D operator *(int b, const Matrix3D& m1);
Vector3D operator* (const Vector3D& v, const Matrix3D& m);

std::istream& operator>>(std::istream& is, Matrix3D& m);
std::ostream & operator<<(std::ostream& os, const Matrix3D&  m);

#endif
