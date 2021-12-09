/*

NUMERO DE GRUPO: D03

NOMBRRE Y APELLIDOS DE LOS AUTORES:
	JAVIER GÓMEZ MORALEDA
	MARIO ALCOLEA ALCOLEA

*/

#include <iostream>

using namespace std;

/*
	Introducción: Este problema nos ha dado muchos quebraderos de cabeza y trás probar varios métodos hemos logrado llegar al más óptimo:
		En un primer instante, intentamos obtener el primer número a partir de los datos de entrada (p.e. 1, 2 => num = 10, 11, ... , 19), pero al llegar al último
		caso era un número muy grande y nos dimos cuenta de que no era viable.
		Luego intentamos estudiar un caso usando arrays (para poder introducir valores grandes), pero al final hemos llegado a la conclusión de que no es necesario,
		ya que vamos a ir dígito por dígito y lo que nos va a interesar es su suma.
		Por lo tanto, la manera de abordar el problema ha cambiado y en vez de empezar por el número con todos los dígitos (k) e ir restando, vamos a partir desde
		2 (ya que cualquier número de un dígito es sumdivisible).

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos
	
	calcula_sumdivisibles:
		- resultado: variable de salida pasada por referencia. Actúa como contador de todos los números que cumplen dicha propiedad.
		- k: número de dígitos que contiene el número (que no vamos a tener almacenado en ningún sitio)
		- cifraActual: cifra del número que evaluaremos para ver si cumple la propiedad. En el fondo, actuaría como un índice en un array, que va recorriendo los distintos
		dígitos del número.
		- suma: suma acumulada de dígitos, que utilizaremos para dividir con cifraActual para calcular si su módulo es 0.

(2) ¿Cómo son las soluciones parciales de este problema?

	Las soluciones parciales son calculadas utilizando la variable suma, en la que iremos almacenando la suma de los dígitos. Según vayamos incrementando cifraActual, nos iremos
	"desplazando" a través de las cifras del número de menos a más.

(3) ¿Cuándo una solución parcial es viable?

	Teniendo en cuenta que suma + i es equivalente a sumar la suma acumulada más la cifra actual (que SIEMPRE oscilará entre el 0 y el 9, al tratarse de un dígito) es la
	suma de los digitos que llevamos y cifraActual + 1 es el número de dígitos actuales (+1 porque lo trataremos como una posición de un array):
		Una solución parcial es viable siempre que la suma acumulada más la cifra actual módulo número de digitos actuales (cifraActual + 1) es igual a 0.
		Es decir, que si la suma de digitos es divisible entre el número de dígitos, continuaré recurriendo.

(4) ¿Cuándo una solución parcial es una solución final al problema?

	Una solución parcial es una solución final cuando he llegado a colocar el último digito y se cumple dicha propiedad.

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?
	
	Dada una solución parcial correcta con la suma actualizada y n digitos, obtengo la siguiente solución parcial viable:
		- Se ejecutará un bucle for en el que i será el siguiente valor que tomará el dígito

		- Ahora compruebo si la suma acumulada más ese valor módulo del número de digitos actual es igual a 0
			- Si se cumple, sigo avanzando en la recursión, es decir, "coloco" el siguiente dígito.
			- Si no, corto la recursión.

(6) Análisis de casos

(6.1) Caso(s) base

	Si cifraActual = k - 1, es decir, estoy en el último dígito:
		- resultado++
	(Llegados al último dígito y habiendo comprobado que cumple la propiedad, no puedo avanzar más en la recursión)


(6.2) Caso(s) recursivos

	- Si se cumple que la suma de los digitos es divisible entre el número de dígitos:
		- Compruebo que no sea el último dígito y hago una llamada recursiva aumentando el número de dígitos en 1 y actualizando la suma acumulada con el dígito actual.

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.
	
	En resumen, el algoritmo va a empezar con el dígito inicial (d) y empezará a evaluar desde el segundo dígito si se cumple la propiedad colocando cualquier dígito posible (del 0 al 9)
	y si se cumple para esos dígitos, añadiremos uno mas y volveremos a comprobar hasta llegar a k dígitos.

*/


void calcula_sumdivisibles(int& resultado, int k, int cifraActual, int suma) {
	for (int i = 0; i < 10; i++) {
	
		if (((suma + i) % (cifraActual + 1)) == 0) {
			if (cifraActual == k - 1) {
				resultado++;
			}

			else {
				calcula_sumdivisibles(resultado, k, cifraActual + 1, suma + i);
			}
		}
	}
}

int num_sumdivisibles(int d, int k) {
	int resultado = 0;
	calcula_sumdivisibles(resultado, k, 1, d);
	return resultado;
}


int main() {
	int d;
	do {
		cin >> d;
		if (d > 0) {
			int k;
			cin >> k;
			cout << num_sumdivisibles(d, k) << endl;
		}
	} while (d > 0);
}