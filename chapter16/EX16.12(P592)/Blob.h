#ifndef BLOB_H
#define BLOB_H
#include<stdexcept>
#include<vector>
#include<memory>
#include<initializer_list>
#include<string>
#include<iterator>
using std::initializer_list;
using std::vector;
using std::shared_ptr; using std::make_shared;
using std::string;
using std::out_of_range;
template <typename> class BlobPtr;
template <typename> class ConstBlobPtr;
template <typename> class Blob;

template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator!=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>=(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
    friend class ConstBlobPtr<T>;
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator!=<T>(const Blob<T>&, const Blob<T>&);
    // clang-format off
    friend bool operator< <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator><T>(const Blob<T>&, const Blob<T>&);
    // clang-format on
    friend bool operator<=<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator>=<T>(const Blob<T>&, const Blob<T>&);

public:
    typedef typename vector<T>::size_type size_type;

    Blob() : data(make_shared<vector<T>>()) {}
    Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) {}

    Blob(const Blob<T>& lhs) : data(make_shared<vector<T>>(*lhs.data)) {}
    Blob& operator=(const Blob<T>&);

    Blob(Blob<T>&& rhs) noexcept : data(std::move(rhs.data)) {}
    Blob& operator=(Blob<T>&&) noexcept;

    BlobPtr<T> begin();
    BlobPtr<T> end();

    ConstBlobPtr<T> cbegin() const;
    ConstBlobPtr<T> cend() const;

    T& operator[](size_t n);
    const T& operator[](size_t n) const;

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T& t) { data->push_back(t); }
    void push_back(T&& s) { data->push_back(std::move(s)); }

    void pop_back();
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;

private:
    void check(size_type, const T&) const;
    shared_ptr<vector<T>> data;
};

//------------------------------------------------------------------------------
//  friend function.
//------------------------------------------------------------------------------

template <typename T> 
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return *lhs.data == *rhs.data;
}

template <typename T> 
bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T> 
bool operator<(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(),
        rhs.data->begin(), rhs.data->end());
}

template <typename T> 
bool operator>(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return rhs < lhs;
}

template <typename T>
bool operator<=(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return !(rhs < lhs);
}

template <typename T>
bool operator>=(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return !(lhs < rhs);
}

//------------------------------------------------------------------------------
//  member function.
//------------------------------------------------------------------------------

template <typename T> 
Blob<T>& Blob<T>::operator=(const Blob<T>& lhs)
{
    data = make_shared<vector<T>>(*lhs.data);
    return *this;
}


template <typename T> Blob<T>& Blob<T>::operator=(Blob<T>&& rhs)noexcept
{
    if (this != &rhs) {
        data = std::move(rhs.data);
        rhs.data = nullptr;
    }

    return *this;
}

template <typename T> BlobPtr<T> Blob<T>::begin()
{
    return BlobPtr<T>(*this);
}

template <typename T> BlobPtr<T> Blob<T>::end()
{
    return BlobPtr<T>(*this, data->size());
}

template <typename T> ConstBlobPtr<T> Blob<T>::cbegin() const
{
    return ConstBlobPtr<T>(*this);
}

template <typename T> ConstBlobPtr<T> Blob<T>::cend() const
{
    return ConstBlobPtr<T>(*this, data->size());
}

template <typename T> inline void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob<T>");
    data->pop_back();
}

template <typename T> inline T& Blob<T>::front()
{
    check(0, "front on empty Blob<T>");
    return data->front();
}

template <typename T> inline T& Blob<T>::back()
{
    check(0, "back on empty Blob<T>");
    return data->back();
}

template <typename T> inline const T& Blob<T>::front() const
{
    check(0, "front on empty Blob<T>");
    return data->front();
}

template <typename T> inline const T& Blob<T>::back() const
{
    check(0, "back on empty Blob<T>");
    return data->back();
}

template <typename T>
inline void Blob<T>::check(size_type i, const T& msg) const
{
    if (i >= data->size()) throw std::out_of_range(msg);
}

template <typename T> inline T& Blob<T>::operator[](size_t n)
{
    check(n, "out of range");
    return data->at(n);
}

template <typename T> inline const T& Blob<T>::operator[](size_t n) const
{
    check(n, "out of range");
    return data->at(n);
}

#endif // !BLOB_H