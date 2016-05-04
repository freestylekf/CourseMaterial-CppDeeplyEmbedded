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
#pragma once

#include "Rectangle.h"
#include "Comparator.h"

// Sorts an array in ascending order using the BubbleSort algorithm.
// The template uses a template argument.
//template <typename T, template Comparator>
template <typename T, template <typename T> typename Comparator = LessThan >
struct ArraySort
{
	void operator() (T* array, unsigned int size) const
	{
		Comparator<T> lessThan;
		for (unsigned int SortPos = size - 1; SortPos > 0; --SortPos)
		{
			for (unsigned int Comparepos = 0; Comparepos < size - 1; ++Comparepos)
			{
				if (lessThan(array[Comparepos + 1], array[Comparepos]))
				{
					swap(array[Comparepos + 1], array[Comparepos]);
				}
			}
		}
	}

	void swap(T& a, T& b) const
	{
		T temp = a;
		a = b;
		b = temp;
	};
};