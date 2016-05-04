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

template<typename T, const unsigned int ThreadCount = 10>
class ThreadPool
{
public:
	ThreadPool()
		: _hasBeenCanceled(false)
	{
		for (int i = 0; i < ThreadCount; i++)
			_threadHandles[i] = NULL;

		_pSynchronizer = new Mutex();
		_customerQueue = new deque<OopDelegate<T>*>();
		_activator = new OopDelegate<ThreadPool>(this, &ThreadPool::Run);
		_poolThread = new DemoThread<ThreadPool>(0, _activator, _pSynchronizer);

		initialize();
		_poolThread->Start();
	}

	~ThreadPool()
	{
		_customerQueue->clear();
		_hasBeenCanceled = true;

		if (_customerQueue)
		{
			delete _customerQueue;
			_customerQueue = NULL;
		}

		for (int i = 0; i < ThreadCount; i++)
		{
			while (_threadHandles[i]->isBusy())
			{
				::Sleep(10);
			}
			_threadHandles[i]->Stop();
			
			if (_threadHandles[i])
			{
				delete _threadHandles[i];
				_threadHandles[i] = NULL;
			}
		}

		if (_poolThread)
		{
			delete _poolThread;
			_poolThread = NULL;
		}

		if (_activator)
		{
			delete _activator;
			_activator = NULL;
		}

		if (_pSynchronizer)
		{
			delete _pSynchronizer;
			_pSynchronizer = NULL;
		}
	}

	void initialize()
	{
		for (int i = 0; i < ThreadCount; i++)
		{
			if (_threadHandles[i] == NULL)
			{
				_threadHandles[i] = new DemoThread<T>();
				_threadHandles[i]->Start();
			}
		}
	}

	void initialize(unsigned int position)
	{
		if (_threadHandles[position]) return;

		_threadHandles[position] = new DemoThread();
	}

	void addCustomer(OopDelegate<T>* customer)
	{
		_customerQueue->push_back(customer);
	}

	void Run(EventArgs e)
	{
		while (!_hasBeenCanceled)
		{
			if (_customerQueue->empty())
				continue;

			auto customer = _customerQueue->front();
			_customerQueue->pop_front();

			auto found = false;

			for (int i = 0; i < ThreadCount; i++)
			{
				if (_threadHandles[i]->isBusy())
					continue;

				_threadHandles[i]->setCustomer(customer);
				found = true;
				break;
			}

			if (found == false)
				cout << "There are no free threads available." << endl;
		}
	}

private:
	DemoThread<ThreadPool>* _poolThread;
	DemoThread<T>* _threadHandles[ThreadCount];
	deque<OopDelegate<T>*>* _customerQueue;
	Mutex* _pSynchronizer;
	OopDelegate<ThreadPool>* _activator;
	bool _hasBeenCanceled;
};

