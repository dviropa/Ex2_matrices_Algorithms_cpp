#ifndef SQUAREMAT_H
#define SQUAREMAT_H
#include "Node.h"

#include <iostream>

namespace matrices {

    class Node; 

    class SquareMat {
    private:
        // int width;
        int length;
        Node* arey;

        bool chekeeqwls(const SquareMat& arr) const;

        int summatrix() const;

        double helpDeterminant(const SquareMat& mat,int row) const;
        
        SquareMat maketempSquareMat(const SquareMat& mat, int colToRemove) const ;
    public:
    SquareMat(const SquareMat& other); // copy constructor
    SquareMat(int rows, int cols); 

        SquareMat( int length);
        ~SquareMat();

        // int getwidth() const;
        int getlength() const;

        SquareMat operator+(const SquareMat& arr) const;
        SquareMat operator-(const SquareMat& arr) const;
        SquareMat operator*(const SquareMat& arr) const;
        SquareMat operator*(double scalar) const;
        friend SquareMat operator*(double scalar, const SquareMat& mat);
        SquareMat operator%(const SquareMat& other) const;
        SquareMat operator%(int scalar) const;
        SquareMat operator/(double scalar) const;
        SquareMat operator-() const;
        SquareMat operator^(int x) const;
        SquareMat operator~() const;

        SquareMat& operator++();
        SquareMat operator++(int);
        SquareMat& operator--();
        SquareMat operator--(int);

        double* operator[](size_t i);
        const double* operator[](size_t i) const;


        bool operator==(const SquareMat& other) const;
        bool operator!=(const SquareMat& other) const;
        bool operator<(const SquareMat& other) const;
        bool operator<=(const SquareMat& other) const;
        bool operator>(const SquareMat& other) const;
        bool operator>=(const SquareMat& other) const;

        SquareMat& operator+=(const SquareMat& other);
        SquareMat& operator-=(const SquareMat& other);
        SquareMat& operator*=(const SquareMat& other);
        SquareMat& operator/=(double scalar);
        SquareMat& operator%=(int scalar);

        SquareMat& operator=(const SquareMat& other);

        friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);

        double operator!() const ;
    

    };




} // namespace SquareMat

#endif // SQUAREMAT_H