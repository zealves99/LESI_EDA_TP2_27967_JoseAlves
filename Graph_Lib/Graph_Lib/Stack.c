/**

    @file      Stack.c
    @brief     Ficheiro que contém a implementação das funções de gestão de stack.
    @details   ~
    @author    José António da Cunha Alves
    @date      22.05.2024
    @copyright © José António da Cunha Alves, 2024. All right reserved.

**/

#include<stdio.h>
#include"Stack.h"
#include<malloc.h>

/**
    @brief  Função que cria um nodo de stack em memória.
    @param  id - ID do vértice a meter na stack.
    @retval    - Apontador para stack.
**/
Stack* CreateStack(int id) {
    Stack* aux = (Stack*)malloc(sizeof(Stack));
    aux->id = id;
    aux->next = NULL;
    aux->prev = NULL;
    return aux;
}

/**
    @brief  Função que coloca um novo nodo de stack no topo da stack.
    @param  stackTop - Apontador para o topo atual da stack.
    @param  idTop    - Novo ID a colocar no topo.
    @retval          - Apontador para o novo topo da stack.
**/
Stack* Push(Stack* stackTop, int idTop) {
    Stack* aux = CreateStack(idTop);
    aux->next = stackTop;
    stackTop->prev = aux;
    stackTop = aux;
    return stackTop;
}

/**
    @brief  Função que retira o topo da stack.
    @param  stackTop - Apontador para o topo da stack.
    @retval          - Apontador para o novo topo da stack.
**/
Stack* Pop(Stack* stackTop) {
    Stack* aux = stackTop;
    stackTop = stackTop->next;
    stackTop->prev = NULL;
    free(aux);
    return stackTop;
}

//Stack* IsStackEmpty(Stack* stack)

//int Push(int stack[], int top, int item) {
//    stack[++top] = item;
//    return top;
//}

//int Pop(int stack[], int top) {
//    return --top;
//}

//int Peek(int stack[], int top) {
//    return stack[top];
//}
//
//bool IsStackEmpty(int top) {
//    return (top == -1);
//}