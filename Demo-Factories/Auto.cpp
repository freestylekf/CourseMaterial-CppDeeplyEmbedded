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
#include "Auto.h"

int Auto::AutoCounter = 0;

Auto::Auto()
	: TankInhalt(0),
	Kennzeichen(""),
	MaxInhalt(0),
	Fahrer("")
{

}

Auto::Auto(int MaxInhalt, string Fahrer)
	: TankInhalt(0),
	Kennzeichen(""),
	MaxInhalt(MaxInhalt),
	Fahrer(Fahrer)
{

}

Auto::Auto(const Auto& rhs)
{

}

Auto::~Auto()
{

}

int Auto::getTankInhalt()
{
	return this->TankInhalt;
}

bool Auto::Tanke(int Menge)
{
	this->TankInhalt = Menge;

	return true;
}

string Auto::getKennzeichen()
{
	return this->Kennzeichen;
}

void Auto::setKennzeichen(string Kennzeichen)
{
	this->Kennzeichen = Kennzeichen;
}

void Auto::write(ostream& os, Token token)
{
	os.write((char*)&token, sizeof(token));
}

void Auto::write(ostream& os, Types types)
{
	os.write((char*)&types, sizeof(types));
}

void Auto::write(ostream& os, Tokens tokens)
{
	os.write((char*)&tokens, sizeof(tokens));
}

void Auto::write(ostream& os, const char* pStr)
{
	os.write((char*)pStr, strlen(pStr));
}

void Auto::write(ostream& os, int value)
{
	os.write((char*)&value, sizeof(value));
}

ostream& operator<<(ostream& os, const Auto& car)
{
	auto typeName = "Auto";
	auto typeNameLength = strlen(typeName);

	auto tankInhalt = "TankInhalt";
	auto tankInhaltLength = strlen(tankInhalt);

	auto maxInhalt = "MaxInhalt";
	auto maxInhaltLength = strlen(maxInhalt);

	auto autoCounter = "AutoCounter";
	auto autoCounterLength = strlen(autoCounter);

	auto kennzeichen = "Kennzeichen";
	auto kennzeichenLength = strlen(kennzeichen);

	auto fahrer = "Fahrer";
	auto fahrerLength = strlen(fahrer);

	Auto::write(os, SoD);
	Auto::write(os, SoL);

	Auto::write(os, TypeName);
	Auto::write(os, typeNameLength);
	Auto::write(os, typeName);

	Auto::write(os, MemberName);
	Auto::write(os, tankInhaltLength);
	Auto::write(os, tankInhalt);
	Auto::write(os, car.TankInhalt);

	Auto::write(os, MemberName);
	Auto::write(os, maxInhaltLength);
	Auto::write(os, maxInhalt);
	Auto::write(os, car.MaxInhalt);

	Auto::write(os, MemberName);
	Auto::write(os, autoCounterLength);
	Auto::write(os, autoCounter);
	Auto::write(os, car.AutoCounter);

	Auto::write(os, MemberName);
	Auto::write(os, kennzeichenLength);
	Auto::write(os, kennzeichen);
	Auto::write(os, car.Kennzeichen.length());
	Auto::write(os, car.Kennzeichen.c_str());

	Auto::write(os, MemberName);
	Auto::write(os, fahrerLength);
	Auto::write(os, fahrer);
	Auto::write(os, car.Fahrer.length());
	Auto::write(os, car.Fahrer.c_str());

	return os;
}

istream& operator>>(istream& is, Auto& car)
{
	char chRead = 0;

	// Read SoD
	is.read(&chRead, 1);

	// Read SoL
	is.read(&chRead, 1);

	while (!is.eof())
	{
		// Read Tokens
		is.read(&chRead, 1);

		if (chRead == TypeName)
		{
			int length = 0;
			is.read((char *)&length, 4);

			// Read TypeName
			char buffer[50] = { 0 };
			for (auto i = 0; i < length; i++)
			{
				is.read(&buffer[i], 1);
			}
		}
		else if(chRead == MemberName)
		{
			int memberNameLength = 0;
			is.read((char *)&memberNameLength, 4);

			// Read TypeName
			char buffer[50] = { 0 };
			for (auto i = 0; i < memberNameLength; i++)
			{
				is.read(&buffer[i], 1);
			}

			if (strcmp(buffer, "TankInhalt") == 0) 
			{
				// Read Value
				int value = 0;
				is.read((char *)&value, 4);
				car.TankInhalt = value;
			}
			else if (strcmp(buffer, "MaxInhalt") == 0)
			{
				// Read Value
				int value = 0;
				is.read((char *)&value, 4);
				car.MaxInhalt = value;
			}
			else if (strcmp(buffer, "AutoCounter") == 0) {
				// Read Value
				int value = 0;
				is.read((char *)&value, 4);
				car.AutoCounter = value;
			} 
			else if (strcmp(buffer, "Kennzeichen") == 0) 
			{
				int kennzeichenLength = 0;
				is.read((char *)&kennzeichenLength, 4);

				// Read TypeName
				char buffer[50] = { 0 };
				for (auto i = 0; i < kennzeichenLength; i++)
				{
					is.read(&buffer[i], 1);
				}
				car.Kennzeichen = string(buffer);
			} 
			else if (strcmp(buffer, "Fahrer") == 0) 
			{
				int fahrerLength = 0;
				is.read((char *)&fahrerLength, 4);

				// Read TypeName
				char buffer[50] = { 0 };
				for (auto i = 0; i < fahrerLength; i++)
				{
					is.read(&buffer[i], 1);
				}
				car.Fahrer = string(buffer);
			}
		}
	}

	return is;
}
