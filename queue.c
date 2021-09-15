#include <stdlib.h>
#include "queue.h"

//inicializa a fila
void initialize(queue *q) {
    q->first = NULL;
    q->last = NULL;
}

//desaloca toda a fila
void destroy(queue *q) {
    while(!empty(q))
        pop(q);
}

//retorna o primeiro item da fila
void* front(queue *q) {
    if(!empty(q))
        return q->first->data;
    return 0;
}

//insere novo item na fila
void push(queue *q, void* data) {
    
    //criando novo item
    qnode *n = (qnode*)malloc(sizeof(qnode));
    n->data = data;
    n->next = NULL;

    //inserindo item
    if(q->last)
        q->last->next = n;

    else q->first = n;

    q->last = n;
}

//remove primeiro item da fila
void pop(queue *q) {
    
    if(!empty(q)){

        qnode *del = q->first; //salva no a ser deletado
        q->first = del->next; //desconecta ele da fila e aponta para o proximo

        free(del); //desaloca o no deletado

        //fila vazia
        if(q->first == NULL)
            q->last = NULL;

    }
}

//verifica se a fila esta vazia
int empty(queue *q) {
    return q->first == 0;
}