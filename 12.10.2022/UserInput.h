#pragma once

#include <string>
#include <iostream>

using namespace std;

template<class T>
class UserInput
{
	T data;
public:
	UserInput(string iName);
	operator T();

};

template<class T>
inline UserInput<T>::UserInput(string iName)
{
	do
	{
		cout << iName;
		cin >> data;
		system("cls");

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else break;
	} while (true);
}

template<class T>
inline UserInput<T>::operator T()
{
	return data;
}