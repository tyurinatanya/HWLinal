#include "Matrix3.hpp"

Matrix3D:: Matrix3D(): Matrix3D(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0){};
Matrix3D:: Matrix3D(double a0, double a1, double a2, double a3,double a4, double a5, double a6, double a7, double a8){
    x=new double* [n];
    for (unsigned int i=0; i<n; ++i){
        x[i]=new double[n];
    }
    x[0][0]=a0;
    x[0][1]=a1;
    x[0][2]=a2;
    x[1][0]=a3;
    x[1][1]=a4;
    x[1][2]=a5;
    x[2][0]=a6;
    x[2][1]=a7;
    x[2][2]=a8;
}
Matrix3D:: ~Matrix3D(){
    for(int i = 0; i < n; i++) delete[] x[i];
    delete[]x;
}
double Matrix3D:: getValue(unsigned int i, unsigned j) const{
    return x[i][j];
}

void Matrix3D:: setValue(unsigned int i, unsigned int j, double value){
    x[i][j]=value;
}

int Matrix3D:: getSize()const {
    return n;
}

Matrix3D Matrix3D:: operator +(const Matrix3D& m1){
    Matrix3D m2= Matrix3D();

    for (unsigned int i=0; i<n;++i){
        for (unsigned int j=0; j<n; ++j){
            m2.setValue(i, j, x[i][j]+m1.getValue(i, j));
        }
    }
    return m2;
}

Matrix3D Matrix3D:: operator -(const Matrix3D& m1){
    Matrix3D m2= Matrix3D();
    for (unsigned int i=0; i<n;++i){

        for (unsigned int j=0; j<n; ++j){
            m2.setValue(i, j, x[i][j]-m1.getValue(i, j));
        }
    }
    return m2;
}

Matrix3D Matrix3D:: operator *(int b){
    Matrix3D m2= Matrix3D();
    for (unsigned int i=0; i<n;++i){

        for (unsigned int j=0; j<n; ++j){
            m2.setValue(i, j, x[i][j]*b);
        }
    }
    return m2;
}

Matrix3D Matrix3D:: operator *(Matrix3D& m1){

    Matrix3D m2= Matrix3D();
    double c[3][3];

    for (unsigned int i=0; i<n; i++)
        for (unsigned int j=0; j<n; j++)
            c[i][j]=0;

    for(unsigned int i=0;i<n; i++)
    {
        for(unsigned int j=0; j<n; j++)
        {
            for(unsigned int m=0; m<n; m++)
            {
                c[i][j]+=x[i][m]*m1.getValue(m, j);
            }
        }
    }

    for (unsigned int i=0; i<n; i++)
        for (unsigned int j=0; j<n; j++)
            m2.setValue(i, j, c[i][j]);

    return m2;
}

Vector3D Matrix3D:: operator* (Vector3D& v){
    Vector3D v2=Vector3D();
    double c[3];

    for (unsigned int i=0; i<n; ++i)
        c[i]=0;

    for (unsigned int i=0; i<n; ++i)
        for (unsigned int j=0; j<n; ++j){
            c[i]+=x[i][j]*v.getValue(j);
        }

    for (unsigned int i=0; i<n; ++i)
        v2.setValue(i, c[i]);

    return v2;
}

double Matrix3D:: det(){
    double rez=0;
    rez+=x[0][0]*x[1][1]*x[2][2];
    rez+=x[0][1]*x[1][2]*x[2][0];
    rez+=x[1][0]*x[2][1]*x[0][2];
    rez-=x[2][0]*x[1][1]*x[0][2];
    rez-=x[0][1]*x[1][0]*x[2][2];
    rez-=x[0][0]*x[1][2]*x[2][1];
    return rez;
}

Matrix3D operator *(int b, const Matrix3D& m1){
    Matrix3D m2= Matrix3D();
    for (unsigned int i=0; i<m1.getSize();++i){

        for (unsigned int j=0; j<m1.getSize(); ++j){
            m2.setValue(i, j, b*m1.getValue(i, j));
        }
    }
    return m2;
}

Vector3D operator* (Vector3D& v, Matrix3D& m){
    Vector3D v2=Vector3D();
    double c[3];

    for (unsigned int i=0; i<m.getSize(); ++i)
        c[i]=0;

    for (unsigned int i=0; i<m.getSize(); ++i)

        for (unsigned int j=0; j<m.getSize(); ++j){
            c[i]+=m.getValue(i, j)*v.getValue(j);
        }

    for (unsigned int i=0; i<m.getSize(); ++i)
        v2.setValue(i, c[i]);

    return v2;
}

std::istream& operator>>  (std::istream& is, Matrix3D& m){
    double x[3];
    double c;
    for (unsigned int i=0; i<m.getSize(); ++i){

        for (unsigned int j=0; j<m.getSize(); ++j){
            is>>c;
            m.setValue(i, j, c);
        }
    }

    return is;
}

std::ostream & operator<<(std::ostream& os, const Matrix3D&  m) {
    os<<std::endl;
    for (unsigned int i=0; i<m.getSize(); ++i){

        for (unsigned int j=0; j<m.getSize(); ++j)
            os<<m.getValue(i, j)<<" ";

        os<<std::endl;
    }
    return os;
}
