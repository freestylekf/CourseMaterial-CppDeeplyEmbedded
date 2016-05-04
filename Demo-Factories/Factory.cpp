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
#include "Factory.h"

Factory::Factory() 
	: head(NULL), tail(NULL)
{

}

bool Factory::doregister(IFactoryElement* ele)
{
	// add Element to end of list
	if (head == NULL)
	{
		// first element ever
		head = ele;
		tail = ele;
	}
	else
	{
		tail->getNext() = ele;
		tail = ele;
	}
	return true;
}

bool Factory::unregister(string Typename)
{
	return true;
}

void* Factory::factorize(string Typename, string filename)
{
	IFactoryElement* ele = find(Typename);
	if (ele != NULL)
	{
		return ele->clone(filename);
	}
	else
		return NULL;
}

IFactoryElement* Factory::find(string Typename)
{
	for (IFactoryElement* ele = head; ele != NULL; ele = ele->getNext())
	{
		if (*ele == Typename)
			return ele;
	}

	return NULL;
}

