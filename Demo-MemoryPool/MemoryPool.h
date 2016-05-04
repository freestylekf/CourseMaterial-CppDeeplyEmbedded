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
#include "Chunk.h"

template <typename T>
class MemoryPool
{
	enum {e_size = 10};

public:
	static Chunk* _pHead;
	static char _memory[4000];

	static Chunk* initializeFreeList()
	{
		Chunk* chunkArray = reinterpret_cast<Chunk*>(_memory);

		for (auto i = 0; i < e_size - 1; i++)
		{
			Chunk* pData = &(chunkArray[i + 1]);
			chunkArray[i]._pNext = pData;
		}

		chunkArray[e_size - 1]._pNext = 0;

		return chunkArray;
	}

	static void* allocate(size_t size)
	{
		if (size == 0) size = sizeof(T);

		if (size != sizeof(T)) throw std::bad_alloc();

		if (!_pHead) throw std::bad_alloc();

		Chunk* ptr = reinterpret_cast<Chunk*>(_pHead);

		_pHead = ptr->_pNext;

		return ptr;
	}

	static void deallocate(void* ptr)
	{
		if (ptr == NULL) return;

		Chunk* chunk = (Chunk*)ptr;

		chunk->_pNext = _pHead;

		_pHead = chunk;
	}
};

template <typename T>
Chunk* MemoryPool<T>::_pHead = MemoryPool<T>::initializeFreeList();

template <typename T>
char MemoryPool<T>::_memory[4000] = { 0 };