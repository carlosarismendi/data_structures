/**
 * Bidirectional linked list header.
 * Author: Carlos Eduardo Arismendi Sanchez.
 * GitHub: https://github.com/carlosarismendi
 * LinkedIn: https://www.linkedin.com/in/carlos-arismendi/
*/

#ifndef _DLIST_H_
#define _DLIST_H_
#include <iostream>
#include <ostream>

/**
 * 	This class represents a node of the linked list (class dlist).
*/

template <typename T>
class dlistnode;

template <typename T>
class dlist
{
	friend class dlistnode<T>;

	template<typename A>
	friend std::ostream & operator<<(std::ostream &, const dlist<A> &);

	private:
		// ============= ATTRIBUTES =============
		// First node in the list
		dlistnode<T> *first_;

		// Last node in the list
		dlistnode<T> *last_;

		// Number of items inserted in the list
		size_t size_;


		// ============= AUXILIAR METHODS =============
		// Copy method used in operator= and copy constructor.
		void copy(const dlist<T> &);

	public:
		// ============= CONSTRUCTORS =============
		// Default constructor: creates an empty list.
		dlist();

		// Copy constructor.
		dlist (const dlist<T> &);

		// Destructor
		~dlist ();


		// ============= OPERATOR OVERLOADS =============
		// Assignment operator overload.
		dlist<T> & operator=(const dlist<T> &);

		// Equality operator overload.
		bool operator==(const dlist<T> &) const;

		// Inequality operator overload.
		bool operator!=(const dlist<T> &) const;

		// L Access[] operator overload.
		T & operator[](const size_t &);

		// R Access[] operator overload.
		T operator[](const size_t &) const;


		// ============= GETTERS =============
		// Returns a reference to the last item in the list.
		inline T back() const;

		// Returns a reference to the first item in the list.
		inline T front() const;

		// Return number of items inserted in the list.
		inline size_t size() const;

		// Returns a boolean indicating if the list is empty or not.
		inline bool empty() const;


		// ============= MODIFIERS =============
		// Inserts an item of type T at the end of the list.
		void push_back(const T &);

		// Inserts an item of type T at the beginning of the list.
		void push_front(const T &);

		/**
		 *  Inserts an item of type T at the position given by size_t.
		 * 	If the given position is greater than the size of the list,
		 *	the new item will be inserted at the end (same as push_back function).
		 *  If the given position is less than 0, the new item will be inserted
		 * 	at the beginning of the list (same as push_front).
		*/
		void insert(const T &, const size_t &);

		// Removes the last element from the list.
		void pop_back();

		// Removes the first element from the list.
		void pop_front();

		// Removes the element given by size_t from the list.
		void erase(const size_t &);

		// Remove all item from the list and free the reserved memory.
		inline void clear();
};

template <typename T>
class dlistnode
{
	friend class dlist<T>;
	private:
		// ============= ATTRIBUTES =============
		// Node item
		T element_;

		// Previous node in the list
		dlistnode *previous_;

		// Next node in the list
		dlistnode *next_;

	public:
		// ============= CONSTRUCTORS =============
		// Default constructor
		dlistnode ();

		// Copy constructor
		dlistnode (const dlistnode<T> &);

		// Destructor
		~dlistnode ();


		// ============= GETTERS =============
		// Returns a copy of the element.
		inline T element() const;

		// Returns a pointer to the previous node.
		inline dlistnode<T> *previous() const;

		// Returns a pointer to the next node.
		inline dlistnode<T> *next() const;


		// ============= OPERATOR OVERLOADS =============
		// Assignment operator overload
		dlistnode<T> & operator=(const dlistnode<T> &);
};


#include "../lib/dlist.tpp"
#endif