//**************************************************************************************
//* Name: Sample linked lists                                                         *
//* Description: Linked Lists                                                          *
//* This program contains the declaration and implementation of all of the methods      *
//* declared for the template class UnorderedLinkedList. This class also inherits      *
//* some methods declared and implemented in LinkedListType
//* UnorderedLinkedList                                                                *
//**************************************************************************************
#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedList.h"
#include <iostream>

using namespace std;

template <class Type>
class UnorderedLinkedList:public LinkedListType<Type> {
public:
    
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the
    //               list, otherwise the value false is
    //               returned.
    bool search(Type& searchItem);

    
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    //               inserted at the beginning of the list,
    //               last points to the last node in the
    //               list, and count is incremented by 1.
    void insertFirst(const Type& newItem);

    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem
    //               is inserted at the end of the list,
    //               last points to the last node in the
    //               list, and count is incremented by 1.
    void insertLast(const Type& newItem);      
   
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing
    //               deleteItem is deleted from the list.
    //               first points to the first node, last
    //               points to the last node of the updated
    //               list, and count is decremented by 1.
    void deleteNode(const Type& deleteItem);
};


template <class Type>
bool UnorderedLinkedList<Type>::search(Type& searchItem) {
    NodeType<Type> *current; //pointer to traverse the list
    bool found = false;

    current = this->top; //set current to point to the first
                     //node in the list

    while (current != nullptr && !found)    //search the list
        if ((current->info) == searchItem) //searchItem is found
            found = true;
        else
            current = current->next; //make current point to
                                     //the next node
    return found;
}//end search

template <class Type>
void UnorderedLinkedList<Type>::insertFirst(const Type& newItem) {
    NodeType<Type> *newNode; //pointer to create the new node

    newNode = new NodeType<Type>; //create the new node

    newNode->info = newItem;
    if (this->isEmptyList()){
        newNode->next = nullptr;
        top = newNode;
        bottom = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
    this->count++;

    // TODO:
    //store the new item in the node
    //insert newNode before first
    //make first point to the
    //actual first node
    //increment count
    //if the list was empty, newNode is also
    //the last node in the list
}//end insertFirst

template <class Type>
void UnorderedLinkedList<Type>::insertLast(const Type& newItem) {
    NodeType<Type> *newNode; //pointer to create the new node

    newNode = new NodeType<Type>; //create the new node

    newNode->info = newItem;        //store the new item in the node
    newNode->next = nullptr;        //set the link field of newNode to nullptr

    // TODO Case 1: if the list is empty, newNode is
    // both the first and last node
    if (this->isEmptyList()){
        top = newNode;
        bottom = newNode;
    } else {
        bottom->next = newNode;
        bottom = newNode;
    }
    
    // TODO Case 2: the list is not empty, insert newNode after last
    // TODO Case 3:
    //insert newNode after last
    //make last point to the actual
    //last node in the list
    //increment count
    count++;
}//end insertLast


template <class Type>
void UnorderedLinkedList<Type>::deleteNode(const Type& deleteItem) {
    NodeType<Type> *current; //pointer to traverse the list
    NodeType<Type> *trailCurrent; //pointer just before current
    current = top->next;
    trailCurrent = top;
    if (deleteItem == trailCurrent){
        top = current;
        delete trailCurrent;
        count--;
        return;
    }
    while (current != nullptr)
    {
        if (current->info == deleteItem){
            trailCurrent->next = current->next;
            delete current;
            break;
        }
        current = current->next;   
        trailCurrent = trailCurrent->next;
    }
    count--;
}//end deleteNode


#endif
