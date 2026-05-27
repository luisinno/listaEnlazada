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

/*
9) Eliminar un nodo de la lista por su contenido

10) Devolver la información de un nodo de la lista identificado por su posición

11) Eliminar un nodo de la lista identificado por su posición

12) Insertar un nodo en la lista, en una posición indicada


*/


//-------------------------------------------------------------------------------------
// EJEMPLOS DE LISTAS ENLAZADAS: EJ
 
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
	
	
