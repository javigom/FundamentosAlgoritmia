#include <iostream>

using namespace std;

const int TMAX = 1000;  // No habr� vectores de m�s de 1000 elementos

/*
GRUPO: 3
NOMBRES: 
 MARIO ALCOLEA ALCOLEA
 JAVIER GOMEZ MORALEDA

*/



/*
PRECONDICION DE LA FUNCION:

	P: {0 < n <= TMAX }

*/
bool es_gaspariforme(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'

  (1) Definiciones auxiliares (si procede):

	suma_parcial(a,i) = {k = SUMA j: 0<= j <= i: a[j]}


  (2) Postcondicion

	Q: {resul = PARA_TODO i: 0<= i <n-1: suma_parcial(a, i) >= 0 ^ suma_parcial(a, n-2) + a[n-1] = 0}
     
 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el
 --- algoritmo

 PASO 1. Variables
   resul, i, k


 PASO 2. Invariante
   INV = {res = PARA_TODO u: 0<= u < i-1: suma_parcial(a, u) >= 0 ^ suma_parcial(a,u) + a[i-1] = 0 ^ 0 <= i < n}


 PASO 3. Inicializaci�n:
   resul = true;
   i = 0;
   k = 0;

 PASO 4: Continuaci�n y finalizaci�n
   i != n-1 && resul



 PASO 5: Cuerpo del bucle.
   Si suma_parcial(a,u) < 0 -> res = false
   Si suma_parcial(a,u) + a[i-1] != 0 -> res = false
   i++;

PASO 6: Terminaci�n
	Cota: (n-1)-i


*/



bool es_gaspariforme(const int a[], int n) {
	bool resul = true;
	int i = 0, 
		suma = 0;

	while (i < n && resul) {
		suma += a[i];
		if ((i < n - 1) && (suma < 0))
			resul = false;

		if ((i == n-1) && (suma != 0))
			resul = false;

		i++;
	}

	return resul;
}

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo
	t(n) = K0 + n*K1: 
		- K0: inicio + fin
		- K1: Cuerpo del bucle
		- El bucle realiza n iteraciones

	t(n) e O(n) 
*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int main() {
	int a[TMAX];
	int n;
	do {
		lee_vector(a, n);
		if (n > 0) {
			if (es_gaspariforme(a, n))
				cout << "SI" << endl;
			else
				cout << "NO" << endl;
		}
	} while (n != 0);

}