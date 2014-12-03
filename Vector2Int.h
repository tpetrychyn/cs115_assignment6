/*
 */

#ifndef VECTOR2INT_H
#define VECTOR2INT_H

class Vector2Int {
    
public:
    int x, y;
    Vector2Int();
    Vector2Int(const int& x1, const int& y1);
    Vector2Int& operator=(const Vector2Int& original);
    ~Vector2Int();
    Vector2Int(const Vector2Int& original);
    bool operator==(const Vector2Int& other) const;
    Vector2Int operator+ (const Vector2Int& addend) const;
    Vector2Int operator- (const Vector2Int& subtrahend) const;
    float getNorm() const;
    
};

#endif