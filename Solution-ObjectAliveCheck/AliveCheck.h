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
#include "SignatureGenerator.h"

template<typename T>
class AliveCheck : public T
{
public:
	inline bool isAlive() const
	{
		return this ? (s_signature == _signature) : false;
	}

	AliveCheck()
	{
		_signature = s_signature;
	}

	~AliveCheck()
	{
		if (isAlive())
		{
			_signature = 0x00DEAD00;
		}
		else
		{
			cout << "Object of type " << typeid(T).name() << "deleted twice!" << endl;
		}
	}

protected:
	int _signature;
	static int s_signature;
};

template <typename T>
int AliveCheck<T>::s_signature = SignatureGenerator::create();

