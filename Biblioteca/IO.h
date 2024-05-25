#pragma once

#include"Graph.h"

/**
    @brief Fun��o que mostra o ID de um v�rtice.
    @param graph - Apontador para o grafo.
    @param node  - Apontador para o v�rtice a mostrar.
**/
void ShowNode(GR* graph, Node* node);

/**
    @brief Fun��o que mostra o v�rtice de destino e o peso da respetiva adjac�ncia.
    @param id     - ID do v�rtice de destino.
    @param weight - Peso da adjac�ncia.
**/
void ShowNodeWeight(int id, int weight);

/**
    @brief Fun��o que mostra os v�rtices de origem e destino, mais o peso da sua adjac�ncia.
    @param origin  - ID do v�rtice de origem.
    @param destiny - ID do v�rtice de destino.
    @param weight  - Peso da adjac�ncia.
**/
void ShowAdjWeight(int origin, int destiny, int weight);

/**
	@brief Fun��o que mostra um grafo.
	@param graph - Apontador para o grafo a mostrar.
**/
void ShowGraph(GR* gr);