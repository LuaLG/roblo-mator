#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using std::string;

#define CLICK_LEFT 0x0002
#define CLICK_RIGHT 0x0008
#define CLICK_MIDDLE 0x0020

namespace Botting {

	static INPUT inp;
	static INPUT* ip = &inp;

	static void presskey(int k) {
		HKL kbl = GetKeyboardLayout(0);
		ip->type = INPUT_KEYBOARD;
		ip->ki.wScan = MapVirtualKey(k, MAPVK_VK_TO_VSC);
		ip->ki.time = 0;
		ip->ki.dwExtraInfo = 0;
		ip->ki.wVk = 0;
		ip->ki.dwFlags = 0;
		SendInput(1, ip, sizeof(*ip));
		ip->ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, ip, sizeof(*ip));
	}

	static void presskey(char k) {
		HKL kbl = GetKeyboardLayout(0);
		ip->type = INPUT_KEYBOARD;
		ip->ki.wScan = MapVirtualKey(VkKeyScanExA(k, kbl), MAPVK_VK_TO_VSC);
		ip->ki.time = 0;
		ip->ki.dwExtraInfo = 0;
		ip->ki.wVk = 0;
		ip->ki.dwFlags = 0;
		SendInput(1, ip, sizeof(*ip));
		ip->ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, ip, sizeof(*ip));
	}

	 static void presskeys(string s)
	{
		HKL kbl = GetKeyboardLayout(0);
		ip->type = INPUT_KEYBOARD;
		ip->ki.wVk = 0;
		ip->ki.time = 0;
		ip->ki.dwExtraInfo = 0;
		for (unsigned int i = 0; i < s.length(); ++i)
		{
			char c = s[i];
			ip->ki.wScan = MapVirtualKey(VkKeyScanExA(c, kbl), MAPVK_VK_TO_VSC);
			ip->ki.dwFlags = 0;
			SendInput(1, ip, sizeof(*ip));
			ip->ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, ip, sizeof(*ip));
		}
	}

	 static void holdkey(int k) {
		ip->type = INPUT_KEYBOARD;
		ip->ki.wScan = MapVirtualKey(k, MAPVK_VK_TO_VSC);
		ip->ki.time = 0;
		ip->ki.dwExtraInfo = 0;
		ip->ki.wVk = 0;
		ip->ki.dwFlags = 0;
		SendInput(1, ip, sizeof(*ip));
	}

	 static void releasekey(int k) {
		ip->type = INPUT_KEYBOARD;
		ip->ki.wScan = MapVirtualKey(k, MAPVK_VK_TO_VSC);;
		ip->ki.time = 0;
		ip->ki.dwExtraInfo = 0;
		ip->ki.wVk = 0;
		ip->ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, ip, sizeof(*ip));
	}

	 static void shift(int k) {
		holdkey(VK_SHIFT);
		presskey(k);
		releasekey(VK_SHIFT);
	}

	 static void shift(char k) {
		 holdkey(VK_SHIFT);
		 presskey(k);
		 releasekey(VK_SHIFT);
	 }

	 static void movemouse(int x, int y, bool relative = true) {
		ip->type = INPUT_MOUSE;
		ip->mi.mouseData = 0;
		ip->mi.dx = x;
		ip->mi.dy = y;
		if (relative) {
			ip->mi.dwFlags = MOUSEEVENTF_MOVE;
			SendInput(1, ip, sizeof(*ip));
		}
		else {
			ip->mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
			SendInput(1, ip, sizeof(*ip));
		}
	}

	 static void movemwheel(int clicks) {
		ip->type = INPUT_MOUSE;
		ip->mi.dwFlags = MOUSEEVENTF_WHEEL;
		ip->mi.mouseData = clicks * 120;
		SendInput(1, ip, sizeof(*ip));
	}

	 static void clickmouse(int button) { //Use the macros CLICK_LEFT, CLICK_RIGHT, and CLICK_MIDDLE
		ip->mi.mouseData = 0;
		ip->type = INPUT_MOUSE;
		switch (button) {
		case CLICK_LEFT:
			ip->mi.dwFlags = CLICK_LEFT;
			SendInput(1, ip, sizeof(*ip));
			ip->mi.dwFlags = 0x0004;
			SendInput(1, ip, sizeof(*ip));
			break;
		case CLICK_RIGHT:
			ip->mi.dwFlags = CLICK_RIGHT;
			SendInput(1, ip, sizeof(*ip));
			ip->mi.dwFlags = 0x0010;
			SendInput(1, ip, sizeof(*ip));
			break;
		case CLICK_MIDDLE:
			ip->mi.dwFlags = CLICK_MIDDLE;
			SendInput(1, ip, sizeof(*ip));
			ip->mi.dwFlags = 0x0040;
			SendInput(1, ip, sizeof(*ip));
			break;
		}
	}

	 static void holdclick(int button) { //Use the macros CLICK_LEFT, CLICK_RIGHT, and CLICK_MIDDLE
		ip->mi.mouseData = 0;
		ip->type = INPUT_MOUSE;
		ip->mi.dwFlags = button;
		SendInput(1, ip, sizeof(*ip));
	}

	 static void releaseclick(int button) { //Use the macros CLICK_LEFT, CLICK_RIGHT, and CLICK_MIDDLE
		ip->mi.mouseData = 0;
		ip->type = INPUT_MOUSE;
		ip->mi.dwFlags = 0x0040;
		SendInput(1, ip, sizeof(*ip));
	}
};
