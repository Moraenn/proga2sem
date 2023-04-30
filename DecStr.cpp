#include <iostream>
#include "Stroka.h"
#include "IdentStr.h"
#include "DecStr.h"

using namespace std;

DecStr::DecStr(int val) : Stroka(val)
{
    cout << "DecStr::DecStr(int val): Stroka, val = " << val << endl;
}

DecStr::DecStr(char ch) : Stroka(ch)
{
    if (!(ch >= '0' && ch <= '9'))
    {
        cout << "Bad simvol, ch = " << ch << endl;
        delete[] pCh;
    }
    cout << "DecStr::DecStr(char ch): Stroka(ch)" << endl;
}

DecStr::DecStr(const char* Str) : Stroka(Str)
{
    if (len == 1 && pCh[0] == '0' || len == 2 && (pCh[0] == '-' || pCh[0] == '+') && pCh[1] == '0') return;
    if (!((pCh[0] >= '1' && pCh[0] <= '9') || pCh[0] == '-' || pCh[0] == '+'))
    {
        cout << "Bad simvol, pCh[0]=" << pCh[0] << endl;
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    if (len > 1)
    {
        if ((pCh[0] == '-' || pCh[0] == '+') && (pCh[1] == '0'))
        {
            cout << "Bad simvol, pCh[" << 1 << "]=" << 0 << endl;
            if (pCh) delete[] pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    for (int i = 1; i < len; i++)
    {
        if (!(pCh[i] >= '0' && pCh[i] <= '9'))
        {
            cout << "Bad simvol, pCh[" << i << "]=" << pCh[i] << endl;
            if (pCh) delete[] pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    cout << "DecStr::DecStr(const char* Str) : Stroka(Str)" << endl;
}

DecStr::DecStr(const DecStr& from) : Stroka(from)
{
    cout << "DecStr::DecStr(const DecStr& from)" << endl;
}

DecStr::~DecStr()
{
    cout << "DecStr::~DecStr()" << endl;
}

DecStr& DecStr::operator=(const DecStr& other)
{
    cout << "DecStr& DecStr::operator=(const DecStr& other)" << endl;
    if (&other != this)
    {
        delete[] pCh;
        len = strlen(other.pCh);
        pCh = new char[len + 1];
        strcpy_s(pCh, len + 1, other.pCh);
        return *this;
    }
}

DecStr operator+(const DecStr& pobj1, const DecStr& pobj2)
{
    cout << "DecStr operator+(const DecStr& pobj1, const DecStr& pobj2)" << endl;
    int num1 = atoi(pobj1.GetStr());
    int num2 = atoi(pobj2.GetStr());
    if (num1 + num2 != (long long)num1 + (long long)num2)
    {
        cout << "int overflow" << endl;
        DecStr result;
        return result;
    }
    int sum = atoi(pobj1.GetStr()) + atoi(pobj2.GetStr());
    if (sum == -2147483648)
    {
        DecStr result("-2147483648");
        return result;
    }
    if (sum == 0)
    {
        DecStr result("0");
        return result;
    }
    bool isNeg = sum < 0;
    if (isNeg) sum = -sum;
    int newLen = 0;
    for (int i = sum; i > 0; i /= 10)
        newLen++;
    if (isNeg) newLen++;
    char* tmp = new char[newLen + 1];
    tmp[newLen] = '\0';
    int curIndex = newLen - 1;
    for (int index = newLen - 1; index >= 0; index--, sum /= 10)
    {
        tmp[index] = '0' + (sum % 10);
    }
    if (isNeg) tmp[0] = '-';
    DecStr result(tmp);
    return result;
}

DecStr operator+(const DecStr& pobj1, const int obj2)
{
    int num1 = atoi(pobj1.GetStr());
    int num2 = obj2;
    if ((long long)(num1 + num2) != (long long)num1 + (long long)num2)
    {
        cout << "int overflow" << endl;
        DecStr result;
        return result;
    }
    int sum = num1 + num2;
    if (sum == -2147483648)
    {
        DecStr result("-2147483648");
        return result;
    }
    if (sum == 0)
    {
        DecStr result("0");
        return result;
    }
    bool isNeg = sum < 0;
    if (isNeg) sum = -sum;
    int newLen = 0;
    for (int i = sum; i > 0; i /= 10)
        newLen++;
    if (isNeg) newLen++;
    char* tmp = new char[newLen + 1];
    tmp[newLen] = '\0';
    int curIndex = newLen - 1;
    for (int index = newLen - 1; index >= 0; index--, sum /= 10)
    {
        tmp[index] = '0' + (sum % 10);
    }
    if (isNeg) tmp[0] = '-';
    DecStr result(tmp);
    return result;
}

DecStr operator-(const DecStr& pobj1, const DecStr& pobj2)
{
    cout << "DecStr operator-(const DecStr& pobj1, const DecStr& pobj2)" << endl;

    DecStr result;
    result = pobj1 + -atoi(pobj2.GetStr());
    return result;
}
