#pragma once

#include "Pair.h"
#include "Vertex.h"



//template representing an edge in the graph 
//typenme t refers to the data type stored in the vertices 
//typename U refers to the data type stored in edges 
template <typename T, typename U>

class Edge
{


protected:

	//Pair of vertices represets the edge. the irst nmber of the paur is the
	//initial vertex of the ge, and the second number of the pair is the terminal vertex of the edge 
	Pair < Vertex<T>, Vertex<T> >* theEdge;



	//Edgeweight parameter can be use dto represent the distance between vertices 
	//etc.
	double edgeWeight;




	//pointer to the data stored in this edge 
	U* data;






public:

	//creates an edge with the given termal and vertices the Edge 
	//contains no data. the defualt edge weight is one 
	Edge(Vertex<T>* initialVertex, Vertex<T>* termianlVertex) {
		theEdge = new Pair<Vertex<T>, Vertex<T>>(initialVertex, termianlVertex);
		this->edgeWeight = 1;
		this->data = nullptr;
	}


	//getter for the data attribute
	U* getData() {
		return this->data;
	}

	//setter for the data attribute 
	void setData(U* data) {
		this->data = data;
	}


	//Getter for the inital vertex
	Vertex<T>* getInitialVertex() {
		return theEdge->first;
	}


	//getter for the terminal vertex
	Vertex<T>* getTerminalVertex() {
		return theEdge->second;
	}


	//getter for the edge weight attribute 
	double getWeight() {
		return edgeWeight;
	}


	//setter for the edge weight attribute 
	void setWeight(double weight) {
		edgeWeight = weight;
	}

	//Return true if and only if the initaial and terminal vertices are 
	//identical.
	bool isLoop() {
		return theEdge->first == theEdge->second;
	}


	// Returns a string representation of this edge 
	std::string toString() {
		std::string result = "";
		result += "(" + theEdge->first->toString() + ", " + theEdge->second->toString() + ")";
		return result;

	}

};

template <typename T, typename U>
bool operator==(Edge<T, U>& lhs, Edge<T, U>& rhs) {
	std::cout << "*" << std::endl;
	return (lhs.getTerminalVertex() == rhs.getTerminalVertex() && lhs.getInitialVertex() == rhs.getInitialVertex() && lhs.getWeight() == rhs.getWeight() && lhs.getData() == rhs.getData());
}

template <typename T, typename U>
bool operator!=(Edge<T, U>& lhs, Edge<T, U>& rhs) {
	std::cout << "*" << std::endl;
	return !(lhs == rhs);
}




