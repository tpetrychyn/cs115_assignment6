//
//  Vector2.h
//  assignment6
//
//  Created by Taylor Petrychyn on 2014-12-02.
//  Copyright (c) 2014 Taylor Petrychyn. All rights reserved.
//

#ifndef VECTOR2_H
#define VECTOR2_H

using namespace std;

template <typename ItemType>

class Vector2 {
    
public:
    ItemType x, y;
    Vector2();
    Vector2(const ItemType& x1, const ItemType& y1);
    Vector2<ItemType>& operator=(const Vector2<ItemType>& original);
    ~Vector2();
    Vector2(const Vector2<ItemType>& original);
    bool operator==(const Vector2<ItemType>& other) const;
    Vector2<ItemType> operator+ (const Vector2<ItemType>& addend) const;
    Vector2<ItemType> operator- (const Vector2<ItemType>& subtrahend) const;
    float getNorm() const;
    
};

#include "Vector2.cpp"
#endif
