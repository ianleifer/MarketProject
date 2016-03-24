﻿#ifndef INTERFACE_H
#define INTERFACE_H

#include <windows.h>
#include <glut.h>

#include <stdlib.h>
// Include tchar to define _T
#include <tchar.h>
#include "chart.h"
#include "interfaceClasses.h"

class OpenGLInterface {
private:
	static OpenGLInterface *p_OpenGLInterface;

	HGLRC	hRC;
	HDC		hDC;
	HWND	hWnd;
	HINSTANCE hInstance;
	
	bool  keys[256];
	bool  active;
	bool  fullscreen;
public:
	OpenGLInterface();
	static OpenGLInterface* getOpenGLInterface();
	
	void printPriceChart(Chart &chart);

	void printChart(Chart &chart, FigureRectangle rectangle);
	int DrawRectangle(FigureRectangle rectangle);
	
	LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK InitialWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

	int InitGL(GLvoid);
	BOOL CreateGLWindow(LPCWSTR title, int width, int height, int bits, bool fullscreenflag);
	GLvoid KillGLWindow(GLvoid);
	GLvoid ReSizeGLScene(GLsizei width, GLsizei height);
};

#endif INTERFACE_H