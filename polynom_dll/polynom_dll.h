#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef MYDLL
#define POLYDLL _declspec(dllexport)
#else
#define POLYDLL _declspec(dllimport)
#endif

	POLYDLL  char * __stdcall divP(const char *d, const char *e, char *r);

#ifdef __cplusplus
}
#endif

