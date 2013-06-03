################################################################################
#
# Copyright CodeRage 2008.
#
# Distributed under the Boost Software License, Version 1.0.(See accompanying 
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
#
################################################################################

Waterfront Library Documentation

I. The Map Concept 


A Map is a class M such that if m is an instance of M and a and b are integers, 
the following expressions are valid:

    Expression       Type                       Semantics
    ----------------------------------------------------------------------------

    m.columns()      convertible to int         The number of cells in m, 
                                                measured horizontally

    m.rows()         convertible to int         The number of cells in m, 
                                                measured vertically

    m.scale()        convertible to double      The extent of each cell, 
                                                measured horizontally or
                                                vertically
    m[a][b]          convertible to bool        true if m contains land at
                                                coordinate (a, b); required
                                                that a and b are positive,
                                                a < m.columns(), and
                                                b < m.rows()

II. Concrete maps

A. The class simple_map, in the namespace waterfront, defines a map implemented
using a dynamically allocated array. If m is an instance of simple map, a and
b are horizontal and vertical coordinates within m, and c is a bool, the 
value of m[a][b] can be set using the expression

    m[a][b] = c

B. The class ball implements a map whose land mass consists of all the cells
within a certain distance of a specified point. This class is provided as a
demonstration.

III. Views.

The class templates inverse, union_, intersection, refinement, and 
coastal_view and the class blurred_view provide a means to construct a new map
from one or more pre-existing maps. (union_ is so-named because "union" is a
reserved word in C++.)

A. inverse, union, and intersection are straightforward; they correspond to set
theoretic operations.

B. refinement creates a map by subdividing each cell of an existing map. 

C. blurred_view creates a new map whose land mass consists of all 
those cells which are within a specified distance of a cell containing land in 
an existing map. 

D. coastal_view is the most important. The coastal_view of a map contains all
cells of the map which are waterfront property; more precisely, it consists of
the intersection of a map with a blurred view of the inverse of the same map. 
The higher the blur radius, the greater the amount of land that qualifies as
waterfront property.

IV. Functions

A. The function area returns the total land area of a map

B. The function coastal_ratio returns the area of a coastal view of a map 
divided by the area of the map; i.e., it returns the fraction of the map
that consists of waterfront property.

coastal_ratio takes three arguments: a map, a blur radius, and a precision.
The correct blur radius depends on the application: e.g., do you want to find 
the fraction of land in Europe within 1 km of the water, or the fraction within
10 km? Both values might be interesting.

The precision controls how accurately the inverse of the given map is blurred.
Smaller precisions yield more accurate values, and longer computation times.

To calculate the coastal ratio of a continent or region, represent it as a map,
most likely an instance of simple_map, and invoke the function coastal_ratio.

V. Performance

The library is probably pretty efficient, except for the class template
blurred_view, which could stand some optimization.
