/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/demo/refinement.cpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Demonstrates the template class refinement.
 */

#include <iostream>
#include "ball.hpp"
#include "refinement.hpp"

using namespace waterfront;

int main(int, char**)
{
    ball              b(80, 50, 7.0, point(300, 290), 55.5);
    refinement<ball>  ref(b, 2);
    for (int w = 0, m = ref.rows(); w < m; ++w) {
        for (int z = 0, n = ref.columns(); z < n; ++z) {
            std::cout << (ref[z][w] ? '*' : ' ');
            if (z == n - 1)
                std::cout << '\n';
        }
    }
}
