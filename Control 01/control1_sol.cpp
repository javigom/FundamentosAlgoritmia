/*

Nº GRUPO:3

NOMBRE Y APELLIDOS DE LOS MIEMBROS:
MARIO ALCOLEA ALCOLEA
JAVIER GÓMEZ MORALEDA

OBSERVACIONES:


*/

#include <iostream>
using namespace std;

const int TMAX = 1000;  // No habr� vectores de m�s de 1000 elementos

/*
PRECONDICION DE LA FUNCION:.
  P: {0 <= n <= TMAX}
*/
int pares_menos_impares(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  Q: {resul = sumapares(a,n) - sumaimpares(a,n)}
  sumapares(a, n): {x = SUMA i: 0 <= i < n ^ par(a[i]): a[i]}
  sumaimpares(a, n): {x = SUMA i: 0 <= i < n ^ ¬par(a[i]): a[i]}
  par(x): {x mod 2 = 0}

				  
 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el algoritmo

 PASO 1: Variables
  resul, n, i (variable de control), a;


 PASO 2: Invariante
  INV: {resul = sumapares(a,n) - sumaimpares(a,n)}


 PASO 3: Inicio
	i = 0;
	resul = 0;
	

 PASO 4: Continuaci�n y finalizaci�n
   i != n  continuacion.
   i = n finalizacion.
   	 

 PASO 5: Bloque del bucle
   Tiene 1 if/else + 2 asignaciones + i++;

   	  
 PASO 6: Terminaci�n.
	cota: n - i;


 */



int pares_menos_impares(const int a[], int n) {
	int resul = 0;
	int i = 0;

	while (i < n) {
		if (a[i] % 2 == 0)
			resul += a[i];
		else
			resul -= a[i];

		i++;
	}

	return resul;
}

/*
COMPLEJIDAD: Determina razonadamente la
complejidad del algoritmo

   La complejidad de el condicional IF-ELSE es logaritmica.
   La complejidad de un bucle for es lineal (n).
   Por lo tanto como tenemos un condicional dentro del bucle for, la complejidad total del algoritmo es n*logn;
   O(nlogn)

 */


 /* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

bool ejecuta_caso() {
	int a[TMAX];
	int n;
	lee_vector(a, n);
	if (n >= 0) {
		cout << pares_menos_impares(a, n) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n;
	while (ejecuta_caso());
}