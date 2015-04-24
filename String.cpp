#include<iostream>
#include<iomanip>
#include<cstring>
#include "String.h"
using namespace std;

String::String(const char *s)
: length((s != 0) ? strlen(s) : 0)
{
	setString(s);
}

String::String(const String &copystring)
: length(copystring.length)
{
	setString(copystring.sPtr);
}

String::~String()
{
	delete[]sPtr;
}

void String::setString(const char *string2)
{
	sPtr = new char[length + 1];

	if (string2 != 0)
	{
		for (int i = 0; i < length + 1; i++)
		{
			sPtr[i] = string2[i];
		}
	}
	else
		sPtr[0] = '\0';

}

const String &String:: operator=(const String & right)
{
	if (*this != right)
	{
		delete[]sPtr;
		length = right.length;
		setString(right.sPtr);
	}
	else
		cout << "Error!" << endl;
	return *this;
}

const String &String:: operator+=(const String &right)
{
	int newlength = length + right.length;
	char *tempsPtr = new char[newlength];
	for (int i = 0; i < length; i++)
		tempsPtr[i] = sPtr[i];
	int j = 0;
	for (int i = length; i < newlength; i++)
	{
		tempsPtr[i] = right.sPtr[j];
		j++;
	}

	delete[]sPtr;
	sPtr = new char[newlength];
	for (int i = 0; i < newlength; i++)
		sPtr[i] = tempsPtr[i];
	length = newlength;
	delete[]tempsPtr;
	return *this;
}

bool String:: operator!() const
{
	return (length == 0);
}

bool String::operator==(const String &right) const
{
	return (strcmp(sPtr, right.sPtr) == 0);
}

bool String:: operator<(const String &right) const
{
	return (strcmp(sPtr, right.sPtr)<0);
}

bool String:: operator>(const String &right) const
{
	return (strcmp(sPtr, right.sPtr)>0);
}

char &String:: operator[](int subcript)
{
	if (subcript<0 || subcript>length)
		cout << "Error" << endl;
	return sPtr[subcript];
}

char String:: operator[](int subcript) const
{
	if (subcript<0 || subcript>length)
		cout << "Error" << endl;
	return sPtr[subcript];
}
String String:: operator()(int start, int sublength) const
{
	if (start<0 || sublength>-length || start + sublength > length)
		return "";
	int newlength;
	if (sublength == 0 || start + sublength > length)
		newlength = length - start;
	else
		newlength = sublength;

	char *tempsPtr = new char[newlength + 1];
	for (int i = start; i < newlength; i++)
		tempsPtr[i] = sPtr[i];
	tempsPtr[newlength] = '\0';
	String convertstring(tempsPtr);
	delete[]tempsPtr;
	return convertstring;
}
int String::getLength() const
{
	return length;
}

ostream &operator<<(ostream &output, const String &s)
{
	output << s.sPtr;
	return output;
}

istream &operator>>(istream &input, String &s)
{
	char word[100];
	input >> setw(100) >> word;
	s = word;
	return input;
}