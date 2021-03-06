
// Copyright 2015, 2016, 2017 Peter Dimov.
//
// Distributed under the Boost Software License, Version 1.0.
//
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt


#include <boost/mp11/algorithm.hpp>
#include <boost/mp11/list.hpp>
#include <boost/mp11/integral.hpp>
#include <boost/mp11/utility.hpp>
#include <boost/core/lightweight_test_trait.hpp>
#include <type_traits>
#include <tuple>
#include <utility>

struct X1 {};

int main()
{
    using boost::mp11::mp_list;
    using boost::mp11::mp_none_of_q;
    using boost::mp11::mp_true;
    using boost::mp11::mp_false;
    using boost::mp11::mp_quote;

    {
        using L1 = mp_list<>;

        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L1, mp_quote<std::is_const>>, mp_true>));

        using L2 = mp_list<X1, X1 const, X1, X1, X1>;

        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L2, mp_quote<std::is_volatile>>, mp_true>));
        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L2, mp_quote<std::is_const>>, mp_false>));

        using L3 = mp_list<X1 const, X1 const, X1, X1 const, X1>;

        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L3, mp_quote<std::is_volatile>>, mp_true>));
        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L3, mp_quote<std::is_const>>, mp_false>));
    }

    {
        using L1 = std::tuple<>;

        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L1, mp_quote<std::is_const>>, mp_true>));

        using L2 = std::tuple<X1, X1 const, X1, X1, X1>;

        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L2, mp_quote<std::is_volatile>>, mp_true>));
        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L2, mp_quote<std::is_const>>, mp_false>));

        using L3 = std::tuple<X1 const, X1 const, X1, X1 const, X1>;

        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L3, mp_quote<std::is_volatile>>, mp_true>));
        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L3, mp_quote<std::is_const>>, mp_false>));
    }

    {
        using L2 = std::pair<X1 const, X1>;

        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L2, mp_quote<std::is_volatile>>, mp_true>));
        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L2, mp_quote<std::is_const>>, mp_false>));

        using L3 = std::pair<X1 const, X1 const>;

        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L3, mp_quote<std::is_volatile>>, mp_true>));
        BOOST_TEST_TRAIT_TRUE((std::is_same<mp_none_of_q<L3, mp_quote<std::is_const>>, mp_false>));
    }

    return boost::report_errors();
}
