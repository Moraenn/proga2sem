#ifndef _IdentStr
#define _IdentStr
class IdentStr : public Stroka
{
public:
    IdentStr(int = 0);
    IdentStr(char);
    IdentStr(const char*);
    IdentStr(const IdentStr&);
    ~IdentStr();

    void upper();
    IdentStr& operator=(const IdentStr&);
    char& operator[](int);
    friend IdentStr operator+(const IdentStr&, const IdentStr&);

    IdentStr operator~();

};
#endif