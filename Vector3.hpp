#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <cmath>
#include <ostream>

template <typename T>
struct Vector3 {
    Vector3();
    Vector3(Vector3<T>& other);
    Vector3(T x, T y, T z);

    T dot(const Vector3<T>& other) const;
    Vector3<T> cross(const Vector3<T>& other) const;
    T magnitude() const;
    T distance(const Vector3<T>& other) const;
    T angle(const Vector3<T>& other) const;
    Vector3<T> normalise() const;
    Vector3<T> operator+(const Vector3<T>& other) const;
    Vector3<T> operator-(const Vector3<T>& other) const;
    Vector3<T>& operator=(const Vector3<T>& other);
    bool operator==(const Vector3<T>& other) const;

    friend std::ostream& operator<<(std::ostream& out, Vector3<T>& vec) {
        return out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    }

    T x, y, z;
};

// Default constructor
template <typename T>
Vector3<T>::Vector3() {
    x = 0;
    y = 0;
    z = 0;
}

// Copy constructor
template <typename T>
Vector3<T>::Vector3(Vector3<T>& other) {
   *this == other;
}

// Constructor with member initialisation
template <typename T>
Vector3<T>::Vector3(T x, T y, T z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Calculate the dot product of two vectors
template <typename T>
T Vector3<T>::dot(const Vector3<T>& other) const {
    return x * other.x + y * other.y + z * other.z;
}

// Calculate the cross product of two vectors
template <typename T>
Vector3<T> Vector3<T>::cross(const  Vector3<T>& other) const {
    // 
    T cx = y * other.z - z * other.y;
    T cy = z * other.x - x * other.z;
    T cz = x * other.y - y * other.x;

    return Vector3<T>(cx, cy, cz);
}

// Returns the length of the vector
template <typename T>
T Vector3<T>::magnitude() const {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

// Returns the distance from this vector to another
template <typename T>
T Vector3<T>::distance(const Vector3<T>& other) const {
    Vector3<T> intermediary = *this - other;
    return intermediary.magnitude();
}

// Returns the angle between this and the specified vector
template <typename T>
T Vector3<T>::angle(const Vector3<T>& other) const {
    T mag_this = magnitude();
    T mag_other = other.magnitude();
    T cosTheta = dot(other) / (mag_this * mag_other);
    return acos(cosTheta);
}

// Returns a vector with a length of 1 in the same direction as the original
template <typename T>
Vector3<T> Vector3<T>::normalise() const {
    T mag = magnitude();
    return Vector3<T>(x / mag, y / mag, z / mag);
}

// TODO: 3d vector rotation
//Vector3<T> Vector3<T>::rotate

// Add two vectors together
template <typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T>& other) const {
    return Vector3<T>(x + other.x, y + other.y, z + other.z);
}

// Subtract vectors from one another
template <typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T>& other) const {
    return Vector3<T>(x - other.x, y - other.y, z - other.z);
}

// Assignment operator
template <typename T>
Vector3<T>& Vector3<T>::operator=(const Vector3<T>& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

// Equality
template <typename T>
bool Vector3<T>::operator==(const Vector3<T>& other) {
    return x == other.x && y == other.y && z == other.z;
}

// Typedef common types of Vector3 for convenience
typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;
typedef Vector3<long double> Vector3l;

#endif // VECTOR3_HPP
