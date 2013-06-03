/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/demo/union.cpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Demonstrates the template class union.
 */

#include <iostream>
#include "ball.hpp"
#include "union.hpp"

using namespace waterfront;

int main(int, char**)
{
    ball b1(80, 50, 2.0, point(40, 50), 40);
    ball b2(80, 50, 2.0, point(120, 50), 40);
    union_<ball, ball> u(b1, b2);
    for (int w = 0, m = u.rows(); w < m; ++w) {
        for (int z = 0, n = u.columns(); z < n; ++z) {
            std::cout << (u[z][w] ? '*' : ' ');
            if (z == n - 1)
                std::cout << '\n';
        }
    }
}
