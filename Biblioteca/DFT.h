#pragma once

/**

    @file      DFT.c
    @brief     Ficheiro que cont�m os cabe�alhos das fun��es necess�rias �s opera��es DFT de um grafo.
    @details   Travessia, N�mero de caminhos entre v�rtices, V�rtice mais pr�ximo, etc.
    @author    Jos� Ant�nio da Cunha Alves
    @date      22.05.2024
    @copyright � Jos� Ant�nio da Cunha Alves, 2024. All right reserved.

**/

#include"Global.h"
#include "Stack.h"

/**
    @brief  Fun��o que verifica qual o v�rtice adjacente mais pr�ximo n�o visitado.
    @param  graph - Apontador para a estrutura do grafo.
    @param  v     - ID do v�rtice a procurar.
    @retval       - V�rtice mais pr�ximo.
**/
Node* GetClosestVerticeAdjUnvisited(GR* graph, int v);

/**
    @brief  Fun��o que faz a travessia do grafo em profundidade.
    @param  graph  - Apontador para a estrutura do grafo.
    @param  origin - ID do v�rtice de origem.
    @retval        -
**/
bool DepthFirstTraversal(GR* graph, int origin);

/**
    @brief  Fun��o que encontra um caminho em profundidade, de um determinado v�rtice at� outro.
    @param  graph   - Apontador para a estrutura do grafo.
    @param  origin  - ID do v�rtice de origem.
    @param  destiny - ID do v�rtice de destino.
    @retval         -
**/
bool DepthFirstSearch(GR* graph, int origin, int destiny, int* sum);

/**
    @brief Fun��o que coloca todos os v�rtices de um grafo como 'n�o visitado'.
    @param graph - Apontador para a estrutura do grafo.
**/
void ResetVisitedNodes(GR* graph);

/**
    @brief  Fun��o que conta o n�mero de caminhos entre dois v�rtices de um grafo.
    @param  graph     - Apontador para a estrutura do grafo.
    @param  origin    - ID do v�rtice de origem.
    @param  destiny   - ID do v�rtice de destino.
    @param  pathCount - N�mero de caminhos entre os v�rtices.
    @retval           -
**/
int CountPaths(GR* graph, int origin, int destiny, int pathCount);

/**
    @brief  Fun��o que calcula o caminho mais curto entre dois v�rtices, usando o v�rtice mais pr�ximo de cada um deles.
    @param  graph   - Apontador para a estrutura do grafo.
    @param  origin  - ID do v�rtice de origem.
    @param  destiny - ID do v�rtice de destino.
    @retval         -
**/
int BruteForceShortestPath(GR* graph, int origin, int destiny);

/**
    @brief  Fun��o que calcula a soma das das adjac�ncias.
    @param  adj - Apontador para a lista de adjac�ncias.
    @param  sum - Apontador para a soma atual.
    @retval     - Novo valor da soma.
**/
int SumAdj(AdjListNode* adj, int* sum);

//int SearchRec(GR* graph, int origin, int dest, Stack* stack);