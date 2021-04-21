//  calendario presencial de personas
#include <iostream>



#include <windows.h>
//#include "C:\Program Files (x86)\MySQL\MySQL Server 5.6\include\mysql.h"	       //Ruta donde se encuenta la bliblioteca mysql.h
#include <mysqld_error.h>  //Ruta donde se encuenta la bliblioteca mysql.h//
#include <mysql.h>
#include<plugin.h>


using namespace std;

MYSQL           *objDatos;
MYSQL_RES       *res;
MYSQL_ROW        row;
unsigned long   *lon;
int               i,j,l,k;

int personas()
{
	cout<<"provar conexion a BBDD";






// Intentar iniciar MySQL:
  if(!(objDatos = mysql_init(0))) {
      // Imposible crear el objeto objDatos
      cout << "ERROR: imposible crear el objeto objDatos." << endl;
      return 1;

  }

 if(mysql_real_connect(objDatos, "127.0.0.1", "alex", "aritz2017", "calendario", MYSQL_PORT, NULL, 0))
 {
 	cout<<"Conexion realizada con exito ";
 	
 	 if ((mysql_query(objDatos,"SELECT * FROM empleado"))==0)
	  {
 	 	
 	 	if(res=mysql_store_result(objDatos))
		  
		  { 
		    
		  	i = (int) mysql_num_rows(res);
      // Obtener el número de columnsa por fila:
            j = (int) mysql_num_fields(res);
            
              
               for(l = 0; l < i; l++)
			   {
               row = mysql_fetch_row(res);
               lon = mysql_fetch_lengths(res);
               cout << "Registro no. " << l+1 << endl;
               // Mostrar cada campo y su longitud:
                 for(k = 0 ; k < j ; k++) 
				   {
                     cout << ((row[k]==NULL) ? "NULL" : row[k]);
                     cout << " longitud: " << lon[k] << endl;
                   }
               }
		  	
 	 		
		  }
 	 	
 	 	
 	 	
 	 	
	  }
	  else
	  {
	  	mysql_close(objDatos);
	  	cout<<"error en consulta ....";
	  	
	  }

 }
 else
 {
 	cout<<"Conexion fallida \n"<<mysql_error(objDatos);
 	
 	 mysql_close(objDatos);
 }

	return 0;
	
 
}











