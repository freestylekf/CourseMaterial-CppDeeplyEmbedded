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

enum Token : char { SoD = 0x00, SoL = 0x01 };

enum Tokens : char
{
	Escape = 0x1B,
	TypeName = 0x1C,
	TypeNameLength = 0x1A,
	MemberNameLength = 0x1D,
	MemberName = 0x1E,
	MemberData = 0x1F
};

enum Types
{
	Type_Auto = 0xF0,
	Type_Motor,
	Type_char,
	Type_bool,
	Type_int_8,
	Type_int_16,
	Type_int_32,
	Type_int_64,
	Type_float,
	Type_double,
	Type_string,
	Type_string_ptr,
	Type_Array,
	Enum_Kraftstoff,
	Type_None = 0x00
};

class Serializer
{
public:
	Serializer();
	~Serializer();
};

