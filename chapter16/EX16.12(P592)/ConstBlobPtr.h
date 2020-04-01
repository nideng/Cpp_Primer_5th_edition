#ifndef CONSTBLOBPTR_H
#define CONSTBLOBPTR_H



#include"Blob.h"
using std::weak_ptr;
template <typename T>
bool operator==(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator!=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator<(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator<=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
template <typename T>
bool operator>=(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);

template <typename T> class ConstBlobPtr {
    friend bool operator==<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    friend bool operator!=<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    // clang-format off
    friend bool operator< <T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    friend bool operator> <T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    // clang-format on
    friend bool operator<=<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);
    friend bool operator>=<T>(const ConstBlobPtr<T>&, const ConstBlobPtr<T>&);

public:
    ConstBlobPtr() : curr(0) {}
    ConstBlobPtr(const Blob<T>& s, size_t sz = 0) : wptr(s.data), curr(sz) {}

    const T& operator*() const;
    const T* operator->() const;
    ConstBlobPtr& operator++();
    ConstBlobPtr& operator--();
    ConstBlobPtr operator++(int);
    ConstBlobPtr operator--(int);
    ConstBlobPtr& operator+=(size_t);
    ConstBlobPtr& operator-=(size_t);
    ConstBlobPtr operator+(size_t) const;
    ConstBlobPtr operator-(size_t) const;

    const T& operator[](size_t n) const;

private:
    std::shared_ptr<vector<T>> check(size_t, const T&) const;

    std::weak_ptr<vector<T>> wptr;
    size_t curr;
};

//------------------------------------------------------------------------------
//  friend function.
//------------------------------------------------------------------------------

template <typename T>
bool operator==(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr > rhs.curr;
}

template <typename T>
bool operator<=(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr <= rhs.curr;
}

template <typename T>
bool operator>=(const ConstBlobPtr<T>& lhs, const ConstBlobPtr<T>& rhs)
{
    return lhs.curr >= rhs.curr;
}

//------------------------------------------------------------------------------
//  member function.
//------------------------------------------------------------------------------

template <typename T>
inline const T& ConstBlobPtr<T>::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <typename T>
inline const T* ConstBlobPtr<T>::operator->() const
{
    return &this->operator*();
}

template <typename T>
inline ConstBlobPtr<T>& ConstBlobPtr<T>::operator++()
{
    check(curr, "increment past end of ConstBlob<T>Ptr");
    ++curr;
    return *this;
}

template <typename T>
inline ConstBlobPtr<T>& ConstBlobPtr<T>::operator--()
{
    --curr;
    check(-1, "decrement past begin of ConstBlob<T>Ptr");
    return *this;
}

template <typename T>
inline ConstBlobPtr<T> ConstBlobPtr<T>::operator++(int)
{
    ConstBlobPtr<T> ret = *this;
    ++* this;
    return ret;
}

template <typename T>
inline ConstBlobPtr<T> ConstBlobPtr<T>::operator--(int)
{
    ConstBlobPtr<T> ret = *this;
    --* this;
    return ret;
}

template <typename T>
inline ConstBlobPtr<T>& ConstBlobPtr<T>::operator+=(size_t n)
{
    curr += n;
    check(curr, "increment past end of ConstBlob<T>Ptr");
    return *this;
}

template <typename T>
inline ConstBlobPtr<T>& ConstBlobPtr<T>::operator-=(size_t n)
{
    curr -= n;
    check(curr, "increment past end of ConstBlob<T>Ptr");
    return *this;
}

template <typename T>
inline ConstBlobPtr<T> ConstBlobPtr<T>::operator+(size_t n) const
{
    ConstBlobPtr<T> ret = *this;
    ret += n;
    return ret;
}

template <typename T>
inline ConstBlobPtr<T> ConstBlobPtr<T>::operator-(size_t n) const
{
    ConstBlobPtr<T> ret = *this;
    ret -= n;
    return ret;
}

template <typename T>
inline std::shared_ptr<vector<T>> ConstBlobPtr<T>::check(size_t i,
    const T& msg) const
{
    auto ret = wptr.lock();
    if (!ret) throw std::runtime_error("unbound Blob<T>Ptr");
    if (i >= ret->size()) throw std::out_of_range(msg);
    return ret;
}

template <typename T>
inline const T& ConstBlobPtr<T>::operator[](size_t n) const
{
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

#endif // !CONSTBLOBPTR_H