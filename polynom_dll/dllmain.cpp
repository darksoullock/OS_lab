// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <iostream>
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
BOOL APIENTRY DllMain( HMODULE hModule,
					  DWORD  ul_reason_for_call,
					  LPVOID lpReserved
					  )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
			std::cout << "dll attached in " << (lpReserved?"static":"dynamic") << " mode\n\n";
			TCHAR name[MAX_PATH];
			GetModuleFileName(hModule,name, MAX_PATH);
			HANDLE h = CreateFile(name,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,0,0);
			DWORD dwCount;
			BYTE buf[65535];
			BOOL b = false;
			int len = sizeof(buf);
			BYTE crc=0xFF;
			if (h!=INVALID_HANDLE_VALUE)
			{
				int flen=GetFileSize(h,NULL);
				do
				{
					b = ReadFile(h,buf,len,&dwCount,0);
					flen-=dwCount;
					if (flen==0) {flen=-1;dwCount--;}
					crc = Crc8(buf,dwCount,crc);
				} while(b&&dwCount);
				SetFilePointer(h,-1,NULL,FILE_END);
				ReadFile(h,buf,1,0,0);
				return buf[0]==(BYTE)crc;
				CloseHandle(h);
			}
		}
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		std::cout << "dll detached;\n";
		break;
	}
	return TRUE;
}

