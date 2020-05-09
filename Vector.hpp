#include<iostream>
#include <fstream>
#ifndef VECTOR_H
#define VECTOR_H
class Vector3D
{
private:
    double *a;
    static const int n=3;

public:

    Vector3D();
    Vector3D(double x, double y, double z);
    ~Vector3D();
    int getSize() const;

    double getValue(unsigned int i) const;

    void setValue(unsigned int i, double x);
    Vector3D operator*(const int& b) const;
    Vector3D operator+(const Vector3D& v) const;
    Vector3D operator-(const Vector3D& v) const;
    unsigned int  operator*(const Vector3D& v) const;
};
std::ostream& operator<< (std::ostream& os, const Vector3D&  v);
std::istream& operator>> (std::istream& is, Vector3D& v);

Vector3D operator*(int b, const Vector3D& v);

#endif
