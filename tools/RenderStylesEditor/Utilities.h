// Utilities.h
//	Handy little utility functions

#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <direct.h>
#include <string>

using namespace std;

// DEFINES
#define D3DRGB_1(r, g, b)				(0xff000000L | ( ((long)((r) * 255)) << 16) | (((long)((g) * 255)) << 8) | (long)((b) * 255))
#define D3DRGBA_1(r, g, b, a)			((((long)((a) * 255)) << 24) | (((long)((r) * 255)) << 16) | (((long)((g) * 255)) << 8) | (long)((b) * 255))
#define D3DRGB_255(r, g, b)				(0xff000000L | ( ((long)(r)) << 16) | (((long)(g)) << 8) | (long)(b))
#define D3DRGBA_255(r, g, b, a)			((((long)(a)) << 24) | (((long)(r)) << 16) | (((long)(g)) << 8) | (long)(b))

// Helper Function...
void	Msg(LPSTR fmt, ...);
void	dprintf(LPSTR fmt, ...);
void	DisplayLastWndError();

// Critial Section...
class CriticalSection {
public:
	CriticalSection()					{ ::InitializeCriticalSection(&m_cSection); }
	~CriticalSection()					{ ::DeleteCriticalSection(&m_cSection); }

    operator CRITICAL_SECTION *()		{ return &m_cSection; }
    void Enter()						{ ::EnterCriticalSection(&m_cSection); }
    void Leave()						{ ::LeaveCriticalSection(&m_cSection); }
private:
	CRITICAL_SECTION    m_cSection;		};

#endif
 