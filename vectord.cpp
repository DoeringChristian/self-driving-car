#include "vectord.h"

Vectord::Vectord(){
    vect = 0;
    length = 0;
}
Vectord::Vectord(unsigned int length){
    this->length = length;
    this->vect = new double[length];
    for(int i = 0;i < length;i++)
        this->vect[i] = 0;
}
Vectord::Vectord(const Vectord &copy){
    this->length = copy.size();
    this->vect = new double[length];
    for(int i = 0;i < length;i++)
        this->vect[i] = copy[i];
}

Vectord::~Vectord(){
    delete [] vect;
}

double& Vectord::operator[](unsigned int index) const{
    return this->vect[index];
}

Vectord Vectord::operator *(const Matrixd &m) const{
    //multiplication vector*matrix
    Vectord v(m.getHeight());
    for(int i = 0;i < m.getHeight();i++){
        double d = 0;
        for(int j = 0;j < m.getWidth();j++)
            d += m.matrix[j][i]*this->vect[j];
        v[i] = d;
    }
    return v;
}

void Vectord::operator =(const Vectord &v){
    //= operator to copy the values of the pointer-array
    delete [] vect;
    this->length = v.size();
    this->vect = new double[length];
    for(int i = 0;i < length;i++)
        this->vect[i] = v[i];
}

unsigned int Vectord::size() const{
    return length;
}


double sig(double d){
    return 1/(1+pow(M_E,d));
}

//sigmoid function for each element in a given vector
Vectord sig(const Vectord &s){
    Vectord v(s.size());
    for(int i = 0;i < s.size();i++)
        v[i] = sig(s[i]);
    return v;
}












