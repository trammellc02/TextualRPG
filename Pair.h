#pragma once

#include <sstream>
#include <string>


/*
 A class to represent paired data. A Pair has a first element and
 a second element. These attributes are publicly accessible, and
 the types of the first and second element can be arbitrary.
 */
template <typename T, typename U>
class Pair {

public:

    /*
     Pointers to the data in this pair.
     */
    T* first;
    U* second;

    /*
     Creates an empty pair.
     */
    Pair() {
        this->first = nullptr;
        this->second = nullptr;
    }

    /*
     Creates a pair whose first and second elements are the specified data.
     */
    Pair(T* first, U* second) {
        this->first = first;
        this->second = second;
    }

    /*
     Returns true if and only if both elements of this pair are null.
     */
    bool isEmpty() {
        return(this->first == nullptr && this->second == nullptr);
    }

    /*
     Returns true if and only if both elements of this pair are non-null.
     */
    bool isComplete() {
        return (this->first != nullptr && this->second != nullptr);
    }

    /*
     Swaps the elements of the pair.
     */
    Pair<U, T>* swap() {
        return new Pair<U, T>(second, first);
    }

    /*// Returns a string representation of this pair. Returns a string
       containing three lines of text giving the addresses of the pair,
       its first attribute, and its second attribute. If either attribute
       is null, the string should say so.

       Example 1: a complete Pair would have the following string representation:

           Pair at <memory address>
           First element at <memory address>
           Second element at <memory address>

       Example 2: An empty Pair would have the following string representation:

           Pair at <memory address>
           No first element
           No second element

       Example 3: a Pair with a first element but no second element would have the string representation:

           Pair at <memory address>
           First element at <memory address>
           No second element

       Example 4: a Pair with no first element but a second element would have the string representation:

           Pair at <memory address>
           No first element
        //   Second element at <memory address>
    */
    std::string toString() {
        std::stringstream ss;
        ss << "Pair at " << this << std::endl;
        if (isEmpty()) {
            ss << "No first element" << std::endl;
            ss << "No second element" << std::endl;
        }
        else if (first != nullptr && second != nullptr) {
            ss << "First element at " << first << std::endl;
            ss << "Second element at " << second << std::endl;
        }
        else if (first != nullptr) {
            ss << "First element at " << first << std::endl;
            ss << "No second element" << std::endl;
        }
        else {
            ss << "No first element" << std::endl;
            ss << "Second element at " << second << std::endl;
        }
        return ss.str();

    }

}; // end template Pair

/*
 Overload operator== to compare two Pairs. This will return
 true if and only if lhs.first and rhs.first both point to the
 same data item AND lhs.second and rhs.second both point to the
 same data item.
 */
template <typename T, typename U>
bool operator==(Pair<T, U>& lhs, Pair<T, U>& rhs) {
    //    std::cout << "operator== here" << std::endl;
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}



