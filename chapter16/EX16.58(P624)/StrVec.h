#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include<initializer_list>
#include<memory>
#include<utility>


class StrVec
{
public:
    StrVec() :element(nullptr), first_free(nullptr), cap(nullptr)
    { }

    StrVec(std::initializer_list<std::string> l);

    StrVec(const StrVec& s);

    StrVec&
        operator =(const StrVec& rhs);

    ~StrVec();


    // public members
    void push_back(const std::string& s);

    // a variadic member template using its argumenst to construct
    // an element directly in space managed by the constainer
    template<typename... Args>
    void emplace_back(Args&&...);

    std::size_t size() const { return first_free - element; }
    std::size_t capacity() const { return cap - element; }

    std::string* begin() const { return element; }
    std::string* end() const { return first_free; }

    // preallocate enough memory for specified number of elements
    void reserve(std::size_t n);

    // resize as required.
    void resize(std::size_t n);
    void resize(std::size_t n, const std::string& s);


private:

    // data members
    std::string* element;       //  pointer to the first element
    std::string* first_free;    //  pointer to the first free element
    std::string* cap;           //  pointer to one past the end

    std::allocator<std::string> alloc;

    void reallocate();
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    void free();

    // utilities added
    // used in reallocate() reserve() and resize().
    void wy_alloc_n_move(std::size_t n);

    std::pair<std::string*, std::string*>
        alloc_n_copy(std::string* b, std::string* e);

};
template<typename... Args>
inline
void StrVec::emplace_back(Args&&...args)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}
StrVec::StrVec(const StrVec& s)
{
    std::pair<std::string*, std::string*>
        newData = alloc_n_copy(s.begin(), s.end());
    element = newData.first;
    first_free = cap = newData.second;
}

StrVec::StrVec(std::initializer_list<std::string> l)
{
    // allocate memory as large as l.size()
    std::string* const
        newData = alloc.allocate(l.size());

    // copy elements from l to the address allocated
    auto p = newData;
    for (const auto& s : l)
        alloc.construct(p++, s);

    // build the data structure
    element = newData;
    first_free = cap = element + l.size();
}


// operator =
StrVec&
StrVec::operator =(const StrVec& rhs)
{
    // allocate and copy first to protect against self-assignment
    std::pair<std::string*, std::string*>
        newData = alloc_n_copy(rhs.begin(), rhs.end());

    // destroy and deallocate
    free();

    element = newData.first;
    first_free = cap = newData.second;

    return *this;
}

// destructor
StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const std::string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::reserve(std::size_t n)
{
    // if the n is too small, just ignore it.
    if (n <= capacity())  return;

    // allocate and move old ones into the new address.
    wy_alloc_n_move(n);
}


void StrVec::resize(std::size_t n)
{
    resize(n, std::string());
}

void StrVec::resize(std::size_t n, const std::string& s)
{
    if (n < size())
    {
        // destroy the range : [element+n, first_free) using destructor
        for (auto p = element + n; p != first_free; /* empty */)
            alloc.destroy(p++);

        // move frist_free point to the new address element + n
        first_free = element + n;
    }
    else if (n > size())
    {
        for (auto i = size(); i != n; ++i)
            push_back(std::string(s));
    }
}
void StrVec::reallocate()
{
    // calculate the new capacity required.
    std::size_t newCapacity = size() ? 2 * size() : 1;

    // allocate and move old ones into the new address.
    wy_alloc_n_move(newCapacity);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(std::string* b, std::string* e)
{
    // calculate the size needed and allocate space accordingly
    std::string* data = alloc.allocate(e - b);

    return { data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free()
{

    if (element)     //  if not nullptr
    {
        // destory it  in reverse order.
        for (auto p = first_free; p != element; /* empty */)
            alloc.destroy(--p);

        alloc.deallocate(element, capacity());
    }
}

void StrVec::wy_alloc_n_move(std::size_t n)
{
    std::size_t newCapacity = n;

    std::string*
        newData = alloc.allocate(newCapacity);

    std::string*
        dest = newData;
    std::string*
        elem = element;

    // move the old to newly allocated space.
    for (std::size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));

    free();

    // update data structure
    element = newData;
    first_free = dest;
    cap = element + newCapacity;
}
#endif