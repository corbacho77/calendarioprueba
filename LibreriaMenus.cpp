
#include"LibreriaMenus.h"
#include"LibreriaConsola.h"
#include <iostream>
#include<windows.h>
#include<wingdi.h>
#include<string>




 void turno();
 void calendarioAnual(HWND ventana);
 int personas();




LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{



switch(msg)
{
case WM_PAINT :{
PAINTSTRUCT ps;
  HDC hdc;
    hdc = BeginPaint(hwnd,&ps);
      RECT coordenadas;

            GetClientRect(hwnd,&coordenadas);
           HFONT hfont=CreateFont(48,0,0,0,0,0,0,0,0,0,0,0,0,"hola");
           SelectObject(hdc,hfont);
           TextOut(hdc,coordenadas.left,coordenadas.top,"hola",4);

            EndPaint(hwnd,&ps);

 break;
}
case WM_COMMAND:

        switch(LOWORD(wParam))

        {

         case 100: turno();
            break;
         case 101:
           // hdc=GetDC(hwnd);




            //BeginPath(hdc);










            // EndPath(hdc);

            calendarioAnual(hwnd);
             break;
        case 105: DestroyWindow(hwnd);


        }
    break;
case WM_CLOSE:
DestroyWindow(hwnd);

break;
case WM_DESTROY:
PostQuitMessage(0);


break;
case WM_SIZE:

default:
return DefWindowProc(hwnd, msg, wParam, lParam);
}
return 0;
}

bool pantallaCompleta(HINSTANCE myInstancia,int modo)
{

HWND ventanaPrincipal;

WNDCLASSEX claseVentana;

claseVentana.lpfnWndProc=WndProc;

claseVentana.cbSize=sizeof(WNDCLASSEX);

claseVentana.style= CS_HREDRAW |CS_VREDRAW ;

claseVentana.cbClsExtra=0;

claseVentana.cbWndExtra=0;

claseVentana.lpszMenuName=NULL;

claseVentana.lpszClassName="ventana";

claseVentana.hInstance=myInstancia;

claseVentana.hCursor= LoadCursor(NULL, IDC_ARROW);

claseVentana.hIcon=LoadIcon(NULL, IDI_APPLICATION);

claseVentana.hbrBackground=NULL;//(HBRUSH)(COLOR_WINDOW+1);

claseVentana.hIconSm=  LoadIcon(NULL, IDI_APPLICATION);




if(!RegisterClassEx(&claseVentana))
{
MessageBox(NULL, "la ventana no se puede mostrar", "Error!", MB_ICONEXCLAMATION | MB_OK);
return false;
}
// crea la ventana

ventanaPrincipal = CreateWindowEx(0,
                   // no extended styles
    "ventana",           // class name
    "CALENDARIO",          // window name
       // overlapped window
       WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            // vertical scroll bar
    0,          // default horizontal position
    0,          // default vertical position
    CW_USEDEFAULT,          // default width
    CW_USEDEFAULT,          // default height
     NULL,            // no parent or owner window
     NULL,           // class menu used
    myInstancia,              // instance handle
    NULL);                  // no window creation data

if (!ventanaPrincipal){
        mensajeError();
    return false;}

// Show the window using the flag specified by the program
// that started the application, and send the application
// a WM_PAINT message.
insertarMenu(ventanaPrincipal);

ShowWindow(ventanaPrincipal,modo);

UpdateWindow(ventanaPrincipal);





return true;

}









void insertarMenu(HWND ventana)
{
    HMENU hmenu1=CreateMenu();
    HMENU hmenu2=CreateMenu();

    AppendMenu(hmenu1,MF_STRING,100,"&TURNO");

    AppendMenu(hmenu1,MF_SEPARATOR,0,NULL);

    AppendMenu(hmenu1,MF_STRING,101,"&CALENDARIO");

     AppendMenu(hmenu1,MF_SEPARATOR,0,NULL);

    AppendMenu(hmenu1,MF_STRING,102,"&PERSONAL");

     AppendMenu(hmenu1,MF_SEPARATOR,0,NULL);

    AppendMenu(hmenu1,MF_STRING|MF_POPUP,(UINT_PTR)hmenu2,"&LISTADO");

    AppendMenu(hmenu1,MF_SEPARATOR,0,NULL);

    AppendMenu(hmenu1,MF_STRING,104,"&MANUAL");

     AppendMenu(hmenu1,MF_SEPARATOR,0,NULL);

    AppendMenu(hmenu1,MF_STRING,105,"&SALIR");

    AppendMenu(hmenu2,MF_STRING,103,"&CALENDARIO TRABAJADOR");

    AppendMenu(hmenu2,MF_STRING,103,"&CALENDARIO ANUAL     ");


       SetMenu(ventana,hmenu1);






}


