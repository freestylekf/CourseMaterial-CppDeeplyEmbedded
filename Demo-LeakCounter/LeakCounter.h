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
#include "stdafx.h"
#include "Info.h"

template <typename T>
class LeakCounter : public T
{
public:
	static void* operator new(size_t size)
	{
		++Counter;
		return malloc(size);
	}

	static void operator delete(void* pObject)
	{
		--Counter;
		Info* pInfo = (Info*)pObject;
		--pInfo;
		string name = typeid(T).name();
		cout << name.c_str() << ", deleting object created ";
		printInfo(pInfo);

		unlink(pInfo);
		free(pInfo);
	}

	static void* operator new(size_t size, void* pMemory)
	{
		++Counter;
		return pMemory;
	}

	static void* operator new(size_t size, char* pFile, int line)
	{
		string name = typeid(T).name();
		cout << name.c_str() << ", newly created in line: " << line << endl;
		++Counter;

		size += sizeof(Info);
		Info* pInfo = (Info*)malloc(size);

		pInfo->pFile = pFile;
		pInfo->Line = line;
		pInfo->pNext = NULL;
		pInfo->pPrevious = NULL;

		link(pInfo);
		return (++pInfo);
	}

	static void link(Info* pInfo)
	{
		if (Info::pTail == NULL)
		{
			Info::pHead = pInfo;
			Info::pTail = pInfo;
			pInfo->pNext = NULL;
			pInfo->pPrevious = NULL;
		}
		else
		{
			pInfo->pPrevious = Info::pTail;
			pInfo->pNext = NULL;
			Info::pTail->pNext = pInfo;
			Info::pTail = pInfo;
		}
	}

	static void unlink(Info* pInfo)
	{
		if (pInfo == Info::pHead)
		{
			Info::pHead = pInfo->pNext;
			if (pInfo->pNext)
			{
				pInfo->pNext->pPrevious = NULL;
			}
		}
		else if (pInfo == Info::pTail)
		{
			Info::pTail = pInfo->pPrevious;
			if (pInfo->pPrevious)
			{
				pInfo->pPrevious->pNext = NULL;
			}
		}
		else
		{
			if (pInfo->pNext)
			{
				pInfo->pNext->pPrevious = pInfo->pPrevious;
			}
			if (pInfo->pPrevious)
			{
				pInfo->pPrevious->pNext = pInfo->pNext;
			}
		}

	}

	static void printInfo(Info* pInfo)
	{
		cout << "in line: " << pInfo->Line << endl;
	}

	static void printLeakInfo()
	{
		string name = typeid(T).name();
		cout << "   LeakCounter memory leak information   " << endl;
		cout << " the following objects are memory leaks: " << endl;
		cout << "=========================================" << endl;

		for (Info* pObject = Info::pHead;
		pObject != NULL;
			pObject = pObject->pNext)
		{
			cout << name.c_str() << " object, created in line: " <<
				pObject->Line <<
				endl;
		}

		cout << "=========================================" << endl;
	}

	static unsigned int getLeakNumber()
	{
		return Counter;
	}

private:
	static unsigned int Counter;
};

template <typename T>
unsigned int LeakCounter<T>::Counter = 0;