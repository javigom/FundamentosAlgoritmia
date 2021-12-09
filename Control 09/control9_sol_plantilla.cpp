/*
Nº Grupo: D03

Nombre y apellidos de los miembros del grupo:
	JAVIER GÓMEZ MORALEDA
	MARIO ALCOLEA ALCOLEA
*/

#define DOM_JUDGE

#include <iostream>

#ifdef DOM_JUDGE 
#include <ctime>
#include <stdlib.h>
#endif

using namespace std;


/*
(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
	sirven cada uno de ellos

	En un primer intento de resolver el algoritmo devolviendo un entero, nos ha sido imposible hallar el resultado ya que necesitábamos más parámetros.
	Por lo tanto, hemos decidido crear un struct, en el que, a parte de la longitud, tengamos el número al que corresponde dicha longitud, un valor
	mínimo que corresponde con el primer elemento de la "subcadena" y un valor máximo que corresponde con el último, debido a que el array está ordenado.
	De esta forma, podremos determinar si la longitud se encuentra al principio, en medio o al final de dicha subcadena y operar en consecuencia.

	Parámetros de entrada:
		- a[]: array con los elementos
		- inicio: posicion inicial de la subcadena
		- final: posicion final de la subcadena

(2) Análisis de casos

	 (2.1) Caso(s) base

	 - Si n = 1, no llamo a la generalización ya que la longitud de un array con un úncio elemento es uno
	 - En otro caso, llamo a la generalización:
		- Dentro de la generalización, mi caso base se dará cuando inicio = fin, es decir, que la subcadena tenga un único elemento
		En este caso, devolveré longitud 1, numero = a [inicio] (valor del único elemento) y lo mismo con el maximo y minimo.
	
	 (2.2) Caso(s) recursivos

	 - Si inicio es distinto a fin, haremos dos llamadas recursivas "dividiendo" el array en dos.
		- La primera irá desde inicio a mitad
		- La segunda irá desde mitad + 1 a fin


(3) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
	a partir de la misma, por inmersión.

	Una vez hemos salido del caso base de la generalizacion, "uniremos" las dos subcadenas para devolver un struct con la longitud mas larga, actualizando
	el número que aparece en dicha longitud y el valor mínimo y máximo.
	El struct devuelto siempre será, por defecto, res1

	1. Si el último elemento (máximo) de la primera subcadena coincide con el primero de la segunda (mínimo):
		
		- Si coincide que el número de la cadena mas larga del primero coincide con el máximo y la cadena más larga del segundo coincide con el mínimo, 
		quiere decir que debemos unir las dos longitudes, ya que la cadena más larga de estas subcadenas estaban divididas. Bastaría con actualizar la longitud
		del primero, que es el que devolvemos.

		- Si coincide el número de la cadena más larga del primero con el máximo, es que se encuentra al final, por lo tanto tendremos que ver si existe
		algún otro valor igual que este número en la otra parte del array. Nos situaremos con el indice en mitad + 1 e iremos recorriendo el array hacia
		delante hasta que el valor sea distinto.

		- Si coincide el número de la cadena más larga del segundo con el mínimo, es que se encuentra al principio, por lo tanto tendremos que ver si existe
		algún otro valor igual que este número en la otra parte del array. Nos situaremos con el indice en mitad e iremos recorriendo el array hacia atrás
		hasta que el valor sea distinto.

		- Por último, si no se cumple ninguna condición, ninguna longitud tiene sus elementos al final en el caso del primero, o al principio en el caso
		del segundo. Tendríamos que comprobar si existe alguna subcadena por el medio que pueda ser mayor de las que ya tengo. Para ello hago uso de una variable
		local aux, que nos servirá para almacenar ese resultado.
		Puesto que el maximo del primero y el mínimo del segundo son iguales, como mínimo existirá una cadena de longitud 2. Como se ha descrito antes, con dos
		bucles while recorreremos esos elementos hasta que sean distintos, hacia atrás en el caso del primero y hacia delante en el segundo.
		Si al final aux es mayor que las dos longitudes que tenía, actualizare la longitud de res1.

	2. Si no coinciden, significa que no puede existir una longitud mayor entre los dos resultados.

	En todos los casos comparo si la longitud del primer resultado es menor que la del segundo, y si se cumple, actualizo la longitud y el numero de res1,
	ya que es la que voy a devolver.

	En todos los casos asigno el valor maximo de res2 a res1, ya que ahora el resultado devuelto es la "suma" de ambos.

*/

typedef struct resultado {
	int longitud;
	int numero;
	int maximo;
	int minimo;
};

resultado mayorLongitud(int a[], int inicio, int fin) {

	resultado res1, res2;
	int mitad, i, aux;

	if (fin == inicio) {
		res1.longitud = (fin - inicio) + 1;
		res1.numero = a[inicio];
		res1.maximo = a[inicio];
		res1.minimo = a[inicio];
	}

	else {
		mitad = (inicio + fin) / 2;
		res1 = mayorLongitud(a, inicio, mitad);
		res2 = mayorLongitud(a, mitad + 1, fin);


		if (res1.maximo == res2.minimo) {
			if (res1.maximo == res1.numero && res2.minimo == res2.numero) {
				res1.longitud = res1.longitud + res2.longitud;
			}

			else if (res1.maximo == res1.numero) {
				i = mitad + 1;
				while (a[i] == res1.numero) {
					res1.longitud++;
					i++;
				}
			}

			else if (res2.minimo == res2.numero) {
				i = mitad;
				while (a[i] == res2.numero) {
					res2.longitud++;
					i--;
				}
			}

			else {
				aux = 0;
				i = mitad + 1;
				while (a[i] == res2.minimo) {
					aux++;
					i++;
				}

				i = mitad;
				while (a[i] == res1.maximo) {
					aux++;
					i--;
				}

				if (aux > res1.longitud&& aux > res2.longitud) {
					res1.longitud = aux;
					res1.numero = res1.maximo;
				}
			}
		}

		if (res2.longitud > res1.longitud) {
			res1.longitud = res2.longitud;
			res1.numero = res2.numero;
		}

		res1.maximo = res2.maximo;

	}

	return res1;
}

//pre: a está ordenado. n > 0
int lon_tramo_cte_max(int a[], int n) {

	if (n == 1) {
		return 1;
	}

	else {
		resultado res = mayorLongitud(a, 0, n - 1);
		return res.longitud;
	}
	
	// Punto de entrada al algoritmo. A implementar
}


/*
(1) Ecuaciones de recurrencia

(2) Resolución de las ecuaciones (aplicación de los patrones de resoulución)

(3) Complejidad final del algoritmo.

(4) Posibles ventajas y desventajas de tu algoritmo frente a una solución iterativa de coste
	 lineal


*/


#ifndef DOM_JUDGE
int lon_tramo_cte_max_it(int a[], int n) {
	int lon = 1;
	int pos = 1;
	int lon_max = 1;
	while (pos != n) {
		if (a[pos] == a[pos - 1]) {
			lon++;
		}
		else {
			lon = 1;
		}
		if (lon > lon_max) {
			lon_max = lon;
		}
		pos++;
	}
	return lon_max;
}


const int MAX_LON = 40;
const int MAX_INIT = 20;
const int MAX_INC = 10;


void genera_caso(int a[], int& n) {
	n = (rand() % MAX_LON) + 1;
	a[0] = rand() % MAX_INIT;
	for (int i = 1; i < n; i++) {
		if (rand() % 2 == 0) {
			a[i] = a[i - 1];
		}
		else {
			a[i] = a[i - 1] + (rand() % MAX_INC);
		}
	}

}

const int MAX_PRUEBAS = 1000;
#endif

#ifdef DOM_JUDGE 
const int MAX_LON = 10000;

bool ejecuta_caso() {
	int a[MAX_LON];
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << lon_tramo_cte_max(a, n) << endl;
		return true;
	}
}

#endif

int main() {
#ifndef DOM_JUDGE 
	int a[MAX_LON];
	int n;
	srand(time(NULL));
	int i = 0;
	int ok = true;
	while (i < MAX_PRUEBAS && ok) {
		genera_caso(a, n);
		if (lon_tramo_cte_max_it(a, n) != lon_tramo_cte_max(a, n)) {
			cout << "NO FUNCIONA PARA: ";
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			ok = false;
		}
		i++;
	}
	if (ok) {
		cout << "OK" << endl;
	}
	system("pause");
#endif

#ifdef DOM_JUDGE 
	while (ejecuta_caso());
#endif

}