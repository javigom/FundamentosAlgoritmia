#include <algorithm>
#include <iostream>

using namespace std;

/*
GRUPO: 3
NOMBRES: MARIO ALCOLEA ALCOLEA
		 JAVIER GOMEZ MORALEDA

*/

/*

PRECONDICION DE LA FUNCION:
  
  P:{n >= 0 ^ k >= 0 ^ es_creciente(a)}

*/
unsigned int num_k_emparejados(int v[], unsigned int n, unsigned int k);
/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'

  (1) Definiciones auxiliares (si procede):
  
  es_creciente(a): {PARA_TODO i: 0<= i < n-1: a[i] < a[i+1]}
  k-emparejados(a,i): {EXISTE j: 0 <= j < i: |a[j] - a[i]| = k}

  (2) Postcondicion

  Q: {resul = #i: 0 < i < n: k-emparejados(a,i)}

 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el
 --- algoritmo


PASO 1. Variables
	i, j, resul


PASO 2. Invariante
	I: {1 <= j <= n ^ 
		0 <= i < n ^ 
		resul = #u: 0 <= u < j: k-emparejados(v,u)}


PASO 3. Inicializaci�n:
	i = 0, j = 1, resul = 0

PASO 4: Continuacion y finalizacion:
	i != n-1 ^ j != n

PASO 5: Cuerpo del bucle
    Existen 3 casos:
	1) v[j] - v[i] = k
		-incrementamos resul e i
		-j lo igualamos a la siguiente pos de i (i+1)
	
	2)v[j] - v[i] < k
		-incrementamos valor de j
	
	3)v[j] - v[i] > k
		-incrementamos valor de i
		-j lo igualamos a la siguiente pos de i (i+1)

PASO 6: Terminaci�n
	cota: j != n 

*/


unsigned int num_k_emparejados(int v[], unsigned int n, unsigned int k) {
	unsigned int i = 0,
				 j = 1,
				 resul = 0;

	if (k == 0)
		resul = n;

	else {

		while (i < n-1 && j < n) {
			if (unsigned(v[j] - v[i]) == k) {
				resul++;
				i++;
				j = i + 1;
			}
			else if (unsigned(v[j] - v[i]) < k) {
				j++;
			}

			else {
				i++;
				j = i + 1;
			}
		}
	}
	return resul;
}

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo:
	T(n) tiene la forma: k0 + nk1
	k0: inicio y fin
	k1: cuerpo del bucle que realiza n iteraciones
	T(n) e O(n)
*/



bool procesa_caso() {
	int v[100];
	int n, k;
	cin >> n;
	if (n != -1) {
		cin >> k;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << num_k_emparejados(v, n, k) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (procesa_caso());
}