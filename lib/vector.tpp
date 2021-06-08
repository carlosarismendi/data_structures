/**
 * Dynamic vector data structure implementation.
 * Author: Carlos Eduardo Arismendi Sanchez.
 * GitHub: https://github.com/carlosarismendi
 * LinkedIn: https://www.linkedin.com/in/carlos-arismendi/
*/

#include <iostream>
#include <ostream>
#include <stdexcept> // std::out_of_range
#include "vector.h"


// ============= CONSTRUCTORS =============
// Default constructor.
template<typename T>
vector<T>::vector(): size_(0), capacity_(0), data_(nullptr)
{}

// Constructor that only reserves memory for size_t elements of type T.
template<typename T>
vector<T>::vector(const size_t &size): size_(0), capacity_(size)
{
	data_ = new T[size];
}

// Copy constructor.
template<typename T>
vector<T>::vector(const vector<T> &vec)
{
	data_ = nullptr;
	copy(vec);
}

// Destructor.
template<typename T>
vector<T>::~vector()
{
	if(data_ != nullptr)
	{
		delete[] data_;
		data_ = nullptr;
	}

	size_ = 0;
	capacity_ = 0;
}


// ============= OPERATOR OVERLOADS =============
// Assignment operator overload.
template<typename T>
vector<T> & vector<T>::operator=(const vector<T> &vec)
{
	if(this != &vec)
		copy(vec);

	return *this;
}

// Equality operator overload.
template<typename T>
bool vector<T>::operator==(const vector<T> &vec) const
{
	if(size_ != vec.size_ || capacity_ != vec.capacity_)
		return false;

	for(size_t i = 0; i < vec.size_; ++i)
		if(data_[i] != vec[i])
			return false;

	return true;
}

// Inequality operator overload.
template<typename T>
bool vector<T>::operator!=(const vector<T> &vec) const
{
	return !(*this == vec);
}

// L Access[] operator overload.
template<typename T>
T & vector<T>::operator[](const size_t &index)
{
	if(index >= size_)
		throw std::out_of_range("Index out of bounds.");

	return data_[index];
}

// R Access[] operator overload.
template<typename T>
T vector<T>::operator[](const size_t &index) const
{
	if(index >= size_)
		throw std::out_of_range("Index out of bounds.");

	return data_[index];
}

/**
 *  operator<< overload. This will call the operator<< of every item of
 *	type T in the vector.
*/
template <typename T>
std::ostream & operator<<(std::ostream &os, const vector<T> &vec)
{
	os << "[";

	for(size_t i = 0; i < vec.size(); i++)
	{
		os << (i + 1) << " " << vec[i];

		if(i < (vec.size() - 1))
		{
			os << " ";
		}
	}

	os << "]";

	return os;
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
	return (size_ == 0);
}


// ============= MODIFIERS =============
// Insert an item of type T at the end of the vector.
template<typename T>
void vector<T>::push_back(const T &element)
{
	if(size_ == capacity_)
		resize(capacity_ + 1);

	data_[size_] = element;
	size_++;
}

// Remove the last item of the vector.
template<typename T>
void vector<T>::pop_back()
{
	if(empty())
		return;

	if(size_ == 1)
	{
		delete[] data_;
		data_ = nullptr;
		size_ = 0;
		capacity_ = 0;
		return;
	}

	size_ -= 1;
	// resize(size_ - 1);
}

/** Insert an item of type T at the indicated position by size_t.
*		If the given index is greater than the capacity of the vector,
*		the new item will be inserted at the end of the vector
* 	(same as push_back function).
*/
template<typename T>
void vector<T>::insert(const T &element, const size_t &index)
{
	if(index >= size_)
	{
		push_back(element);
		return;
	}

	if(size_ == capacity_)
		resize(capacity_ + 1);

	// Moves the items to the right from the given index to create an empty
	// position for the new element.
	for(size_t i = size_ - 1; i >= index; --i)
		data_[i + 1] = data_[i];

	data_[index] = element;
	size_++;
}

// Remove from the vector the item of at the position size_t.
template<typename T>
void vector<T>::erase(const size_t &index)
{
	if(empty())
		return;

	// Erase the last item in the list
	if(index == size_ - 1)
	{
		size_ -= 1;
		return;
	}

	// Erase an item at the beginning or in the middle of the vector
	for(size_t i = index+1; i < size_; ++i)
		data_[i - 1] = data_[i];

	size_ -= 1;
}

// Remove all item from the vector and free the reserved memory.
template<typename T>
inline void vector<T>::clear()
{
	if(data_ != nullptr)
	{
		delete[] data_;
		data_ = nullptr;
	}

	capacity_ = 0;
	size_ = 0;
}

// Resize vector to be size_t items of type T.
template<typename T>
void vector<T>::resize(const size_t &size)
{
	if(size == 0)
		throw std::out_of_range("Size can not be <= 0.");

	// Vector is empty and just reserves memory
	if(data_ == nullptr)
	{
		data_ = new T[size];
		capacity_ = size;
		return;
	}

	// The new required size is the same that the vector has, so no resize required.
	if(size == this->capacity_)
		return;

	capacity_ = size;
	if(size < this->size_)
		this->size_ = size;

	T *newdata { new T[capacity_] };
	for( size_t i = 0; i < this->size_; ++i )
		newdata[i] = data_[i];

	delete[] data_;
	data_ = newdata;
}


// ============= AUXILIAR METHODS =============
// Copy method used in operator= and copy constructor.
template<typename T>
void vector<T>::copy(const vector<T> &vec)
{
	size_ = vec.size_;
	capacity_ = vec.capacity_;

	if(data_ != nullptr)
		delete[] data_;

	data_ = new T[vec.size_];

	for( size_t i = 0; i < vec.size_; ++i )
		data_[i] = vec[i];
}