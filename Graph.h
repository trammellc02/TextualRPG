#pragma once

#include <sstream>
#include <string>
#include <cmath>

#include "Vertex.h"
#include "Edge.h"

/*
A templated class to represent directed graphs. The vertices of the graph can
store pointers to data of type T, and the edges of the graph can store pointers
to data of type U.
*/
template <typename T, typename U>
class Graph {

protected:

	/*
	This list contains the vertices that are part of this graph.
	*/
	List<Vertex<T>>* vertices;

	/*
	This list contains the edges that are part of this graph.
	*/
	List<Edge<T, U>>* edges;

public:

	/*
	Creates an empty graph: no vertices (and therefore no edges)
	*/
	Graph() {
		this->edges = new List<Edge<T, U>>();
		this->vertices = new List<Vertex<T>>();
	}

	/*
	Returns true if and only if this graph is empty.
	*/
	bool isEmpty() {
		return this->vertices->isEmpty();
	}

	/*
	Returns the number of vertices in this graph.
	*/
	int getNumVertices() {
		return this->vertices->getSize();
	}

	/*
	Returns a pointer to a list containing pointers to all the vertices in
	this graph.
	 */
	List<Vertex<T>>* getVertices() {
		return this->vertices;
	}

	/*
	Returns the number of edges in this graph.
	*/
	int getNumEdges() {
		return this->edges->getSize();
	}

	/*
	 Returns a pointer to a list containing pointers to all the edges in
	 this graph.
	*/
	List<Edge<T, U>>* getEdges() {
		return this->edges;
	}


	/*
	Returns the in-degree of the specified vertex, or a negative number if
	the specified vertex is not part of this graph.
	*/
	int getInDegree(Vertex<T>* vertex) {
		if (!hasVertex(vertex)) {
			return -1;
		}
		int count = 0;
		for (int i = 0; i < edges->getSize(); i++) {
			if (edges->get(i)->getToVertex() == vertex) {
				count++;
			}
		}
		return count;
	}


	/*
	Returns the out-degree of the specified vertex, or a negative number if
	the specified vertex is not part of this graph.
	*/
	int getOutDegree(Vertex<T>* vertex) {
		if (!hasVertex(vertex)) {
			return -1;
		}
		return vertex->getOutVertex();
	}

	/*
	Returns a pointer to the vertex with the given index. If no vertex has
	the given index, this method returns the null pointer.
	*/
	Vertex<T>* getVertex(int index) {
		return this->vertices->peek(index);
	}
	/*
	Adds the specified vertex to this graph. Vertices can't be added more than
	once, so if the specified vertex is already part of this graph, this method
	does nothing.
	*/
	void addVertex(Vertex<T>* vertex) {
		if (hasVertex(vertex)) { // check if the vertex is already present in the graph
			return; // vertex already exists in the graph, do nothing
		}
		else {
			this->vertices->insertAtEnd(vertex);   // add it
		}

	}


	/*
	Returns true if and only if the specified vertex is part of this graph.
	*/
	bool hasVertex(Vertex<T>* vertex) {
		for (int k = 0; k < vertices->getSize(); k++) {
			if (vertices->peek(k) == vertex) { // compare the vertices using the overloaded == operator
				return true;
			}
		}
		return false;
	}

	/*
	Adds a directed edge to this graph, from the "from" vertex to the "to"
	vertex, provided that edge does not already exist. If an edge already
	exists in this graph from the "from" vertex to the "to" vertex, this
	method does nothing. If either of the two input vertices are not already
	part of this graph, they are added. If the "from" and "to" vertices are
	identical, a loop is added to that vertex.
	*/
	void addEdge(Vertex<T>* fromVertex, Vertex<T>* toVertex) {
		// create an Edge from the specified vertices to see whether this edge
		// is already part of the graph
		//Edge<T, U>* newEdge = new Edge<T, U>(fromVertex, toVertex);
		// returns a negative number if newEdge is not part of this graph
		//int edgeNdx = this->edges->getIndex(newEdge);
		int edgeNdx = -1;
		for (int k = 0; k < this->edges->getSize(); k++) {
			Edge<T, U>* edgeK = this->edges->peek(k);
			if (edgeK->getInitialVertex() == fromVertex && edgeK->getTerminalVertex() == toVertex) {
				edgeNdx = k;
				break;
			}
		}
		// if this edge is already in the graph, do nothing. Otherwise:
		if (edgeNdx < 0) {
			Edge<T, U>* newEdge = new Edge<T, U>(fromVertex, toVertex);
			// need to handle a special case: if the from and to vertices
			// are actually the same, then we're adding a edge from that
			// vertex to itself. Otherwise, we're adding an edge between
			// different vertices
			if (fromVertex == toVertex) {
				// get the indices for the from node (which is the same as
				// the to node). If getIndex returns a negative number, it
				// means that the corresponding vertex is not a member of
				// this graph.
				int fromNdx = this->vertices->getIndex(fromVertex);
				// if the vertex is not in the graph, add it
				if (fromNdx < 0) {
					this->vertices->insertAtEnd(fromVertex);
				}
				// add the new edge to this graph
				this->edges->insertAtEnd(newEdge);
				// manage previousNodes and nextNodes. Since the edge goes
				// from a vertex to itself, the vertex is both an incoming
				// and outgoing vertex of itself.
				fromVertex->addOutVertex(fromVertex);
			}
			else {
				// get the indices for the from and to nodes. If getIndex returns
				// a negative number, it means that the corresponding vertex is
				// not a member of this graph.
				int fromNdx = this->vertices->getIndex(fromVertex);
				int toNdx = this->vertices->getIndex(toVertex);
				// if the from vertex is not in the graph, add it
				if (fromNdx < 0) {
					this->vertices->insertAtEnd(fromVertex);
				}
				// if the to vertex is not in the graph, add it
				if (toNdx < 0) {
					this->vertices->insertAtEnd(toVertex);
				}
				// add the new edge to this graph
				this->edges->insertAtEnd(newEdge);
				// manage previousNodes and nextNodes
				fromVertex->addOutVertex(toVertex);
			}
		}
	}


	/*
	Returns true if and only if this graph contains an edge from the "from"
	vertex to the "to" vertex.
	*/
	bool hasEdge(Vertex<T>* from, Vertex<T>* to) {
		for (int i = 0; i < edges->getSize(); i++) {
			Edge<T, U>* edge = edges->peek(i);
			if (edge->getInitialVertex() == from && edge->getTerminalVertex() == to) {// change the getFrom and getTo
				return true;
			}
		}
		return false;
	}


	/*
	Returns a list of the outgoing vertices form the specified vertex. If the
	specified vertex is not part o                                                                                                                                                           f this graph, this method returns the empty
	list.
	*/
	List<Vertex<T>>* getOutgoingVertices(Vertex<T>* vertex) {
		List <Vertex<T>>* result = new List<Vertex<T>>();
		if (this->hasVertex(vertex)) {
			int outDegree = vertex->getOutDegree();
			for (int k = 0; k < outDegree; k++) {
				result->insertAtEnd(vertex->getOutVertex(k));
			}
		}
		return result;
	}

	/*
	Returns a list of the incoming vertices form the specified vertex. If the
	specified vertex is not part of this graph, this method returns the empty
	list.
	*/
	List<Vertex<T>>* getIncomingVertices(Vertex<T>* vertex) {
		List <Vertex<T>>* result = new List<Vertex<T>>();
		if (this->hasVertex(vertex)) {
			int inDegree = vertex->getInDegree();
			for (int k = 0; k < inDegree; k++) {
				result->insertAtEnd(vertex->getInVertex(k));
			}
		}
		return result;
	}

	/*
		Returns the weight of the specified edge. If the specified edge is not
		part of this graph, this method returns NaN (not a number) as a double.
		*/
	U getEdgeWeight(Vertex<T>* fromVertex, Vertex<T>* toVertex) {
		// Iterate over all the edges in the graph and return the weight of
		// the first edge that has the same from and to vertices as the input vertices
		for (int i = 0; i < edges->getSize(); i++) {
			Edge<T, U>* edge = edges->get(i);
			if (edge->getInitialVertex() == fromVertex && edge->getTerminalVertex() == toVertex) {
				return edge->getWeight();
			}
		}
		return std::nan(" ");
		//maybe return -1 or 0
	}

	/*
	Returns the weight of the edge with the given index. If no edge in this
	graph has the given index, this method returns NaN (not a number) as a
	double.
	*/
	double getEdgeWeight(int index) {
		double result = std::nan(" ");
		Edge<T, U>* theEdge = this->edges->peek(index);
		if (theEdge != nullptr) {
			result = theEdge->getWeight();
		}
		return result;
	}

	/*
	Sets the weight of the specified edge. If the specified edge is not
	part of this graph, this method does nothing. If the set operation is
	successful this method returns 0. If it is unsuccessful it returns a
	negative number.
	*/
	int setEdgeWeight(double weight, Vertex<T>* from, Vertex<T>* to) {
		int result = -1;
		int ndx = getEdgeIndex(from, to);
		if (ndx >= 0) {
			this->edges->peek(ndx)->setWeight(weight);
			result = 0;
		}
		return result;

		//for (int k = 0; k < this->edges) {
		//	if (e->getInitialVertex() == from && e->getTerminalVertex() == to) {
		//		(e->setWeight(weight));
		//		return 0; // set operation successful
		//	}
		//}
		//return -1; // set operation unsuccessful
	}


	/*
	Sets the weight of the edge with the given index. If no edge in this
	graph has the given index, this method does nothing. If the set
	operation is successful this method returns 0. If it is unsuccessful
	it returns a negative number.
	*/
	int setEdgeWeight(double weight, int index) {
		int result = -1;
		Edge<T, U>* theEdge = this->edges->peek(index);
		if (theEdge != nullptr) {
			// set its weight
			theEdge->setWeight(weight);
		}
		return result;
	}

	/*
	Stores the specified data in the specified vertex of this graph. If the
	specified vertex is not in this graph, then this method does nothing. If
	the store operation is successful, this method returns 0. If it is
	unsuccessful, this method returns a negative number.
	*/
	int storeInVertex(T* data, Vertex<T>* vertex) {
		if (!hasVertex(vertex)) {
			return -1;
		}
		vertex->setData(data);
		return 0;
	}


	/*
	Stores the specified data in the vertex of this graph with the specified
	index. If no vertex of this graph has the specified index, this method
	does nothing.If the store operation is successful, this method returns 0.
	If it is unsuccessful, this method returns a negative number.
	*/
	int storeInVertex(T* data, int index) {
		Vertex<T>* vertex = this->vertices->peek(index);
		if (vertex != nullptr) {
			vertex->setData(data);
		}
		return 0;
	}


	/*
	Retrieves a pointer to the data that is stored in the specified vertex.
	If the specified vertex is not part of this graph, or if there is no data
	stored in the vertex, this method returns the null pointer.
	*/
	T* getVertexData(Vertex<T>* vertex) {
		if (!hasVertex(vertex)) {
			return nullptr;
		}
		return vertex->getData();
	}


	/*
	Retrieves a pointer to the data that is stored in the vertex with the
	specified index. If no vertex of this graph has the specified index, or
	if there is no data stored in the vertex, this method returns the null
	pointer.
	*/
	T* getVertexData(int index) {
		Vertex<T>* vertex = this->getVertex(index);
		if (vertex == nullptr) {
			return nullptr;
		}
		return vertex->getData();
	}


	/*
	Stores the specified data in the specified edge of this graph. If the
	specified edge is not in this graph, then this method does nothing. If
	the store operation is successful, this method returns 0. If it is
	unsuccessful, this method returns a negative number.
	*/
	int storeInEdge(U* data, Vertex<T>* from, Vertex<T>* to) {
		int result = -1;
		int ndx = getEdgeIndex(from, to);
		if (ndx >= 0) {
			this->edges->peek(ndx)->setData(data);
			result = 0;
		}
		return result;
	}

	/*
	Stores the specified data in the the edge of this graph with the specified
	index. If no edge of this graph has the specified index, this method does
	nothing. If the store operation is successful, this method returns 0. If it
	is unsuccessful, this method returns a negative number.
	*/
	int storeInEdge(U* data, int index) {//x
		int result = -1;
		Edge<T, U>* theEdge = this->edges->peek(index);
		if (theEdge != nullptr) {
			// store the data in the edge
			theEdge->setData(data);
			result = 0;
		}
		return result;
	}


	/*
	Retrieves a pointer to the data that is stored in the specified edge.
	If the specified edge is not part of this graph, or if there is no data
	stored in the edge, this method returns the null pointer.
	getEdge(from, to);
	*/
	U* getEdgeData(Vertex<T>* from, Vertex<T>* to) {//x
		int ndx = getEdgeIndex(from, to);
		return getEdgeData(ndx);
		//Edge<T, U>* edge = this->edges->peek();
		//if (edge != nullptr) {
		//	return edge->getData();
		//}
		//else {
		//	return nullptr;
		//}
	}

	/*
	Retrieves a pointer to the data that is stored in the edge with the
	specified index. If no edge of this graph has the specified index, or
	if there is no data stored in the edge, this method returns the null
	pointer.
	*/
	U* getEdgeData(int index) {//
		Edge<T, U>* theEdge = this->edges->peek(index);
		if (theEdge != nullptr) {
			return theEdge->getData();
		}
		return nullptr;
	}


	/*
	Returns the index of the specified vertex in this graph. If the specified
	vertex is not part of this graph, this method returns a negative number.
	*/
	int getVertexIndex(Vertex<T>* vertex) {//
		for (int k = 0; k < this->vertices->getSize(); k++) {
			if (this->vertices->peek(k) == vertex) {
				// Found the vertex, return its index
				return k;
			}
		}
		// Vertex not found, return a negative number
		return -1;
	}


	/*
	Returns the index of the specified edge in this graph. If the specified
	edge is not part of this graph, this method returns a negative number.
	*/
	int getEdgeIndex(Vertex<T>* from, Vertex<T>* to) {//
		for (int k = 0; k < this->edges->getSize(); k++) {
			Edge<T, U>* edge = this->edges->peek(k);
			if (edge->getInitialVertex() == from && edge->getTerminalVertex() == to) {
				return k;
			}
		}
		return -1;
	}




	/*
	Returns a string representation of this graph.
	*/
	std::string toString() {
		std::ostringstream sout;
		sout << "Graph at " << this << std::endl;
		sout << "Number of vertices: " << this->getNumVertices() << std::endl;
		sout << "Number of edges: " << this->getNumEdges() << std::endl;
		sout << "Storing data of type " << typeid(T).name() << " in vertices " << std::endl;
		sout << "Storing data of type " << typeid(U).name() << " in Edges " << std::endl;
		return sout.str();
	}
};



