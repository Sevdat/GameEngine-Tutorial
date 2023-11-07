//Readme: This project is licensed under the terms of the MIT license.
//Author: Pardcode

#pragma once
#include <Windows.h>

class Window
{
public:
	Window();

	// Initilize the window
	bool init();

	bool broadcast();

	//Release the window
	bool release();

	bool isRun();

	RECT getClientWindowRect();
	void setHWND(HWND hwnd);
	

	//EVENTS
	virtual void onCreate() = 0; // diff 0
	virtual void onUpdate() = 0; // diff 0
	virtual void onDestroy();

	~Window();

protected:
	HWND m_hwnd;
	bool m_is_run;
};

