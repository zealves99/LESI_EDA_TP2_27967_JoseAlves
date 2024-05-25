#pragma once

#include"Graph.h"

/**
    @brief Função que mostra o ID de um vértice.
    @param graph - Apontador para o grafo.
    @param node  - Apontador para o vértice a mostrar.
**/
void ShowNode(GR* graph, Node* node);

/**
    @brief Função que mostra o vértice de destino e o peso da respetiva adjacência.
    @param id     - ID do vértice de destino.
    @param weight - Peso da adjacência.
**/
void ShowNodeWeight(int id, int weight);

/**
    @brief Função que mostra os vértices de origem e destino, mais o peso da sua adjacência.
    @param origin  - ID do vértice de origem.
    @param destiny - ID do vértice de destino.
    @param weight  - Peso da adjacência.
**/
void ShowAdjWeight(int origin, int destiny, int weight);

/**
	@brief Função que mostra um grafo.
	@param graph - Apontador para o grafo a mostrar.
**/
void ShowGraph(GR* gr);