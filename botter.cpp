#include <stdlib.h>
#include <iostream>
#include <string>
#include <Windows.h>

#include "keypresser.h"

INPUT *Botting::ip;
INPUT inp = {};

using std::cin;
using std::cout;
using std::string;

int main()
{
    Botting::ip = &inp;
    cout << "WE HAVE SPAM-OFF!\n";
    while (true)
    {
        if (GetAsyncKeyState(VK_MBUTTON))
        {
            for (int i = 0; i < 10; ++i)
            {
                Botting::movemouse(750, 0);
                if (i <= 5)
                    Sleep(35 - 5 * i);
                else
                    Sleep(5 * (i - 5));
            }
            Botting::movemouse(-70, 0);
            Botting::clickmouse(CLICK_LEFT);
            Sleep(1000);
        }
        Sleep(1);
        if (GetAsyncKeyState(VK_F3))
        {
            goto END;
        }
    }
END:
    cout << "Done!\n";
    cin.ignore();
    return 0;
}