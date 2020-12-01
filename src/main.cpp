/*
*   File: main.cpp
*   Author: Adrian
*/

#include <iostream>
#include "include/link.hpp"

int main(int argc, char *argv[])
{
	Link<int> list; 
	list.add(1,5); 
	list.add(2,3); 
	list.add(5,4); 

	list.printLinkedList(); 

	Link<bool> listbooll; 
	listbooll.add(1, true); 
	listbooll.add(2,false); 

	listbooll.printLinkedList();
}