#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>
#include <ostream>

template <typename T>
struct Vector2 {
    Vector2();
    Vector2(T x, T y);

    T dot(const Vector2<T>& other) const;
    T magnitude() const;
    T distance(const Vector2<T>& other) const;
    T angle(const Vector2<T>& other) const;
    Vector2<T> normalise() const;
    Vector2<T> operator+(const Vector2<T>& other) const;
    Vector2<T> operator-(const Vector2<T>& other) const;
    Vector2<T>& operator=(const Vector2<T>& other);
    bool operator==(const Vector2<T>& other) const;

    friend std::ostream& operator<<(std::ostream& out, Vector2<T>& vec) {
        return out << "(" << vec.x << ", " << vec.y << ")";
    }

    T x, y;
};

// Default constructor
template <typename T>
Vector2<T>::Vector2() {
    x = 0;
    y = 0;
}

// Constructor with member initialisation
template <typename T>
Vector2<T>::Vector2(T x, T y) {
    this->x = x;
    this->y = y;
}

// Calculate the dot product of two vectors
template <typename T>
T Vector2<T>::dot(const Vector2<T>& other) const {
    return x * other.x + y * other.y;
}

// Returns the length of the vector
template <typename T>
T Vector2<T>::magnitude() const {
    return sqrt(pow(x, 2) + pow(y, 2));
}

// Returns the distance from this vector to another
template <typename T>
T Vector2<T>::distance(const Vector2<T>& other) const {
    Vector2<T> intermediary = *this - other;
    return intermediary.magnitude();
}

// Returns the angle between this and the specified vector
template <typename T>
T Vector2<T>::angle(const Vector2<T>& other) const {
    T mag_this = magnitude();
    T mag_other = other.magnitude();
    T cosTheta = dot(other) / (mag_this * mag_other);
    return acos(cosTheta);
}

// Returns a unit vector in the same direction as the original
template <typename T>
Vector2<T> Vector2<T>::normalise() const {
    T mag = magnitude();
    return Vector2<T>(x / mag, y / mag);
}

// Add two vectors together
template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& other) const {
    return Vector2<T>(x + other.x, y + other.y);
}

// Subtract vectors from one another
template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& other) const {
    return Vector2<T>(x - other.x, y - other.y);
}

// Assignment operator
template <typename T>
Vector2<T>& Vector2<T>::operator=(const Vector2<T>& other) {
    x = other.x;
    y = other.y;
    return *this;
}

// Equality
template <typename T>
bool Vector2<T>::operator==(const Vector2<T>& other) {
    return x == other.x && y == other.y;
}

// Typedef common types of Vector2 for convenience
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;
typedef Vector2<long double> Vector2l;

#endif // VECTOR2_HPP
