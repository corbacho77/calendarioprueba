
#ifndef LIBRERIA_CONSOLA
#define LIBRERIA_CONSOLA

#include<windows.h>




int gotoX();

int gotoY();

int obtenerTecla();

void posCursorConsola(short x,short y);

void setColor(WORD color);

void clearScreen();

short posConsolaCursorX();

short posConsolaCursorY();


int longCadena(std::string);

int leerNumeroConsola(int longitud);// valida la entrada elige opcion de los menus

void limpiarCadena(int);


std::string mensajeError();








#endif


























