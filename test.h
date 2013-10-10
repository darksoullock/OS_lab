
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
}