/*

NUMERO DE GRUPO: D03

NOMBRRE Y APELLIDOS DE LOS AUTORES:
	JAVIER GÓMEZ MORALEDA
	MARIO ALCOLEA ALCOLEA
*/

#include <iostream>
using namespace std;

typedef unsigned long long t_num;

/*

PRECONDICION DE LA FUNCION:
---Escribe aqu� la precondici�n de la funci�n.

	P: {0 < = d <= 9 && alpha > 0}

*/
bool es_limpio(unsigned short d, unsigned short alpha, t_num n);


/*
POSTCONDICION DE LA FUNCION:
---Escribe aqu� la poscondici�n de la funci�n. Para refirte
---al valor devuelto por la funci�n, utiliza la pseudo-variable
---'resul'

(1) Definiciones auxiliares (si procede):
	es_limpio(unsigned short d, unsigned short alpha, t_num n) return (bool limpio)

(2) Postcondici�n
	Q = {limpio = es_limpio(d, alpha, n)}

*/

/* DISE�O DEL ALGORITMO:
--- Detalla aqu� el proceso seguido para dise�ar el algoritmo

PASO 1: Variables


PASO 2: Invariante


PASO 3: Inicio


PASO 4: Continuaci�n y finalizaci�n


PASO 5: Bloque del bucle


PASO 6: Terminaci�n.

*/

bool es_limpio(unsigned short d, unsigned short alpha, t_num n) {
	
	int contador = 0, contadorMax = 0;
	bool limpio = true, flag = false;

	if (n == 0) {
		if (d == 0) {
			contadorMax++;
		}
	}

	else {
		while (n > 0) {
			if (!flag && n % 10 == d) {
				contador = 1;
				flag = true;
			}

			else if (flag && n % 10 == d) {
				contador++;
			}

			else {
				flag = false;
			}
			n = n / 10;

			if (contador > contadorMax) {
				contadorMax = contador;
			}
		}
	}
	
	if (contadorMax >= alpha) {
		limpio = false;
	}

	return limpio;
}

/*
COMPLEJIDAD: Determina razonadamente la
complejidad del algoritmo


*/



bool procesa_caso() {
	int d;
	unsigned short alpha;
	t_num n;
	cin >> d;
	if (d != -1) {
		cin >> alpha >> n;

		if (es_limpio((unsigned short)d, alpha, n)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (procesa_caso());
}