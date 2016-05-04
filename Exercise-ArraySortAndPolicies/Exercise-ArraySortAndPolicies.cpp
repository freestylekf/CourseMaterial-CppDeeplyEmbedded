/**
* The MIT License (MIT)
*
* Copyright (c) 2016 Denis Vasilik
*
* Permission is hereby granted, free of charge, to any person
* obtaining a copy of this software and associated documentation
* files (the "Software"), to deal in the Software without
* restriction, including without limitation the rights to use,
* copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following
* conditions:
*
* The above copyright notice and this permission notice
* shall be included in all copies or substantial portions
* of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
* ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
* TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
* PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
* SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
* ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
* OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include "stdafx.h"

int main()
{
	//
	// Sort int
	//
	int intArray[] = { 1, 8, 5, 3, 4, 8, 10, 7, 7 };

	ArraySort<int> intSort;

	intSort(intArray, _countof(intArray));

	//
	// Sort Rectangle
	//

	Rectangle rectArray[] =
	{
		Rectangle(6, 7),
		Rectangle(8, 9),
		Rectangle(2, 2),
		Rectangle(4, 4),
		Rectangle(1, 9)
	};

	ArraySort<Rectangle> rectSort;

	rectSort(rectArray, _countof(rectArray));

	//
	// TODO: Use WidthComparator here!!!
	//

	ArraySort<Rectangle> rectSortWidth;

	rectSortWidth(rectArray, _countof(rectArray));

	return 0;
}
