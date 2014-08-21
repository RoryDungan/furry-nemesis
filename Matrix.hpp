#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <ostream>

template <typename T>
class Matrix {
public:
    Matrix(unsigned int rows, unsigned int columns);
    Matrix(Matrix<T>& other);

    virtual ~Matrix();

    unsigned int rows() const;
    unsigned int columns() const;

    T& get(unsigned int row, unsigned int col);
    Matrix<T> transpose() const;
    Matrix<T> inverse() const;
    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator-(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    Matrix<T>& operator=(const Matrix<T>& other);
    bool operator==(const Vector3<T>& other) const;

    friend std::ostream& operator<<(std::ostream& out, Matrix<T>& mat);

private:
    T* data;
    const unsigned int rows, columns;
};

// Allocate array
template <typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int columns) : 
                this->rows = rows, this->columns = columns {
    data = new T[rows * columns];
}

template <typename T>
Matrix<T>::~Matrix() {
    // Free memory
    delete[] data;
}

template <typename T>
T& Matrix<T>::get(unsigned int row, unsigned int col) {
    return data[row * (col + 1)];
}

#endif // MATRIX_HPP
