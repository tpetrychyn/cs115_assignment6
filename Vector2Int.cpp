#include "Vector2Int.h"
#include <math.h>

Vector2Int::Vector2Int(): x(),y () {
    
}
Vector2Int::Vector2Int(const int& x1, const int& y1) {
    x = x1;
    y = y1;
}
Vector2Int& Vector2Int::operator=(const Vector2Int& original) {
    x = original.x;
    y = original.y;
    return *this;
}
Vector2Int::~Vector2Int() {}

Vector2Int::Vector2Int(const Vector2Int& original) {
    x = original.x;
    y = original.y;
}
bool Vector2Int::operator==(const Vector2Int& other) const {
    return (x == other.x && y == other.y);
}
Vector2Int Vector2Int::operator+ (const Vector2Int& addend) const {
    Vector2Int newOne(*this);
    newOne.x += addend.x;
    newOne.y += addend.y;
    return newOne;
}
Vector2Int Vector2Int::operator- (const Vector2Int& subtrahend) const {
    Vector2Int newOne(*this);
    newOne.x -= subtrahend.x;
    newOne.y -= subtrahend.y;
    return newOne;
}
float Vector2Int::getNorm() const {
    return sqrt(x*x + y*y);
}
