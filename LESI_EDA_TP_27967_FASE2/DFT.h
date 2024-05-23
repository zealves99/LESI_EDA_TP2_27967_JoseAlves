#pragma once

/**

    @file      DFT.c
    @brief     Ficheiro que contém os cabeçalhos das funções necessárias às operações DFT de um grafo.
    @details   Travessia, Número de caminhos entre vértices, Vértice mais próximo, etc.
    @author    José António da Cunha Alves
    @date      22.05.2024
    @copyright © José António da Cunha Alves, 2024. All right reserved.

**/

#include"Global.h"

/**
    @brief  Função que verifica qual o vértice adjacente mais próximo não visitado.
    @param  graph - Apontador para a estrutura do grafo.
    @param  v     - ID do vértice a procurar.
    @retval       - Vértice mais próximo.
**/
Node* GetClosestVerticeAdjUnvisited(GR* graph, int v);

/**
    @brief  Função que faz a travessia do grafo em profundidade.
    @param  graph  - Apontador para a estrutura do grafo.
    @param  origin - ID do vértice de origem.
    @retval        -
**/
bool DepthFirstTraversal(GR* graph, int origin);

/**
    @brief  Função que encontra um caminho em profundidade, de um determinado vértice até outro.
    @param  graph   - Apontador para a estrutura do grafo.
    @param  origin  - ID do vértice de origem.
    @param  destiny - ID do vértice de destino.
    @retval         -
**/
bool DepthFirstSearch(GR* graph, int origin, int destiny);

/**
    @brief Função que coloca todos os vértices de um grafo como 'não visitado'.
    @param graph - Apontador para a estrutura do grafo.
**/
void ResetVisitedNodes(GR* graph);

/**
    @brief  Função que conta o número de caminhos entre dois vértices de um grafo.
    @param  graph     - Apontador para a estrutura do grafo.
    @param  origin    - ID do vértice de origem.
    @param  destiny   - ID do vértice de destino.
    @param  pathCount - Número de caminhos entre os vértices.
    @retval           -
**/
int CountPaths(GR* graph, int origin, int destiny, int pathCount);

/**
    @brief  Função que calcula o caminho mais curto entre dois vértices, usando o vértice mais próximo de cada um deles.
    @param  graph   - Apontador para a estrutura do grafo.
    @param  origin  - ID do vértice de origem.
    @param  destiny - ID do vértice de destino.
    @retval         -
**/
int BruteForceShortestPath(GR* graph, int origin, int destiny);