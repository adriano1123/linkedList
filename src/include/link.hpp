/*
*   File: link.hpp
*   Author: Adrian
*/

#ifndef LINK_HPP
#define LINK_HPP

template <class dataType>
class Link
{
private:
    class Node
    {
    private:
        Node *next;
        Node *prev;
        dataType data;
    };

    int size;
    Node *head;

public:
    Link();
    Link(const Link &aList);
    Link(Node *head);

    ~Link();

    bool isEmpty();
    int getLength();
    void add(int index, dataType data);
    void remove(int index);
    dataType retrieve(int index);
    dataType extract(int index);
    void printLinkedList();
    void removeDuplicates();
    Node *find(int index);
};

#endif