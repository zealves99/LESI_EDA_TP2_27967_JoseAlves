/**

    @file      Stack.c
    @brief     
    @details   ~
    @author    José António da Cunha Alves
    @date      22.05.2024
    @copyright © José António da Cunha Alves, 2024. All right reserved.

**/

#include<stdio.h>
#include"Stack.h"

int Push(int stack[], int top, int item) {
    stack[++top] = item;
    return top;
}

int Pop(int stack[], int top) {
    return --top;
}

int Peek(int stack[], int top) {
    return stack[top];
}

bool IsStackEmpty(int top) {
    return (top == -1);
}