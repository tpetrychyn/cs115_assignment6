//
//  PathWalked.cpp
//  assignment6
//
//  Created by Taylor Petrychyn on 2014-12-02.
//  Copyright (c) 2014 Taylor Petrychyn. All rights reserved.
//

#include "PathWalked.h"
#include <math.h>
#include <iostream>

PathWalked::PathWalked() {
    head = NULL;
    count = 0;
}
void PathWalked::clear() {
    if (count == 0)
        return;
    Element *delPtr;
    Element *currPtr;
    delPtr = head; //set pointer to be delete at head
    currPtr = head->next; //set a pointer one step ahead to maintain position
    while(currPtr->next != NULL) { //while we arent at the last element
        delete delPtr; //delete pointer to be deleted (one step behind our current pointer)
        delPtr=currPtr; //set delete to current
        currPtr = currPtr->next; //set current to next
    }
    delete currPtr; //once we're done delete current
    delete head; //delete head too
    
    count = 0;
    totalPath = 0;
}

Element* PathWalked::copyLinkedList(Element* head) {
    Element* newHead;
    Element* currPtr;
    Element* newNodePtr;
    Element* copyListPtr = head;
    
    if(copyListPtr->next == NULL){
        return NULL;
    }
    newNodePtr = new Element(copyListPtr->datum, NULL); //create new node
    newHead = newNodePtr; //set newHead to the pointer to that node
    currPtr = newHead; //set our current pointer to newHead
    
    while (copyListPtr->next != NULL) { //as long as there are more links
        copyListPtr = copyListPtr->next; //set our copy pointer to our next element
        newNodePtr = new Element(copyListPtr->datum, NULL); //create a new node with the datum from the copy pointer
        currPtr->next = newNodePtr; //link our current node to our new one
        currPtr=newNodePtr; //set our current pointer to our new one
    }
    
    return newHead;
}

bool PathWalked::empty() const {
    return (head == NULL);
}

float PathWalked::getPathLength() const {
    return totalPath;
}

void PathWalked::add(const Vector2<float>& position) {
    if (head!=NULL) {
        Vector2<float> C;
        C.x = fabs(head->datum.x - position.x);
        C.y = fabs(head->datum.y - position.y);

        totalPath += C.getNorm();
    }
    
    Element* newNodePtr;
    
    newNodePtr = new Element(position, head);
    head = newNodePtr;
    
}

void PathWalked::print() const {
    Element *currPtr;
    currPtr = head; //set a pointer one step ahead to maintain position
    while(currPtr != NULL) { //while we arent at the last element
        cout << "(" << currPtr->datum.x << ", " << currPtr->datum.y << ")" << endl;
        currPtr = currPtr->next;
    }
}

/*Add a public add function that takes a Vector2<float> as a parameter.  If there is already at least one element in the linked list, calculate the distance between its position and the position parameter.  Then add this distance onto the total length for the path.  Otherwise this is the first position in the path and the total distance should remain 0.  In either case, create a new Element for this position and add it onto the front of the linked list.
 You may need a special case for adding the first Element.
 You can calculate the distance between two positions by subtracting one from the other and taking the norm of the difference.*/