#include <iostream>
#include <windows.h>
#include <tchar.h>

using namespace std;

void polyPrint(const char *a)
{
	int l = strlen(a);
	if (!l) {cout << '0'; return;};
	for (int i=0;i<l;i++)
		if (a[i]-48)
		{
			cout << 'x' << '^' << l-i-1 << "+";
		}
	cout << "\b ";
}

void test(const char*a, const char * b)
{
	typedef char* (WINAPI *asd)(const char *, const char *, char *);
	HMODULE lh = LoadLibrary(_T("..\\debug\\polynom_dll"));
	asd divP = (asd)GetProcAddress(lh,"_divP@12");

	int l =strlen(a);
	char *r = new char[l+1];
	for (int i=0;i<l;i++)
		r[i]=48;
	r[l]=0;
	polyPrint(a);
	cout << "/ ";
	polyPrint(b);
	cout << " == ";
	char *t = divP(a,b,r);
	polyPrint(r);
	char *rt = new char[10];
	CharToOem(L"остаток: ",rt);
	cout << endl << rt;
	polyPrint(t);
	cout << endl << endl;

	FreeLibrary(lh);
}

int main()
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
	
	//test("1100010101010010100101010111101010101010010101010101100111","101110110");	//with this all doesn't place in 80 lines
	cin.get();
    return 0;
}

