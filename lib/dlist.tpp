/**
 * Bidirectional linked list header.
 * Author: Carlos Eduardo Arismendi Sanchez.
 * GitHub: https://github.com/carlosarismendi
 * LinkedIn: https://www.linkedin.com/in/carlos-arismendi/
*/

#include <iostream>
#include <ostream>
#include "dlist.h"

//#################################################
//#                                               #
//#            LINKED LIST NODE CLASS             #
//#                                               #
//#################################################
// ============= CONSTRUCTORS =============
// Default constructor
template <typename T>
dlistnode<T>::dlistnode (): element_(), previous_(nullptr), next_(nullptr)
{}

// Copy constructor
template <typename T>
dlistnode<T>::dlistnode (const dlistnode<T> &node): element_(node.element_), previous_(nullptr), next_(nullptr)
{}

// Destructor
template <typename T>
dlistnode<T>::~dlistnode ()
{
  previous_ = nullptr;
  next_ = nullptr;
}


// ============= GETTERS =============
// Returns a copy of the element.
template <typename T>
inline T dlistnode<T>::element() const
{
  return element_;
}

// Returns a pointer to the previous node.
template <typename T>
inline dlistnode<T> * dlistnode<T>::previous() const
{
  return previous_;
}

// Returns a pointer to the next node.
template <typename T>
inline dlistnode<T> * dlistnode<T>::next() const
{
  return next_;
}


// ============= OPERATOR OVERLOADS =============
// Assignment operator overload
template <typename T>
dlistnode<T> & dlistnode<T>::operator=(const dlistnode<T> &node)
{
  if(this != &node)
  {
    previous_ = nullptr;
    next_ = nullptr;
    element_ = node.element_;
  }

  return *this;
}




//#################################################
//#                                               #
//#              LINKED LIST CLASS                #
//#                                               #
//#################################################
// ============= CONSTRUCTORS =============
// Default constructor: creates an empty list.
template <typename T>
dlist<T>::dlist(): first_(nullptr), last_(nullptr), size_(0)
{}

// Copy constructor.
template <typename T>
dlist<T>::dlist (const dlist<T> &list): first_(nullptr), last_(nullptr), size_(0)
{
  copy(list);
}

// Destructor
template <typename T>
dlist<T>::~dlist ()
{
  if(empty())
    return;

  dlistnode<T> *del, *next { first_ };

  for(size_t i = 0; i < size_; ++i)
  {
    del = next;
    next = next->next_;
    delete del;
  }

  first_ = nullptr;
  last_ = nullptr;
  size_ = 0;
}


// ============= OPERATOR OVERLOADS =============
// Assignment operator overload.
template <typename T>
dlist<T> & dlist<T>::operator=(const dlist<T> &list)
{
  if(this != &list)
    copy(list);

  return *this;
}

// Equality operator overload.
template <typename T>
bool dlist<T>::operator==(const dlist<T> &list) const
{
  if(size_ != list.size_)
    return false;

  if(empty())
    return true;

  dlistnode<T> *nlist1 { first_ };
  dlistnode<T> *nlist2 { list.first_ };

  // Checks up to the element previous to the last one
  for(size_t i = 0; i < size_; ++i)
  {
    if(nlist1->element_ != nlist2->element_)
      return false;

    nlist1 = nlist1->next_;
    nlist2 = nlist2->next_;
  }

  // Checks the last element
  return true;
}

// Inequality operator overload.
template <typename T>
bool dlist<T>::operator!=(const dlist<T> &list) const
{
  return !(*this == list);
}

// L Access[] operator overload.
template <typename T>
T & dlist<T>::operator[](const size_t &index)
{
  if(index >= size_ || index < 0)
		throw std::out_of_range("Index out of bounds.");

  dlistnode<T> *iterator { first_ };

  for(size_t i = 0; i < size_; ++i)
  {
    if(i == index)
      break;
    iterator = iterator->next_;
  }

  return iterator->element_;
}

// R Access[] operator overload.
template <typename T>
T dlist<T>::operator[](const size_t &index) const
{
  if(index >= size_ || index < 0)
		throw std::out_of_range("Index out of bounds.");

  dlistnode<T> *iterator { first_ };

  for(size_t i = 0; i < size_; ++i)
  {
    if(i == index)
      break;
    iterator = iterator->next_;
  }

  return iterator->element_;
}

/**
	 *  operator<< overload. This will call the operator<< of every item of
	 *	type T in the list.
	*/
template <typename T>
std::ostream & operator<<(std::ostream &os, const dlist<T> &list)
{
  os << "(";

	dlistnode<T> *iterator { list.first_ };

	for(size_t i = 0; i < list.size_; ++i)
	{
		os << iterator->element();

		if(iterator->next() != nullptr)
			os << " ";

		iterator = iterator->next();
	}

	os << ")";

	return os;
}


// ============= GETTERS =============
// Returns a reference to the last item in the list.
template <typename T>
inline T & dlist<T>::back() const
{
  return last_->element;
}

// Returns a reference to the first item in the list.
template <typename T>
inline T & dlist<T>::front() const
{
  return first_->element;
}

// Return number of items inserted in the list.
template <typename T>
inline size_t dlist<T>::size() const
{
  return size_;
}

// Returns a boolean indicating if the vector is empty or not.
template <typename T>
inline bool dlist<T>::empty() const
{
  return (first_ == nullptr);
}


// ============= MODIFIERS =============
// Inserts an item of type T at the end of the list.
template <typename T>
void dlist<T>::push_back(const T &element)
{
  size_++;

  dlistnode<T> *newnode { new dlistnode<T> };
  newnode->element_ = element;

  if(empty())
  {
    first_ = newnode;
    last_ = first_;
    return;
  }

  last_->next_ = newnode;
  newnode->previous_ = last_;
  last_ = newnode;
}

// Inserts an item of type T at the beginning of the list.
template <typename T>
void dlist<T>::push_front(const T &element)
{
  if(empty())
  {
    push_back(element);
    return;
  }

  dlistnode<T> *newnode { new dlistnode<T> };
  newnode->element_ = element;

  first_->previous_ = newnode;
  newnode->next_ = first_;
  first_ = newnode;

  size_++;
}

/**
 *  Inserts an item of type T at the position given by size_t.
 * 	If the given position is greater than the size of the list,
 *	the new item will be inserted at the end (same as push_back function).
 *  If the given position is less than 0, the new item will be inserted
 * 	at the beginning of the list (same as push_front).
*/
template <typename T>
void dlist<T>::insert(const T &element, const size_t &index)
{
  if(empty() || index >= size_)
  {
    push_back(element);
  }
  else if(index < 0)
  {
    push_front(element);
  }
  else
  {
    // Insert element in the middle of the list.
    dlistnode<T> *iterator { first_ };

    // Position the iterator over the item to delete
    for(size_t i = 0; i < size_; ++i)
    {
      if(i == index)
        break;

      iterator = iterator->next_;
    }

    dlistnode<T> *newnode { new dlistnode<T> };
    newnode->element_ = element;
    newnode->previous_ = iterator->previous_;
    newnode->next_ = iterator;

    iterator->previous_->next_ = newnode;
    iterator->previous_ = newnode;
  }

}

// Removes the last element from the list.
template <typename T>
void dlist<T>::pop_back()
{
  if(empty())
    return;

  // There is only one item in the list.
  if (size_ == 1)
  {
    this->~dlist();
    return;
  }

  dlistnode<T> *del { last_ };

  // Previos node must not point to the last because the last
  // is going to be deleted.
  del->previous_->next_ = nullptr;
  last_ = del->previous_;

  delete del;
  size_--;
}

// Removes the first element from the list.
template <typename T>
void dlist<T>::pop_front()
{
  if(empty())
    return;

  // There is only one item in the list.
  if (size_ == 1)
  {
    this->~dlist();
    return;
  }

  dlistnode<T> *del { first_ };

  // Next node must not point to the first because the first
  // is going to be deleted.
  del->next_->previous_ = nullptr;
  first_ = del->next_;

  delete del;
  size_--;
}

// Removes the element given by size_t from the list.
template <typename T>
void dlist<T>::erase(const size_t &index)
{
  if(empty())
    return;

  if(index >= size_ || index < 0)
		throw std::out_of_range("Index out of bounds.");

  if(index == 0)
  {
    pop_front();
  }
  else if(index == size_ - 1)
  {
    pop_back();
  }
  else
  {
    // Deletes an item in the middle of the list
    dlistnode<T> *iterator { first_ };

    // Position the iterator over the item to delete
    for(size_t i = 0; i < size_; ++i)
    {
      if(i == index)
        break;

      iterator = iterator->next_;
    }

    // Reassign the pointers so no longer the deleted element is pointed by any node.
    iterator->previous_->next_ = iterator->next_;
    iterator->next_->previous_ = iterator->previous_;
    delete iterator;
    size_--;
  }

}

// Remove all item from the vector and free the reserved memory.
template <typename T>
inline void dlist<T>::clear()
{
  this->~dlist();
}

// ============= AUXILIAR METHODS =============
// Copy method used in operator= and copy constructor.
template <typename T>
void dlist<T>::copy(const dlist<T> &list)
{
  this->~dlist();
  dlistnode<T> *iterator { list.first_ };

  for(size_t i = 0; i < list.size_; ++i)
  {
    push_back(iterator->element_);
    iterator = iterator->next_;
  }
}