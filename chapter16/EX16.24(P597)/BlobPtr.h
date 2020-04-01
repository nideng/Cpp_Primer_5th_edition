#ifndef BLOBPTR_H
#define BLOBPTR_H


#include"Blob.h"
using std::weak_ptr;
template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>=(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> class BlobPtr {
    friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    // clang-format off
    friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator> <T>(const BlobPtr<T>&, const BlobPtr<T>&);
    // clang-format on
    friend bool operator<=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator>=<T>(const BlobPtr<T>&, const BlobPtr<T>&);

public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T>& s, size_t sz = 0) : wptr(s.data), curr(sz) {}

    T& deref() const;
    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);
    BlobPtr& operator+=(size_t);
    BlobPtr& operator-=(size_t);
    BlobPtr operator+(size_t) const;
    BlobPtr operator-(size_t) const;

    T& operator[](size_t n);
    const T& operator[](size_t n) const;

private:
    shared_ptr<vector<T>> check(size_t, const T&) const;

    std::weak_ptr<vector<T>> wptr;
    size_t curr;
};

//------------------------------------------------------------------------------
//  friend function.
//------------------------------------------------------------------------------

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
    return x.curr < y.curr;
}

template <typename T>
bool operator>(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
    return x.curr > y.curr;
}

template <typename T>
bool operator<=(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
    return x.curr <= y.curr;
}

template <typename T>
bool operator>=(const BlobPtr<T>& x, const BlobPtr<T>& y)
{
    return x.curr >= y.curr;
}

//------------------------------------------------------------------------------
//  member function.
//------------------------------------------------------------------------------

template <typename T>
inline T& BlobPtr<T>::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <typename T>
inline BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr, "increment past end of Blob<T>Ptr");
    ++curr;
    return *this;
}

template <typename T>
inline BlobPtr<T>& BlobPtr<T>::operator--()
{
    --curr;
    check(-1, "decrement past begin of Blob<T>Ptr");
    return *this;
}

template <typename T>
inline BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr<T> ret = *this;
    ++* this;
    return ret;
}

template <typename T>
inline BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr<T> ret = *this;
    --* this;
    return ret;
}

template <typename T>
inline BlobPtr<T>& BlobPtr<T>::operator+=(size_t n)
{
    curr += n;
    check(curr, "increment past end of Blob<T>Ptr");
    return *this;
}

template <typename T>
inline BlobPtr<T>& BlobPtr<T>::operator-=(size_t n)
{
    curr -= n;
    check(curr, "increment past end of Blob<T>Ptr");
    return *this;
}

template <typename T>
inline BlobPtr<T> BlobPtr<T>::operator+(size_t n) const
{
    BlobPtr<T> ret = *this;
    ret += n;
    return ret;
}

template <typename T>
inline BlobPtr<T> BlobPtr<T>::operator-(size_t n) const
{
    BlobPtr<T> ret = *this;
    ret -= n;
    return ret;
}

template <typename T>
inline shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const T& msg) const
{
    auto ret = wptr.lock();
    if (!ret) throw std::runtime_error("unbound Blob<T>Ptr");
    if (i >= ret->size()) throw std::out_of_range(msg);
    return ret;
}

template <typename T>
inline T& BlobPtr<T>::operator[](size_t n)
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

template <typename T>
inline const T& BlobPtr<T>::operator[](size_t n) const
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

#endif // !BLOBPTR_H