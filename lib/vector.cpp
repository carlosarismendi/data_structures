/**
 * Dynamic vector data structure implementation.
 * Author: Carlos Eduardo Arismendi Sanchez.
 * GitHub: https://github.com/carlosarismendi
 * LinkedIn: https://www.linkedin.com/in/carlos-arismendi/
*/

#include <iostream>
#include <ostream>
#include "vector.h"

// ============= CONSTRUCTORS =============
// Default constructor.
template<typename T>
vector<T>::vector()
{

}

// Constructor that only reserves memory for size_t elements of type T.
template<typename T>
vector<T>::vector(const size_t &size)
{

}

// Copy constructor.
template<typename T>
vector<T>::vector(const vector<T> &vec)
{

}

// Destructor.
template<typename T>
vector<T>::~vector()
{

}


// ============= OPERATOR OVERLOADS =============
// Assignment operator overload.
template<typename T>
vector<T> & vector<T>::operator=(const vector<T> &vec)
{

}

// Equality operator overload.
template<typename T>
bool vector<T>::operator==(const vector<T> &vec) const
{
	return false;
}

// Inequality operator overload.
template<typename T>
bool vector<T>::operator!=(const vector<T> &vec) const
{
	return false;
}

// L Access[] operator overload.
template<typename T>
T & vector<T>::operator[](const size_t &index)
{

}

// R Access[] operator overload.
template<typename T>
T vector<T>::operator[](const size_t &index) const
{

}


// ============= GETTERS =============
// Return maximum amount of items that fit into the vector.
template<typename T>
inline size_t vector<T>::capacity() const
{
	return capacity_;
}

// Return number of items inserted in the vector.
template<typename T>
inline size_t vector<T>::size() const
{
	return size_;
}

// Returns a boolean indicating if the vector is empty or not.
template<typename T>
inline bool vector<T>::empty() const
{
	return (size == 0);
}


// ============= MODIFIERS =============
// Insert an item of type T at the end of the vector.
template<typename T>
void vector<T>::push_back(const T &element)
{

}

// Remove the last item of the vector.
template<typename T>
void vector<T>::pop_back(const T &element)
{

}

/** Insert an item of type T at the indicated position by size_t.
*		If the given index is greater than the capacity of the vector,
*		the new item will be inserted at the end of the vector
* 	(same as push_back function).
*/
template<typename T>
void vector<T>::insert(const T &element, const size_t &index)
{

}

// Remove from the vector the item of at the position size_t.
template<typename T>
void vector<T>::erase(const size_t &index)
{

}

// Remove all item from the vector and free the reserved memory.
template<typename T>
inline void vector<T>::clear()
{

}

// Resize vector to be size_t items of type T.
template<typename T>
void vector<T>::resize(const size_t &size)
{

}

/**
 *  operator<< overload. This will call the operator<< of every item of
 *	type T in the vector.
*/
// template<typename T>
// std::ostream & operator<<(std::ostream &os, const vector<T> &vec)
// {
// 	return os;
// }


// ============= AUXILIAR METHODS =============
// Copy method used in operator= and copy constructor.
template<typename T>
void vector<T>::copy(const vector<T> &vec)
{

}