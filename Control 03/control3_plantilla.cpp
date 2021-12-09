/*
GRUPO:
COMPONENTES DEL GRUPO:

*/


#include <iostream>


using namespace std;


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
  

*/
bool es_sobrado(int n); 

/*
POSTCONDICION DE LA FUNCION: 
  ---Escribe aquí la poscondición de la función. Para refirte 
  ---al valor devuelto por la función, utiliza la pseudo-variable
  ---'resul'
  
  (1) Definiciones auxiliares (si procede):
  
  
  (2) Postcondición
    
    
 */

 /* DISEÑO DEL ALGORITMO:
 --- Detalla aquí el proceso seguido para diseñar el
 --- algoritmo
 
 PASO 1. Variables
 
 
 PASO 2. Invariante
	 

 PASO 3. Inicialización:
 
 
 PASO 4: Continuación y finalización: 
 	  
 
 PASO 5: Cuerpo del bucle
 
 
PASO 6: Terminación		  

 
*/
 
 
 bool es_sobrado(int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */

}	

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo


*/ 
	 

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */


int main() {
   int n_casos;
   cin >> n_casos;
   while (n_casos > 0) {
	   int n;
	   cin >> n;
	   if (es_sobrado(n)) {
		  cout << "SI" << endl;  
	   }
	   else {
		  cout << "NO" << endl; 
	   }
	   n_casos--;
   }
   return 0;
}