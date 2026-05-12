//
//  listaEnlazadaSimple.h
//  listaEnlazadaSimple


#ifndef LISTA_ENLAZADA_SIMPLE_H
#define LISTA_ENLAZADA_SIMPLE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef int tipoInfo;

typedef tipoInfo *tipoInfoRef;




typedef struct tipoNodo {
	tipoInfo info;				
	struct tipoNodo * sig;
} tipoNodo;
typedef tipoNodo *tipoNodoRef;


typedef tipoNodo * ListaEnlazada;
typedef ListaEnlazada *ListaEnlazadaRef;


/* Funciones independientes del tipo definido como tipoInfo */

int crearVacia(ListaEnlazadaRef raiz);
int estaVacia(ListaEnlazada raiz);
int liberarListaEnlazada(ListaEnlazadaRef raiz);

int insertarAntesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info);
int insertarDespuesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info);

int eliminarNodo(ListaEnlazadaRef raiz, tipoNodoRef pos);
int insertarNodoComienzo(ListaEnlazadaRef raiz, tipoInfoRef info);
int insertarNodoFinal(ListaEnlazadaRef raiz, tipoInfoRef info);
int eliminarNodoComienzo(ListaEnlazadaRef raiz);
int eliminarNodoFinal(ListaEnlazadaRef raiz);
int insertarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice, tipoInfoRef info);
int eliminarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice);




/* Funciones dependientes del tipo definido como tipoInfo */

tipoInfo devolverInfoPosicionIndice(ListaEnlazada raiz, int indice);
int mostrarListaEnlazada(ListaEnlazada raiz);
int crearListaValoresAleatorios(ListaEnlazadaRef raiz, int numNodos);
int insertarOrdenada(ListaEnlazadaRef raiz, tipoInfoRef info);

#endif

//-------------------------------------------------------------------------------------
// EJEMPLOS DE LISTAS ENLAZADAS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _agenda {
	char nombre[20];
	char telefono[12];
	struct _agenda *siguiente;
};

 
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
