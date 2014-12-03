//
//  Vector2.cpp
//  assignment6
//
//  Created by Taylor Petrychyn on 2014-12-02.
//  Copyright (c) 2014 Taylor Petrychyn. All rights reserved.
//

#include "Vector2.h"
#ifndef VECTOR2_CPP
#define VECTOR2_CPP


#include <math.h>

template <typename ItemType>
Vector2<ItemType>::Vector2(): x(),y() {
    
}

template <typename ItemType>
Vector2<ItemType>::Vector2(const ItemType& x1, const ItemType& y1) {
    x = x1;
    y = y1;
}

template <typename ItemType>
Vector2<ItemType>& Vector2<ItemType>::operator=(const Vector2<ItemType>& original) {
    if(&original != this)	// don't assign to itself
    {
        x = original.x;
        y = original.y;
    }
    return *this;
}

template <typename ItemType>
Vector2<ItemType>::~Vector2() {}

template <typename ItemType>
Vector2<ItemType>::Vector2(const Vector2<ItemType>& original) {
        x= original.x;
        y= original.y;
}

template <typename ItemType>
bool Vector2<ItemType>::operator==(const Vector2<ItemType>& other) const {
    return (x == other.x && y == other.y);
}

template <typename ItemType>
Vector2<ItemType> Vector2<ItemType>::operator+ (const Vector2<ItemType>& addend) const {
    Vector2 newOne(*this);
    newOne.x += addend.x;
    newOne.y += addend.y;
    return newOne;
}

//TODO: FIX TO SUBTRACT
template <typename ItemType>
Vector2<ItemType> Vector2<ItemType>::operator- (const Vector2<ItemType>& subtrahend) const {
    Vector2<ItemType> temp;
    temp.x = x + subtrahend.x;
    temp.y = y + subtrahend.y;
    return temp;
}

template <typename ItemType>
float Vector2<ItemType>::getNorm() const {
    return sqrt(x*x + y*y);
}


#endif
