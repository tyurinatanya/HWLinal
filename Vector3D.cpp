#include<iostream>
using namespace std;


class Vector3D{
private:
    double *a;
    const int n=3;
public:
    Vector3D(): Vector3D(0.0, 0.0, 0.0){}
    Vector3D(double x, double y, double z) {
        a=new double[3];
        a[0]=x;
        a[1]=y;
        a[2]=z;
    }
    ~Vector3D(){
        delete[] a;
    }
    int getSize() const{
        return n;
    }

    double getValue(unsigned int i) const {
        return a[i];
    }

    void setValue(unsigned int i, double x){
        a[i]=x;
    }

    Vector3D operator*(int b){
        Vector3D v;
        for (unsigned int i=0; i<n;++i){
            v.setValue(i, a[i]*b);
        }
        return v;
    }

    Vector3D operator+(const Vector3D& v){
        Vector3D v2;
        for (unsigned int i=0; i<n; ++i){
            v2.setValue(i, v.getValue(i)+a[i]);
        }
        return v2;
    }

    Vector3D operator-(const Vector3D& v){
        Vector3D v2;
        for (unsigned int i=0; i<n; ++i){
            v2.setValue(i, a[i]-v.getValue(i));
        }
        return v2;
    }

    unsigned int  operator*(Vector3D& v){
        unsigned int rez=0;
        for(unsigned int i=0; i<n;++i){
            rez+=a[i]*v.getValue(i);
        }
        return  rez;
    }


};
Vector3D operator*(int b, const Vector3D& v){
    Vector3D v2;
    for (unsigned int i=0; i<v.getSize();++i){
        v2.setValue(i, v.getValue(i)*b);
    }
    return v2;
}
istream& operator>>  (istream& is, Vector3D& v){
    double x[3];
    for (unsigned int i=0; i<v.getSize(); ++i){
        is>>x[i];
        v.setValue(i, x[i]);
    }

    return is;
}
ostream & operator<<(ostream& os, const Vector3D&  v) {

    for (unsigned int i=0; i<v.getSize(); ++i){
        os<<v.getValue(i)<<" ";
    }
    return os;
    }

class Matrix3D{
private:
    const int n=3;
    double** x;
public:
    Matrix3D(): Matrix3D(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0){};
    Matrix3D(double a0, double a1, double a2, double a3,double a4, double a5, double a6, double a7, double a8){
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
    ~Matrix3D(){
        for(int i = 0; i < n; i++) delete[] x[i];
        delete[]x;
    }
    double getValue(unsigned int i, unsigned j) const{
        return x[i][j];
    }

    void setValue(unsigned int i, unsigned int j, double value){
        x[i][j]=value;
    }

    int getSize()const {
        return n;
    }

    Matrix3D operator +(const Matrix3D& m1){
        Matrix3D m2= Matrix3D();
        for (unsigned int i=0; i<n;++i){

            for (unsigned int j=0; j<n; ++j){
                m2.setValue(i, j, x[i][j]+m1.getValue(i, j));
            }
        }
        return m2;
    }

    Matrix3D operator -(const Matrix3D& m1){
        Matrix3D m2= Matrix3D();
        for (unsigned int i=0; i<n;++i){

            for (unsigned int j=0; j<n; ++j){
                m2.setValue(i, j, x[i][j]-m1.getValue(i, j));
            }
        }
        return m2;
    }

    Matrix3D operator *(int b){
        Matrix3D m2= Matrix3D();
        for (unsigned int i=0; i<n;++i){

            for (unsigned int j=0; j<n; ++j){
                m2.setValue(i, j, x[i][j]*b);
            }
        }
        return m2;
    }

    Matrix3D operator *(Matrix3D& m1){
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

    Vector3D operator* (Vector3D& v){
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

    double det(){
        double rez=0;
        rez+=x[0][0]*x[1][1]*x[2][2];
        rez+=x[0][1]*x[1][2]*x[2][0];
        rez+=x[1][0]*x[2][1]*x[0][2];
        rez-=x[2][0]*x[1][1]*x[0][2];
        rez-=x[0][1]*x[1][0]*x[2][2];
        rez-=x[0][0]*x[1][2]*x[2][1];
        return rez;
    }

};

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
istream& operator>>  (istream& is, Matrix3D& m){
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
ostream & operator<<(ostream& os, const Matrix3D&  m) {
    os<<endl;
    for (unsigned int i=0; i<m.getSize(); ++i){

        for (unsigned int j=0; j<m.getSize(); ++j)
            os<<m.getValue(i, j)<<" ";

        os<<endl;
    }
    return os;
    }


int main()
{
    // Вектор задан в коде
    Vector3D A(1, 2, 3);
    // Вектор читается из cin
    Vector3D B;
    cin >> B;

    // Базовые операции с векторами
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "A * 3 = " << A * 3 << endl;
    cout << "2 * B = " << 2 * B << endl;
    cout << "B * 2 = " << B * 2 << endl;
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;

    // Матрица задана в коде
    Matrix3D C(1, 0, 0, 0, 1, 0, 0, 0, 1);
    // Матрица читается из cin
    Matrix3D D;
    cin >> D;

    // Базовые операции с матрицами
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "C * 3 = " << C * 3 << endl;
    cout << "2 * D = " << 2 * D << endl;
    cout << "C + D = " << C + D << endl;
    cout << "C - D = " << C - D << endl;
    cout << "C * D = " << C * D << endl;

    // Детерминант матрицы
    cout << "det(D) = " << D.det() << endl;

    // Умножение матрицы на вектор
    cout << "D * B = " << D * B << endl;
    return 0;
}
