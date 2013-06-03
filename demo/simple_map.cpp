/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/test/simple_map.cpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Demonstrates the class simple_map.
 */

#include <iostream>
#include "simple_map.hpp"

using namespace waterfront;

int main(int, char**)
{
    simple_map m(10, 10, 7);
    m[0][0] = 1;
    m[1][0] = 1;
    m[0][1] = 1;
    m[9][9] = 1;

    // Should print 'true'
    std::cout << std::boolalpha
              << (m[0][0] && m[1][0] && m[0][1] && m[9][9] && !m[0][2]) 
              << "\n";
}
