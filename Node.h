#pragma once
#include <string>
#include <iostream>
#include <sstream>


template <typename T>
class Node {
protected:
    T* data; // Pointer to data of type T

    Node<T>* nextNode; // Pointer to the next node in the list

    Node<T>* previousNode; // pointer to the previous node 

public:
    Node() {
        this->nextNode = nullptr;
        this->data = nullptr;
        this->previousNode = nullptr;
    }; // Default constructor

    Node(T* data) { // Parameterized constructor that takes a pointer to data of type T and sets the next node to null
        this->data = data;
        nextNode = nullptr;
        this->previousNode = nullptr;
    }

    T* getData() { // Method to get the data pointer
        return data;
    }

    void setData(T* data) { // Method to set the data pointer
        this->data = data;
    }

    Node<T>* getNextNode() { // Method to get the next node pointer
        return nextNode;
    }

    void setNextNode(Node<T>* nextNode) { // Method to set the next node pointer
        this->nextNode = nextNode;
    }

    Node<T>* getPreviousNode() { // Method to get the previous node pointer
        return previousNode;
    }

    void setPreviousNode(Node<T>* previousNode) { // Method to set the previous node pointer
        this->previousNode = previousNode;
    }


    std::string toString() { // Method to return a string representation of the node
        std::ostringstream sout; // Create an output string stream
        sout << "Node at " << this << std::endl; // Print the node address
        if (data == nullptr) { // If the data pointer is null print a message indicating there is no data
            sout << "No data" << std::endl;
        }
        else { // Otherwise
            sout << "data at " << data << std::endl; // Print the data address
        }
        if (nextNode == nullptr) { // If the next node pointer is null print a message indicating there is no next node
            sout << "No next node" << std::endl;
        }
        else { // Otherwise
            sout << "nextNode at " << nextNode << std::endl; // Print the next node address
        }
        if (previousNode == nullptr) { // If the previous node pointer is null print a message indicating there is no previous node
            sout << "No previous node" << std::endl;
        }
        else { // Otherwise
            sout << "previous node at " << previousNode; // Print the previous node address
        }
        return sout.str(); // Return the string representation of the node
    }
};

