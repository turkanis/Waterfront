/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/demo/coastal_ratio.cpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Demonstrates the template class coastal_view.
 */

#include <iostream>
#include "ball.hpp"
#include "coastal_ratio.hpp"
#include "union.hpp"

using namespace waterfront;

int main(int, char**)
{
    ball b1(400, 250, 2.0, point(200, 250), 200);
    ball b2(400, 250, 2.0, point(600, 250), 200);
    union_<ball, ball> u(b1, b2);
    std::cout << coastal_ratio(u, 50, 3);
}
