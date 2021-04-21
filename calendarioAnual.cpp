
//  calendario presencial de personas
#include <iostream>
#include<string>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include"LibreriaMenus.h"
#include"LibreriaConsola.h"
using namespace std;
HWND ventanaActiva;
void calculaCalendario(int ,int );
bool esBisiesto(int);
int calculaDia(int,int,int);
void mostrarCalendario(int mes);
void inicializarCalendario();



int calendarioMes[6][7];//contiene el calendario del mes elegido


string diaSemana[]={"DOMINGO","LUNES","MARTES","MIERCOLES","JUEVES","VIERNES","SABADO"};

TCHAR *nombreMes[]={"ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};

bool esBisiesto(int anny)
{

return (anny%4==0)||((anny%100!=0)&&(anny%400==0));

 }
 int calculaDia(int anny,int mes,int dia)//calcula que numero de dia cayo una fecha
 {
 	int a,y1,m,d;

 	    a=(14-mes)/12;

        y1=anny-a;

        m=mes+(12*a)-2;

        d=(dia+y1+(y1/4)-(y1/100)+(y1/400)+(31*m)/12)%7;

 	return d;
 }

void mostrarCalendario(int mes)
{
	int i,j,x,y;
	int posicion[7];

    posCursorConsola(0,posConsolaCursorY()+2);

      x=posConsolaCursorX();
      y=posConsolaCursorY();


   for(i=0;i<7;i++)
   {
   	  posicion[i]=posConsolaCursorX()+10;
   	  posCursorConsola(posConsolaCursorX()+10,posConsolaCursorY());

   	  cout<<diaSemana[i];

   	}

		for(i=0;i<6;i++)


   	 for(j=0;j<7;j++)

   	    {       if(j==0) posCursorConsola(posicion[j],posConsolaCursorY()+3);

   	            posCursorConsola(posicion[j],posConsolaCursorY());

   	    	    if (calendarioMes[i][j]>0)cout<<calendarioMes[i][j];

   	    	    if(j==6) posCursorConsola(posicion[j],posConsolaCursorY()+3);


		}


}

void inicializarCalendario()
{
	int i,j;

	 for(i=0;i<6;i++)
     for(j=0;j<7;j++)calendarioMes[i][j]=0;


}

void calculaCalendario(int anny,int mes)
{
    int i,d,x,y,j,diaDelMes;
    int diasMes=31;


    inicializarCalendario();



    switch (mes)
    {

    	case 4: diasMes=30;
    	break;

    	case 6: diasMes=30;

        break;
    	case 9: diasMes=30;
        break;

    	case 11: diasMes=30;
    	break;

    	case 2 : (esBisiesto(anny) ? diasMes=29:diasMes=28);break;


    }

     d=calculaDia(anny,mes,1);







   diaDelMes=0;



    for(i=0;i<6;i++)
    {


     for(j=0;j<7;j++)
       {



       	if (i==0 && j>=d)
       	{

       	   diaDelMes+=1;
       	   calendarioMes[i][j]=diaDelMes;


        }

       	if(i>0 && diaDelMes<diasMes)

		   {

		   diaDelMes+=1;
		   calendarioMes[i][j]=diaDelMes;
       	   }





       }




    }


mostrarCalendario(mes);





return;

}






void calendarioAnual(HWND ventana)
{
ventanaActiva =ventana;

     clearScreen();







     calculaCalendario(2012,2);







    getch();


	return;
}


