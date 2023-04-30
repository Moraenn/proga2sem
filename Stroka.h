#ifndef _Stroka
#define _Stroka
class Stroka
{
protected:
    int len;
    char* pCh;
public:
    Stroka(int = 0);
    Stroka(char);
    Stroka(const char*);
    Stroka(const Stroka&);
    ~Stroka();
    void StrokaIsEmpty();
    char* GetStr(void) const { return pCh; }
    int GetLen(void) const { return len; }
    void Show(void);
};
#endif