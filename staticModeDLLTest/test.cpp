
#include "..\\polynom_dll\\polynom_dll.h"
#include <iostream>
#include <windows.h>

using namespace std;
#include "..\\test.h"


int main()
{
	test("11001110","110");
	test("111000","111000");
	test("111000","11");
	test("111100","00000011");
	test("100","110010");
	test("11111111","1");

	char *a = new char[20];
	CharToOem(L"��� ������� �� ����:",a);
	cout << a << endl;
	test("11001110","0");

	//test("1100010101010010100101010111101010101010010101010101100111","101110110");	//with this all doesn't place in 80 lines
	cin.get();
    return 0;
}

