/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/demo/inverse.cpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Demonstrates the template class inverse.
 */

#include <iostream>
#include "ball.hpp"
#include "inverse.hpp"

using namespace waterfront;

int main(int, char**)
{
    ball           b(80, 50, 7.0, point(300, 290), 55.5);
    inverse<ball>  inv(b);
    for (int w = 0, m = inv.rows(); w < m; ++w) {
        for (int z = 0, n = inv.columns(); z < n; ++z) {
            std::cout << (inv[z][w] ? '*' : ' ');
            if (z == n - 1)
                std::cout << '\n';
        }
    }
}
