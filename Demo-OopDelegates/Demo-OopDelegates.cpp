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

int main()
{
	Light light("Light 1");
	Oven oven1("Oven 1");
	Oven oven2("Oven 2");

	OopDelegate<Light> lightSwitch = OopDelegate<Light>(&light, &Light::Switched);
	OopDelegate<Oven> ovenSwitch = OopDelegate<Oven>(&oven1, &Oven::Switched);
	ovenSwitch.add(&oven2, &Oven::Switched);

	lightSwitch(EventArgs("Switching light on."));
	ovenSwitch(EventArgs("Heating up the oven."));

    return 0;
}

