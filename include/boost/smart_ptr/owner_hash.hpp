#ifndef BOOST_SMART_PTR_OWNER_HASH_HPP_INCLUDED
#define BOOST_SMART_PTR_OWNER_HASH_HPP_INCLUDED

// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <cstddef>

namespace boost
{

template<class T> struct owner_hash
{
    using result_type = std::size_t;
    using argument_type = T;

    std::size_t operator()( T const & t ) const noexcept
    {
        return t.owner_hash_value();
    }
};

} // namespace boost

#endif  // #ifndef BOOST_SMART_PTR_OWNER_HASH_HPP_INCLUDED
