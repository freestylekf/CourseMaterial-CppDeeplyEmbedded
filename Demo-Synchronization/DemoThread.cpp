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
#include "DemoThread.h"

int DemoThread::Counter = 0;

DemoThread::DemoThread(int sleepTime, char*& pBuffer)
	: _pBuffer(pBuffer)
{
	_sleepTime = sleepTime;
	_synchronizer = new Mutex();
}

DemoThread::~DemoThread()
{
	delete _synchronizer;
}

bool DemoThread::WorkCycle()
{
	_synchronizer->Aquire();

	cout << "Thread: " << _threadId << ", " << ++Counter << endl;

	int offset = 0;

	// Add a string to the buffer
	memcpy(_pBuffer, "Thread: ", 8);
	offset = 8;

	// Add thread id to buffer
	char* chStr = ultoa(_threadId, _pBuffer + offset, 10);
	memcpy(_pBuffer + offset, chStr, strlen(chStr));
	offset += strlen(chStr);

	// Add a separator the buffer
	memcpy(_pBuffer + offset, ", ", 2);
	offset += 2;

	// Add the counter value to the buffer
	chStr = itoa(Counter, _pBuffer + offset, 10);
	memcpy(_pBuffer + offset, chStr, strlen(chStr));
	offset += strlen(chStr);

	memcpy(_pBuffer + offset, "\r\n", 2);
	offset += 2;

	_pBuffer += offset;

	_synchronizer->Release();

	return Counter > 19 ? true : false;
}
