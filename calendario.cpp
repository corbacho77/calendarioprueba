

//  calendario presencial de personas modulo principal que llama al resto de modulos
#include <iostream>
#include"LibreriaMenus.h"
#include<string>
#include<conio.h>
#include<cstdio>


HINSTANCE myInstancia;





int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    MSG mensaje;




   // ShowWindow(GetConsoleWindow(),SW_HIDE);


    if (! pantallaCompleta(GetModuleHandle(0),nCmdShow))return false;





    BOOL mensajeVentana;
    while ((mensajeVentana = GetMessage(&mensaje, (HWND) NULL, 0, 0)) != 0 && mensajeVentana != -1)
    {
        TranslateMessage(&mensaje);
        DispatchMessage(&mensaje);
    }






return mensaje.wParam;

}












