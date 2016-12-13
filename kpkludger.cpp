// kpkludger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <math.h>
#include <thread>
#include <ctime>
#include "botter.cpp"
#include "EasyBMP.h"

using std::cin;
using std::cout;
using std::string;

const double pi = 3.141592;
const string specialchars = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
int arr[360][2];

bool contains(string str, char c) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == c)
			return true;
	}
	return false;
}

void pointsOnCircle(double rad, int arr[][2], int step = 1) {
	for (int i = 0; i <= 360; i++) {
		arr[i][0] = (int)(rad * std::cos(i * (pi / 180.0)));
		arr[i][1] = (int)(rad * std::sin(i * (pi / 180.0)));
	}
}

void spin(bool* cond) {
	while (*cond) {
		Botting::movemouse(10, 0);
		Sleep(2);
	}
}

void goInCircle() {
	for (int i = 1; i < 360; i += 6) {
		Botting::movemouse(arr[i - 1][0] - arr[i][0], arr[i - 1][1] - arr[i][1]);
		Sleep(10);
	}
}

void constacircle(bool* cond) {
	while (*cond) {
		goInCircle();
	}
}

int main()
{
	std::srand(std::time(0));
	RECT rectum;
	const wchar_t * name = L"ROBLOX";
	HWND roblox = FindWindow(NULL, name);
	if (!roblox) {
		cout << "No running ROBLOX process.\n";
		cout << "Searching...\n";
		while (!roblox) {
			Sleep(1000);
			roblox = FindWindow(NULL, name);
		}
	}
	const HDC robdc = GetDC(roblox);
	pointsOnCircle(500, arr);
	while (true) {
		cout << "WELCOME TO DUMB-ROBLO-BOT 3000.\n" << "MIDDLE-CLICK TO PERFORM YOUR CHOSEN FUNCTION\n" << "PRESS F4 TO EXIT, AND F3 TO RETURN TO THIS MENU\n";
		cin.ignore();
	SELECT:
		system("cls");
		cout << "1. 360 No-Scope\n"
			<< "2. Circle\n"
			<< "3. Chat Spam\n"
			<< "4. Retard Mode\n"
			<< "5. Autoclick\n"
			<< "6. Insta-Leave\n"
			<< "7. Insta-Screeny\n";
		string s;
		char c;
		std::cin >> c;
		switch (c) {
		case '1':
			while (true) {
				if (GetAsyncKeyState(VK_MBUTTON)) {
					while (GetAsyncKeyState(VK_MBUTTON)) { Sleep(1); }
					for (int i = 0; i < 30; ++i) {
						Botting::movemouse(32, 0);
						if (i <= 15)
							Sleep(8 + i);
						else
							Sleep(35 - i);
					}
					Botting::movemouse(1, 0);
					Sleep(500);
				}
				Sleep(1);
				if (GetAsyncKeyState(VK_F3)) {
					goto SELECT;
				}
				if (GetAsyncKeyState(VK_F4)) {
					goto END;
				}
			}
			break;
		case '2':
			while (true) {
				if (GetAsyncKeyState(VK_MBUTTON)) {
					while (GetAsyncKeyState(VK_MBUTTON)) { Sleep(1); }
					bool condition = true;
					std::thread circly(constacircle, &condition);
					while (true) {
						if (GetAsyncKeyState(VK_MBUTTON)) {
							condition = false;
							circly.join();
							break;
						}
						Sleep(25);
					}
				}
				Sleep(1);
				if (GetAsyncKeyState(VK_F3)) {
					goto SELECT;
				}
				if (GetAsyncKeyState(VK_F4)) {
					goto END;
				}
			}
			break;
		case '3': {
			cout << "Phrase:";
			string phr;
			std::cin >> phr;

			while (true) {
				if (GetAsyncKeyState(VK_MBUTTON)) {
					while (GetAsyncKeyState(VK_MBUTTON)) { Sleep(1); }
					Botting::presskey('/');
					for (int i = 0; i < phr.length(); ++i) {
						char c = phr[i];
						if (contains(specialchars, c)) {
							Botting::shift(c);
						}
						else { Botting::presskey(c); }
					}Botting::presskey(VK_RETURN);
					Sleep(2000);
				}
				Sleep(1);
				if (GetAsyncKeyState(VK_F3)) {
					goto SELECT;
				}
				if (GetAsyncKeyState(VK_F4)) {
					goto END;
				}
			}
			break;
		}

		case '4': {
			while (true) {
				if (GetAsyncKeyState(VK_MBUTTON)) {
					while (GetAsyncKeyState(VK_MBUTTON)) { Sleep(1); }
					bool condition = true;
					std::thread spinny(spin, &condition);
					std::thread circly(constacircle, &condition);
					while (true) {
						if (GetAsyncKeyState(VK_MBUTTON)) {
							condition = false;
							spinny.join();
							circly.join();
							break;
						}
						Sleep(25);
					}
					Sleep(2000);
				}
				Sleep(1);
				if (GetAsyncKeyState(VK_F3)) {
					goto SELECT;
				}
				if (GetAsyncKeyState(VK_F4)) {
					goto END;
				}
			}
			break;
		}
		case '5':
			while (true) {
				if (GetAsyncKeyState(VK_MBUTTON)) {
					while (GetAsyncKeyState(VK_MBUTTON)) { Sleep(1); }
					while (!GetAsyncKeyState(VK_MBUTTON)) {
						Botting::clickmouse(CLICK_LEFT);
						Sleep(10);
					}Sleep(2000);
				}
				Sleep(1);
				if (GetAsyncKeyState(VK_F3)) {
					goto SELECT;
				}
				if (GetAsyncKeyState(VK_F4)) {
					goto END;
				}
			}
			break;
		case '6': {
			GetWindowRect(roblox, &rectum);
			short width = rectum.right - rectum.left;
			short height = rectum.bottom - rectum.top;
			int leaveloc[2] = { width * 0.4, height * 0.4 };
			while (true) {
				if (GetAsyncKeyState(VK_MBUTTON)) {
					while (GetAsyncKeyState(VK_MBUTTON)) { Sleep(1); }
					Botting::presskey(VK_ESCAPE);
					Botting::presskey('l');
					Sleep(500);
					SetCursorPos(leaveloc[0], leaveloc[1]);
					Botting::clickmouse(CLICK_LEFT);
					Sleep(110);
				}
				Sleep(1);
				if (GetAsyncKeyState(VK_F3)) {
					goto SELECT;
				}
				if (GetAsyncKeyState(VK_F4)) {
					goto END;
				}
			}

		}break;
		case '7': {
			while (true) {
				if (GetAsyncKeyState(VK_MBUTTON)) {
					while (GetAsyncKeyState(VK_MBUTTON)) { Sleep(1); }
					GetWindowRect(roblox, &rectum);
					int dim[] = { rectum.right - rectum.left, rectum.bottom - rectum.top };
					Botting::presskey(VK_ESCAPE);
					Botting::presskey('l');
					Sleep(500);
					Botting::clickmouse(CLICK_LEFT);
					Sleep(110);
					BMP thebmp;
					thebmp.SetBitDepth(24);
					thebmp.SetSize(dim[0], dim[1]);
					for (int y = 0; y < dim[1]; ++y) {
						for (int x = 0; x < dim[0]; ++x) {
							RGBApixel currentpix;
							COLORREF pixie = GetPixel(robdc, x, y);
							unsigned char * pointy = (unsigned char*)&pixie;
							currentpix.Red = pointy[0];
							currentpix.Green = pointy[1];
							currentpix.Blue = pointy[2];
							thebmp.SetPixel(x, y, currentpix);
						}
					}
					time_t rawtime;
					struct tm * timeinfo;
					char buffer[128];
					time(&rawtime);
					timeinfo = localtime(&rawtime);
					strftime(buffer, 128, "%Y%m%d%H%M%S.", timeinfo);
					string s = string(buffer);
					s += std::rand();
					thebmp.WriteToFile(s.c_str());
					thebmp.~BMP();
				}
			}
			Sleep(1);
			if (GetAsyncKeyState(VK_F3)) {
				goto SELECT;
			}
			if (GetAsyncKeyState(VK_F4)) {
				goto END;
			}
		}
		 break;
		default:
			system("cls");
			break;
		}
	}
END:
	cout << "Done!\n";
	cin.ignore();
	return 0;
}
