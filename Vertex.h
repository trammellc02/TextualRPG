#pragma once

#include <sstream>
#include <string>

#include "List.h"

/*
 A Vertex is a container that supports multiple previous nodes (called
 incoming vertices) and multiple next nodes (called outgoing vertices).
 */
template <typename T>
class Vertex {

protected:

    /*
     Pointer to the data stored in this vertex.
     */
    T* data;

    /*
     List of incoming vertices.
     */
    List<Vertex<T>>* previousNodes;

    /*
     List of outgoing vertices.
     */
    List<Vertex<T>>* nextNodes;

public:

    /*
     Creates an empty vertex: no data, no incoming nodes, no outgoing nodes.
     */
    Vertex() {
        this->data = nullptr;
        this->previousNodes = new List<Vertex<T>>();
        this->nextNodes = new List<Vertex<T>>();
    }

    /*
     Creates a vertex containing the specified data, but with no incoming or
     outgoing vertices.
     */
    Vertex(T* data) {
        this->data = data;
        this->previousNodes = new List<Vertex<T>>();
        this->nextNodes = new List<Vertex<T>>();
    }

    /*
     Returns a pointer to the data stored in this vertex.
     */
    T* getData() {
        return this->data;
    }

    /*
     Sets the data stored by this node to the specified value.
     */
    void setData(T* data) {
        this->data = data;
    }

    /*
     Returns the number of incoming vertices to this one.
     */
    int getInDegree() {
        return this->previousNodes->getSize();
    }

    /*
     Returns the number of outgoing vertices from this one.
     */
    int getOutDegree() {
        return this->nextNodes->getSize();
    }

    /*
     Returns true if and only if the specified vertex is an incoming vertex
     to this one.
     */
    bool hasInVertex(Vertex<T>* vertex) {
        int ndx = this->previousNodes->getIndex(vertex);
        return (ndx >= 0);
    }

    /*
     Retrieves the incoming vertex with the specified index. Note that
     indices are assigned to incoming vertices in the order that they
     are added: the first incoming vertex added to this one has index
     0, the second has index 1, and so on.
     */
    Vertex<T>* getInVertex(int index) {
        return this->previousNodes->peek(index);
    }

    /*
     Adds the specified vertex to the list of incoming vertices to this
     vertex. Note that indices are assigned to incoming vertices in the
     order that they are added: the first incoming vertex added to this
     one has index 0, the second has index 1, and so on.
     */
    void addInVertex(Vertex<T>* inVertex) {
        int ndx = this->previousNodes->getIndex(inVertex);
        if (ndx < 0) {
            this->previousNodes->add(inVertex);
            inVertex->nextNodes->insertAtEnd(this);
        }
    }

    /*
     Removes the specified vertex from the list of incoming vertices to
     this one. Note that this will change the indices of subsequent
     incoming vertices.
     */
    T* removeInVertex(int index) {
        return this->previousNodes->remove(index);
    }

    /*
     Returns true if and only if the specified vertex is an outgoing vertex
     from this one.
     */
    bool hasOutVertex(Vertex<T>* vertex) {
        int ndx = this->nextNodes->getIndex(vertex);
        return (ndx >= 0);
    }

    /*
     Adds the specified vertex to the list of outgoing vertices to this
     vertex. Note that indices are assigned to outgoing vertices in the
     order that they are added: the first outgoing vertex added to this
     one has index 0, the second has index 1, and so on.
     */
    Vertex<T>* getOutVertex(int index) {
        return this->nextNodes->peek(index);
    }

    /*
     Adds the specified vertex to the list of outgoing vertices to this
     vertex. Note that indices are assigned to outgoing vertices in the
     order that they are added: the first outgoing vertex added to this
     one has index 0, the second has index 1, and so on.
     */
    void addOutVertex(Vertex<T>* outVertex) {
        int ndx = this->nextNodes->getIndex(outVertex);
        //if ndx >= 0, outVertex is already an outgoing vertex, so
        // we do nothing otherwise we add the outvertex to our list 
        // of outgoing vertices
        if (ndx < 0) {
            this->nextNodes->insertAtStart(outVertex);
            outVertex->previousNodes->insertAtEnd(this);
        }
    }

    /*
     Removes the specified vertex from the list of outgoing vertices to
     this one. Note that this will change the indices of subsequent
     outgoing vertices.
     */
    T* removeOutVertex(int index) {
        return this->nextNodes->remove(index);
    }

    /*
     Returns a string representation of this vertex.

     Example output:

        For a Vertex with data:

           Vertex at <address of this vertex>
           Indegree is <num incoming nodes>
           Outdegree is <num outgoing nodes>
           Data at <address of data>

        For a Vertex with no data:

           Vertex at <address of this vertex>
           Indegree is <num incoming nodes>
           Outdegree is <num outgoing nodes>
           No data

     */
    std::string toString() {
        std::ostringstream sout;
        sout << "vertex at " << this << std::endl;
        sout << "indegree is " << this->getInDegree() << std::endl;
        sout << "Outdegree is " << this->getOutDegree() << std::endl;
        if (this->data != nullptr) {
            sout << "Data at " << this->data << std::endl;
        }
        else {
            sout << "no data";
        }
        return sout.str();
    }
};

