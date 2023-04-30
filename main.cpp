#include <iostream>
#include "Stroka.h"
#include "IdentStr.h"
#include "DecStr.h"

using namespace std;

int main()
{
    
    IdentStr str("ITMO");

    ~str;

    cout << str.GetStr() << endl;
    return 0;
}
