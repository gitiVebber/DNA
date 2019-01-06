#ifndef __SHARED_PTR_H__
#define __SHARED_PTR_H__

#include <iostream>

template<typename T>
class SharedPtr
{
public:
    explicit SharedPtr(T* ptr = NULL);
    SharedPtr(const SharedPtr& other);

    template<class U>
    friend class SharedPtr;

    template<class U>
    SharedPtr(const SharedPtr<U>& pt);

    ~SharedPtr();

    SharedPtr& operator=(const SharedPtr&);
    SharedPtr& operator=(T*);
    T* operator->() const;
    T& operator*()  const;
    bool operator!=(const SharedPtr&) const;
    bool operator==(const SharedPtr&) const;

    T* get() const;

    operator bool() const;

private:
    T *m_ptr;
    size_t *m_refCount;
};

template<typename T>
SharedPtr<T>::SharedPtr(T *ptr) :m_ptr(ptr)
{
    //std::cout<<"===============Ctor=============="<<std::endl;
    m_refCount = new size_t;
    *m_refCount = 1;
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& other):m_ptr(other.m_ptr), m_refCount(other.m_refCount)
{
    //std::cout<<"===============copy Ctor=============="<<std::endl;
    ++*m_refCount;
}

template<typename T>
template<class U>
SharedPtr<T>::SharedPtr(const SharedPtr<U>& pt):m_ptr(pt.m_ptr), m_refCount(pt.m_refCount)
{
    //std::cout<<"===============copy Ctor Poly=============="<<std::endl;
    ++*m_refCount;
}

template<typename T>
SharedPtr<T>::~SharedPtr()
{
    //std::cout<<"=============Dtor============="<<std::endl;
    --*m_refCount;
    if ((m_ptr != NULL) && (*m_refCount == 0))
    {
        delete m_ptr;
        delete m_refCount;
    }
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& other)
{
    if (this != &other)
    {
        --*m_refCount;
        if (*m_refCount == 0)
        {
            delete m_ptr;
            delete m_refCount;
        }
        m_ptr = other.m_ptr;
        m_refCount = other.m_refCount;
        ++*m_refCount;
    }
    return *this;
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(T *other)
{
    --*m_refCount;
    if (*m_refCount == 0)
    {
        delete m_ptr;
        delete m_refCount;
    }
    m_ptr = other;
    m_refCount = new size_t;
    *m_refCount = 1;
    return *this;
}

template<typename T>
inline T* SharedPtr<T>::operator->() const
{
    return m_ptr;
}

template<typename T>
inline T& SharedPtr<T>::operator*() const
{
    return *m_ptr;
}

template<typename T>
inline bool SharedPtr<T>::operator!=(const SharedPtr& other) const
{
    return !(*this == other);
}

template<typename T>
inline bool SharedPtr<T>::operator==(const SharedPtr& other) const
{
    return *m_ptr == *other.m_ptr;
}

template<typename T>
inline T* SharedPtr<T>::get() const
{
    return m_ptr;
}

template<typename T>
inline SharedPtr<T>::operator bool() const
{
    return m_ptr;
}

#endif	//__SHARED_PTR_H__