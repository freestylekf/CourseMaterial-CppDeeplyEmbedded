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

class Auto
{
private:
	int TankInhalt;
	string Kennzeichen;
	int MaxInhalt;
	string Fahrer;
	static int AutoCounter;

public:
	Auto();

	Auto(int MaxInhalt, string Fahrer);

	Auto(const Auto& rhs);

	~Auto();

	int getTankInhalt();

	bool Tanke(int Menge);

	string getKennzeichen();

	void setKennzeichen(string Kennzeichen);

	friend ostream& operator<< (ostream& Destination, const Auto& rhs);

	friend istream& operator>> (istream& Source, Auto& rhs);

private:
	static void write(ostream& os, Types types);

	static void write(ostream& os, Token token);

	static void write(ostream& os, Tokens token);
	
	static void write(ostream& os, const char* pStr);
	
	static void write(ostream& os, int value);

};
