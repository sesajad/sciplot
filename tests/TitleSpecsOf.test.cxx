// sciplot - a modern C++ scientific plotting library powered by gnuplot
// https://github.com/sciplot/sciplot
//
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
//
// Copyright (c) 2018 Allan Leal
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// Catch includes
#include <tests/catch.hpp>

// sciplot includes
#include <sciplot/specs/TitleSpecsOf.hpp>
using namespace sciplot;

// This construction is needed to test TitleSpecsOf below!
struct SomeObject : TitleSpecsOf<SomeObject> {};

TEST_CASE("TitleSpecsOf", "[specs]")
{
    auto obj = SomeObject();

    obj.title("Hello");

    CHECK( obj.repr() == "title 'Hello' enhanced textcolor '#404040' font 'Georgia,12'");

    obj.titleShiftAlongX(1);

    CHECK( obj.repr() == "title 'Hello' enhanced textcolor '#404040' font 'Georgia,12' offset 1, 0");

    obj.titleShiftAlongY(2);

    CHECK( obj.repr() == "title 'Hello' enhanced textcolor '#404040' font 'Georgia,12' offset 1, 2");

    obj.titleShiftAlongGraphX(0.3);

    CHECK( obj.repr() == "title 'Hello' enhanced textcolor '#404040' font 'Georgia,12' offset graph 0.3, 2");

    obj.titleShiftAlongGraphY(0.4);

    CHECK( obj.repr() == "title 'Hello' enhanced textcolor '#404040' font 'Georgia,12' offset graph 0.3, graph 0.4");

    obj.titleShiftAlongScreenX(0.5);

    CHECK( obj.repr() == "title 'Hello' enhanced textcolor '#404040' font 'Georgia,12' offset screen 0.5, graph 0.4");

    obj.titleShiftAlongScreenY(0.6);

    CHECK( obj.repr() == "title 'Hello' enhanced textcolor '#404040' font 'Georgia,12' offset screen 0.5, screen 0.6");
}
