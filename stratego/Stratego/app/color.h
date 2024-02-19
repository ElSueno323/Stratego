#ifndef COLOR_H
#define COLOR_H
#include <windows.h>
#include <iostream>
#endif // COLOR_H
inline std::ostream& BLUE(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE
              |FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& RED(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
                FOREGROUND_RED|FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& GREEN(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
              FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& YELLOW(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
         FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& WHITE(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
       FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    return s;
}

struct color {
    color(WORD attribute):m_color(attribute){};
    WORD m_color;
};

template <class _Elem, class _Traits>
std::basic_ostream<_Elem,_Traits>&
      operator<<(std::basic_ostream<_Elem,_Traits>& i, color& c)
{
    HANDLE hStdout=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,c.m_color);
    return i;
}
