/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

typedef struct
{
    int id;
    char marca[20];
    char modelo[20];
    float precio;
}eGuitarra;

void mostrarGuitarra(eGuitarra* guitarra);
void mostrarGuitarras(LinkedList* guitarras);

int main(void)
{
     eGuitarra* guitarra=NULL;
     LinkedList* guitarras=NULL;
     LinkedList* guitarrasSubLista=NULL;
     LinkedList* guitarrasClone=NULL;

     //Creo linked list con la fx "ll_newLinkedList()
     guitarras=ll_newLinkedList();
     if(guitarras==NULL)
     {
         exit(1);
     }else
     {
         printf("Linked list de guitarras creada exitosamente\n\n");
     }

     //Reservo espacio en la memoria dinamica para crear una estructura guitarra
     guitarra=(eGuitarra*)malloc(sizeof(eGuitarra));
     if(guitarra!=NULL)
     {
         guitarra->id=5000;
         strcpy(guitarra->marca,"Fender");
         strcpy(guitarra->modelo,"Stratocaster");
         guitarra->precio=70000;
     }

     //Se agrega guitarra al LinkedList
     if(ll_add(guitarras,guitarra)==0)
     {
         printf("Guitarra agregada a la linked list\n\n");
     }
     mostrarGuitarras(guitarras);
     printf("\n\n");

     //Muestro tamaño de la linkedlist de guitarras
     printf("Tamanio linked list guitarras: %d\n\n",ll_len(guitarras));

     //Creo otra estructura guitarra y la agrego a la linked list, y muestro el tamaño actualizado de la misma
     guitarra=(eGuitarra*)malloc(sizeof(eGuitarra));
     if(guitarra!=NULL)
     {
         guitarra->id=5001;
         strcpy(guitarra->marca,"Gibson");
         strcpy(guitarra->modelo,"Les Paul");
         guitarra->precio=100000;
     }

     if(ll_add(guitarras,guitarra)==0)
     {
         printf("Guitarra agregada a la linked list\n\n");
     }

     guitarra=(eGuitarra*)malloc(sizeof(eGuitarra));
     if(guitarra!=NULL)
     {
         guitarra->id=5002;
         strcpy(guitarra->marca,"Gibson");
         strcpy(guitarra->modelo,"SG");
         guitarra->precio=90000;
     }

     if(ll_add(guitarras,guitarra)==0)
     {
         printf("Guitarra agregada a la linked list\n\n");
     }
     mostrarGuitarras(guitarras);
     printf("\n\n");
     //Muestro tamaño de la linkedlist de guitarras actualizada
     printf("Tamanio linked list guitarras: %d\n\n",ll_len(guitarras));


     //Creo estructura guitarra y la inserto con ll_push en el indice 1
     guitarra=(eGuitarra*)malloc(sizeof(eGuitarra));
     if(guitarra!=NULL)
     {
         guitarra->id=5003;
         strcpy(guitarra->marca,"Fender");
         strcpy(guitarra->modelo,"Telecaster");
         guitarra->precio=110000;
     }
     if(ll_push(guitarras,1,guitarra)==0)
     {
         printf("Se inserto la guitarra en el indice 1\n\n");
     }
     mostrarGuitarras(guitarras);
     printf("\n\n");

     //Hago una copia de la linked list de guitarras
     guitarrasClone=ll_clone(guitarras);
     if(guitarrasClone!=NULL)
     {
         printf("Lista copiada con exito\n\n");
     }
     printf("Muestro lista original: \n");
     mostrarGuitarras(guitarras);
     printf("\n\n");
     printf("Muestro lista copiada: \n");
     mostrarGuitarras(guitarrasClone);
     printf("\n\n");

     //Reemplazo los campos de la guitarra que esta en el indice 2 con la funcion ll_set
     guitarra=(eGuitarra*)malloc(sizeof(eGuitarra));
     if(guitarra!=NULL)
     {
         guitarra->id=5004;
         strcpy(guitarra->marca,"Fender");
         strcpy(guitarra->modelo,"Firebird");
         guitarra->precio=85000;
     }
     if(ll_set(guitarras,2,guitarra)==0)
     {
         printf("Se modificaron los campos de la estructura guitarra del indice solicitado con exito\n\n");
     }
     mostrarGuitarras(guitarras);
     printf("\n\n");

     //Compruebo si la lista original contiente todos los mismos elementos que la lista copiada
     if(ll_containsAll(guitarras,guitarrasClone))
     {
         printf("Todos los elementos de la lista de guitarras original se encuentran copiados en la lista clon\n\n");
     }else
     {
         printf("Hay uno o mas elementos en la lista original que no coinciden con la lista clon\n\n");
     }
     printf("lista original: \n");
     mostrarGuitarras(guitarras);
     printf("\n\n");
     printf("lista copiada: \n");
     mostrarGuitarras(guitarrasClone);
     printf("\n\n");

     //Elimino la guitarra que se encuentra en el indice 1
     if(ll_remove(guitarras,1)==0)
     {
         printf("Se elimino la guitarra del indice 1 exitosamente\n\n");
         mostrarGuitarras(guitarras);
        printf("\n\n");
     }


     //Creo sublista con elementos del 0 al 1 de la lista original
     guitarrasSubLista=ll_subList(guitarras,0,2);
     if(guitarrasSubLista!=NULL)
     {
         printf("Se creo exitosamente la sublista con los elementos 0 y 1 de la lista original\n\n");
         mostrarGuitarras(guitarrasSubLista);
         printf("\n\n");
     }

     //Elimino todos los elementos de la lista clonada
     if(ll_clear(guitarrasClone)!=-1)
     {
         printf("Se limpio la lista con exito\n\n");
         mostrarGuitarras(guitarrasClone);
         printf("\n\n");
     }

     //Elimino la linked list original
     if(ll_deleteLinkedList(guitarras)!=-1)
     {
         printf("Se elimino la linked list con exito\n\n");
     }

     /*startTesting(1);  // ll_newLinkedList
        startTesting(2);  // ll_len
        startTesting(3);  // getNode - test_getNode
        startTesting(4);  // addNode - test_addNode
           startTesting(5);  // ll_add
        startTesting(6);  // ll_get
        startTesting(7);  // ll_set
        startTesting(8);  // ll_remove
        startTesting(9);  // ll_clear
        startTesting(10); // ll_deleteLinkedList
        startTesting(11); // ll_indexOf
        startTesting(12); // ll_isEmpty
        startTesting(13); // ll_push
        startTesting(14); // ll_pop
        startTesting(15); // ll_contains
        startTesting(16); // ll_containsAll
        startTesting(17); // ll_subList
        startTesting(18); // ll_clone
        startTesting(19); // ll_sort*/

    return 0;
}

void mostrarGuitarra(eGuitarra* guitarra)
{
    if(guitarra!=NULL)
    {
        printf("%d  %-10s  %-12s %.2f\n", guitarra->id, guitarra->marca, guitarra->modelo, guitarra->precio);
    }
}

void mostrarGuitarras(LinkedList* guitarras)
{
    int tam;
    if(guitarras!=NULL)
    {
        tam=ll_len(guitarras);
        printf(" ID   DESCRIPCION MARCA        PRECIO\n");
        for(int i=0;i<tam;i++)
        {
            mostrarGuitarra((eGuitarra*)ll_get(guitarras,i));
        }
    }
}































