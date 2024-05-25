#pragma once
/**

	@file      Stack.c
	@brief     Ficheiro que cont�m os cabe�alhos das fun��es de gest�o de stack.
	@details   ~
	@author    Jos� Ant�nio da Cunha Alves
	@date      22.05.2024
	@copyright � Jos� Ant�nio da Cunha Alves, 2024. All right reserved.

**/

#include<stdbool.h>

typedef struct Stack {  //Nodo de stack.
	int id;
	struct Stack* prev;
	struct Stack* next;
}Stack;

//int Push(int stack[], int top, int item);
//int Pop(int stack[], int top);
//int Peek(int stack[], int top);
//bool IsStackEmpty(int top);

/**
	@brief  Fun��o que cria um nodo de stack em mem�ria.
	@param  id - ID do v�rtice a meter na stack.
	@retval    - Apontador para stack.
**/
Stack* CreateStack(int id);

/**
	@brief  Fun��o que coloca um novo nodo de stack no topo da stack.
	@param  stackTop - Apontador para o topo atual da stack.
	@param  idTop    - Novo ID a colocar no topo.
	@retval          - Apontador para o novo topo da stack.
**/
Stack* Push(Stack* stackTop, int idTop);

/**
	@brief  Fun��o que retira o topo da stack.
	@param  stackTop - Apontador para o topo da stack.
	@retval          - Apontador para o novo topo da stack.
**/
Stack* Pop(Stack* stackTop);