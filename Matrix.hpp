#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <ostream>

template <typename T>
class Matrix {
public:
    Matrix(int rows, int columns);
    Matrix(Matrix<T>& other);

    int rows() const;
    int columns() const;

    T& get(int row, int col);
    Matrix<T> transpose() const;
    Matrix<T> inverse() const;
    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator-(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    Matrix<T>& operator=(const Matrix<T>& other);
    bool operator==(const Vector3<T>& other) const;

    friend std::ostream& operator<<(std::ostream& out, Matrix<T>& mat);

private:
    std::vector<std::vector<T> > data;
};

#endif // MATRIX_HPP
