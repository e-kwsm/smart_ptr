#ifndef BOOST_POINTER_TO_OTHER_HPP_INCLUDED
#define BOOST_POINTER_TO_OTHER_HPP_INCLUDED

//
//  pointer_to_other.hpp
//
//  (C) Copyright Ion Gaztanaga 2005.
//  Copyright (c) 2005 Peter Dimov.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  See http://www.boost.org/libs/smart_ptr/ for documentation.
//

namespace boost
{

// Defines the same pointer type (raw or smart) to another pointee type

template<class T, class U>
struct pointer_to_other;

template<class T, class U, 
         template<class> class Sp>
struct pointer_to_other< Sp<T>, U >
{
   using type = Sp<U>;
};

template<class T, class T2, class U, 
         template<class, class> class Sp>
struct pointer_to_other< Sp<T, T2>, U >
{
   using type = Sp<U, T2>;
};

template<class T, class T2, class T3, class U, 
         template<class, class, class> class Sp>
struct pointer_to_other< Sp<T, T2, T3>, U >
{
   using type = Sp<U, T2, T3>;
};

template<class T, class U>
struct pointer_to_other< T*, U >
{
   using type = U*;
};

} // namespace boost

#endif // #ifndef BOOST_POINTER_TO_OTHER_HPP_INCLUDED
