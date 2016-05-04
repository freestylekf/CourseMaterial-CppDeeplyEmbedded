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

template <typename T>
class InDeQueue
{
public:
	InDeQueue()
		: _pHead(NULL),
		_pTail(NULL)
	{
		// Intentionally left blank!!!
	}

	~InDeQueue()
	{
		while (!IsEmpty())
		{
			auto pObject = pop_front();

			if (pObject)
			{
				delete pObject;
				pObject = NULL;
			}
		}
	}

	bool IsEmpty()
	{
		return (_pHead == NULL || _pTail == NULL);
	}

	T* pop_front()
	{
		if (IsEmpty())
			throw std::runtime_error("empty queue");

		auto retVal = _pHead;

		_pHead = _pHead->getNextPointer();

		// Check whether it is the last object in the queue
		if (_pHead)
			_pHead->setPrevPointer(NULL);

		retVal->setNextPointer(NULL);
		retVal->setPrevPointer(NULL);

		return retVal;
	}

	T& front()
	{
		return (*_pHead)
	}

	void push_back(T* pObject)
	{
		if (IsEmpty())
			_pHead = pObject;
		else
			_pTail->setNextPointer(pObject);

		pObject->setPrevPointer(_pTail);
		pObject->setNextPointer(NULL);

		_pTail = pObject;
	}

private:

	T* _pHead;
	T* _pTail;
};

