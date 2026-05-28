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
	*raiz=NULL;
	return 0;
}

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int
estaVacia(ListaEnlazada raiz)
{
	return (raiz==NULL);
}

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
tipoNodoRef
creaNodo(tipoInfoRef info)
{
	tipoNodoRef nuevo;

	if(NULL==(nuevo=malloc(sizeof(tipoNodo))))
	{
		return NULL;
	}
	
	nuevo->info=*info;
	nuevo->sig=NULL;
	return nuevo;
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
	tipoNodoRef nuevo;
	
	if(NULL==(nuevo=creaNodo(info)) || NULL==pos)
	return -1;

	if(estaVacia(*raiz))
	*raiz=nuevo;
	nuevo->sig=pos->sig;
	pos->sig=nuevo;
	return 0;
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
	tipoNodoRef nuevo, ant;
	
	if(NULL==(nuevo=creaNodo(info)))
	return -1;

	if(NULL==(*raiz) || NULL==raiz)
	return -1;

	ant= *raiz; //QUE ANT APUNTE A LA LISTA ENLAZADA
	if(NULL==pos)
	return -1;
	if(pos==*raiz) //INSERTAR ANTES DEL PRIMER NODO
	{
		nuevo->sig=pos;
		*raiz=nuevo;
	}

	while(ant->sig!=pos && ant->sig!=NULL)
	ant=ant->sig;

	if(NULL==ant->sig)
	return -1;
	nuevo->sig=ant->sig;
	ant->sig=nuevo;
	return 0;
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
	tipoNodoRef inicio;

	if(raiz==NULL)
	return -1;

	if(NULL==(inicio=creaNodo(info)))
	return -1;

	if(*raiz==NULL)
	{
		raiz=inicio;
		return 0;
	}
	inicio->sig=*raiz;
	*raiz=inicio;
	return 0;
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
	tipoNodoRef final,nuevo;

	if(raiz==NULL)
	return -1;

	if(NULL==(nuevo=creaNodo(info)))
	return -1;
	if(*raiz==NULL)
	{
		*raiz=nuevo;
		return 0;
	}
	final=*raiz;
	while(final->sig!=NULL)
	final=final->sig;
	nuevo->sig=final->sig;
	final->sig=nuevo;
	return 0;
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
int //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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
	tipoNodoRef ant;

	if(*raiz==NULL)
	return -1;
	ant=*raiz;
	if(pos==NULL)
	return -1;

	if(pos==*raiz)
	{
		*raiz=pos->sig;
		free(pos);
		return 0;
	}
	while(ant->sig!=NULL && ant->sig!=pos)
	ant=ant->sig;

	if(ant->sig==NULL)
	return -1;

	ant->sig=pos->sig;
	free(pos);
	return 0;
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
	tipoNodoRef aux, aBorrar;

	if(raiz==NULL || *raiz==NULL)
	return -1;

	aBorrar=*raiz;

	aux=aBorrar->sig;
	free(aBorrar);
	*raiz=aux;
	return 0;
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
	tipoNodoRef aux, aBorrar;

	if(*raiz==NULL || raiz==NULL)
	return -1;
	aBorrar=*raiz;
	if(aBorrar->sig==NULL) //UN SOLO NODO
	{
		free(aBorrar);
		*raiz=NULL;
		return 0;
	}
	while(aBorrar->sig!=NULL)
	{
		aux=aBorrar;
		aBorrar=aBorrar->sig;
	}
	free(aBorrar);
	aux->sig=NULL;
	return 0;
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
int  //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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
	tipoNodoRef aBorrar, aux;

	if(*raiz==NULL)
	return -1;

	aux=*raiz;

	while(aux!=NULL)
	{
		aBorrar=aux;
		aux=aux->sig;
		free(aBorrar);
	}
	(*raiz)=NULL;
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
tipoInfo //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
devolverInfoPosicionIndice(ListaEnlazada raiz, int indice)
{
}


/*
 * Función presentada en clase de teoría. Se debe implementar
 * la versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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



























































































// RESUELTO. pablo (indice de luis, es pos de pablo)


//
//  listaEnlazadaSimple.c
//  listaEnlazadaSimple


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaEnlazadaSimple.h"

/*
 * Crea una lista vacia
 */
int
crearVacia(ListaEnlazadaRef raiz)
{
	*raiz = NULL;

	return 0;
}

/*
 * Determina si una lista esta vacia
 */
int
estaVacia(ListaEnlazada raiz)
{
	return (raiz == NULL);
}

/*
 * Crea un nodo
 */
tipoNodoRef
creaNodo(tipoInfoRef info)
{
	tipoNodoRef nuevo;

	if((nuevo = malloc(1*sizeof(tipoNodoRef))) == NULL)
		return NULL;

	nuevo->info = *info;
	nuevo->sig = NULL;

	return nuevo;
}

/*
 * Inserta un nodo despues de otro dada su posicion
 */
int
insertarDespuesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
	tipoNodoRef nuevo, indice, anterior;

	if((nuevo = creaNodo(info)) == NULL)
		return -1;

	if(estaVacia(*raiz))
		*raiz = nuevo;
	else
	{
		indice = *raiz;
		anterior = NULL;
		while(indice != NULL && indice != pos)
		{
			anterior = indice;
			indice = indice->sig;
		}

		if(indice != NULL && pos != NULL)
		{
			nuevo->sig = pos->sig;
			pos->sig = nuevo;
		}
		else if(pos == NULL)
				anterior->sig = nuevo;
			else
			{
				free(nuevo);
				return -2;
			}

		return 0;
	}
}

/*
 * Inserta un nodo antes de otro dada su posicion
 */
int
insertarAntesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
	tipoNodoRef nuevo, anterior;

	if((nuevo = creaNodo(info)) == NULL)
		return -1;

	if((estaVacia(*raiz)) || (pos == NULL) || (pos == *raiz))
	{
		nuevo->sig = *raiz;
		*raiz = nuevo;
	}
	else
	{
		anterior = *raiz;
		while((anterior != NULL) && (anterior->sig != pos))
			anterior = anterior->sig;
		if(anterior != NULL)
		{
			nuevo->sig = pos;
			anterior->sig = nuevo;
		}
		else
		{
			free(nuevo);
			return -2;
		}

		return 0;
	}
}

/*
 * Inserta un nodo al comienzo de una lista
 */
int
insertarNodoComienzo(ListaEnlazadaRef raiz, tipoInfoRef info)
{

	tipoNodoRef nuevo;

	if((nuevo = creaNodo(info)) == NULL)
		return -1;

	nuevo->sig = *raiz;
	*raiz = nuevo;

	return 0;
}

/*
 * Inserta un nodo al final de una lista
 */
int
insertarNodoFinal(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	tipoNodoRef nuevo, indice;

	if((nuevo = creaNodo(info)) == NULL)
		return -1;

	if((estaVacia(*raiz)))
		*raiz = nuevo;
	else
	{
		indice = *raiz;
		while(indice->sig != NULL)
			indice = indice->sig;
		indice->sig = nuevo;
	}

	return 0;
}

/*
 * Esta funciÃ³n recibe una lista (por referencia), un Ã­ndice entero y una
 * variable de tipoInfo por referencia. Debe insertar un nuevo nodo
 * en la posiciÃ³n indicada por el Ã­ndice entero (implica recorrido contando
 * nodos hasta el valor indicado por indice). Ojo, hay que garantizar que 
 * esa posiciÃ³n existe, es decir, que si la lista tiene 5 nodos, (los numeramos
 * de 0 a 4), las posiciones vÃ¡lidas son 0, 1, 2, 3, 4, 5 (la posiciÃ³n 5
 * es equivalente a aÃ±adir al final).
 * Si la posiciÃ³n no existe, no se puede hacer la inserciÃ³n (en nuestro ejemplo,
 * la posiciÃ³n -1 ya no existe, y la posiciÃ³n 6 tampoco).
 * Se puede hacer uso de alguna de las funciones implementadas, aunque implique 
 * ineficiencias (recorridos adicionales de la lista enlazada). Opcional 
 * escribir una versiÃ³n eficiente que no implique repetir recorridos.
 */
int
insertarNodoPosicionIndice(ListaEnlazadaRef raiz, int pos, tipoInfoRef info)
{
	tipoNodoRef nuevo, indice, anterior;
	int numNodos;

	// Numero nodos
	numNodos = 0;
	indice = *raiz;
	while(indice != NULL)
	{
		indice = indice->sig;
		numNodos++;
	}

	if(pos < 0 || pos > numNodos)
		return -2;

	if((estaVacia(*raiz)))
	{
		*raiz = nuevo;
		return 0;
	}
	else
	{
		if(pos == numNodos)
		{
			if((insertarNodoFinal(raiz, info)) < 0)
				return -3;
			return 0;
		}
		else if(pos == 0)
			{
				if((nuevo = creaNodo(info)) == NULL)
					return -1;

				nuevo->sig = *raiz;
				*raiz = nuevo;
				return 0;
			}
			else
			{
				if((nuevo = creaNodo(info)) == NULL)
					return -1;

				indice = *raiz;
				anterior = NULL;
				numNodos = 0;
				while(pos > numNodos)
				{
					anterior = indice;
					indice = indice->sig;
					numNodos++;
				}

				anterior->sig = nuevo;
				nuevo->sig = indice;
			}
	}

	return 0;
}


/*
 * Elimina un nodo de la lista dada su posicion 
 */
int
eliminarNodo(ListaEnlazadaRef raiz, tipoNodoRef pos)
{
	tipoNodoRef anterior;

	if((estaVacia(*raiz)))
		return -1;
	else if(pos == NULL)
		return -2;
		else if(pos == *raiz)
			{
				*raiz = (*raiz)->sig;
				free(pos);
				return 0;
			}

	anterior = *raiz;
	while(anterior->sig != pos)
		anterior = anterior->sig;

	anterior->sig = pos->sig;
	free(pos);

	return 0;
}


/*
 * Elimina el primer nodo de la lista
 */
int
eliminarNodoComienzo(ListaEnlazadaRef raiz)
{
	tipoNodoRef indice;

	if((estaVacia(*raiz)))
		return -1;

	indice = *raiz;
	*raiz = (*raiz)->sig;
	free(indice);

	return 0;
	
}


/*
 * Elimina el ultimo nodo de la lista
 */
int
eliminarNodoFinal(ListaEnlazadaRef raiz)
{
	tipoNodoRef indice, anterior;

	if((estaVacia(*raiz)))
		return -1;

	indice = *raiz;
	anterior = NULL;
	while(indice->sig != NULL)
	{
		anterior = indice;
		indice = indice->sig;
	}

	if(anterior == NULL)
	{
		free(*raiz);
		*raiz = NULL;
		return 0;
	}

	anterior->sig = NULL;
	free(indice);

	return 0;
}

/*
 * Esta funciÃ³n recibe una lista (por referencia) y un Ã­ndice entero
 * Debe eliminar el nodo situado en en la posiciÃ³n indicada por el
 * Ã­ndice entero (implica recorrido contando nodos hasta el valor
 * indicado por indice). Ojo, hay que garantizar que
 * esa posiciÃ³n existe, es decir, que si la lista tiene 5 nodos (los numeramos
 * de 0 a 4), las posiciones vÃ¡lidas son 0, 1, 2, 3, 4.
 * Si la posiciÃ³n no existe, no se puede hacer la eliminaciÃ³n (en nuestro ejemplo,
 * la posiciÃ³n -1 ya no existe, y la posiciÃ³n 5 tampoco).
 * Se puede hacer uso de alguna de las funciones implementadas, aunque 
 * implique ineficiencias (recorridos adicionales de la lista enlazada). 
 * Opcional escribir una versiÃ³n eficiente que no implique repetir recorridos.
 */
int
eliminarNodoPosicionIndice(ListaEnlazadaRef raiz, int pos)
{
	tipoNodoRef nuevo, indice, anterior;
	int indNodo;

	// Numero nodos
	indNodo = 0;
	indice = *raiz;
	while(indice->sig != NULL)
	{
		indice = indice->sig;
		indNodo++;
	}

	if(pos < 0 || pos > indNodo)
		return -2;

	if((estaVacia(*raiz)))
		return -1;
	else
	{
		if(pos == 0)
		{
			indice = *raiz;
			*raiz = (*raiz)->sig;
			free(indice);
			return 0;
		}
		indice= *raiz;
		anterior = NULL;
		indNodo = 0;
		while(pos > indNodo)
		{
			anterior = indice;
			indice = indice->sig;
			indNodo++;
		}

		anterior->sig = indice->sig;
		free(indice);
	}

	return 0;
}

/*
 * Libera toda una lista
 */
int
liberarListaEnlazada(ListaEnlazadaRef raiz)
{
	tipoNodoRef aBorrar, indice;

	if((estaVacia(*raiz)))
		return -1;

	indice = *raiz;
	while(indice != NULL)
	{
		aBorrar = indice;
		indice = indice->sig;
		free(aBorrar);
	}
	*raiz = NULL;

	return 0;

}


/********************************************************************
 *                                                                  *
 * Las cuatro funciones que vienen a continuaciÃ³n dependen de cÃ³mo  *
 * estÃ¡ definido el tipo de dato tipoInfo. No es lo mismo mostrar   *
 * por pantalla el contenido de los datos almacenados en una lista  *
 * enlazada si Ã©ste es de tipo entero, o si se trata de un registro.*
 * Adicionalmente, y para que el alumno no pierda el tiempo         *
 * en implementar funciones que aportan poco desde un punto de vista*
 * docente, se proporcionan ya implementadas las funciones          *
 * mostrarListaEnlazada() y crearListaValoresAleatorios(). Las otras*
 * dos son sencillas y se dejan al alumno su implementaciÃ³n.        *
 *                                                                  *
 *******************************************************************/

/*
 * Esta funciÃ³n recibe una lista (por referencia) y un Ã­ndice entero
 * Debe devolver la informaciÃ³n almacenada en el nodo situado en la 
 * posiciÃ³n indicada por el Ã­ndice entero (implica recorrido contando nodos 
 * hasta el valor indicado por indice). Ojo, hay que garantizar que
 * esa posiciÃ³n existe, es decir, que si la lista tiene 5 nodos (los numeramos
 * de 0 a 4), las posiciones vÃ¡lidas son 0, 1, 2, 3, 4.
 * Si la posiciÃ³n no existe, no se puede devolver nada (en nuestro ejemplo,
 * la posiciÃ³n -1 ya no existe, y la posiciÃ³n 5 tampoco).
 * IMPORTANTE: tipoInfo es, en este caso particular, un entero. Aunque
 * la dependencia es pequeÃ±a, si existe. Â¿CÃ³mo se devuelve el cÃ³digo de error
 * en caso de no existir la posiciÃ³n indicada por el parÃ¡metro indice?. Si 
 * tipoInfo es un int es sencillo, si es un registro tambiÃ©n, pero ya es
 * diferente implementaciÃ³n.
 */
tipoInfo
devolverInfoPosicionIndice(ListaEnlazada raiz, int pos)
{
	tipoNodoRef nuevo, indice;
	tipoInfo info, error;
	error = -1;

	int indNodo;

	// Numero nodos
	indNodo = 0;
	indice = raiz;
	while(indice->sig != NULL)
	{
		indice = indice->sig;
		indNodo++;
	}

	if(pos < 0 || pos > indNodo)
		return error;

	if((estaVacia(raiz)))
		return error;
	else
	{
		indice = raiz;
		indNodo = 0;
		while(pos > indNodo)
		{
			indice = indice->sig;
			indNodo++;
		}

		return indice->info;
	}
}

/*
 * Inserta un nodo de forma ordenada segun su campo info
 */
int
insertarOrdenada(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	tipoNodoRef nuevo, indice, anterior;

	if((nuevo = creaNodo(info)) == NULL)
		return -1;

	if(estaVacia(*raiz))
		*raiz = nuevo;
	else
	{
		indice = *raiz;
		anterior = NULL;
		while(indice->info < nuevo->info && indice->sig != NULL)
		{
			anterior = indice;
			indice = indice->sig;
		}

		if(indice->info < nuevo->info && indice->sig == NULL)
			indice->sig = nuevo;

		else if(indice == *raiz) // anterior == NULL
			{
				nuevo->sig = indice;
				*raiz = nuevo;
			}
			else
			{
				nuevo->sig = indice;
				anterior->sig = nuevo;
			}
	}
}
/*
 * Mostrar lista enlazada
 */
int
mostrarListaEnlazada(ListaEnlazada raiz)
{
	tipoNodoRef aImprimir;
	int res = 0,i = 0;
	
	printf("\nDireccion de memoria Comienzo Lista:\t%p\n",raiz);
	printf("\n\n");
	printf("%-14s%-10s%-22s\n","  PosiciÃ³n", "Valor", "Direcion de memoria");
	printf("%-14s%-10s%-22s\n","  ==========", "======", "====================");


	aImprimir = raiz;
	while (aImprimir != NULL) {
		printf("\t%3d)\t%7d\t%10p\n",i++, aImprimir->info, aImprimir);
		aImprimir = aImprimir->sig;
	}
	return res;
}
/*
 * Crear lista con valores aleatorios
 */
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








//FICHEROS


//PABLO

/*
 * Guardar lista en fichero
 */
int guardarListaEnlazadaTexto(ListaEnlazada raiz, char *nombreFichero)
{
	FILE *f;
	int numElementos = 0;
	tipoNodoRef indice;

	if((f = fopen(nombreFichero, "w")) == NULL)
		return -1;

	indice = raiz;
	while(indice != NULL)
	{
		if((escribirArchivoDelimitado(f, indice)) == -1)
		{
			fclose(f);
			return -1;
		}

		numElementos++;
		indice = indice->sig;
	}

	if((fclose(f)) != 0)
	{
		printf("Error al cerrar el archivo\n");
		return -2;
	}

	return numElementos;
}
/*
 * Cargar lista desde fichero
 */
int cargarListaEnlazadaTexto (ListaEnlazadaRef raiz, char *nombreFichero)
{
	FILE *f;
	int numElementos = 0;

	if((f = fopen(nombreFichero, "r")) == NULL)
		return -1;

	while((leerArchivoDelimitado(f, raiz)) != EOF)
		numElementos++;

	fclose(f);

	return numElementos;
}

int escribirArchivoDelimitado(FILE *f, ListaEnlazada raiz)
{
	int numCar;

	if((numCar = (fprintf(f, "%d ", raiz->info))) < 0)
		return -1;
	else
		return numCar;
}

int leerArchivoDelimitado(FILE *f, ListaEnlazadaRef raiz)
{
	tipoInfo i;
	if((fscanf(f, "%d", &i)) == EOF)
		return (EOF);
	else
	{
		insertarNodoFinal(raiz, &i);
		return 0;
	}
}





/*
//FICHEROS JAVI

#include <stdio.h>
#include <stdlib.h>

	typedef struct Nodo
	{
	int info;
	struct Nodo *sig;
	}tipoNodo;
	
	
	int guardarListaenTexto(tipoNodo *lista, char *nombreFichero)
	{
		FILE *fp;
		tipoNodo *aux;
		int contador;
		
		if(lista==NULL)
			return -1;
		
		fp=fopen(nombreFichero, "w");
		
		if(fp==NULL)
			return -1;
			
		aux=lista;
		contador=0;
		
		while(aux!=NULL)
		{
			fprintf(fp, "%d ", aux->info);
			aux=aux->sig;
			contador++;
				
		}
		
		
		fclose(fp);
		return contador;
	}
	
	int cargarListadeTexto(tipoNodo **raiz, char *nombreFichero)
	{
		FILE *fp;
		tipoNodo *nuevo;
		tipoNodo *aux;
		int num;
		
		if(raiz == NULL)
			return -1;
			
		fp=fopen(nombreFichero, "r");
		if(fp==NULL)
			return -1;
			
		while(fscanf(fp,"%d",&num)!=EOF)
		{
			
			nuevo = malloc(sizeof(tipoNodo));
			if(nuevo==NULL)
				return -2;
			nuevo->sig = NULL;	
			nuevo->info=num;
			
			if(*raiz==NULL)
			{
				*raiz=nuevo;	
			}
			else
			{
				aux=*raiz;
				while(aux->sig!=NULL)
				{
					aux=aux->sig;
				}
				aux->sig=nuevo;
			}
			

			
		}
			
		fclose(fp);
		
		return 0;
	}
	
*/

















































































































































	
// ej res pablo

#include <stdio.h>
#include <stdlib.h>

// *** -------------------------
// *** Definicion del tipo nodo
// *** -------------------------

typedef int tipoInfo;

typedef struct tipoNodo {
	tipoInfo info;
	struct tipoNodo *sig;
} tipoNodo;

int main (void) {

// *** -------------------------------
// *** 1) Crear una lista enlazada vacía
// *** -------------------------------

	tipoNodo *lista; // Puntero de entrada a la lista enlazada

	tipoNodo *nuevo;
	tipoNodo *indice;
	tipoNodo *aborrar;
	tipoNodo *ultimo;
	tipoNodo *anterior;

	tipoInfo num;
	int cuantos;
	long suma;

	lista = NULL;

// *** -----------------------------------
// *** 2) Crear un bucle que vaya leyendo números hasta que se teclee 0 o negativo 
// ***   (bucle controlado por centinela). Por cada número leído debe de crear un nodo
// ***   y enlazarlo como PRIMERO a la lista enlazada.
// *** ----------------------------------

	printf("\n\nCREAR LISTA ENLAZANDO NODOS COMO PRIMERO\n");
	printf("-----------------------------------------\n\n");

	printf("Introduzca un valor\n(Salir: valor igual o menor que 0)\t");
	scanf("%d",&num);

	while(num > 0)
	{
		if((nuevo = malloc(1*sizeof(tipoNodo))) == NULL)
		{
			printf("Error en la reserva dinamica");
			return -1;
		}

		nuevo->info = num;
		nuevo->sig = NULL;

		nuevo->sig = lista;
		lista = nuevo;

		printf("Introduzca un valor\n(Salir: valor igual o menor que 0)\t");
		scanf("%d",&num);
	}

// *** -----------------------------------
// *** 3) Crear un bucle para que recorra la lista, la visualice, 
// ***    cuente sus nodos y obtenga la suma del valor de todos los nodos
// ***    Imprimir el numero de nodos y su suma en pantalla
// *** ----------------------------------

	printf("\nMORASTRAR INFORMACION LISTA ENLAZADA\n");
	printf("-------------------------------------\n\n");

	cuantos = 0;
	suma = 0;

	indice = lista;

	printf("Lista enlazada:\n\t");
	while(indice != NULL)
	{
		printf("%d\t",indice->info);
		cuantos++;
		suma = suma + indice->info;

		indice = indice->sig;
	}

	printf("\n");

	printf("La lista enlazada tiene %d nodos.\n", cuantos);
	printf("El valor de su suma es %ld.\n", suma);

// *** -----------------------------------
// *** 4) Crear un bucle que vaya leyendo números hasta que se teclee 0 o negativo
// ***    (bucle controlado por centinela). Por cada número leído debe de crear un nodo y enlazarlo 
// ***    como ULTIMO a la lista enlazada.
// *** ----------------------------------
// *** ----------------------------------------------------
// --- 4.1 Versión 1 del Algoritmo. Ante cada inserción, siempre recorremos la lista
// --- desde el principio hasta localizar el ultimo nodo. Es poco eficiente
// *** ----------------------------------------------------

	printf("\n\nCREAR LISTA ENLAZANDO NODOS COMO ULTIMO (algoritmo 1)\n");
	printf("-------------------------------------------------------\n\n");

	printf("Introduzca un valor\n(Salir: valor igual o menor que 0)\t");
	scanf("%d",&num);

	while(num > 0)
	{
		if((nuevo = malloc(1*sizeof(tipoNodo))) == NULL)
		{
			printf("Error en la reserva dinamica");
			return -1;
		}

		nuevo->info = num;
		nuevo->sig = NULL;

		indice = lista;
		if(indice == NULL)
			lista = nuevo;
		else
		{
			while(indice->sig != NULL)
				indice = indice->sig;

			indice->sig = nuevo;
		}

		printf("Introduzca un valor\n(Salir: valor igual o menor que 0)\t");
		scanf("%d",&num);
	}


// *** --------------------------
// *** Visualizacion de la lista
// *** --------------------------

	printf("\nMORASTRAR INFORMACION LISTA ENLAZADA\n");
	printf("-------------------------------------\n\n");

	indice = lista;

	printf("Lista enlazada:\n\t");
	while(indice != NULL)
	{
		printf("%d\t",indice->info);

		indice = indice->sig;
	}

	printf("\n");

// *** ----------------------------------------------------
// --- 4.2 Versión 2 del Algoritmo. Recorremos la lista la primera vez para localizar el ultimo
// --- nodo, y a partir de ahí, mantenemos un puntero al ultimo nodo de forma que asi hacemos
// --- más eficientes las inserciones.
// *** ---------------------------------------------------- 

	printf("\n\nCREAR LISTA ENLAZANDO NODOS COMO ULTIMO (algoritmo 2)\n");
	printf("-------------------------------------------------------\n\n");

	// El ultimo nodo está apuntado por "ultimo"
	ultimo = lista;
	if(lista != NULL)
	{
		while(ultimo->sig != NULL)
			ultimo = ultimo->sig;
	}

	printf("Introduzca un valor\n(Salir: valor igual o menor que 0)\t");
	scanf("%d",&num);

	while(num > 0)
	{
		if((nuevo = malloc(1*sizeof(tipoNodo))) == NULL)
		{
			printf("Error en la reserva dinamica");
			return -1;
		}

		nuevo->info = num;
		nuevo->sig = NULL;

		if(lista == NULL)
		{
			lista = nuevo;
			ultimo = nuevo; // Siempre dejamos apuntado el ultimo nodo
		}
		else
		{
			ultimo->sig = nuevo;
			ultimo = nuevo; // Siempre dejamos apuntado el ultimo nodo
		}

		printf("Introduzca un valor\n(Salir: valor igual o menor que 0)\t");
		scanf("%d",&num);
	}

// *** --------------------------
// *** Visualizacion de la lista
// *** --------------------------

	printf("\nMORASTRAR INFORMACION LISTA ENLAZADA\n");
	printf("-------------------------------------\n\n");

	indice = lista;

	printf("Lista enlazada:\n\t");
	while(indice != NULL)
	{
		printf("%d\t",indice->info);

		indice = indice->sig;
	}

	printf("\n");

// *** ---------------------------------------
// *** 5) Eliminar el primer nodo de la lista
// *** ---------------------------------------

	if(lista != NULL)
	{
		indice = lista;
		lista = lista->sig;

		free(indice);
		indice = NULL;
	}

// *** --------------------------
// *** Visualizacion de la lista
// *** --------------------------

	printf("\nMORASTRAR INFORMACION LISTA ENLAZADA (Eliminacion PRIMER elemento)\n");
	printf("-------------------------------------\n\n");

	indice = lista;

	printf("Lista enlazada:\n\t");
	while(indice != NULL)
	{
		printf("%d\t",indice->info);

		indice = indice->sig;
	}

	printf("\n");

// *** ---------------------------------------
// *** 6) Eliminar el último nodo de la lista
// *** ---------------------------------------

	indice = lista;
	ultimo = lista->sig;
	if(lista != NULL && lista->sig == NULL)
	{
		free(lista);
		lista = NULL;
	}
	else if(lista != NULL)
		{
			while(ultimo->sig != NULL)
			{
				indice = indice->sig;
				ultimo = ultimo->sig;
			}

			free(ultimo);
			ultimo = NULL;
			indice->sig = NULL;
		}

// *** --------------------------
// *** Visualizacion de la lista
// *** --------------------------

	printf("\nMORASTRAR INFORMACION LISTA ENLAZADA (Eliminacin ULTIMO elemento)\n");
	printf("-------------------------------------\n\n");

	indice = lista;

	printf("Lista enlazada:\n\t");
	while(indice != NULL)
	{
		printf("%d\t",indice->info);

		indice = indice->sig;
	}

	printf("\n");

// *** -----------------------------------
// *** 7) Insertar un nodo en orden en una lista enlazada:
// ***    a) Eliminar la lista enlazada que tengamos construida hasta este momento.
// ***    b) Crear un bucle que vaya leyendo números hasta que se teclee 0 o negativo
// ***    (bucle controlado por centinela). Por cada número leído debe de crear un nodo y enlazarlo 
// ***    en la posición que le correspnda dentro de la lista enlazada. De esta forma, la lista se ira 
// ***    creando siempre de forma ordenada
// *** -----------------------------------

	printf("\n\nCREAR LISTA ENLAZANDO ORDENADA\n");
	printf("-------------------------------\n\n");

	// Eliminacion Lista Enlazada
	aborrar = lista;
	while(lista != NULL)
	{
		lista = lista->sig;

		free(aborrar);
		aborrar = lista;
	}

	// Creacion nueva Lista Ordenada
	printf("Introduzca un valor\n(Salir: valor igual o menor que 0)\t");
	scanf("%d",&num);

	while(num > 0)
	{
		if((nuevo = malloc(1*sizeof(tipoNodo))) == NULL)
		{
			printf("Error en la reserva dinamica");
			return -1;
		}

		nuevo->info = num;
		nuevo->sig = NULL;

		if(lista == NULL)
			lista = nuevo;
		else
		{
			indice = lista;
			anterior = NULL;
			while(indice->info < nuevo->info && indice->sig != NULL) //con un puntero ..->sig->sig
			{
				anterior = indice;
				indice = indice->sig;
			}

			if(indice->info < nuevo->info && indice->sig == NULL)
				indice->sig = nuevo;

			else if(/*indice->info >= nuevo->info &&*/ lista == indice) // anterior == NULL
				{
					nuevo->sig = indice;
					lista = nuevo;
				}
				else /*if(indice->info >= nuevo->info)*/
					{
						nuevo->sig = indice;
						anterior->sig = nuevo;
					}
		}

		printf("Introduzca un valor\n(Salir: valor igual o menor que 0)\t");
		scanf("%d",&num);
	}

// *** --------------------------
// *** Visualizacion de la lista
// *** --------------------------

	printf("\nMORASTRAR INFORMACION LISTA ENLAZADA ORDENADA\n");
	printf("----------------------------------------------\n\n");

	indice = lista;

	printf("Lista enlazada:\n\t");
	while(indice != NULL)
	{
		printf("%d\t",indice->info);

		indice = indice->sig;
	}

	printf("\n");

/*
// *** -------------------------------------------------
// *** 8) Eliminar un nodo de la lista por su contenido
// *** -------------------------------------------------

	printf("\n\nELIMINAR VALOR DE LA LISTA\n");
	printf("---------------------------\n\n");

	// Creacion nueva Lista Ordenada
	while(num <= 0)
	{
		printf("Introduzca un valor\n(Salir: valor igual o menor que 0)\t");
		scanf("%d",&num);
	}

	
	if(lista == NULL)
		printf("\nLista vacia\n");
	else
	{
		indice = lista;
		anterior = indice;
		while(indice != NULL)
		{
			if(indice->info == num)
			{
				if(indice == lista)
				{
					lista = lista->sig;
					free(indice);
				}
				else
				{
					anterior->sig = indice->sig;
					free(indice);
					indice = anterior;
				}
			}

			anterior = indice;
			indice = indice->sig;
		}
	}

// *** --------------------------
// *** Visualizacion de la lista
// *** --------------------------

	printf("\nMORASTRAR INFORMACION LISTA ENLAZADA ORDENADA SIN EL VALOR\n");
	printf("----------------------------------------------------------\n\n");

	indice = lista;

	printf("Lista enlazada:\n\t");
	while(indice != NULL)
	{
		printf("%d\t",indice->info);

		indice = indice->sig;
	}

	printf("\n");

// *** -----------------------------------
// *** 9) Devolver el campo información de un nodo identificado por su posicion en la lista
// ***     Debe obtenerse la información almacenada en el nodo situado en la posición indicada 
// ***     por un índice entero (0 para primer nodo, 1 para segundo, 2 para tercero, etc, ...)
// ***     Implica recorrido contando nodos hasta el valor indicado por índice. 
// ***     Atención, hay que garantizar que esa posición existe, es decir, que si la lista 
// ***     tiene 4 nodos (los numeramos de 0 a 3), las posiciones válidas son 0, 1, 2, 3. 
// ***     Si la posición no existe, no se puede devolver nada (en nuestro ejemplo, la posición -1
// ***     o cualquier otro número negativo, no existe, y la posición 4 y superiores tampoco).
// *** -----------------------------------

	printf("\n\nDEVOLVER INFORMACION NODO\n");
	printf("-------------------------\n\n");

	if(lista != NULL)
	{
		// Numero nodos
		cuantos = 0;
		indice = lista;
		while(indice != NULL)
		{
			indice = indice->sig;
			cuantos++;
		}

		// Introducir numero de nodo
		num = -1;
		while(num < 0 || num > cuantos)
		{
			printf("Introduzca un valor\n(Mayor o igual que 0 y menor o igual que %d)\t",cuantos-1);
			scanf("%d",&num);
		}

		// Busequeda del dato
		cuantos = 0;
		indice = lista;
		while(num > cuantos)
		{
			indice = indice->sig;
			cuantos++;
		}

		printf("Dato de la posicion %d de la lista:\t%d\n", num, indice->info);
	}

// *** -----------------------------------
// *** 10) Eliminar un nodo identificado por su posicion en la lista
// ***     Debe eliminarse el nodo situado en la posición indicada por un índice entero
// ***     (0 para primer nodo, 1 para segundo, 2 para tercero, etc, ...)
// ***     Implica recorrido contando nodos hasta el valor indicado por índice.
// ***     Atención, hay que garantizar que esa posición existe, es decir, que si la lista 
// ***     tiene 4 nodos (los numeramos de 0 a 3), las posiciones válidas son 0, 1, 2, 3. 
// ***     Si la posición no existe, no se hace nada.
// *** -----------------------------------

	printf("\n\nELIMINAR NODO POR POSICION\n");
	printf("---------------------------\n\n");

	if(lista != NULL)
	{
		// Numero nodos
		cuantos = 0;
		indice = lista;
		while(indice != NULL)
		{
			indice = indice->sig;
			cuantos++;
		}

		// Introducir numero de nodo
		num = -1;
		while(num < 0 || num > cuantos)
		{
			printf("Introduzca un valor\n(Mayor o igual que 0 y menor o igual que %d)\t",cuantos-1);
			scanf("%d",&num);
		}

		// Busequeda del dato
		cuantos = 0;
		anterior = NULL;
		indice = lista;
		while(num > cuantos)
		{
			anterior = indice;
			indice = indice->sig;
			cuantos++;
		}

		if(indice == lista)
		{
			lista = lista->sig;
			free(indice);
			indice = NULL;
		}
		else
		{
			anterior->sig = indice->sig;
			free(indice);
			indice = NULL;
		}
	}

// *** --------------------------
// *** Visualizacion de la lista
// *** --------------------------

	printf("\nMORASTRAR INFORMACION LISTA ENLAZADA\n");
	printf("------------------------------------\n\n");

	indice = lista;

	printf("Lista enlazada:\n\t");
	while(indice != NULL)
	{
		printf("%d\t",indice->info);

		indice = indice->sig;
	}

	printf("\n");

// *** -----------------------------------
// *** 11) Insertar un nodo identificado por su posicion en la lista
// ***     (0 para primer nodo, 1 para segundo, 2 para tercero, etc, ...)
// ***     Si la posicion no existe el nodo se inserta como ultimo.
// ***     Por ejemplo, sila lista tiene 4 nodos (los numeramos de 0 a 3), y se 
// ***     ha indicado como posicion 6, el nodo se inserta ultimo
// *** -----------------------------------

	printf("\n\nINSERTAR NODO POR POSICION\n");
	printf("---------------------------\n\n");

	if(lista != NULL)
	{
		// Numero nodos
		cuantos = 0;
		indice = lista;
		while(indice != NULL)
		{
			indice = indice->sig;
			cuantos++;
		}

		// Introducir numero de nodo
		pos = -1;
		while(pos < 0)
		{
			printf("Introduzca un valor\n(Mayor o igual que 0)\t");
			scanf("%d",&pos);
		}
	
		num = -1;
		while(num <= 0)
		{
			printf("Introduzca un valor\n(Salir: valor igual o menor que 0)\t");
			scanf("%d",&num);
		}

		if((nuevo = malloc(1*sizeof(tipoNodo))) == NULL)
		{
			printf("Error en la reserva dinamica");
			return -1;
		}

		nuevo->info = num;
		nuevo->sig = NULL;

		// Busequeda del dato
		anterior = NULL;
		indice = lista;
		if(pos > cuantos)
		{
			while(indice->sig != NULL)
				indice = indice->sig;
			indice->sig = nuevo;
		}
		else
		{
			cuantos = 0;
			while(pos > cuantos)
			{
				anterior = indice;
				indice = indice->sig;
				cuantos++;
			}

			if(indice == lista)
			{
				nuevo->sig = indice;
				lista = nuevo;
			}
			else
			{
				anterior->sig = nuevo;
				nuevo->sig = indice;
			}
		}
	}

// *** --------------------------
// *** Visualizacion de la lista
// *** --------------------------

	printf("\nMORASTRAR INFORMACION LISTA ENLAZADA\n");
	printf("------------------------------------\n\n");

	indice = lista;

	printf("Lista enlazada:\n\t");
	while(indice != NULL)
	{
		printf("%d\t",indice->info);

		indice = indice->sig;
	}

	printf("\n");*/

// *** -----------------------------------
// *** ULTIMO (5) 12) Bucle para eliminar cada uno de los nodos de la lista enlazada
// *** Al finalizar este algoritmo lst queda con valor NULL
// *** -----------------------------------

	printf("\nELIMINAR LISTA ENLAZADA\n");
	printf("------------------------\n\n");

	aborrar = lista;
	while(lista != NULL)
	{
		lista = lista->sig;

		free(aborrar);
		aborrar = lista;
	}

	lista = NULL;
	nuevo = NULL;
	indice = NULL;
	ultimo = NULL;
	aborrar = NULL;

   printf("\n");
   system ("pause");
   return 0;

}


/*//clase luis 2025, mismo ej_________________________________________________________________________________


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



5) Crear un bucle que elimine todos los nodos de la lista (dejar la lista vacia)


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



//6) Eliminar el primer nodo de la lista

//también es válido si solo tiene 1 nodo o si está vacia

if (lst != NULL){
	aborrar = lst;
	lst = lst->sig;
	free(aborrar);
}

//7) Eliminar el ultimo nodo de la lista

if (lst != NULL){
	ultimo = lst;
	anterior = NULL;
while (ultimo->sig != NULL){
	anterior = ultimo;
	ultimo = ultimo->sig;
	}
if (anterior == NULL) {
	free (lst);
	lst = NULL;//resolvemos si solo hay un nodo 
	} else{
	free(ultimo);
	anterior->sig = NULL; // error si solo hay un nodo
	}
}
//ROBUSTEZ (vacia ok), si solo hay uno 







//8) Insertar un nodo en orden en una lista enlazada MAS COMPLEJO: 4 ramas


//si la lista está vacía, el nodo que acabo de crear es el primero
if (lst == NULL) {
	lst = nuevo;
}

// en otro caso, recorremos la lista con DOS PUNTEROS, que apunten a los nodos entre los que inserto el nuevo
else { //lista no vacía
	indice = lst;
	anterior = NULL;
	while ( (indice->info < nuevo->info)&& (indice->sig != NULL)){
		anterior = int indice;
		indice = indice->sig;
	} //hemos encontrado los nodos a los que apuntaremos entre los que metemos el nuevo
//resolver ERROR 1
//el nodo se inserta como primero
	if (anterior == NULL) {
	nuevo->sig = lst;
	lst = nuevo;
}
//resolver error 2
else if ((indice->sig==NULL)&&(indice->info < nuevo->info)){
//el nodo se inserta al final 
	nuevo->sig = NULL;
	indice->sig= nuevo;
}

else { //el nodo se inserta en medio de la lista
		nuevo->sig= indice; //ERROR 2; (si apunta al último, lo esta apuntando delante, y lo quiero detras)
		anterior->sig= nuevo; //ERROR 1 (si apunta al primero)

}


// FIN


9) Eliminar un nodo de la lista por su contenido

10) Devolver la información de un nodo de la lista identificado por su posición

11) Eliminar un nodo de la lista identificado por su posición

12) Insertar un nodo en la lista, en una posición indicada


*/






















//-------------------------------------------------------------------------------------
// NAVIA EJEMPLOS DE LISTAS ENLAZADAS: EJ
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINIR STRUCT: NODO

struct _agenda {
	char nombre[20];
	char telefono[12];
	struct _agenda *siguiente;
};

 
// MOSTRAR MENU 


void mostrar_menu()
 {
	fflush(stdout);
	printf("\n\nMenu:\n=====\n\n");
	printf("1.- ANadir elementos\n");
	printf("2.- Borrar elementos\n");
	printf("3.- Mostrar lista\n");
	printf("4.- Salir\n\n");
	printf("Escoge una opcion: ");
}
/* Con esta funcion se anade un elemento al final de la lista */
void anadir_elemento(struct _agenda **primero)
 {
	struct _agenda *nuevo, *ant, *aux=*primero;
	/* Se reserva memoria para el nuevo elemento */
	nuevo = (struct _agenda *) malloc (sizeof(struct _agenda));
	if (nuevo==NULL)
	{
		printf( "No hay memoria disponible!\n");
		exit(0);

	}
	
 	printf("\nNombre a incluir: ");
	scanf("%s%*c",nuevo->nombre);
	printf("\nTelefono: ");
	scanf("%s",nuevo->telefono);
	
       /* Ahora se introduce el nuevo elemento en la lista.
	Se situa al final de la lista */
	if (*primero==NULL) {
		printf( "Primer elemento\n");
		*primero = nuevo;
        nuevo->siguiente=NULL;
	}
      else
        { 
         if ((strcmp(nuevo->nombre, aux->nombre))<0) 
          {
            nuevo->siguiente=*primero;
            *primero=nuevo;
          }
         else
          {
           ant=NULL;
           while(aux!=NULL && strcmp(nuevo->nombre, aux->nombre)>0)  
           {
             ant=aux;
             aux=aux->siguiente;
           }
           if (aux==NULL)
           {
              ant->siguiente=nuevo;
              nuevo->siguiente=NULL;
          }
          else
          {
              nuevo->siguiente=aux;
              ant->siguiente=nuevo;
          }
         }
    }
}

// ELIMINAR LISTA

void eliminar_lista(struct _agenda **primero, char *nombre) 
{

     struct _agenda *auxiliar, *ant=NULL; /* Para recorrer la lista */
	 int lon=20;	 
	 nombre=(char *)malloc(lon *sizeof(char));
 	 printf("\nNombre a eliminar: ");
	 scanf("%s",nombre);
	 getchar();
 	for (auxiliar=*primero;auxiliar!=NULL && (strcmp(auxiliar->nombre, nombre)!=0);ant= auxiliar,auxiliar = auxiliar->siguiente);
	{
		if(!strcmp(auxiliar->nombre, nombre)==0)
	    {
         printf("\nNo se encontro ");
         }
         else
         {
             printf("\n Encontro el nombre");
             if(ant==NULL)
             { 
		       if (auxiliar->siguiente == NULL)
		       {
                *primero=NULL; /*es el primero y el unico*/
                free(ant);
                }   
	           else
		       {
		        auxiliar = auxiliar->siguiente;/*es el primero*/
                *primero=auxiliar;
                free(ant);
                }
             }   
	    	else
		    {
		      if (auxiliar->siguiente == NULL)
		      {
			  /*Es el ultimo*/
			  ant->siguiente=NULL;
			  free(auxiliar);
			 }
	         else 
		    {
		     ant->siguiente=auxiliar->siguiente;
		     free(auxiliar);
		     		 }
     }
	}
  }

}


// MOSTRAR LISTA
 
void mostrar_lista(struct _agenda *primero) 
{
	struct _agenda *auxiliar; /* Para recorrer la lista */
	int i;
	i=0;
	auxiliar = primero;
 	printf("\nMostrando la lista completa:\n");
	while (auxiliar!=NULL)
	{
		printf("Nombre: %s, Telefono: %s\n",
		auxiliar->nombre, auxiliar->telefono);
		auxiliar = auxiliar->siguiente;
		i++;
	}
if (i==0) printf( "\nLa lista esta  vacia!!\n" );
}
int main()
{
 
  struct _agenda *primero = NULL;
  struct _agenda *ultimo = NULL;

  char opcion;
  char *nombre="";
  do 
  {
    fflush(stdout);
    mostrar_menu();
    fflush(stdin);
    opcion = getchar();
    switch ( opcion )
	{
      case '1':
           {
            anadir_elemento(&primero);
	         break;
          }
      case '2':{
            eliminar_lista(&primero,nombre) ;
	        break;
         }
      case '3': {
               mostrar_lista(primero);
	           break;
            }
      case '4': exit( 1 );
      default:{
                printf( "Opcion no valida\n" );
	            break;
             }
}
} while (opcion!='4');
}










//------------------------------------------------------------------------------------------------------------------------------------------

//EJERCICIO 15

int guardarListaEnlazadaTexto(ListaEnlazada raiz, char *nombreFichero)
{
	tipoNodoRef aux;
	int contador,i,total_car;
	FILE *f;

	if(NULL==(f=fopen(nombreFichero, "w")))
	return -1;

	if(raiz==NULL)
	{
		fclose(f);
		return -1;
	}
	
	aux=raiz;
	total_car=contador=0;
	while(aux!=NULL)
	{
		if(aux->sig==NULL)
		{
			contador=fprintf(f,"%d",aux->info);
		}
		else
		{
			contador=fprintf(f,"%d\t",aux->info);
		}
		
		if(contador<0)
		{
			fclose(f);
			return -1;
		}
		total_car+=contador;
		aux=aux->sig;
	}

	fclose(f);
	return total_car;
	
}

int cargarListaEnlazadaTexto(ListaEnlazadaRef raiz, char *nombreFichero)
{
    tipoNodoRef aux, nuevo, ant;
    int valido, total_nodos, dato, flag, flag2;
    FILE *f;

    // 1. Abrimos archivo (sin exigir que *raiz sea NULL)
    if (NULL == (f = fopen(nombreFichero, "r")))
    {
        *raiz = NULL;
        return -1;
    }
    
    *raiz = NULL; // Inicializamos la lista vacía para cargar los datos
    flag = 1;
    total_nodos = 0;

    // El bucle se controla exclusivamente por la variable 'flag'
    while (flag == 1)
    {
        valido = fscanf(f, "%d", &dato);
        
        if (valido == EOF) 
        {
            flag = 0; // FIN DE ARCHIVO: Apagamos el flag para que el bucle termine limpiamente
        }
        else if (valido <= 0) 
        {
            flag = -1; // ERROR DE LECTURA: Usamos un valor especial para detectar el fallo fuera
        }
        else 
        {
            // LECTURA CORRECTA: Intentamos reservar memoria para el nodo
            if (NULL == (nuevo = malloc(sizeof(tipoNodo)))) 
            {
                flag = -2; // ERROR DE MEMORIA: Apagamos el bucle
            }
            else 
            {
                total_nodos++;
                nuevo->sig = NULL;
                nuevo->info = dato;

                // LOGICA DE INSERCIÓN ORDENADA
                if (*raiz == NULL) 
                {
                    *raiz = nuevo;
                }
                else
				{
					aux = *raiz;
					ant = NULL;

					// 1. Buscamos el sitio usando el propio aux para avanzar
					while (aux != NULL && aux->info < nuevo->info) 
					{
						ant = aux;
						aux = aux->sig;
					}

					// 2. Una vez salimos del bucle, insertamos según dónde haya quedado aux
					if (ant == NULL) 
					{
						// Si ant sigue siendo NULL, significa que el nuevo número es el menor de todos
						// y el bucle while de arriba ni siquiera llegó a dar una vuelta.
						nuevo->sig = *raiz;
						*raiz = nuevo;
					}
					else 
					{
						// Si ant NO es NULL, se inserta en medio o al final de la lista (da igual si aux es NULL o no)
						nuevo->sig = aux;
						ant->sig = nuevo;
					}
				}
            }
        }
    }

    // Cerramos el archivo siempre antes de salir
    fclose(f);

    // Evaluamos cómo terminó el bucle según el valor de 'flag'
    if (flag == 0) {
        return total_nodos; // Todo fue bien
    } else if (flag == -1) {
        return -2; // Error de lectura (ej. una letra en el archivo)
    } else {
        return total_nodos; // Error de memoria (devolvemos lo que se pudo salvar)
    }
}#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoInfo {
    char palabra[20];
    int fil, col, numCar;
} tipoInfo;

typedef struct tipoNodo {
    tipoInfo info;
    struct tipoNodo *sig;
} tipoNodo;

typedef tipoNodo *ListaEnlazada;         // Puntero a tipoNodo
typedef ListaEnlazada *ListaEnlazadaRef; // Puntero a puntero a tipoNodo

typedef struct {
    char **m;
    int numFil, numCol;
} matChar;

matChar *generarSopaLetras(ListaEnlazada *raiz, int nFil, int nCol, int *codError) {
    int i, j;

    // Si la lista esta vacia, se devuelve error
    if (*raiz == NULL) {
        *codError = -1;
        return NULL;
    }

    // Reserva dinamica de la matriz de palabras
    matChar *palabras = malloc(sizeof(matChar));
    if (palabras == NULL) {
        *codError = -2;
        return NULL;
    }

    palabras->m = malloc(nFil * sizeof(char*));
    if (palabras->m == NULL) {
        free(palabras);
        *codError = -3;
        return NULL;
    }

    for (i = 0; i < nFil; i++) {
        palabras->m[i] = malloc(nCol * sizeof(char));
        if (palabras->m[i] == NULL) {
            // Rollback en caso de fallo
            for (j = i - 1; j >= 0; j--) {
                free(palabras->m[j]);
            }
            free(palabras->m);
            free(palabras);
            *codError = -4;
            return NULL;
        }
    }

    // Asignar nfil y ncol
    palabras->numFil = nFil;
    palabras->numCol = nCol;

    // Llenar la matriz con asteriscos
    for (i = 0; i < nFil; i++) {
        for (j = 0; j < nCol; j++) {
            palabras->m[i][j] = '*';
        }
    }

    // Colocar las palabras en la sopa con las condiciones
    ListaEnlazada actual = *raiz;
    ListaEnlazada anterior = NULL;

    while (actual != NULL) {
        if (actual->info.col < nCol && (actual->info.fil + actual->info.numCar) <= nFil) {
            // La palabra cabe, se inserta verticalmente
            for (i = 0; i < actual->info.numCar; i++) {
                palabras->m[actual->info.fil + i][actual->info.col] = actual->info.palabra[i];
            }
            anterior = actual;
            actual = actual->sig;
        } else {
            // La palabra NO cabe, se extrae el nodo y se borra
            ListaEnlazada aBorrar = actual;
            if (anterior == NULL) {
                *raiz = (*raiz)->sig;
            } else {
                anterior->sig = actual->sig;
            }
            actual = actual->sig;
            free(aBorrar);
        }
    }

    // Rellenar huecos vacíos con letras aleatorias
    for (i = 0; i < nFil; i++) {
        for (j = 0; j < nCol; j++) {
            if (palabras->m[i][j] == '*') {
                palabras->m[i][j] = 'A' + rand() % 26;
            }
        }
    }

    *codError = 0;
    return palabras;
}

int escribirListaEnFichero(ListaEnlazada lista, char *nombreFichero) {
    ListaEnlazada actual = lista;
    FILE *fp;
    int cont = 0;

    fp = fopen(nombreFichero, "w");
    if (fp == NULL) {
        printf("ERROR. No se pudo abrir el fichero.\n");
        return -1;
    } else {
        while (actual != NULL) {
            fprintf(fp, "%-19s (%4d , %4d) %4d\n",
                    actual->info.palabra,
                    actual->info.fil,
                    actual->info.col,
                    actual->info.numCar);
            cont++;
            actual = actual->sig;
        }
        fclose(fp);
        return cont;
    }
}

int main(void) {
    ListaEnlazada raiz = NULL;
    matChar *sopa;
    int numFilas = 10, numCols = 10;
    int error;

    // -------------------------------
    // Crear algunos nodos de ejemplo en el Heap
    // -------------------------------
    
    // Nodo 1
    ListaEnlazada nodo1 = malloc(sizeof(tipoNodo));
    strcpy(nodo1->info.palabra, "CARTA");
    nodo1->info.fil = 2;
    nodo1->info.col = 1;
    nodo1->info.numCar = strlen(nodo1->info.palabra);
    nodo1->sig = NULL;
    raiz = nodo1;

    // Nodo 2
    ListaEnlazada nodo2 = malloc(sizeof(tipoNodo));
    strcpy(nodo2->info.palabra, "LUNA");
    nodo2->info.fil = 0;
    nodo2->info.col = 3;
    nodo2->info.numCar = strlen(nodo2->info.palabra);
    nodo2->sig = NULL;
    nodo1->sig = nodo2;

    // -------------------------------
    // Generar sopa de letras
    // -------------------------------
    sopa = generarSopaLetras(&raiz, numFilas, numCols, &error);
    
    if (error != 0) {
        printf("Error al generar sopa de letras (código %d)\n", error);
        return 1;
    }

    // Mostrar la sopa por pantalla
    printf("\nSopa de letras generada:\n\n");
    for (int i = 0; i < sopa->numFil; i++) {
        for (int j = 0; j < sopa->numCol; j++) {
            printf("%c ", sopa->m[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    // -------------------------------
    // Guardar lista en fichero
    // -------------------------------
    int numEscritos = escribirListaEnFichero(raiz, "palabras.txt");
    if (numEscritos == -1) {
        printf("No se pudo escribir el archivo.\n");
    } else {
        printf("Se escribieron %d palabras en el archivo.\n", numEscritos);
    }
    printf("\n");

    // -------------------------------
    // Liberar memoria (Evitar Fugas)
    // -------------------------------
    
    // 1. Liberar Matriz
    for (int i = 0; i < sopa->numFil; i++) {
        free(sopa->m[i]);
    }
    free(sopa->m);
    free(sopa);

    // 2. Liberar Lista Enlazada
    while (raiz != NULL) {
        ListaEnlazada tmp = raiz;
        raiz = raiz->sig;
        free(tmp);
    }

    return 0;
}