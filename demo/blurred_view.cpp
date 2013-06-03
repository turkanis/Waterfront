/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/demo/blurred_view.cpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Demonstrates the class blurred_view.
 */

#include <iostream>
#include "ball.hpp"
#include "blurred_view.hpp"

using namespace waterfront;

int main(int, char**)
{
    std::cout << "non-blurred ball:\n\n";
    ball b(80, 50, 7.0, point(300, 290), 55.5);
    for (int w = 0, m = b.rows(); w < m; ++w) {
        for (int z = 0, n = b.columns(); z < n; ++z) {
            std::cout << (b[z][w] ? '*' : ' ');
            if (z == n - 1)
                std::cout << '\n';
        }
    }
    std::cout << "\n\nblurred ball:\n\n";
    blurred_view  view(b, 20.0);
    for (int w = 0, m = view.rows(); w < m; ++w) {
        for (int z = 0, n = view.columns(); z < n; ++z) {
            std::cout << (view[z][w] ? '*' : ' ');
            if (z == n - 1)
                std::cout << '\n';
        }
    }
}
