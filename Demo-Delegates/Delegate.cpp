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
#include "Delegate.h"
#include "EventArgs.h"

Delegate::Delegate(CallbackFunction callback)
	: _callbacks(new list<CallbackFunction>())
{
	_callbacks->push_back(callback);
}

Delegate::~Delegate()
{
	delete _callbacks;
}

void Delegate::add(CallbackFunction callback)
{
	_callbacks->push_back(callback);
}

void Delegate::operator()(EventArgs e)
{
	FireEvent(e);
}

void Delegate::FireEvent(EventArgs e)
{
	for (list<CallbackFunction>::iterator it = _callbacks->begin();
		 it != _callbacks->end();
		 it++)
	{
		(*it)(e);
	}
}
