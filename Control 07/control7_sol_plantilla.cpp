/*
No Grupo:
Nombre y Apellidos de los miembros:

	Javier Gómez Moraleda
	Mario Alcolea Alcolea

*/


// Si se comenta esta definición, el programa
// autocomprobará su funcionamiento comparando
// la implementación realizada con una 
// implementación 'naif' del algoritmo
#include <iostream>

#include <vector>

#define DOM_JUDGE

#ifndef DOM_JUDGE
#include <ctime>
#include <stdlib.h>
#endif 

using namespace std;

typedef unsigned long long t_num;
long long int potencia, suma;

/*
(1) En caso de utilizar una generalizacion,
determinación de los parámetros de la generalización.
Determina los parámetros de la generalización. Para cada parámetro
indica: (i) su tipo; (ii) su nombre; (iii) si es un parámetro
de entrada, de salida, o de entrada / salida; (iv) su propósito,
descrito de manera clara y concisa.

	Parámetros de entrada:

	- vector v: En él almacenamos los digitos del numero del que deseamos obtener
	la cantidad de números singulares menores que él. Iremos introduciendo los digitos
	desde el menos significativo al más significativo.
	- int i: Variable entera que usaremos para movernos por las posiciones del vector.

	Parámetros de salida:

	- t_num resultado: Cantidad de números singulares menores que n.
	La utilizaremos para ir actualizando el valor de salida. 

(2) Análisis de casos:

(2.1) Casos base
	
	Utilizaremos una variable local max que tendrá la última posición del vector (dígito más significativo)

	Entraremos en el caso base cuando la i = 0, es decir, estemos en el digito menos
	significativo del número. En él distinguimos dos casos:

		- v[0] <= v[max] (dígito más significativo):
		resul = v[0];
		- En otro caso (v[0] > v[max]):
		resul = v[0] - 1;

		Al final, inicializamos suma = 1 (acarreo final) y potencia = 9 (la usaremos para multiplicar)

(2.2) Casos recursivos
	
	- Si i != 0 (no es del digito menos significativo). Distinguimos dos casos:
		
		* Si i < max (no es el dígito más significativo):
			
			- Si v[i] == v[max]: resultado = v[i] * potencia;
			- Si v[i] < v[max]: resultado = resultado + v[i] * potencia;
			- En otro caso (v[i] > v[max]): resultado = resultado + (v[i] - 1) * potencia;

			Al final, actualizamos: 

				suma = suma + potencia;
				potencia = potencia*9;

		* En otro caso (i = max, es decir, estamos en el último dígito):
			
			resultado = resultado + v[i] * potencia + suma;
	

(3) En caso de utilizar una generalizacion, definición por inmersión
del algoritmo. Describe de manera clara y concisa cómo se lleva a
cabo el algoritmo, en qué punto o puntos se invoca a la generalización,
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización.

	- El caso n = 0, se trata de manera especial y devuelve resul = 0. No es necesario
	llamar a la función recursiva;

	- En cualquier otro caso realizamos la llamada recursiva a calcula_singulares_menoresque(v, i, resultado);
	Devolviendo el resultado en resultado.

*/

void calcula_singulares_menoresque(const vector <int>& v, int i, t_num & resultado) {

	int max = v.size() - 1;

	if (i == 0) {
		if (v[i] <= v[max]) {
			resultado = v[i];
		}
		else {
			resultado = (v[i] - 1);
		}
		potencia = 9;
		suma = 1;
	}

	else {
		calcula_singulares_menoresque(v, i - 1, resultado);

		if (i < max) {

			if (v[i] == v[max]) {
				resultado = v[i] * potencia;
			}

			else if (v[i] < v[max]) {
				resultado = resultado + v[i] * potencia;
			}

			else {
				resultado = resultado + ((v[i] - 1) * potencia);
			}

			suma = suma + potencia;
			potencia = potencia * 9;
		}

		else {
			resultado = resultado + v[i] * potencia + suma;
		}
	}
}

t_num num_singulares_menoresque(t_num n) {

	t_num num = n, resultado;
	vector <int> v;

	if (n == 0) {
		resultado = 0;
	}

	else {

		while (num > 0) {
			v.push_back(num % 10);
			num = num / 10;
		}
		calcula_singulares_menoresque(v, v.size() - 1, resultado);
	}

	return resultado;
}

/*
Determina justificadamente la complejidad del algoritmo

(1) Determinación de las ecuaciones de recurrencia para la generalización	

	t(1) = co
	t(n) = c1 + t(n/10) 

	NO dividimos el número entre 10, pero vamos avanzando en el vector decrementando la poscion,
	y como el vector contiene los dígitos de dicho número, que en el fondo es como si lo dividimos entre 10.

(2) Resolución utilizando los patrones vistos en clase

	Es una recurrencia en la que vamos modificando la posicion en el vector:

	- a=1
	- k = 0
	- b = 10

   Por tanto, b^k = 1. Es decir, estamos en el caso
   a = b^k. Por tanto t(n) será O(n^k log n). Es decir,
   O(n^0 log n). Es decir O(log n)

(3) Determinación justificada de la complejidad del algoritmo final.

	Al no estar acotado por arriba, la complejidad final del algoritmo es logn, ya que
	varía en función de sus dígitos.

*/

#ifndef DOM_JUDGE
unsigned short digito_mas_significativo(t_num n) {
	while (n > 9) {
		n = n / 10;
	}
	return (unsigned short)n;
}
bool es_singular(t_num n) {
	unsigned short msd = digito_mas_significativo(n);
	bool loes = true;
	while (n > 9 && loes) {
		loes = (n % 10 != msd);
		n = n / 10;
	}
	return loes;
}

t_num num_singulares_menoresque_naif(t_num n) {
	t_num num = 0;
	for (t_num i = 0; i < n; i++) {
		if (es_singular(i)) {
			num++;
		}
	}
	return num;
}
#endif

#ifdef DOM_JUDGE
bool ejecuta_caso() {
	long long n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		cout << num_singulares_menoresque(n) << endl;
		return true;
	}
}

#endif

int main() {

#ifndef DOM_JUDGE
	srand(time(NULL));
	for (int i = 1; i < 1000; i++) {
		t_num  n = (t_num)rand();
		if (num_singulares_menoresque_naif(n) != num_singulares_menoresque(n)) {
			cout << "NO FUNCIONA" << endl;
			cout << n << ":" << num_singulares_menoresque_naif(n) << "..." << num_singulares_menoresque(n) << endl;
			break;
		}
	}
	cout << "OK" << endl;
	system("pause");
#endif

#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif
}