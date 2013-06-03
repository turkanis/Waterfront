/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/simple_map.hpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the class simple_map, a model of Map based on a dynamically
 * allocated array.
 */

#ifndef WATERFRONT_SIMPLE_MAP_HPP_INCLUDED
#define WATERFRONT_SIMPLE_MAP_HPP_INCLUDED

#include <cmath>   // ceil, floor
#include <climits> // CHAR_BIT
#include <cstddef> // size_t
#include <cstring> // memset
#include <string>

namespace waterfront {

class simple_map {
private:
    class column_type;
    class const_column_type;
public:
    simple_map(int cols, int rows, double scale)
        : cols_(cols), rows_(rows), scale_(scale)
    {
        std::size_t length = ceil(static_cast<double>(cols * rows) / CHAR_BIT);
        data_ = new unsigned char[length];
        memset(data_, 0, length);
    }
    ~simple_map()
    {
        delete [] data_;
    }
    int columns() const { return cols_; }
    int rows() const { return rows_; }
    double scale() const { return scale_; }
    column_type operator[](int col);
    const_column_type operator[](int col) const;
    std::string to_string() const
    {
        std::string result;
        std::size_t length = 
            ceil(static_cast<double>(cols_ * rows_) / CHAR_BIT);
        int cells = cols_ * rows_;
        for (std::size_t z = 0; z < length; ++z) {
            unsigned char value = data_[z];
            for (int w = 0; w < CHAR_BIT; ++w) {
                int mask = 1 << w;
                result += (value & mask) ? '1' : '0';
                if (--cells == 0)
                    return result;
            }
        }
    }
private:

    // Prohibit copying and assignment
    simple_map(const simple_map&);
    simple_map& operator=(const simple_map&);

    bool get(int col, int row) const
    {
        std::size_t  bit_offset = cols_ * row + col;
        std::size_t  byte_offset = floor(bit_offset / CHAR_BIT);
        std::size_t  remainder = bit_offset - byte_offset * CHAR_BIT;
        int          mask = 1 << remainder;
        return (data_[byte_offset] & mask) != 0;
    }

    void set(int col, int row, bool value) const
    {
        std::size_t  bit_offset = cols_ * row + col;
        std::size_t  byte_offset = floor(bit_offset / CHAR_BIT);
        std::size_t  remainder = bit_offset - byte_offset * CHAR_BIT;
        int          mask = 1 << remainder;
        unsigned char c = data_[byte_offset];
        data_[byte_offset] = value ?
            (data_[byte_offset] | mask) :
            (data_[byte_offset] & ~mask);
    }

    std::size_t ceil(double d) const
    {
        return static_cast<std::size_t>(std::ceil(d));
    }

    std::size_t floor(double d) const
    {
        return static_cast<std::size_t>(std::floor(d));
    }

    // Return type of const operator[]
    class const_column_type {
    public:
        const_column_type(const simple_map& map, int col)
            : map_(map), col_(col)
            { }
        bool operator[](int row) const
        {
            return map_.get(col_, row); 
        }
    private:
        const simple_map&  map_;
        int                col_;
    };
    friend class const_column_type;

    class cell {
    private:
        struct safe_bool_impl {
            void x() { }
        };
        typedef void (safe_bool_impl::*safe_bool)();
    public:
        cell(simple_map& map, int col, int row)
            : map_(map), col_(col), row_(row)
            { }
        operator safe_bool() const
        {
            return map_.get(col_, row_) ? &safe_bool_impl::x : 0;
        }
        bool operator=(bool value)
        {
            map_.set(col_, row_, value);
            return value;
        }
    private:
        simple_map&  map_;
        int          col_;
        int          row_;
    };

    // Return type of non-const operator[]
    class column_type {
    public:
        column_type(simple_map& map, int col)
            : map_(map), col_(col)
            { }
        cell operator[](int row) const
        {
            return cell(map_, col_, row);
        }
    private:
        simple_map&  map_;
        int          col_;
    };
    friend class column_type;

    int             cols_;
    int             rows_;
    double          scale_;
    unsigned char*  data_;
};

simple_map::column_type
simple_map::operator[] (int col)
{
    return column_type(*this, col);
}

simple_map::const_column_type
simple_map::operator[] (int col) const
{
    return const_column_type(*this, col);
}

} // End namespace waterfront.

#endif // #ifndef WATERFRONT_SIMPLE_MAP_HPP_INCLUDED
