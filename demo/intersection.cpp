/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/demo/intersection.cpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Demonstrates the template class intersection.
 */

#include <iostream>
#include "ball.hpp"
#include "intersection.hpp"

using namespace waterfront;

int main(int, char**)
{
    ball b1(80, 50, 2.0, point(60, 50), 40);
    ball b2(80, 50, 2.0, point(100, 50), 40);
    intersection<ball, ball> i(b1, b2);
    for (int w = 0, m = i.rows(); w < m; ++w) {
        for (int z = 0, n = i.columns(); z < n; ++z) {
            std::cout << (i[z][w] ? '*' : ' ');
            if (z == n - 1)
                std::cout << '\n';
        }
    }
}
