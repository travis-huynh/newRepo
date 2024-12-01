/*

Header file for single linked list class library

*/

#ifndef slist
#define slist

#include <string>

class Airport;

struct Node;

class Slist {
    private:
        Node* head;
        int length;
    public:
        Slist();
        ~Slist();


        Node* getNode();
        
        void setNode(Node* node);

        void add(Airport* value);				//Adds a new value to the end of this list.

        void clear();					//Removes all elements from this list.

        bool equals(Slist list);			//Returns true if the two lists contain the same elements in the same order.

        Airport* get(int index);				//Returns the element at the specified index in this list.

        void insert(int index, Airport *value);		//Inserts the element into this list before the specified index.

        void exchg(int index1, int index2);		//Switches the payload data of specified indexex.

        void swap(int index1, int index2);		//Swaps node located at index1 with node at index2

        bool isEmpty();				//Returns true if this list contains no elements.

        // mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.

        Airport* remove(int index);			//Removes the element at the specified index from this list.

        void set(int index, Airport *value);		//Replaces the element at the specified index in this list with a new value.

        int size();					//Returns the number of elements in this list.

        Slist subList(int start, int length);	//Returns a new list containing elements from a sub-range of this list.

        std::string toString();				//Converts the list to a printable string representation.

};

#endif