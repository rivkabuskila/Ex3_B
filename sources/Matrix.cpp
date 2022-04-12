//
// Created by rivka on 03/04/2022.
//

#include "Matrix.hpp"
#include <string>
#include <regex>

namespace zich {
    //constructor
    Matrix::Matrix() {
        column = 0;
        row = 0;
    }

    //constructor
    Matrix::Matrix(const vector<double> &v, const int newRow, const int newColumn)  {
        if (newRow <= 0 || newColumn <= 0) {
            throw std::out_of_range{"Invalid values"};
        }
        if (v.size() != newRow * newColumn) {
            throw std::out_of_range{"Invalid values"};
        }
        this->mat = v;
        this->column = newColumn;
        this->row = newRow;
    }

    //copy constructor
    Matrix::Matrix(const Matrix &other) {
//        Matrix(other.mat,other.column,other.row);
        mat = other.mat;
        column = other.column;
        row = other.row;
    }

    //addition matrix to new matrix
    Matrix Matrix::operator+(const Matrix &matrix) {
        if (this->row != matrix.row || this->column != matrix.column) {
            throw std::out_of_range{"Invalid operation"};
        }
        vector<double> v;
        for (unsigned long i = 0; i < row * column; i++) {
            v.push_back(this->mat[i] + matrix.mat[i]);
        }
        return Matrix(v, this->row, this->column);
    }

    //addition matrix
    Matrix &Matrix::operator+=(const Matrix &matrix) {
        if (this->row != matrix.row || this->column != matrix.column) {
            throw std::out_of_range{"Invalid operation"};
        }
        for (unsigned i = 0; i < row * column; ++i) {
            this->mat[i] = this->mat[i] + matrix.mat[i];
        }
        return *this;
    }

    Matrix &Matrix::operator+() {
        return *this;
    }

//subtraction matrix to new matrix
    Matrix Matrix::operator-(const Matrix &matrix) {
        if (this->row != matrix.row || this->column != matrix.column) {
            throw std::out_of_range{"Invalid operation"};
        }
        vector<double> v;
        for (unsigned long i = 0; i < row * column; i++) {
            v.push_back(this->mat[i] - matrix.mat[i]);
        }
        return Matrix(v, this->row, this->column);
    }

//subtraction matrix
    Matrix &Matrix::operator-=(const Matrix &matrix) {
        if (this->row != matrix.row || this->column != matrix.column) {
            throw std::out_of_range{"Invalid operation"};
        }
        for (unsigned long i = 0; i < row * column; ++i) {
            this->mat[i] = this->mat[i] - matrix.mat[i];
        }
        return *this;
    }

    Matrix Matrix::operator-() {
        return *this * (-1);
    }

//Checking if this<matrix
    bool Matrix::operator<(const Matrix &matrix) {
        if (this->row != matrix.row || this->column != matrix.column) {
            throw std::out_of_range{"Invalid operation"};
        }
        double sum1 = 0;
        double sum2 = 0;
        for (unsigned long i = 0; i < row * column; ++i) {
            sum1 += this->mat[i];
            sum2 += matrix.mat[i];
        }

        return sum1 < sum2;
    }

//Checking if this<=matrix
    bool Matrix::operator<=(const Matrix &matrix) {
        if (this->row != matrix.row || this->column != matrix.column) {
            throw std::out_of_range{"Invalid operation"};
        }
        return *this == matrix || *this < matrix;
    }

//Checking if this>matrix
    bool Matrix::operator>(const Matrix &matrix) {
        if (this->row != matrix.row || this->column != matrix.column) {
            throw std::out_of_range{"Invalid operation"};
        }
        return !(*this <= matrix);
    }

//Checking if this>=matrix
    bool Matrix::operator>=(const Matrix &matrix) {
        if (this->row != matrix.row || this->column != matrix.column) {
            throw std::out_of_range{"Invalid operation"};
        }
        return *this == matrix || *this > matrix;
    }

//Checking if this==matrix
    bool Matrix::operator==(const Matrix &matrix) {
        if (this->row != matrix.row || this->column != matrix.column) {
            throw std::out_of_range{"Invalid operation"};
        }
        for (unsigned long i = 0; i < this->row * this->column; ++i) {
            if (this->mat[i] != matrix.mat[i]) {
                return false;
            }
        }
        return true;
    }

    //Checking if this==matrix
    bool operator==(const Matrix &matrix1, const Matrix &matrix2) {
        if (matrix1.row != matrix2.row || matrix1.column != matrix2.column) {
            throw std::out_of_range{"Invalid operation"};
        }
        for (unsigned long i = 0; i < matrix1.row * matrix1.column; ++i) {
            if (matrix1.mat[i] != matrix2.mat[i]) {
                return false;
            }
        }
        return true;
    }

    //Checking if this!=matrix
    bool Matrix::operator!=(const Matrix &matrix) {
        if (this->row != matrix.row || this->column != matrix.column) {
            throw std::out_of_range{"Invalid operation"};
        }
        return !(*this == matrix);
    }

    //++mat
    Matrix &Matrix::operator++() {
        for (unsigned long i = 0; i < this->row * this->column; ++i) {
            this->mat[i]++;
        }
        return *this;
    }

    //mat++
    Matrix Matrix::operator++(int num) {
        Matrix copy = *this;
        for (unsigned long i = 0; i < this->row * this->column; ++i) {
            this->mat[i]++;
        }
        return copy;
    }

    //--mat
    Matrix &Matrix::operator--() {
        for (unsigned long i = 0; i < this->row * this->column; ++i) {
            this->mat[i]--;
        }
        return *this;
    }

    //mat--
    Matrix Matrix::operator--(int num) {
        Matrix copy = *this;
        for (unsigned long i = 0; i < this->row * this->column; ++i) {
            this->mat[i]--;
        }
        return copy;
    }

    //Multiply the matrix by the number and return a new matrix
    Matrix Matrix::operator*(double num) {
        vector<double> v;
        for (unsigned long i = 0; i < row * column; i++) {
            v.push_back(this->mat[i] * num);
        }
        return Matrix(v, this->row, this->column);
    }

//Multiply the matrix by the number
    Matrix &Matrix::operator*=(const double num) {
        for (unsigned i = 0; i < row * column; ++i) {
            this->mat[i] = this->mat[i] * num;
        }
        return *this;
    }

    //Multiply the matrix by the number and return a new matrix
    Matrix operator*(double num, Matrix &matrix) {
        return matrix * num;
    }

    //Multiply the matrix by another matrix and return a new matrix
    Matrix Matrix::operator*(const Matrix &matrix) {
        if (this->column != matrix.row) {
            throw std::out_of_range{"Invalid operation"};
        }
        vector <vector<double>> mat1((unsigned long) this->row, vector<double>((unsigned long) this->column));
        vector <vector<double>> mat2((unsigned long) matrix.row, vector<double>((unsigned long) matrix.column));
        unsigned long indexmat1 = 0;
        for (unsigned long i = 0; i < this->row; i++) {
            for (unsigned long j = 0; j < this->column; j++) {
                mat1[i][j] = this->mat[indexmat1];
                indexmat1++;
            }
        }
        unsigned long indexmat2 = 0;
        for (unsigned long i = 0; i < matrix.row; i++) {
            for (unsigned long j = 0; j < matrix.column; j++) {
                mat2[i][j] = matrix.mat[indexmat2];
                indexmat2++;
            }
        }
        vector <vector<double>> mat3((unsigned long) this->row, vector<double>((unsigned long) matrix.column));
        for (unsigned long i = 0; i < this->row; i++) {
            for (unsigned long j = 0; j < matrix.column; j++) {
                for (unsigned long k = 0; k < this->column; k++) {
                    mat3[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        vector<double> v;
        for (unsigned long i = 0; i < this->row; i++) {
            for (unsigned long j = 0; j < matrix.column; j++) {
                v.push_back(mat3[i][j]);
            }
        }

        return Matrix(v, this->row, matrix.column);

    }

    //Multiply the matrix by another matrix
    Matrix &Matrix::operator*=(const Matrix &matrix) {
        Matrix m = *this * matrix;
        this->mat = m.mat;
        this->row = m.row;
        this->column = m.column;
        return *this;
    }

//output matrix
    std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
        unsigned long index = 0;
        for (unsigned int i = 0; i < matrix.row; i++) {
            os << "[";
            for (int j = 0; j < matrix.column - 1; j++) {
                os << matrix.mat[index++] << ' ';
            }
            os << matrix.mat[index++];
            os << "]";
            if (i != matrix.row - 1) {
                os << "\n";
            }
        }
        return os;
    }

//input matrix
    std::istream &operator>>(std::istream &is, Matrix &matrix) {
        vector<double> v;
        string mystr;
        getline(is, mystr);
        unsigned long sizeStart = 0;
        string s;
        int row = 0;
        int col = 0;
        // regex expression for pattern to be searched
        regex regexp("[['-'*0-9*.0-9* ]+]");
        if (mystr[0] != '[') {
            throw std::out_of_range{"Invalid values"};
        }
        while (!mystr.empty()) {
            unsigned long sizeEnd = mystr.find(']');
            s = mystr.substr(sizeStart, sizeEnd + 1);
            if (mystr.size() != s.size()) {
                if (mystr[s.size()] != ',' || mystr[s.size() + 1] != ' ') {
                    throw std::out_of_range{"Invalid values"};
                }
                mystr = mystr.substr(s.size() + 2, mystr.size());

            } else {
                mystr = "";
            }

            // flag type for determining the matching behavior (in this case on string objects)
            smatch m;
            // regex_search that searches pattern regexp in the string mystr
            if (regex_search(s, m, regexp)) {
                row++;
                if (s[0] == ' ') {
                    s = s.substr(1, s.size());
                }
                s = s.substr(1, s.size() - 1);
                stringstream ss(s);
                string word;
                col = 0;
                while (ss >> word) {
                    if (word[word.size() - 1] == ']') {
                        word = word.substr(0, word.size() - 1);
                    }
                    if (word[0] == '[') {
                        word = word.substr(1, word.size());
                    }
                    double num = stod(word);
                    v.push_back(num);
                    col++;
                }
            }


        }
        matrix.mat = v;
        matrix.row = row;
        matrix.column = col;
        if (v.size() != row * col) {
            throw std::out_of_range{"Invalid values"};
        }
        return is;
    }


    Matrix::~Matrix() {
    }
}