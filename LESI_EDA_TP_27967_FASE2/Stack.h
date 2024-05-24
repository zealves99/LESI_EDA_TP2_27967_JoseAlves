#pragma once

#include<stdbool.h>

typedef struct Stack {
	int id;
	struct Stack* prev;
	struct Stack* next;
}Stack;

int Push(int stack[], int top, int item);
int Pop(int stack[], int top);
int Peek(int stack[], int top);
bool IsStackEmpty(int top);