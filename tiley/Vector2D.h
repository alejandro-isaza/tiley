//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#pragma once


namespace mcw {

class Vector2D {
public:
    using Type = double;

public:
    Vector2D() = default;
    Vector2D(Type x, Type y) : _x(x), _y(y) {}

    Type x() const { return _x; }
    Type y() const { return _y; }

    void setX(Type x) { _x = x; }
    void setY(Type y) { _y = y; }

    Type magnitudeSquared() const {
        return _x*_x + _y*_y;
    }

    // Operators
    Vector2D& operator+=(const Vector2D& rhs) {
        _x += rhs._x;
        _y += rhs._y;
        return *this;
    }
    Vector2D& operator-=(const Vector2D& rhs) {
        _x -= rhs._x;
        _y -= rhs._y;
        return *this;
    }
    Vector2D& operator*=(Type scale) {
        _x *= scale;
        _y *= scale;
        return *this;
    }
    Vector2D& operator/=(Type scale) {
        _x /= scale;
        _y /= scale;
        return *this;
    }

private:
    Type _x = 0;
    Type _y = 0;
};

inline Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs) {
    auto result = lhs;
    result += rhs;
    return result;
}

inline Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs) {
    auto result = lhs;
    result -= rhs;
    return result;
}

inline Vector2D::Type operator*(const Vector2D& lhs, const Vector2D& rhs) {
    return lhs.x() * rhs.x() + lhs.y() * rhs.y();
}

} // namespace mcw
