/******************************************************************************
 * $Id$
 *
 * Project:  libLAS - http://liblas.org - A BSD library for LAS format data.
 * Purpose:  LAS color class 
 * Author:   Howard Butler, hobu.inc@gmail.com
 *
 ******************************************************************************
 * Copyright (c) 2008, Howard Butler
 *
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following 
 * conditions are met:
 * 
 *     * Redistributions of source code must retain the above copyright 
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright 
 *       notice, this list of conditions and the following disclaimer in 
 *       the documentation and/or other materials provided 
 *       with the distribution.
 *     * Neither the name of the Martin Isenburg or Iowa Department 
 *       of Natural Resources nor the names of its contributors may be 
 *       used to endorse or promote products derived from this software 
 *       without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS 
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 ****************************************************************************/

#ifndef LIBLAS_LASCOLOR_HPP_INCLUDED
#define LIBLAS_LASCOLOR_HPP_INCLUDED

#include <liblas/detail/fwd.hpp>
#include <liblas/detail/utility.hpp>
// boost
#include <boost/cstdint.hpp>
// std
#include <stdexcept> // std::out_of_range
#include <cstdlib> // std::size_t

namespace liblas {

/// RGB color container
class Color
{
public:

    typedef boost::uint16_t value_type;

    /// Default constructor.
    /// Initializes with black color using RGB {0, 0, 0}.
    Color();

    // User-defined constructor.
    // Initializes object with given RGB values.
    Color(value_type red, value_type green, value_type blue)
        : m_red(red), m_green(green), m_blue(blue)
    {}

    /// Copy constructor.
    Color(Color const& other);

    /// Assignment opreator.
    Color& operator=(Color const& rhs);

    /// Comparison operator.
    bool operator==(const Color& other) const;
    
    /// Fetch value of the red image channel 
    value_type GetRed() const;

    /// Set value of the red image channel 
    void SetRed(value_type const& value);

    /// Fetch value of the blue image channel 
    value_type GetBlue() const;

    /// Set value of the blue image channel 
    void SetBlue(value_type const& value);

    /// Fetch value of the green image channel 
    value_type GetGreen() const;

    /// Set value of the red image channel 
    void SetGreen(value_type const& value);

    /// Index operator providing access to RGB values.
    /// Valid index values are 0, 1 or 2.
    /// \exception std::out_of_range if requested index is out of range (> 2).
    value_type& operator[](std::size_t const& n);

    /// Const version of index operator providing access to RGB values.
    /// Valid index values are 0, 1 or 2.
    /// \exception std::out_of_range if requested index is out of range (> 2).
    value_type const& operator[](std::size_t const& n) const;

private:

    value_type m_red;
    value_type m_green;
    value_type m_blue;
    
    void throw_out_of_range() const
    {
        throw std::out_of_range("subscript out of range");
    }
};


inline Color::value_type Color::GetRed() const
{
    return m_red;
}

inline void Color::SetRed(Color::value_type const& value)
{
    m_red = value;
}

inline Color::value_type Color::GetBlue() const
{
    return m_blue;
}

inline void Color::SetBlue(Color::value_type const& value)
{
    m_blue = value;
}

inline Color::value_type Color::GetGreen() const
{
    return m_green;
}

inline void Color::SetGreen(Color::value_type const& value)
{
    m_green = value;
}

inline Color::value_type& Color::operator[](std::size_t const& n)
{
    if (n == 0) { return m_red; }
    if (n == 1) { return m_green; }
    if (n == 2) { return m_blue; }

    throw_out_of_range();
}

inline Color::value_type const& Color::operator[](std::size_t const& n) const
{
    if (n == 0) { return m_red; }
    if (n == 1) { return m_green; }
    if (n == 2) { return m_blue; }

    throw_out_of_range();
}

} // namespace liblas

#endif // LIBLAS_LASCOLOR_HPP_INCLUDED
