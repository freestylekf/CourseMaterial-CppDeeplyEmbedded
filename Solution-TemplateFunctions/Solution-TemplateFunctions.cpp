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

int Max(int a, int b);

template <typename T>
T GenericMax(T a, T b);

int main()
{
	char chA = numeric_limits<char>::min();
	char chB = numeric_limits<char>::max();
	char chResult = Max(chA, chB);

	cout << "The maximum value for type char is: " << numeric_limits<int>::max() << endl;
	cout << "Char Result => " << (int)chResult << endl;

	int iA = numeric_limits<int>::min();
	int iB = numeric_limits<int>::max();
	int iResult = Max(iA, iB);

	cout << "The maximum value for type int is: " << numeric_limits<int>::max() << endl;
	cout << "Int Result => " << iResult << endl;

	double dA = numeric_limits<double>::min();
	double dB = numeric_limits<double>::max();
	double dResult = GenericMax<double>(dA, dB);

	cout << "The maximum value for type double is: " << numeric_limits<double>::max() << endl;
	cout << "Double Result => " << dResult << endl;

	return 0;
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

template <typename T>
T GenericMax(T a, T b)
{
	return a > b ? a : b;
}



