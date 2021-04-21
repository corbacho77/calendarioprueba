
#ifndef LIBRERIA_MENU
#define LIBRERIA_MENU
#include"windows.h"
#include<string>





bool pantallaCompleta(HINSTANCE,int);


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

void insertarMenu(HWND ventana);


#endif



