/**
 * Dynamic vector data structure.
 * Author: Carlos Eduardo Arismendi Sánchez.
 * GitHub: https://github.com/carlosarismendi
 * LinkedIn: https://www.linkedin.com/in/carlos-arismendi/
*/

#include <iostream>
#include <ostream>

#ifndef _VECTOR_H_
#define _VECTOR_H_
template <typename T>
class vector
{
	/**
	 *  operator<< overload. This will call the operator<< of every item of
	 *	type T in the vector.
	*/
	friend ostream & operator<<(ostream &, const vector<T> &);

	private:
		// Number of items inserted in the vector
		size_t size;

		// Maximum amount of items that fit into the vector
		size_t capacity;

		// Datos del vector
		T *data;

		// ============= AUXILIAR METHODS =============
		// Copy method used in operator= and copy constructor.
		void copy(const vector<T> &);


	public:
		// Default constructor.
		vector<T>();

		// Constructor that only reserves memory for size_t elements of type T.
		vector<T>(const size_t &);

		// Copy constructor.
		vector<T>(const vector<T> &);

		// Destructor.
		~vector<T>();

		// Assignment operator overload.
		vector<T> & operator=(const vector<T> &);

		// Equality operator overload.
		bool operator==(const vector<T> &) const;

		// Inequality operator overload.
		bool operator!=(const vector<T> &) const;

		// L Access[] operator overload.
		T & operator[](const size_t &);

		// R Access[] operator overload.
		T operator[](const size_t &) const;

		// Return maximum amount of items that fit into the vector.
		inline size_t capacity() const;

		// Return number of items inserted in the vector.
		inline size_t size() const;

		// Insert an item of type T at the end of the vector.
		void push_back(const T &);

		// Remove the last item of the vector.
		void pop_back(const T &);

		/** Insert an item of type T at the indicated position by size_t.
		*		If the given index is greater than the capacity of the vector,
		*		the new item will be inserted at the end of the vector
		* 	(same as push_back function).
		*/
		void insert(const T &, const size_t &);

		// Remove from the vector the item of at the position size_t.
		void erase(const size_t &)

		// Remove all item from the vector and free the reserved memory.
		inline void clear();

		// Resize vector to be size_t items of type T.
		void resize(const size_t &);
};

#endif