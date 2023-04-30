#include <iostream>
#include "Stroka.h"
using namespace std;


void Stroka::StrokaIsEmpty()
{
    if (len == 0) { cout << "Stroka is Empty" << endl; }
}

Stroka::Stroka(int val) : len(val), pCh(new char[len + 1])
{
    if (val == 0) pCh[0] = '\0';
    cout << "Stroka::Stroka(int val)" << endl;
}

Stroka::Stroka(char ch) : len(1), pCh(new char[len + 1])
{
    pCh[0] = ch;
    pCh[1] = '\0';
    cout << "Stroka::Stroka (char ch)" << endl;
}

Stroka::~Stroka()
{
    if (!pCh) delete[] pCh;
    cout << "Stroka::~Stroka()" << endl;
}

void Stroka::Show(void)
{
    cout << "pCh = " << pCh << endl;
    cout << "len = " << len << endl;
}

Stroka::Stroka(const char* S) : len(strlen(S)), pCh(new char[len + 1])
{
    strcpy(pCh, S);
    cout << "Stroka::Stroka(const char* S)" << endl;
}

Stroka::Stroka(const Stroka& from) : len(strlen(from.pCh)), pCh(new char[from.len + 1])
{
    strcpy(pCh, from.pCh);
    cout << "Stroka::Stroka(const Stroka & from)" << endl;
}