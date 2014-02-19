#include <iostream>
#include <windows.h>
using namespace std;
unsigned char Crc8(unsigned char *pcBlock, unsigned int len, unsigned char crc = 0xFF)
{
    unsigned int i;

    while (len--)
    {
        crc ^= *pcBlock++;

        for (i = 0; i < 8; i++)
            crc = crc & 0x80 ? (crc << 1) ^ 0x31 : crc << 1;
    }

    return crc;
}
int main(int argc, CHAR **argv)
{
	if (!*(argv+1)) return 1;
    HANDLE h = CreateFile((LPCSTR)*(argv+1),GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,0,OPEN_EXISTING,0,0);
    DWORD dwCount;
    BYTE buf[65535];
    BOOL b = false;
    int len = sizeof(buf);
    BYTE crc=0xFF;
    if (h!=INVALID_HANDLE_VALUE)
    {
        do
        {
            b = ReadFile(h,buf,len,&dwCount,0);
            crc = Crc8(buf,dwCount,crc);
        } while(b&&dwCount);
        cout << (int)crc << endl;
        SetFilePointer(h,0,0,FILE_END);
        buf[0]=crc;
        WriteFile(h,buf,1,&dwCount,0);
        CloseHandle(h);
    }
    else cout << "error" << endl;
    return 0;
}
