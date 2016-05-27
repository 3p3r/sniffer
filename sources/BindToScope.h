/*
 * BindToScope.h
 *
 *  Created on: May 27, 2016
 *      Author: sepehr
 */

#ifndef BINDTOSCOPE_H_
#define BINDTOSCOPE_H_

namespace gtss {

/*!
 * @struct BindToScope
 * @brief  RAII utility that releases a typed C-style pointer.
 */
template<typename T>
struct BindToScope
{
    BindToScope(T*& ptr) : pointer(ptr) {}
    ~BindToScope();
    T*& pointer;
};

template< class T > struct no_ptr        { typedef T type; };
template< class T > struct no_ptr<T*>    { typedef T type; };

//! convenience macro to bound a pointer to a scope
#define BIND_TO_SCOPE(var) gtss::BindToScope<\
    gtss::no_ptr<decltype(var)>::type> scoped_##var(var);

} /* namespace gtss */

#endif /* BINDTOSCOPE_H_ */
