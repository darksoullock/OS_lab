// sLibTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "..\\Win32Project1\\polynom.h"
using namespace std;

#include "..\\test.h"

int _tmain(int argc, _TCHAR* argv[])
{
	test("11001110","110");
	test("111000","111000");
	test("111000","11");
	test("111100","00000011");
	test("100","110010");
	test("11111111","1");

	char *a = new char[20];
	CharToOem(L"тут деление на ноль:",a);
	cout << a << endl;
	test("11001110","0");

	test("1100010101010010100101010111101010101010010101010101100111","101110110");
	cin.get();
    return 0;
}

