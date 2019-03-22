#include "stack.h"

using namespace stack;

/****************************************************************/
bool stack::isEmpty(const Stack &s) {
    return s == EMPTYSTACK;
}

/****************************************************************/
void stack::push(const Elem x, Stack &s) {
    pila *s1 = new pila;
    if (isEmpty(s)){
        s1->tk = x;
        s1->next = EMPTYSTACK;
        s = s1;
    }else{
        s1->tk = x;
        s1->next = s;
        s = s1;
    }
}

/****************************************************************/
Elem stack::pop(Stack &s) {
    Elem e;
    pila *s2 = new pila;
    if(!isEmpty(s)){
        s2 = s;
        s = s->next;
        e = s2->tk;
        delete s2;
    }else{
        e.k = SCONOSCIUTO;
    }
    return e;
}

/****************************************************************/