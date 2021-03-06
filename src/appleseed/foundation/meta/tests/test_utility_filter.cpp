
//
// This source file is part of appleseed.
// Visit https://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2013 Francois Beaune, Jupiter Jazz Limited
// Copyright (c) 2014-2018 Francois Beaune, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

// appleseed.foundation headers.
#include "foundation/utility/filter.h"
#include "foundation/utility/test.h"

using namespace foundation;

TEST_SUITE(Foundation_Utility_Filter_RegExFilter)
{
    TEST_CASE(IsValid_GivenEmptyRegularExpression_ReturnsTrue)
    {
        const RegExFilter filter("");

        const bool result = filter.is_valid();

        EXPECT_TRUE(result);
    }

    TEST_CASE(IsValid_GivenValidRegularExpression_ReturnsTrue)
    {
        const RegExFilter filter(".*");

        const bool result = filter.is_valid();

        EXPECT_TRUE(result);
    }

    TEST_CASE(IsValid_GivenInvalidRegularExpression_ReturnsFalse)
    {
        const RegExFilter filter("*");

        const bool result = filter.is_valid();

        EXPECT_FALSE(result);
    }

    TEST_CASE(Accepts_GivenCaseSensitiveRegExAndNameMatchingPattern_ReturnsTrue)
    {
        const RegExFilter filter("hell", RegExFilter::CaseSensitive);

        const bool result = filter.accepts("hello");

        EXPECT_TRUE(result);
    }

    TEST_CASE(Accepts_GivenCaseSensitiveRegExAndNameNotMatchingPattern_ReturnsFalse)
    {
        const RegExFilter filter("hell", RegExFilter::CaseSensitive);

        const bool result = filter.accepts("jell");

        EXPECT_FALSE(result);
    }

    TEST_CASE(Accepts_GivenCaseSensitiveRegExAndNameCaseNotMatchingPatternCase_ReturnsFalse)
    {
        const RegExFilter filter("hell", RegExFilter::CaseSensitive);

        const bool result = filter.accepts("HELLO");

        EXPECT_FALSE(result);
    }

    TEST_CASE(Accepts_GivenCaseInsensitiveRegExAndNameMatchingPattern_ReturnsTrue)
    {
        const RegExFilter filter("hell", RegExFilter::CaseInsensitive);

        const bool result = filter.accepts("HELLO");

        EXPECT_TRUE(result);
    }

    TEST_CASE(Accepts_GivenCaseInsensitiveRegExAndNameNotMatchingPattern_ReturnsFalse)
    {
        const RegExFilter filter("hell", RegExFilter::CaseInsensitive);

        const bool result = filter.accepts("jell");

        EXPECT_FALSE(result);
    }
}
