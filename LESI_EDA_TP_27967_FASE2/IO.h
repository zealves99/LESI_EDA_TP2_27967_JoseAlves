#pragma once

#include"Graph.h"

void ShowNode(GR* graph, Node* node);

void ShowNodeWeight(int id, int weight);

void ShowAdjWeight(int origin, int destiny, int weight);

/**
	@brief Função que mostra um grafo.
	@param graph - Apontador para o grafo a mostrar.
**/
void ShowGraph(GR* gr);