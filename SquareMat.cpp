#include "SquareMat.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

namespace matrices {
    SquareMat::SquareMat(const SquareMat& other) : length(other.length), arey(nullptr) {
        if (!other.arey) return;
    
        Node* currOther = other.arey;
        Node* prevNew = nullptr;
    
        while (currOther) {
            double* newArr = new double[length];
            for (int i = 0; i < length; ++i) {
                newArr[i] = currOther->getarr()[i];
            }
    
            Node* newNode = new Node(newArr, currOther->getname());
            if (!arey) {
                arey = newNode;
            } else {
                prevNew->setnext(newNode);
            }
    
            prevNew = newNode;
            currOther = currOther->getnext();
        }
    }
    SquareMat::SquareMat(int rows, int cols) : SquareMat(rows) {
        if (rows != cols)
            throw std::invalid_argument("Matrix must be square (rows == cols)");
    }
    
    SquareMat::SquareMat(int length) : length(length), arey(nullptr) {
        if (length <= 0) throw std::invalid_argument("Matrix size must be positive.");
    
        Node* prev = nullptr;
    
        for (int i = 0; i < length; ++i) {
            double* row = new double[length](); // אתחול כל האיברים ל־0
            Node* node = new Node(row, i);
            if (!arey)
                arey = node;
            else
                prev->setnext(node);
            prev = node;
        }
    }
    

    SquareMat::~SquareMat() {
        Node* curr = arey;
        while (curr) {
            Node* next = curr->getnext();
            // delete[] curr->getarr();
            delete curr;
            curr = next;
        }    }

    // int SquareMat::getwidth() const { return width; }
    int SquareMat::getlength() const { return length; }

    int SquareMat::summatrix() const {
        int sum = 0;
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < length; ++j)
                sum += (*this)[i][j];
        return sum;
    }

    bool SquareMat::chekeeqwls(const SquareMat& arr) const {
        return (this->length == arr.getlength());
    }

    double* SquareMat::operator[](size_t i) {
        // כאן נניח שאתה משתמש ב־arey כמו רשימה מקושרת של שורות
        Node* curr = arey;
        while (curr && curr->getname() != i) curr = curr->getnext();
        if (!curr) throw std::out_of_range("Index out of range");
        return curr->getarr();
    }

    const double* SquareMat::operator[](size_t i) const {
        Node* curr = arey;
        while (curr && curr->getname() != i) curr = curr->getnext();
        if (!curr) throw std::out_of_range("Index out of range");
        return curr->getarr();
    }

    SquareMat SquareMat::operator+(const SquareMat& other) const {
        if (!chekeeqwls(other)) throw std::invalid_argument("Size mismatch");
        SquareMat result( length);
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < length; ++j)
                result[i][j] = (*this)[i][j] + other[i][j];
        return result;
    }

    SquareMat SquareMat::operator-(const SquareMat& other) const {
        if (!chekeeqwls(other)) throw std::invalid_argument("Size mismatch");
        SquareMat result( length);
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < length; ++j)
                result[i][j] = (*this)[i][j] - other[i][j];
        return result;
    }

    SquareMat SquareMat::operator*(const SquareMat& other) const {
        if (length != other.length)
            throw std::invalid_argument("Matrix multiplication size mismatch");

        SquareMat result(other.length, length);
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < other.length; ++j) {
                int val = 0;
                for (int k = 0; k < length; ++k) {
                    val += (*this)[i][k] * other[k][j];
                }
                result[i][j] = val;
            }
        }
        return result;
    }

    SquareMat SquareMat::operator*(double scalar) const {
        SquareMat result( length);
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < length; ++j)
                result[i][j] = (*this)[i][j] * scalar;
        return result;
    }

    SquareMat operator*(double scalar, const SquareMat& mat) {
        return mat * scalar;
    }

    SquareMat SquareMat::operator%(const SquareMat& other) const {
        if (!chekeeqwls(other)) throw std::invalid_argument("Size mismatch");
        SquareMat result( length);
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < length; ++j)
                result[i][j] = (*this)[i][j] * other[i][j];
        return result;
    }

    SquareMat SquareMat::operator%(int scalar) const {
        SquareMat result( length);
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < length; ++j)
                result[i][j] = std::fmod((*this)[i][j], scalar);
        return result;
    }

    SquareMat SquareMat::operator/(double scalar) const {
        if (scalar == 0) throw std::invalid_argument("Division by zero");
        SquareMat result( length);
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < length; ++j)
                result[i][j] = (*this)[i][j] / scalar;
        return result;
    }

    SquareMat SquareMat::operator-() const {
        SquareMat result( length);
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < length; ++j)
                result[i][j] = -(*this)[i][j];
        return result;
    }

    SquareMat SquareMat::operator~() const {
        SquareMat result( length);
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < length; ++j)
                result[j][i] = (*this)[i][j];
        return result;
    }

    SquareMat SquareMat::operator^(int power) const {
        if (power < 0) throw std::invalid_argument("Negative powers not supported.");
        SquareMat result( length);
        for (int i = 0; i < length; ++i)
            result[i][i] = 1;

        SquareMat base = *this;
        while (power > 0) {
            if (power % 2 == 1)
                result = result * base;
            base = base * base;
            power /= 2;
        }
        return result;
    }

    SquareMat& SquareMat::operator++() {
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < length; ++j)
                (*this)[i][j]++;
        return *this;
    }

    SquareMat SquareMat::operator++(int) {
        SquareMat temp = *this;
        ++(*this);
        return temp;
    }

    SquareMat& SquareMat::operator--() {
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < length; ++j)
                (*this)[i][j]--;
        return *this;
    }

    SquareMat SquareMat::operator--(int) {
        SquareMat temp = *this;
        --(*this);
        return temp;
    }

    bool SquareMat::operator==(const SquareMat& other) const {
        return this->summatrix() == other.summatrix();
    }

    bool SquareMat::operator!=(const SquareMat& other) const {
        return !(*this == other);
    }

    bool SquareMat::operator<(const SquareMat& other) const {
        return this->summatrix() < other.summatrix();
    }

    bool SquareMat::operator<=(const SquareMat& other) const {
        return this->summatrix() <= other.summatrix();
    }

    bool SquareMat::operator>(const SquareMat& other) const {
        return this->summatrix() > other.summatrix();
    }

    bool SquareMat::operator>=(const SquareMat& other) const {
        return this->summatrix() >= other.summatrix();
    }

    SquareMat& SquareMat::operator+=(const SquareMat& other) {
        *this = *this + other;
        return *this;
    }

    SquareMat& SquareMat::operator-=(const SquareMat& other) {
        *this = *this - other;
        return *this;
    }

    SquareMat& SquareMat::operator*=(const SquareMat& other) {
        *this = *this * other;
        return *this;
    }

    SquareMat& SquareMat::operator/=(double scalar) {
        *this = *this / scalar;
        return *this;
    }

    SquareMat& SquareMat::operator%=(int scalar) {
        *this = *this % scalar;
        return *this;
    }

    SquareMat& SquareMat::operator=(const SquareMat& other) {
        if (this == &other) return *this;
    
        // שחרור הזיכרון הקיים
        Node* curr = arey;
        while (curr) {
            Node* next = curr->getnext();
            delete[] curr->getarr();  // שחרר את השורה (מטריצה)
            delete curr;              // שחרר את הצומת
            curr = next;
        }
    
        arey = nullptr;
    
        // העתקה כמו copy constructor
        length = other.length;
        Node* currOther = other.arey;
        Node* prevNew = nullptr;
    
        while (currOther) {
            double* newArr = new double[length];
            for (int i = 0; i < length; ++i)
                newArr[i] = currOther->getarr()[i];
    
            Node* newNode = new Node(newArr, currOther->getname());
            if (!arey) arey = newNode;
            else prevNew->setnext(newNode);
    
            prevNew = newNode;
            currOther = currOther->getnext();
        }
    
        return *this;
    }
    
    std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
        for (int i = 0; i < mat.getlength(); ++i) {
            for (int j = 0; j < mat.getlength(); ++j)
                os << mat[i][j] << " ";
            os << std::endl;
        }
        return os;
    }
    double SquareMat::operator!() const {
        return helpDeterminant(*this,0);
    }
    
    double SquareMat::helpDeterminant(const SquareMat& mat,int row) const {
        int n = mat.getlength();
        if (n == 1)
            return mat[0][0];
    
        if (n == 2)
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    
        double det = 0;
        for (int i = 0; i < n; ++i) {
            SquareMat sub = maketempSquareMat(mat, i);
            det += (i % 2 == 0 ? 1 : -1) * mat[0][i] * helpDeterminant(sub, row + 1);
        }
        return det;
    }
    
    SquareMat SquareMat::maketempSquareMat(const SquareMat& mat, int colToRemove) const {
        int n = mat.getlength();
        SquareMat temp(n - 1);
        for (int i = 1; i < n; ++i) { 
            int tempCol = 0;
            for (int j = 0; j < n; ++j) {
                if (j == colToRemove)
                    continue;
                temp[i - 1][tempCol++] = mat[i][j];
            }
        }
        return temp;
    }
}
