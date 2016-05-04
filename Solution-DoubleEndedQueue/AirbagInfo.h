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

class AirbagInfo
{
public:
	AirbagInfo(string name)
		: _name(name),
		_pNext(NULL),
		_pPrev(NULL)
	{
		// Intentionally left blank!!!
	}

	~AirbagInfo()
	{
		_pNext = NULL;
		_pPrev = NULL;
	}

	inline void setNextPointer(AirbagInfo* pNext)
	{
		_pNext = pNext;
	}

	inline void setPrevPointer(AirbagInfo* pPrev)
	{
		_pPrev = pPrev;
	}

	inline AirbagInfo* getNextPointer()
	{
		return _pNext;
	}

	inline AirbagInfo* getPreviousPointer()
	{
		return _pPrev;
	}

	inline string GetName()
	{
		return _name;
	}

private:
	string _name;
	AirbagInfo* _pNext;
	AirbagInfo* _pPrev;
};

