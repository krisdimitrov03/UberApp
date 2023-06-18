#pragma once

template <typename T>
class Optional
{
	T* ptr = nullptr;

	void free();
	void copyFrom(const Optional& other);
	void moveFrom(Optional&& other) noexcept;
public:
	Optional() = default;
	Optional(const T& _ptr);

	Optional(const Optional& other);
	Optional(Optional&& other) noexcept;

	Optional& operator=(const Optional& other);
	Optional& operator=(Optional&& other) noexcept;

	const T& getData() const;
	void setData(const T&);
	bool hasValue() const;

	~Optional();
};

template<typename T>
inline void Optional<T>::free()
{
	delete ptr;
}

template<typename T>
inline void Optional<T>::copyFrom(const Optional& other)
{
	if (!other.hasValue())
		ptr = nullptr;
	else
		ptr = new T(*other.ptr);
}

template<typename T>
inline void Optional<T>::moveFrom(Optional&& other) noexcept
{
	ptr = other.ptr;
	other.ptr = nullptr;
}

template<typename T>
inline Optional<T>::Optional(const T& _ptr)
{
	ptr = new T(_ptr);
}

template<typename T>
inline Optional<T>::Optional(const Optional& other)
{
	copyFrom(other);
}

template<typename T>
inline Optional<T>::Optional(Optional&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline Optional<T>& Optional<T>::operator=(const Optional<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
inline Optional<T>& Optional<T>::operator=(Optional<T>&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
inline const T& Optional<T>::getData() const
{
	return *ptr;
}

template<typename T>
inline void Optional<T>::setData(const T& data)
{
	ptr = new T(data);
}

template<typename T>
inline bool Optional<T>::hasValue() const
{
	return ptr != nullptr;
}

template<typename T>
inline Optional<T>::~Optional()
{
	free();
}
