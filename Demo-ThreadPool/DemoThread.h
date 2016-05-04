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
#include "Thread.h"
#include "Mutex.h"
#include "OopDelegate.h"
#include "EventArgs.h"
#include "TypeMethodWrapper.h"

template<typename T>
class DemoThread : public Thread
{
public:
	DemoThread()
		: _busy(false),
		_counter(0),
		_synchronizer(NULL),
		_customer(NULL)
	{
		_sleepTime = 10;
	}

	DemoThread(int sleepTime, OopDelegate<T>* customer, Mutex* synchronizer)
		: _busy(false),
		_counter(0),
		_synchronizer(synchronizer),
		_customer(customer)
	{
		_sleepTime = sleepTime;
	}

	void setCustomer(OopDelegate<T>* customer)
	{
		_customer = customer;
		_busy = true;
		_counter = 0;
	}

	bool isBusy()
	{
		return _busy;
	}

private:
	bool WorkCycle()
	{
		if (_customer != NULL)
		{
			cout << "Thread: " << _threadId << endl;

			(*_customer)(EventArgs("Test"));
			_customer = NULL;
			_busy = false;
		}
		else
		{
			::Sleep(0);
		}
		return false;
	}

	bool _busy;
	int _counter;
	Mutex* _synchronizer;
	OopDelegate<T>* _customer;
};
