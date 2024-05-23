#pragma once

#include<stdbool.h>

int Push(int stack[], int top, int item);
int Pop(int stack[], int top);
int Peek(int stack[], int top);
bool IsStackEmpty(int top);