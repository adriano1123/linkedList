/*
*   File: link.cpp
*   Author: Adrian
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/link.hpp"

using namespace std; 

template <typename dataType> 
Link<dataType>::~Link() {
    while(!isEmpty()) {
        remove(0);
    }
}

template <typename dataType> 
Link<dataType>::Link() {
    size = 0; 
    head = NULL; 
}

template <typename dataType> 
Link<dataType>::Link(Node* aHead) {
    size = 0; 
    head = aHead; 
    for(Node* curr = head; curr != NULL; curr = curr->next) {
        size++;
    }
}

template <typename dataType> 
Link<dataType>::Link(const Link& aList) {
    size = aList.size; 

    head = new Node; 
    head -> data = aList.head->data; 
    Node *cur = head; 

    for(Node *curr = aList.head; curr != NULL; curr = curr->next) {
        curr -> next = new Node; 
        curr = curr->next; 
        curr -> data = curr->data; 
    }

    cur -> next = NULL;
}

template <typename dataType> 
void Link<dataType>::add(int index, dataType data) {
    if(index < 0) {
        cout << "No, negative index" << endl; 
        return;
    } 

    if(index > size) {
        cout << "Not Permited" << endl; 
        return; 
    }

    if(index == 0) {
        Node *newHead = new Node; 
        newHead -> next = head; 
        newHead -> data = data; 
        head = newHead; 
    } else {
        Node *prev = find(index - 1); 
        Node node = new Node; 
        node -> next = prev -> next; 
        node -> data = data; 
        prev -> next = node;
    }
    size++;
}


template <typename dataType> 
dataType Link<dataType>::extract(int index) {
    if(index < 0 || index >= size) {
        cout << "Wrong" << endl; 
        return 0; 
    }

    Node* node = find(index); 
    dataType retData = node -> data; 
    remove(index); 
    node = NULL; 
    return retData; 
}

template <typename dataType> 
void Link<dataType>::remove(int index) {
    if(size == 0) {
        cout << "No item" << endl; 
        return; 
    } else if(index >= size || index < 0) {
        cout << "Nothing there" << endl; 
        return;
    }

    Node *curr; 

    if(index == 0) {
        curr = head; 
        head = head->next; 
    } else {
        Node *prev = find(index - 1); 
        curr = prev->next; 
        prev->next = curr->next; 
    }

    curr->next = NULL; 
    delete curr; 
    curr = NULL; 
    size--; 
}

template <typename dataType> 
typename Link<dataType>::Node* Link<dataType>::find(int index) {
    Node *curr = head; 
    for(int i = 0; i < index; i++) {
        curr = curr->next; 
    }
    return curr; 
}

template <typename dataType> 
bool Link<dataType>::isEmpty() {
    return (size ==0) ? true : false; 
}

template <typename dataType> 
void Link<dataType>::printLinkedList() {
    for(Node *curr = head; curr != NULL; curr = curr->next) {
        cout << curr -> data << endl; 
    }
    cout << endl; 
}