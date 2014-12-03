//
//  PathWalked.h
//  assignment6
//
//  Created by Taylor Petrychyn on 2014-12-02.
//  Copyright (c) 2014 Taylor Petrychyn. All rights reserved.
//

#ifndef PATHWALKED_H
#define PATHWALKED_H

#include <stdio.h>
#include "Vector2.h"

struct Element
{
private:
    Vector2<float> datum;
    Element* next;
    
public:
    Element (Vector2<float> _datum, Element* _next): datum(_datum), next(_next){}
    friend class PathWalked;  // gives LinkedList access to datum and next
};

class PathWalked {
private:
    Element* head;
    unsigned int count;
    float totalPath;
    Element* copyLinkedList(Element* head);
    
public:
    PathWalked();
    void clear();
    bool empty() const;
    float getPathLength() const;
    void add(const Vector2<float>& position);
    void print() const;
};

#endif 
