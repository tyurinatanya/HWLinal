#include "Vector.hpp"

using namespace std;

Vector3D::Vector3D(): Vector3D(0.0, 0.0, 0.0){}
Vector3D::Vector3D(double x, double y, double z) {
    a=new double[3];
    a[0]=x;
    a[1]=y;
    a[2]=z;
}
Vector3D::~Vector3D(){
    delete[] a;
}

int Vector3D::getSize() const{
    return n;
}

double Vector3D::getValue(unsigned int i) const {
        return a[i];
    }

void Vector3D::setValue(unsigned int i, double x){
        a[i]=x;
    }

Vector3D Vector3D:: operator+(const Vector3D& v){
    Vector3D v2;
    for (unsigned int i=0; i<n; ++i){
        v2.setValue(i, v.getValue(i)+a[i]);
    }
    return v2;
}

Vector3D Vector3D:: operator-(const Vector3D& v){
    Vector3D v2;
    for (unsigned int i=0; i<n; ++i){
        v2.setValue(i, a[i]-v.getValue(i));
    }
    return v2;
}

unsigned int Vector3D:: operator*(Vector3D& v){
    unsigned int rez=0;
    for(unsigned int i=0; i<n;++i){
        rez+=a[i]*v.getValue(i);
    }
    return  rez;
}
Vector3D Vector3D:: operator*(int b){
    Vector3D v;
    for (unsigned int i=0; i<n;++i){
        v.setValue(i, a[i]*b);
    }
    return v;
}
Vector3D operator*(int b, const Vector3D& v){
    Vector3D v2;
    for (unsigned int i=0; i<v.getSize();++i){
        v2.setValue(i, v.getValue(i)*b);
    }
    return v2;
}
std::istream& operator>>  (std::istream& is, Vector3D& v){
    double x[3];
    for (unsigned int i=0; i<v.getSize(); ++i){
        is>>x[i];
        v.setValue(i, x[i]);
    }

    return is;
}
std::ostream & operator<<(std::ostream& os, const Vector3D&  v) {

    for (unsigned int i=0; i<v.getSize(); ++i){
        os<<v.getValue(i)<<" ";
    }
    return os;
}

