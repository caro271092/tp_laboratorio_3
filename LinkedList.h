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
#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;

//linkedList estructura que contiene direcciones de memoria que conforman una lista, se autogestiona con estas f:
//Publicas
LinkedList* ll_newLinkedList(void); //crea lista en el heap=constructor
int ll_len(LinkedList* this);//largo
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement); //agrega elemento a la lista
void* ll_get(LinkedList* this, int index);//obtiene el elemento en el index indicado
int ll_set(LinkedList* this, int index,void* pElement);//setea un elemento sacando otro de la lista
int ll_remove(LinkedList* this,int index);//remueve un elemento y enlaza el elemento anterior con el siguiente al eliminado
int ll_clear(LinkedList* this);//elimina todos los nodos de la lista, lista sigue existiendo
int ll_deleteLinkedList(LinkedList* this);//elimina la lista directamente=destructor
int ll_indexOf(LinkedList* this, void* pElement);//devuelve el indice del dato informado
int ll_isEmpty(LinkedList* this);//informa si lista está vacía
int ll_push(LinkedList* this, int index, void* pElement);//agrega un elemento delante o detras del indice especificado
void* ll_pop(LinkedList* this,int index);//como un remove pero devuelve el elemento sacado (para luego poder hacer algo con él)
int ll_contains(LinkedList* this, void* pElement);//si lista contiene tal elemento
int ll_containsAll(LinkedList* this,LinkedList* this2);//si una lista contiene a otra
LinkedList* ll_subList(LinkedList* this,int from,int to);//crea una copia de un indice a otro de la lista
LinkedList* ll_clone(LinkedList* this);//duplica la lista entera(llama a sublist de 0 al len)
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//ordenar
#endif
