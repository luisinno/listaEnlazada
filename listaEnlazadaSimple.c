//
//  listaEnlazadaSimple.c
//  listaEnlazadaSimple


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaEnlazadaSimple.h"

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
crearVacia(ListaEnlazadaRef raiz)
{
}

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
estaVacia(ListaEnlazada raiz)
{
}

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
tipoNodoRef
creaNodo(tipoInfoRef info)
{
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
insertarDespuesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
 }


/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
insertarAntesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
}



/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
insertarNodoComienzo(ListaEnlazadaRef raiz, tipoInfoRef info)
{
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
insertarNodoFinal(ListaEnlazadaRef raiz, tipoInfoRef info)
{
}

/*
 * Esta función recibe una lista (por referencia), un índice entero y una
 * variable de tipoInfo por referencia. Debe insertar un nuevo nodo
 * en la posición indicada por el índice entero (implica recorrido contando
 * nodos hasta el valor indicado por indice). Ojo, hay que garantizar que 
 * esa posición existe, es decir, que si la lista tiene 5 nodos, (los numeramos
 * de 0 a 4), las posiciones válidas son 0, 1, 2, 3, 4, 5 (la posición 5
 * es equivalente a añadir al final).
 * Si la posición no existe, no se puede hacer la inserción (en nuestro ejemplo,
 * la posición -1 ya no existe, y la posición 6 tampoco).
 * Se puede hacer uso de alguna de las funciones implementadas, aunque implique 
 * ineficiencias (recorridos adicionales de la lista enlazada). Opcional 
 * escribir una versión eficiente que no implique repetir recorridos.
 */
int
insertarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice, tipoInfoRef info)
{
}


/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
eliminarNodo(ListaEnlazadaRef raiz, tipoNodoRef pos)
{
}


/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
eliminarNodoComienzo(ListaEnlazadaRef raiz)
{
}


/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
eliminarNodoFinal(ListaEnlazadaRef raiz)
{
}

/*
 * Esta función recibe una lista (por referencia) y un índice entero
 * Debe eliminar el nodo situado en en la posición indicada por el
 * índice entero (implica recorrido contando nodos hasta el valor
 * indicado por indice). Ojo, hay que garantizar que
 * esa posición existe, es decir, que si la lista tiene 5 nodos (los numeramos
 * de 0 a 4), las posiciones válidas son 0, 1, 2, 3, 4.
 * Si la posición no existe, no se puede hacer la eliminación (en nuestro ejemplo,
 * la posición -1 ya no existe, y la posición 5 tampoco).
 * Se puede hacer uso de alguna de las funciones implementadas, aunque 
 * implique ineficiencias (recorridos adicionales de la lista enlazada). 
 * Opcional escribir una versión eficiente que no implique repetir recorridos.
 */
int
eliminarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice)
{
}



/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
liberarListaEnlazada(ListaEnlazadaRef raiz)
{
}


/********************************************************************
 *                                                                  *
 * Las cuatro funciones que vienen a continuación dependen de cómo  *
 * está definido el tipo de dato tipoInfo. No es lo mismo mostrar   *
 * por pantalla el contenido de los datos almacenados en una lista  *
 * enlazada si éste es de tipo entero, o si se trata de un registro.*
 * Adicionalmente, y para que el alumno no pierda el tiempo         *
 * en implementar funciones que aportan poco desde un punto de vista*
 * docente, se proporcionan ya implementadas las funciones          *
 * mostrarListaEnlazada() y crearListaValoresAleatorios(). Las otras*
 * dos son sencillas y se dejan al alumno su implementación.        *
 *                                                                  *
 *******************************************************************/

/*
 * Esta función recibe una lista (por referencia) y un índice entero
 * Debe devolver la información almacenada en el nodo situado en la 
 * posición indicada por el índice entero (implica recorrido contando nodos 
 * hasta el valor indicado por indice). Ojo, hay que garantizar que
 * esa posición existe, es decir, que si la lista tiene 5 nodos (los numeramos
 * de 0 a 4), las posiciones válidas son 0, 1, 2, 3, 4.
 * Si la posición no existe, no se puede devolver nada (en nuestro ejemplo,
 * la posición -1 ya no existe, y la posición 5 tampoco).
 * IMPORTANTE: tipoInfo es, en este caso particular, un entero. Aunque
 * la dependencia es pequeña, si existe. ¿Cómo se devuelve el código de error
 * en caso de no existir la posición indicada por el parámetro indice?. Si 
 * tipoInfo es un int es sencillo, si es un registro también, pero ya es
 * diferente implementación.
 */
tipoInfo
devolverInfoPosicionIndice(ListaEnlazada raiz, int indice)
{
}


/*
 * Función presentada en clase de teoría. Se debe implementar
 * la versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
insertarOrdenada(ListaEnlazadaRef raiz, tipoInfoRef info)
{
}

int
mostrarListaEnlazada(ListaEnlazada raiz)
{
	tipoNodoRef aImprimir;
	int res = 0,i = 0;
	
	printf("\n\n");
	printf("%-14s%-10s\n","  Posición", "Valor");
	printf("%-14s%-10s\n","  ==========", "======");


	aImprimir = raiz;
	while (aImprimir != NULL) {
		printf("\t%3d)\t%7d\n",i++, aImprimir->info);
		aImprimir = aImprimir->sig;
	}
	return res;
}


int
crearListaValoresAleatorios(ListaEnlazadaRef raiz, int numNodos)
{
	int i;
	tipoInfo temp;
	
	if (estaVacia(*raiz)) {
		srandom(time(NULL));
		for (i = 0; i < numNodos; i++) {
            temp = random()%10000;
            insertarDespuesDeNodo(raiz, NULL, &temp);
            //insertarAntesDeNodo(raiz, NULL, &temp);
            //insertarNodoFinal(raiz, &temp);
			//insertarNodoComienzo(raiz, &temp);
		}
		return 0;
	}
	return -1;
}

//EJ PRACT 13_________________________________________________________________________________


int main (void) {

// *** -----------------------------------
// *** 1) Crear una lista enlazada vac�a
// *** ----------------------------------

//CREACION DE NODO
   nuevo = malloc(sieof(tipoNodo));
   if(nuevo == NULL)
   else {

}



// *** -----------------------------------
// *** 2) Crear un bucle que vaya leyendo n�meros hasta que se teclee 0 o negativo 
// ***   (bucle controlado por centinela). Por cada n�mero le�do debe de crear un nodo
// ***   y enlazarlo como PRIMERO a la lista enlazada.
// *** ----------------------------------

printf
while





// *** -----------------------------------
// *** 3) Crear un bucle para que recorra la lista, la visualice, 
// ***    cuente sus nodos y obtenga la suma del valor de todos los nodos
// ***    Imprimir el n�mero de nodos y su suma en pantalla
// *** ----------------------------------
printf("lista enlazada");

cuantos = 0;
suma = 0;

indice = lst; //empezar
while (indice != NULL){
	//tratamiento del nodo
printf("%d", indice -> info);
cuantos ++;
______
______




 indice = indice -> sig; //cada vez que quiera avanzar
}
// ej lista vacia: sirve porque no hay nada que recorrer, el algoritmo no falla



// *** -----------------------------------
// *** 4) Crear un bucle que vaya leyendo n�meros hasta que se teclee 0 o negativo
// ***    (bucle controlado por centinela). Por cada n�mero le�do debe de crear un nodo y enlazarlo 
// ***    como ULTIMO a la lista enlazada.
// *** ----------------------------------

if (lst==NULL) //hacemos este if para que si la lista este vacía, el algoritmo while sea valido
	lst = nuevo;
else{
indice = lst;
while (indice->sig != NULL) //indice se queda apuntando al ultimo nodo, el puntero de ese nodo va a null, por eso sabemos que es el último
	indice = indice->sig;
indice->sig = nuevo; //OBLIGATORIO
}

// *** ----------------------------------------------------
// --- 4.1 Versi�n 1 del Algoritmo. Ante cada inserci�n, siempre recorremos la lista
// --- desde el principio hasta localizar el ultimo nodo. Es poco eficiente
// *** ----------------------------------------------------
   

//recorremos una vez hasta encontrar el último nodo, apuntamos con un puntero al último nodo
ultimo=lst;
if (lst != NULL){
ultimo=lst;
while(ultimo->sig != NULL) //si la lista está vacía: error
	ultimo = ultimo -> sig
}
...
...
if (lst==NULL){
	lst=nuevo;
	ultimo=nuevo;
}
else{
	ultimo->sig=nuevo;
	ultimo=nuevo;
}

// ultimo->sig=nuevo;
// ultimo=nuevo; //SIEMPRE DEJAMOS APUNTADO EL ÚLTIMO NODO


// *** -----------------------------------
// *** Bucle para recorrer la lista para visualizarla
// *** Similar al creado en el punto 3)
// *** ----------------------------------

/*

1) Crear una lista enlazada vacía (definir la variable correspondiente)

2) Crear un bucle que vaya leyendo números hasta que se teclee uno 0 o negativo (bucle controlado por centinela). Por cada número leído debe de crearse un nodo y enlazarlo como primero a la lista enlazada

3) Crear un bucle para que recorra la lista, la visualice, cuente sus nodos y obtenga la suma del valor de todos los nodos

4) Crear un bucle que vaya leyendo números hasta que se teclee uno 0 o negativo (bucle controlado por centinela). Por cada número leído debe de crear un nodo y enlazarlo como ultimo a la lista enlazada. Se deben escribir dos versiones de este algoritmo
   1.- Ante cada inserción, siempre recorremos la lista desde el principio hasta localizar el último nodo. Es poco eficiente
   2.- Recorremos la lista la primera vez para localizar el ultimo nodo, y a partir de ahí, mantenemos un puntero al último nodo de forma que así hacemos más eficientes las inserciones



5) Crear un bucle que elimine todos los nodos de la lista (dejar la lista vacia)*/


//para lista vacía: OK
aborrar = lst; //apuntar al primer nodo
while (lst != NULL){
	lst = lst->sig; //1 apuntar al siguiente
	free(aborrar); //2 liberar
	aborrar = lst; //3
}
// 1 2 3 o 3 1 2 
/*
OTRA OPCIÓN: indice apunta a todos los elementos, aborrar va por detras de el liberando todos los nodos. 

indice = lst;
whule(indice != NULL){
	aborrar = indice;
	indice = indice->sig
	free(aborrar);
}
	lst = NULL; // no se modifica el valor del puntero de la lista, por eso igualamos al final a NULL
*/

/*
6) Eliminar el primer nodo de la lista



7) Eliminar el ultimo nodo de la lista



8) Insertar un nodo en orden en una lista enlazada MAS COMPLEJO: 4 ramas



9) Eliminar un nodo de la lista por su contenido

10) Devolver la información de un nodo de la lista identificado por su posición

11) Eliminar un nodo de la lista identificado por su posición

12) Insertar un nodo en la lista, en una posición indicada


*/
