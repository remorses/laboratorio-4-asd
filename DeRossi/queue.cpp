#include "queue.h"

using namespace queue;


/****************************************************************/
/* 			FUNZIONI SULLE CODE 			*/
/****************************************************************/

/****************************************************************/
void queue::enqueue(Elem e, Queue &l) // aggiunge e in coda
{
    coda *s1 = new coda;
    if(isEmpty(l)){
        s1->tk = e;
        s1->next = EMPTYQUEUE;
        l = s1;
    }else{
        s1->tk = e;
        s1->next = EMPTYQUEUE;
        Queue t = l;
        while(t->next != EMPTYQUEUE){
            t = t->next;
        }
        t->next = s1;
    }
}


/****************************************************************/
Elem queue::dequeue(Queue &l) // rimuove il primo elemento e lo restituisce
{
    Elem e;
    coda *s2 = new coda;
    if(!isEmpty(l)){
        s2 = l;
        l = l->next;
        e = s2->tk;
        delete(s2);
    }else{
        e.k = SCONOSCIUTO;
    }
    return e;
}

/****************************************************************/
bool queue::isEmpty(const Queue &l) {
    return l == EMPTYQUEUE;
}

/****************************************************************/
