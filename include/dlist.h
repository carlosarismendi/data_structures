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

class dlistnode
{
	private:
		// ============= ATTRIBUTES =============
		// Node item
		T e;

		// Previous node in the list
		dlistnode *previous_;

		// Next node in the list
		dlistnode *next_;

	public:
		// ============= CONSTRUCTORS =============
		// Default constructor
		dlistnode ();

		// Copy constructor
		dlistnode (const dlistnode &);

		// Destructor
		~dlistnode ();


		// ============= GETTERS =============
		// Returns a pointer to the previous node.
		dlistnode *previous();

		// Returns a pointer to the next node.
		dlistnode *next();


		// ============= OPERATOR OVERLOADS =============
		// Assignment operator overload
		dlistnode & operator=(const dlistnode &);
};


template <typename T>
class dlist
{
	/**
	 *  operator<< overload. This will call the operator<< of every item of
	 *	type T in the list.
	*/
	// friend std::ostream & operator<<(std::ostream &, const vector<T> &);

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
		void copy(const vector<T> &);

	public:
		// ============= CONSTRUCTORS =============
		// Default constructor: creates an empty list.
		dlist();

		// Copy constructor.
		dlist (const dlist &);

		// Destructor
		~dlist ();


		// ============= OPERATOR OVERLOADS =============
		// Assignment operator overload.
		dlist & operator=(const dlist &);

		// Equality operator overload.
		bool operator==(const dlist &);

		// L Access[] operator overload.
		T & operator[](const size_t &);

		// R Access[] operator overload.
		T operator[](const size_t &) const;


		// ============= GETTERS =============
		// Returns a reference to the last item in the list.
		T & back() const;

		// Returns a reference to the first item in the list.
		T & front() const;

		// Return number of items inserted in the list.
		inline size_t size() const;

		// Returns a boolean indicating if the vector is empty or not.
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

		// Remove all item from the vector and free the reserved memory.
		inline void clear();
};

#endif