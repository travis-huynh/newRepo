#include "slist.h"
#include <iostream>

/*

Class Library File

*/
class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
};

struct Node {
    Airport* data;
    Node* next;

    Node() {
        data = NULL;
        next = nullptr;
    }
    
    Node(Airport* data) {
        data = data;
        next = nullptr;
    }
};

    //Node* head;
    //int length;

    //public:

// Constructor
Slist::Slist() { 
        length = 0;
        head = nullptr;
    };

// Destructor
Slist::~Slist() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
    }

Node* Slist::getNode() {
    return head;
}

void Slist::setNode(Node* node) {
    head = node;
}

void Slist::add(Airport *value){				//Adds a new value to the end of this list.
    Node* newNode = new Node(value);
    
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
 }
void Slist::clear() {			//Removes all elements from this list.
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}
bool Slist::equals(Slist list)	{			//Returns true if the two lists contain the same elements in the same order.
    bool equal = true;
    if(length == list.size()) {
        for(int i = 0; i< length; i++) {
            if(get(i) != list.get(i)) {
                equal = false;
            }
        }
    }
    return equal;
}

Airport* Slist::get(int index) {				//Returns the element at the specified index in this list.
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        if (count == index) {
            return current->data;
        }
        count++;
        Node* next = current->next;
        current = next;
        }
    return NULL;
}
void Slist::insert(int index, Airport* value) {		//Inserts the element into this list before the specified index.
  Node *newNode = new Node();
  newNode->data = value;
  if (index == 0) {
    newNode->next = head;
    head = newNode;
  } else {
    Node *current = head;
    Node *previous = nullptr;

    for (int i = 0; i < index && current != nullptr; i++) {
      previous = current;
      current = current->next;
    }
    if (previous) {
      previous->next = newNode;
    }
    newNode->next = current;
  }
  length++;
}
void Slist::exchg(int index1, int index2) {		//Switches the payload data of specified indexex.
  Airport *temp = get(index1);
  set(index1, get(index2));
  set(index2, temp);
}

void Slist::swap(int index1, int index2) {		//Swaps node located at index1 with node at index2
    Node *temp = head;
}

bool Slist::isEmpty() {			//Returns true if this list contains no elements.
    return !head;
}

Airport* Slist::remove(int index)	{		//Removes the element at the specified index from this list.
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        if (count == index) {
            return current->data;
            delete current;
        }
        count++;
        Node* next = current->next;
        current = next;
        }
    return NULL;
 }
void Slist::set(int index, Airport *value) {	//Replaces the element at the specified index in this list with a new value.
    Node* current = head;
    for (int i=0; i<index; i++) {
        current = current->next;
    }
    current->data = value;
}

int Slist::size() {					//Returns the number of elements in this list.
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
        }
    return count;
 }

Slist Slist::subList(int start, int length){	//Returns a new list containing elements from a sub-range of this list.
    Node* subcurrent = NULL;
    Node* subend = NULL;
    Node* current = head;
    int i = 0;
     
    while(current != NULL && i <= length){

        if(i == start){
            subcurrent = current;
        }
         
        if(i == start+length){
            subend = current;
            subend->next = NULL;
        }
        
        current = current->next;
        i++;
    }
    Slist *sublist = new Slist();
    sublist->head = subcurrent;

    return *sublist;
    
}

std::string Slist::toString()	{           //Converts the list to a printable string representation.
    Node *temp = head;
    std::string comp = "";
    //Check for empty list
    if (head == NULL) {
        comp = "List empty\n";
    }
    while (temp != nullptr) {
        comp = "" + comp + ((*temp).data->code) + std::to_string((*temp).data->latitude) + std::to_string((*temp).data->longitude) + " ";
        temp = temp->next;
    }
    
    return comp;

}			
