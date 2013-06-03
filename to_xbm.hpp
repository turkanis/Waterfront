/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/to_xbm.hpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the function template to_xbm, which accepts a map and returns
 * image data in the XBM format.
 */

#ifndef WATERFRONT_TO_XBM_HPP_INCLUDED
#define WATERFRONT_TO_XBM_HPP_INCLUDED

#include <cmath>    // ceil
#include <ios>      // hex
#include <locale>
#include <sstream>
#include <string>
#include "map_base.hpp"

namespace waterfront {

template<typename Map>
std::string to_xbm(const Map& map)
{
    using namespace std;
    stringstream s;
    s.imbue(locale("C"));
    s << "#define test_width " << map.columns() << "\n";
    s << "#define test_height " << map.rows() << "\n";
    s << "static char test_bits[] = {";
    s << hex;
    int columns = map.columns();
    int bytes = static_cast<int>(ceil(static_cast<double>(columns / 8)));
    for (int y = 0, n = map.rows(); y < n; ++y) {
        int x = 0;
        for (int b = 0; b < bytes; ++b) {
            int value = 0;
            for (int z = 0; z < 8; ++z) {
                if (map[x][y])
                    value |= (1 << z);
                if (++x == columns)
                    break;
            }
            s << "0x" << value;
            if (y < n - 1 || b < bytes - 1)
                s << ',';
        }
    }
    s << "};\n";
    return s.str();
}

} // End namespace waterfront.

#endif // #ifndef WATERFRONT_TO_XBM_HPP_INCLUDED
