/*

NUMERO DE GRUPO: D03

NOMBRRE Y APELLIDOS DE LOS AUTORES:
	JAVIER GÓMEZ MORALEDA
	MARIO ALCOLEA ALCOLEA
*/

#include <iostream>

using namespace std;

// RepresentaciÃ³n de un tema
typedef struct {
	float tiempo_req;  // tiempo requerido para estudiar
	float nota_prim;   // Nota que supone en la primera parte
	float nota_sec;    // Nota que supone en la segunda parte
} tInfoTema;

const unsigned int MAX_TEMAS = 20;

/*

(1) En caso de utilizar una generalizaciÃ³n, indicar su parÃ¡metros, y explicar para que
sirven cada uno de ellos

	calcula_mejor_puntuacion: 
	
		- info_temas[]: array que contiene los distinos temas que entran en el examen, junto al tiempo necesario para estudiarlos y la puntuación que se obtiene en 
		cada una de las partes.
		- num_temas: número de temas incluidos en el examen (contador del array).
		- tiempo_disponible: tiempo máximo que tiene para estudiar el examen.
		- pos: posicion con la que iremos recorriendo el array de las preguntas.
		- tiempoParcial: tiempo acumulado con las preguntas que hemos escojido, nos servirá para no pasarnos del tiempo disponible.
		- mediaMaxima: variable (de salida) por referencia en la que almacenaremos la nota media máxima obtenible.
		- marcaje: array de booleanos que nos servirá para saber que preguntas hemos escojido para estudiar (podríamos usar 2 variables para representar las puntuaciones
		acumuladas que llevamos con las preguntas escojidas, pero nos pareció adecuado usar este método).
		

(2) Â¿CÃ³mo son las soluciones parciales de este problema?

	Las soluciones parciales para este problema las iremos calculando con la suma, tanto del tiempo que la almacenaremos en tiempoParcial, como de las puntuaciones, cuyo recuento lo
	llevaremos poniendo a true la posición correspondiente en el vector de marcaje.
	El tiempo parcial es la única variable que pasaremos por parámetros ya que la usaremos frecuentemente para ver si una solución es válida aunque podríamos recorrer el array de
	marcaje para obtenerlo, al igual que la puntuación.

(3) Â¿CuÃ¡ndo una soluciÃ³n parcial es viable?

	Una solución parcial es viable siempre que la suma del tiempo parcial no supere el tiempo disponible.

(4) Â¿CuÃ¡ndo una soluciÃ³n parcial es una soluciÃ³n final al problema?
	
	Una solución parcial es una solución final siempre que:
		- La posicion que recorre el array (pos) haya llegado a su fin.
		- La media de ambas partes esté aprobada, es decir, se cumple esSolucion.
		- La media total del examen sea mayor que mediaMaxima, es decir, supere la media máxima obtenida hasta el momento (lo gestionaremos con tratarSolucion)

(5) Dada una soluciÃ³n parcial, Â¿cÃ³mo se generan las siguientes soluciones
parciales viables?

	Tenemos dos caminos a seguir: estudiar el siguiente tema del examen o no hacerlo:

		- Si se estudia: Primero compruebo que el tiempo parcial + el tiempo de ese tema sea menor o igual que el tiempo disponible y una vez dentro compruebo si estoy en el último
		elemento del array para hacer o no la llamada recursiva.

		- Si no se estudia:  Compruebo si estoy en el ultimo elemento del array para hacer o no la llamada recursiva.

(6) AnÃ¡lisis de casos

(6.1) Caso(s) base

	- Si estoy en el último elemento del array y he sumado ese último tema: 
		- Compruebo si esSolucion es true y entonces llamo a tratarSolucion (detallado en el punto 7).

	 - Si estoy en el último elemento del array y no he sumado ese último tema:
		- Compruebo si esSolucion es true y entonces llamo a tratarSolucion (detallado en el punto 7).

(6.2) Caso(s) recursivos

	Considerando pos el índice del array:
		
		- Compruebo si el tiempo parcial + tiempo requerido de info_temas[pos] es menor o igual que el tiempo disponible:
			- Compruebo que no estoy en el último elemento del array: 
				- Hago una llamada recursiva a calcula_mayor_puntuacion incrementando en 1 pos y sumando a tiempo parcial el tiempo requerido de esa posición.

		- Si no he sumado esa pregunta, no es necesario comprobar si es un resultado válido, por lo tanto sólo comprobaré si no estoy en el último elemento:
			- Hago una llamada recursiva a calcula_mayor_puntuacion incrementando pos en 1.

(7) En caso de utilizar una generalizaciÃ³n, explicar cÃ³mo se define el algoritmo final
a partir de la misma, por inmersiÃ³n.

	El algoritmo final va a funcionar de la siguiente manera:
	Voy a generar llamadas recursivas en el que o bien me estudio un tema del array o no lo hago, en función de eso evalúo:

		- Si me lo estudio, compruebo no pasarme del tiempo. Pongo el array marcaje a true y compruebo si estoy en el último tema:
			- Si lo estoy, compruebo que ambas partes estén aprobadas y trato la solución mirando si la media actual supera a la máxima
			- Si no lo estoy hago una llamada recursiva para evaluar el siguiente tema (teniendo en cuenta que he sumado el tema actual).
			Al salir, siempre pongo el array de marcajes de nuevo a false.
		- Si no me lo estudio, compruebo si es el último tema:
			- Si lo estoy, compruebo que ambas partes estén aprobadas y trato la solución mirando si la media actual supera a la máxima
			- Si no lo estoy hago una llamada recursiva para evaluar el siguiente tema(teniendo en cuenta que no me he estudiado el tema actual, por lo tanto no es
			necesario el marcaje).
*/

void tratarSolucion(const tInfoTema info_temas[], const bool marcaje[], unsigned int num_temas, float& mediaMaxima) {
	float media = 0, puntosA = 0, puntosB = 0;
	for (int i = 0; i < num_temas; i++) {
		if (marcaje[i]) {
			puntosA = puntosA + info_temas[i].nota_prim;
			puntosB = puntosB + info_temas[i].nota_sec;
		}
	}

	media = (puntosA + puntosB) / 2;

	if (media > mediaMaxima) {
		mediaMaxima = media;
	}

}

bool esSolucion(const tInfoTema info_temas[], const bool marcaje[], unsigned int num_temas, float tiempo_disponible) {

	bool solucion = false;
	float puntosA = 0, puntosB = 0, tiempo = 0;

	for (int i = 0; i < num_temas; i++) {
		if (marcaje[i]) {
			tiempo = tiempo + info_temas[i].tiempo_req;
			puntosA = puntosA + info_temas[i].nota_prim;
			puntosB = puntosB + info_temas[i].nota_sec;
		}
	}

	if (puntosA >= 5 && puntosB >= 5 && tiempo <= tiempo_disponible) {
		solucion = true;
	}

	return solucion;
}

void calcula_mejor_puntuacion(const tInfoTema info_temas[], unsigned int num_temas, float tiempo_disponible, int pos, float tiempoParcial, float& mediaMaxima, bool marcaje[]) {
	
	if ((tiempoParcial + info_temas[pos].tiempo_req) <= tiempo_disponible) {
		marcaje[pos] = true;
		if ((pos + 1) == num_temas) {

			if (esSolucion(info_temas, marcaje, num_temas, tiempo_disponible))
				tratarSolucion(info_temas, marcaje, num_temas, mediaMaxima);
		}

		else {
			calcula_mejor_puntuacion(info_temas, num_temas, tiempo_disponible, pos + 1, tiempoParcial + info_temas[pos].tiempo_req, mediaMaxima, marcaje);
		}
		marcaje[pos] = false;
	}


	if ((pos + 1) == num_temas) {
		if (esSolucion(info_temas, marcaje, num_temas, tiempo_disponible))
			tratarSolucion(info_temas, marcaje, num_temas, mediaMaxima);
	}

	else {
		calcula_mejor_puntuacion(info_temas, num_temas, tiempo_disponible, pos + 1, tiempoParcial, mediaMaxima, marcaje);
	}
}

float mejor_puntuacion(const tInfoTema info_temas[], unsigned int num_temas, float tiempo_disponible) {
	
	float mediaMaxima = -1;

	bool marcaje[MAX_TEMAS];

	for (int i = 0; i < num_temas; i++){
		marcaje[i] = false;
	}

	calcula_mejor_puntuacion(info_temas, num_temas, tiempo_disponible, 0, 0, mediaMaxima, marcaje);

	return mediaMaxima;
}

bool procesa_caso() {
	int num_temas;
	tInfoTema info_temas[MAX_TEMAS];
	cin >> num_temas;
	if (num_temas != -1) {
		float tiempo_disponible;
		cin >> tiempo_disponible;
		for (int i = 0; i < num_temas; i++) {
			cin >> info_temas[i].tiempo_req;
			cin >> info_temas[i].nota_prim;
			cin >> info_temas[i].nota_sec;
		}
		cout << mejor_puntuacion(info_temas, num_temas, tiempo_disponible) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (procesa_caso());
} 