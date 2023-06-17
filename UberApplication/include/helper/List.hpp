#pragma once
#include <iostream>
#include "Optional.hpp"

#pragma warning (disable : 6385)

namespace {
	const int RESIZE_LENGTH = 4;
}

template <typename T>
class List
{
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = RESIZE_LENGTH;

	void free();
	void copyFrom(const List& other);
	void moveFrom(List&& other);
	void resize(size_t _capacity);
public:
	List();
	List(size_t _capacity);

	List(const List& other);
	List& operator=(const List& other);

	List(List&& other) noexcept;
	List& operator=(List&& other) noexcept;

	~List();

	size_t length() const;

	void add(const T& element);
	void add(T&& element);

	bool remove(size_t index);

	T& operator[] (int idx);
	const T& operator[] (int idx) const;

	template <typename Tf>
	Optional<T> find(Tf condition) const;

	bool contains(const T& element) const;
	template <typename Tf>
	bool contains(Tf condition) const;
};

template<typename T>
inline void List<T>::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = RESIZE_LENGTH;
}

template<typename T>
inline void List<T>::copyFrom(const List& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new T[capacity];
	for (size_t i = 0; i < other.size; i++)
		data[i] = other.data[i];
}

template<typename T>
inline void List<T>::moveFrom(List&& other)
{
	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = RESIZE_LENGTH;

	data = other.data;
	other.data = nullptr;
}

template<typename T>
inline void List<T>::resize(size_t _capacity)
{
	capacity = _capacity;
	T* tempData = new T[capacity];

	for (size_t i = 0; i < size; i++)
		tempData[i] = std::move(data[i]);

	delete[] data;
	data = tempData;
	tempData = nullptr;
}

template<typename T>
inline List<T>::List()
{
	data = new T[capacity];
}

template<typename T>
inline List<T>::List(size_t _capacity)
{
	capacity = _capacity;
	data = new T[capacity];
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
	copyFrom(other);
}

template<typename T>
inline List<T>& List<T>::operator=(const List<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
inline List<T>::List(List&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline List<T>& List<T>::operator=(List<T>&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
inline List<T>::~List()
{
	free();
}

template<typename T>
inline size_t List<T>::length() const
{
	return size;
}

template<typename T>
inline void List<T>::add(const T& element)
{
	if (capacity <= size)
		resize(capacity + RESIZE_LENGTH);

	data[size++] = element;
}

template<typename T>
inline void List<T>::add(T&& element)
{
	if (capacity <= size)
		resize(capacity + RESIZE_LENGTH);

	data[size++] = std::move(element);
}

template<typename T>
inline bool List<T>::remove(size_t index)
{
	if (index >= size)
		return false;

	for (size_t i = index; i < size - 1; i++)
		data[i] = data[i + 1];
	size--;

	return true;
}

template<typename T>
inline T& List<T>::operator[](int idx)
{
	if (idx >= size)
		throw std::invalid_argument("Index out of range");

	return data[idx];
}

template<typename T>
inline const T& List<T>::operator[](int idx) const
{
	if (idx >= size)
		throw std::invalid_argument("Index out of range");

	return data[idx];
}

template<typename T>
inline bool List<T>::contains(const T& element) const
{
	for (size_t i = 0; i < size; i++)
		if (data[i] == element)
			return true;

	return false;
}

template<typename T>
template<typename Tf>
inline Optional<T> List<T>::find(Tf condition) const
{
	Optional<T> result;

	for (size_t i = 0; i < size; i++)
		if (condition(data[i]))
			result.setData(data[i]);

	return result;
}

template<typename T>
template<typename Tf>
inline bool List<T>::contains(Tf condition) const
{
	for (size_t i = 0; i < size; i++)
		if (condition(data[i]))
			return true;

	return false;
}
