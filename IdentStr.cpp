#include <iostream>
#include "Stroka.h"
#include "IdentStr.h"


using namespace std;

IdentStr::IdentStr(int val) : Stroka(val)
{
    cout << "IdentStr::IdentStr(int val) : Stroka(val)" << val << endl;
}

IdentStr::IdentStr(char ch) : Stroka(ch)
{
    if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z')))
    {
        cout << "Bad element: " << pCh << endl;
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    else
    {
        cout << "IdentStr::IdentStr(char ch) : Stroka(ch)" << endl;
    }
}

IdentStr::IdentStr(const char* Str) : Stroka(Str)
{
    const char* keyword[] = { "alignas", "alignof", "and", "and_eq", "asm",
        "atomic_cancel", "atomic_commit", "atomic_noexcept", "auto", "bitand",
        "bitor", "bool", "break", "case", "catch", "char", "char8_t", "char16_t",
        "char32_t", "class", "compl", "concept", "const", "consteval", "constexpr",
        "const_cast", "continue", "co_await", "co_return", "co_yield", "decltype",
        "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit",
        "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline",
        "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr",
        "operator", "or", "or_eq", "private", "protected", "public", "reflexpr", "register",
        "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static",
        "static_assert", "static_cast", "struct", "switch", "synchronized", "template", "this",
        "thread_local", "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned",
        "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq" };
    for (int j = 0; j < 96; j++)
    {
        if (strcmp(pCh, keyword[j]) == 0)
        {
            cout << "Bad element: keyword " << pCh << endl;
            if (pCh) delete[] pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }

    }
    if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z') || (pCh[0] == '_')))
    {
        cout << "Bad element: " << pCh << endl;
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    else
    {
        for (int i = 1; i < len; i++)
        {
            if (!((pCh[i] >= 'a' && pCh[i] <= 'z') || (pCh[i] >= 'A' && pCh[i] <= 'Z') || (pCh[i] >= '0' && pCh[i] <= '9') || (pCh[i] == '_')))
            {
                cout << "Bad element 2: " << pCh << endl;
                if (pCh) delete[] pCh;
                len = 0;
                pCh = new char[len + 1];
                pCh[0] = '\0';
                return;
            }
        }
        cout << "IdentStr::IdentStr(const char* Str) : Stroka(Str)" << endl;
    }
}

IdentStr::IdentStr(const IdentStr& from) : Stroka(from)
{
    cout << "IdentStr::IdentStr(const IdentStr& from) : Stroka(from)" << endl;
}

IdentStr::~IdentStr()
{
    if (!pCh) delete[] pCh;
    cout << "IdentStr::~IdentStr()" << endl;
}

void IdentStr::upper()
{
    for (int i = 0; i < len; i++)
    {
        if (pCh[i] >= 'a' && pCh[i] <= 'z') 
            pCh[i] -= 32; 
    }
}

IdentStr& IdentStr::operator=(const IdentStr& other)
{
    if (&other != this)
    {
        delete[] pCh;
        len = strlen(other.pCh);
        pCh = new char[len + 1];
        strcpy_s(pCh, len + 1, other.pCh);
        cout << "IdentStr& IdentStr::operator=(const IdentStr& other) " << endl;
        return *this;
    }
}

char& IdentStr::operator[](int index)
{
    if (index >= 0 && index < len)
    {
        cout << "char& IdentStr::operator[](int index)" << endl;
        return pCh[index];
    }
    return pCh[0];
}

IdentStr operator+(const IdentStr& pobj1, const IdentStr& pobj2)
{
    IdentStr tmp(pobj1.GetLen() + pobj2.GetLen());
    int i = 0, j = 0;
    while (tmp.pCh[i++] = pobj1.pCh[j++]);
    --i;
    j = 0;
    while (tmp.pCh[i++] = pobj2.pCh[j++]);
    return tmp;
}

IdentStr IdentStr::operator~()
{
    char* str = new char[len+1];
    str[len] = '\0';
    int l, r;
    for (l = 0, r = len - 1; l <= r; l++, r--)
    {
        str[l] = pCh[r];
        str[r] = pCh[l];
    }
    IdentStr result(str);
    this->pCh = result.pCh;
    this->len = result.len;
    delete[] str;
    return *this;
}
