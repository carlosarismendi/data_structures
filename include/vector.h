#pragma once

/**
 * Dynamic vector data structure header.
 * Author: Carlos Eduardo Arismendi Sanchez.
 * GitHub: https://github.com/carlosarismendi
 * LinkedIn: https://www.linkedin.com/in/carlos-arismendi/
*/

#include <iostream>
#include <ostream>
#include <memory>
#include <initializer_list>

// #include <vector>
// std::vector<int>::iterator a;

#define DEBUG 0
#if DEBUG == 1
	#define LOG(msg, x) std::cout << msg << " " << x << std::endl;
#else
	#define LOG(msg, x)
#endif

template <typename vector>
class vector_iterator
{
public:
	using value_type = typename vector::value_type;
	using pointer_type = value_type *;
	using reference_type = value_type &;

	vector_iterator(pointer_type ptr)
		: m_ptr(ptr)
	{
	}

	inline vector_iterator &operator++()
	{
		++m_ptr;
		return *this;
	}

	inline vector_iterator operator++(int)
	{
		vector_iterator it = *this;
		++(*this);
		return it;
	}

	inline vector_iterator &operator+=(const size_t offset)
	{
		m_ptr += offset;
		return *this;
	}

	inline vector_iterator operator+(const size_t offset)
	{
		vector_iterator it = *this;
		it += offset;
		return it;
	}

	inline vector_iterator &operator--()
	{
		--m_ptr;
		return *this;
	}

	inline vector_iterator operator--(int)
	{
		vector_iterator it = *this;
		--(*this);
		return it;
	}

	inline vector_iterator &operator-=(const size_t offset)
	{
		m_ptr -= offset;
		return *this;
	}

	inline vector_iterator operator-(const size_t offset)
	{
		vector_iterator it = *this;
		it -= offset;
		return it;
	}

	inline reference_type operator[](size_t index)
	{
		return *(m_ptr + index);
	}

	inline reference_type operator*()
	{
		return *m_ptr;
	}

	inline pointer_type operator->()
	{
		return m_ptr;
	}

	inline bool operator==(const vector_iterator &other) const
	{
		return m_ptr == other.m_ptr;
	}

	inline bool operator!=(const vector_iterator &other) const
	{
		return !(m_ptr == other.m_ptr);
	}

private:
	pointer_type m_ptr;
};

template<typename T, typename _Alloc = std::allocator<T> >
class vector
{

public:
	using value_type = T;
	using iterator = vector_iterator<vector<T>>;	
	using allocator_type = _Alloc;

public:
	// ============= CONSTRUCTORS =============
	// Default constructor.
	vector(const allocator_type& alloc = allocator_type())
		: m_size(0), m_capacity(0), m_alloc(alloc), m_data(nullptr)
	{
	}

	// Constructor that only reserves memory for size_t elements of type T.
	vector(const size_t &size, const allocator_type& alloc = allocator_type())
		: m_size(0), m_capacity(size), m_alloc(alloc)
	{		
		m_data = m_alloc.allocate(m_capacity);
		for(size_t i = 0; i < m_capacity; ++i)
			m_alloc.construct(m_data + i, T());
	}

	// Copy constructor.
	vector(const vector<T> &src)
		: m_size(src.m_size), m_capacity(src.m_capacity), m_alloc(src.m_alloc)
	{		
		m_data = m_alloc.allocate(m_capacity);
		for (size_t i = 0; i < m_size; ++i)
			m_alloc.construct(m_data + i, src[i]);
	}

	// Move constructor.
	vector(const vector<T> &&src)
		: m_size(src.m_size), m_capacity(src.m_capacity), m_alloc(std::move(src.m_alloc))
	{		
		m_data = src.m_data;
		src.m_data = nullptr;
	}

	vector(const std::initializer_list<T> ilist)
		: m_size(ilist.size()), m_capacity(ilist.size()), m_alloc()
	{		
		m_data = m_alloc.allocate(m_capacity);
		size_t i = 0;
		for (auto it = ilist.begin(); it < ilist.end(); ++it)			
			m_alloc.construct(m_data[++i], *it);
	}

	// Destructor.
	~vector()
	{		
		clear();
	}

	// ============= OPERATOR OVERLOADS =============
	// Assign operator overload.
	vector &operator=(const vector<T> &src)
	{
		if (this != &src)
		{			
			destroy_and_clean_memory();
			m_size = src.m_size;
			m_capacity = src.m_capacity;
			
			m_data = m_alloc.allocate(m_capacity);
			for (size_t i = 0; i < m_size; ++i)				
				m_alloc.construct(m_data + i, src[i]);
		}

		return *this;
	}

	// Move operator overload.
	vector &operator=(const vector<T> &&src)
	{
		if (this != &src)
		{
			destroy_and_clean_memory();
			m_size = src.m_size;
			m_capacity = src.m_capacity;

			m_data = src.m_data;
			src.m_data = nullptr;
		}		

		return *this;
	}

	// Equality operator overload.
	bool operator==(const vector<T> &right) const noexcept
	{
		if (m_size == right.m_size && m_capacity == right.m_capacity)
		{
			for (size_t i = 0; i < m_size; ++i)
			{
				if (m_data[i] != right[i])
					return false;
			}

			return true;
		}

		return false;
	}

	// Inequality operator overload.
	inline bool operator!=(const vector<T> &right) const noexcept
	{
		return !(*this == right);
	}

	// L Access[] operator overload.
	inline T& operator[](const size_t &index) const noexcept
	{
		return *(m_data + index);
	}

	// R Access[] operator overload.
	inline T operator[](const size_t &index) noexcept
	{
		return *(m_data + index);
	}

	// ============= GETTERS =============
	inline iterator begin() const noexcept
	{
		return { m_data };
	}

	inline iterator end() const noexcept
	{
		return { m_data + m_size };		
	}

	// Return maximum amount of items that fit into the vector.
	inline size_t capacity() const noexcept
	{
		return m_capacity;
	}

	// Return number of items inserted in the vector.
	inline size_t size() const noexcept
	{
		return m_size;
	}

	// Returns a boolean indicating if the vector is empty or not.
	inline bool empty() const noexcept
	{
		return (m_size == 0);
	}

	inline allocator_type get_allocator() const noexcept
	{
		return m_alloc;
	}
	
	// ============= MODIFIERS =============
	// Insert an item of type T at the end of the vector.
	iterator push_back(const T &item)
	{
		if (m_size >= m_capacity)
			reserve(2 + m_capacity + m_capacity * 0.5);
		
		m_alloc.construct(m_data + m_size, item);
		++m_size;
		
		return { m_data + m_size - 1 };
	}

	// Insert an item of type T at the end of the vector.
	template <typename... Args>
	iterator emplace_back(Args &&...args)
	{
		if (m_size >= m_capacity)
			reserve(2 + m_capacity + m_capacity * 0.5);

		new (&m_data[m_size]) T(std::forward<Args>(args)...);
		++m_size;

		return { m_data + m_size - 1 };
	}

	// Remove the last item of the vector.
	void pop_back() noexcept
	{
		if(m_size == 0)
			return;
		
		--m_size;
		m_alloc.destroy(m_data + m_size);	
	}

	/** Insert an item of type T at the indicated position by size_t.
	*		If the given index is greater than the capacity of the vector,
	*		the new item will be inserted at the end of the vector
	* 	(same as push_back function).
	*/
	iterator insert(const T &item, const size_t &index)
	{		
		if (index >= m_size)		
			return push_back(item);		

		size_t idx = index;	
		if (idx < 0)
			idx = 0;

		if (m_size >= m_capacity)
			reserve(1 + m_capacity + m_capacity / 2);

		for (size_t i = m_size - 1; i >= idx; --i)
			m_data[i + 1] = std::move(m_data[i]);

		m_data[idx] = item;
		++m_size;

		return { m_data + idx };
	}

	// Remove from the vector the item of at the position size_t.
	void erase(const size_t &index)
	{
		if (index >= m_size)
		{
			pop_back();
			return;
		}

		size_t idx = index;	
		if (idx < 0)
			idx = 0;

		m_alloc.destroy(m_data + idx);	
		for (size_t i = idx + 1; i < m_size; ++i)
			m_data[i - 1] = std::move(m_data[i]);
				
		--m_size;
	}

	// Remove all item from the vector and free the reserved memory.
	void clear()
	{						
		destroy_and_clean_memory();
		m_size = 0;
		m_capacity = 0;
	}

	// Resize vector to be size_t items of type T.
	void reserve(const size_t &size)
	{
		if (size <= m_capacity)
			return;
				
		T* newdata = m_alloc.allocate(size);
				
		for (size_t i = 0; i < m_size; ++i)
			newdata[i] = std::move(m_data[i]);
		
		destroy_and_clean_memory();
		m_data = newdata;
		m_capacity = size;		
	}

	// Resize vector to be size_t items of type T.
	void resize(const size_t &size)
	{
		if (size == m_capacity)
			return;
		
		size_t min_size = m_size;
		if (size < m_size)
			min_size = size;

		T* newdata = m_alloc.allocate(size);
		for (size_t i = 0; i < min_size; ++i)
			newdata[i] = std::move(m_data[i]);
				
		for (size_t i = min_size; i < size; ++i)
			m_alloc.construct(newdata + i, T());

		destroy_and_clean_memory();
		m_data = newdata;
		m_capacity = size;
		m_size = size;
	}

private:
	// ============= AUXILIAR =============
	void destroy_and_clean_memory()
	{
		if (m_data == nullptr)
			return;

		for(size_t i = 0; i < m_size; ++i)
			m_alloc.destroy(m_data + i);	
		m_alloc.deallocate(m_data, m_capacity);
		m_data = nullptr;	
	}

private:
	// ============= ATTRIBUTES =============
	// Number of items inserted in the vector
	size_t m_size;

	// Maximum amount of items that fit into the vector
	size_t m_capacity;

	allocator_type m_alloc;

	T *m_data;	
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const vector<T> &vec) noexcept
{
	os << "[";
	for (size_t i = 0; i < vec.size(); i++)
	{
		os << (i + 1) << " " << vec[i];
		if (i < (vec.size() - 1))
			os << " ";
	}
	os << "]";

	return os;
}