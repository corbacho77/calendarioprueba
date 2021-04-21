


#include<windows.h>
#include<cstdio>
#include<stdlib.h>
#include<string>
#include<iostream>
#include"LibreriaConsola.h"



int gotoX()
{
 POINT X;
    GetCursorPos(&X);

return X.x;

}
int gotoY()
{
    POINT Y;
    GetCursorPos(&Y);

return  Y.y;
}





void posCursorConsola(short  x,short y)
{
	HANDLE  buffer=GetStdHandle(STD_OUTPUT_HANDLE);

	COORD    coordenadas;

	coordenadas.X=x;

	coordenadas.Y=y;

	SetConsoleCursorPosition(buffer,coordenadas);

	return;
}
void setColor(WORD color)
{
       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
       return;
}
void clearScreen()
{
       COORD coordScreen = { 0, 0 };
       DWORD cCharsWritten;
       CONSOLE_SCREEN_BUFFER_INFO csbi;
       DWORD dwConSize;
       HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

       GetConsoleScreenBufferInfo(hConsole, &csbi);
       dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
       FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
       GetConsoleScreenBufferInfo(hConsole, &csbi);
       FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
       SetConsoleCursorPosition(hConsole, coordScreen);
       return;
}

short posConsolaCursorX()
{

	CONSOLE_SCREEN_BUFFER_INFO bufferX;
    HANDLE cursor = GetStdHandle(STD_OUTPUT_HANDLE);


	    GetConsoleScreenBufferInfo(cursor, &bufferX);



	return (short) bufferX.dwCursorPosition.X;
}
short posConsolaCursorY()
{

	CONSOLE_SCREEN_BUFFER_INFO bufferY;
    HANDLE cursor = GetStdHandle(STD_OUTPUT_HANDLE);


	GetConsoleScreenBufferInfo(cursor, &bufferY);


	return (short) bufferY.dwCursorPosition.Y;


}


int longCadena(std::string cadena)

{ int i;
  bool valido=false;
   do
   {
   	 if (cadena[i]=='\0')

   	    return i;
   	 else
   	    i++;

   }while (!valido);


return i;
}
void limpiarCadena(int posicion)
{


		int i;

          for(i=0;i<posicion;i++)putchar(32);


return;


}

int leerNumeroConsola(int longitud)
{    char numero[longitud]="";
     char uno[]="1";
     char dos[]="2";
     char tres[]="3";
     char cuatro[]="4";
     char cinco[]="5";
     char seis[]="6";
     char siete[]="7";
     char ocho[]="8";
     char nueve[]="9";
     char cero[]="0";







    bool valido=false;

do
{





           switch (obtenerTecla())
        {

          case VK_NUMPAD0:strcat(numero,cero);


             break;
           case VK_NUMPAD1:strcat(numero,uno);



             break;
           case VK_NUMPAD2:strcat(numero,dos);


             break;
           case VK_NUMPAD3:strcat(numero,tres);

             break;
           case VK_NUMPAD4:strcat(numero,cuatro);

             break;

          case VK_NUMPAD5:strcat(numero,cinco);

             break;
          case VK_NUMPAD6:strcat(numero,seis);

            break;

           case VK_NUMPAD7:strcat(numero,siete);

            break;

            case VK_NUMPAD8:strcat(numero,ocho);

            break;
           case VK_NUMPAD9:strcat(numero,nueve);


            break;
            case VK_RETURN :

             valido=true;
             break;



          }



}while (!valido);






return atoi(numero);
}


std::string mensajeError()
{

    DWORD errorMensajeId =GetLastError();
    if(errorMensajeId == 0)
        return std::string(); //no hay error

    LPSTR mensajeBuffer= NULL;
    size_t tamanyo = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                 NULL, errorMensajeId, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&mensajeBuffer, 0, NULL);

    std::string mensaje(mensajeBuffer, tamanyo);

    //liberar buffer
    LocalFree(mensajeBuffer);

    return mensaje;
}

 int obtenerTecla( )
{



KEY_EVENT_RECORD _tecla;

HANDLE hconsola=GetStdHandle(STD_INPUT_HANDLE);

DWORD modoAnterior;

DWORD  regLeidos,teclado, i;

INPUT_RECORD buffer[128];







           if(hconsola==INVALID_HANDLE_VALUE) return -1;

             teclado = ENABLE_WINDOW_INPUT;

             if (! GetConsoleMode(hconsola, &modoAnterior) )return -1;

            if (! SetConsoleMode(hconsola, teclado) ) return -1;

                FlushConsoleInputBuffer(hconsola);

                  if (!ReadConsoleInput(
                hconsola, // manipulador de entrada
                buffer,
                128,         // tamaño
                &regLeidos)) return -1;





                  	  for(i=0;i<regLeidos;i++)
						{
						    if(buffer[i].EventType==KEY_EVENT && buffer[i].Event.KeyEvent.bKeyDown)


                            {




                              std::cout<<buffer[i].Event.KeyEvent.uChar.AsciiChar;
                              return buffer[i].Event.KeyEvent.wVirtualKeyCode;



	                        }



					    }

						SetConsoleMode(hconsola, modoAnterior);



   return 0;






}




