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
#include "Thread.h"

Thread::Thread()
	: _running(false),
	_sleepTime(100)
{
}

Thread::Thread(long sleepTime)
	: _running(false),
	_sleepTime(sleepTime)
{
}

void Thread::SetPriority(int priorityLevel)
{
	_priorityLevel = priorityLevel;
}

void Thread::Start()
{
	_threadHandle = CreateThread(
		NULL,
		0,
		(LPTHREAD_START_ROUTINE) Init,
		this,
		0,
		(LPDWORD) &_threadId);

	if (_threadHandle == NULL)
		throw runtime_error("Unable to start thread!");
}

void Thread::Stop()
{
	if (!_running) return;
	if (!_suspended) Resume();
	Terminate();
	CloseHandle(_threadHandle);
}

void Thread::Join()
{
	throw runtime_error("Not implemented!");
}

void Thread::Suspend()
{
	if (_running && !_suspended)
	{
		SuspendThread(_threadHandle);
		_suspended = true;
	}
}

void Thread::Resume()
{
	if (_running && _suspended)
	{
		ResumeThread(_threadHandle);
	}
}

int Thread::Init(void * pParam)
{
	((Thread*) pParam)->Run();
	return 0;
}

void Thread::Run()
{
	bool hasBeenCanceled = false;
	do
	{
		hasBeenCanceled = WorkCycle();
		Sleep(_sleepTime);
	} while (!hasBeenCanceled);
}

void Thread::Terminate()
{
	if (_running && !_suspended)
	{
		TerminateThread(_threadHandle, 0);
		_running = false;
	}
}
