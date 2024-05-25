#pragma once
/**

	@file      Graph.c
	@brief     Ficheiro que contém õs cabeçalhos das funções de gestão de grafos.
	@details   ~
	@author    José António da Cunha Alves
	@date      12.05.2024
	@copyright © José António da Cunha Alves, 2024. All right reserved.

**/

#include<stdbool.h>

#pragma region Estruturas 
//Node da lista de adjacencias.
typedef struct AdjListNode {
	int value;
	int weight; //peso
	struct AdjListNode* next;
}AdjListNode;

//Vertice
typedef struct Node {
	int value;
	struct Node* nextNode; //apontador para o proximo vertice.
	AdjListNode* next; //apontador para a lista de adjacencias.
	bool visited;
	int numAdj;
}Node;

//Grafo
typedef struct GR {
	Node* headGraph; //lista vertices.
	int numNodes;
}GR;

#pragma endregion

#pragma region Gestão de Vértices

/**
	@brief  Função que cria um nodo.
	@param  value - Valor a atribuir ao nodo.
	@retval       - Apontador para o nodo.
**/
Node* CreateNode(int value);

/**
	@brief  Função que verifica se um nodo existe na memória.
	@param  head  - Apontador para o início da lista de nodos.
	@param  value - Valor do vértice a encontrar.
	@retval true - O nodo existe.
	@retval false - O nodo não existe.
**/
bool ExistNode(Node* head, int value);

/**
	@brief  Função que insere um nodo na lista de nodos.
	@param  head    - Apontador para o início da lista de nodos.
	@param  newNode - Apontador para o nodo a adicionar à lista.
	@param  res     - Variável de controlo de sucesso.
	@retval         - Apontador para a lista de nodos.
**/
Node* InsertNode(Node* head, Node* newNode, bool* res);

/**
	@brief  Função que elimina um nodo da lista de nodos.
	@param  head    - Apontador para o início da lista de nodos.
	@param  codNode - Valor do nodo a eliminar.
	@param  res     - Variável de controlo de sucesso.
	@retval         - Apontador para o início da lista de nodos.
**/
Node* DeleteNode(Node* head, int codNode, bool* res);

/**
	@brief  Função que procura a posição de um nodo na lista de nodos.
	@param  head  - Apontador para o início da lista de nodos.
	@param  value - Valor do nodo a procurar.
	@retval       - Retorna o nodo procurado, caso exista. Caso contrário, retorna NULL.
**/
Node* WhereisNode(Node* head, int value);

/**
	@brief Função que liberta a memória de um nodo.
	@param node - Apontador para o nodo a eliminar.
**/
void DestroyNode(Node* node);

#pragma endregion

#pragma region Gestão de Adjacências

/**
	@brief  Função que reserva lugar na memória para uma nova adjacência.
	@param  value  - Valor do vértice adjacente.
	@param  weight - Peso da aresta a criar.
	@retval        - Retorna um apontador para a adjacência.
**/
AdjListNode* NewAdjacent(int value, int weight);

/**
	@brief  Função que elimina uma adjacência.
	@param  listAdj - Apontador para o início da lista de adjacências.
	@param  codAdj  - Valor do vértice a eliminar adjacência.
	@param  res     - Variável de controlo de sucesso.
	@retval         - Apontador para o início da lista de adjacências.
**/
AdjListNode* DeleteAdj(AdjListNode* listAdj, int codAdj, bool* res);

/**
	@brief  Função que elimina todas as adjacências de um vértice.
	@param  listAdj - Apontador para o início da lista de adjacências do vértice a eliminar.
	@param  res     - Variável de controlo de sucesso.
	@retval         - Apontador para o início da lista de adjacências do vértice.
**/
AdjListNode* DeleteAllAdj(AdjListNode* listAdj, bool* res);

/**
	@brief  Função que elimina a adjacência de um nodo com todos os outros nodos.
	@param  node   - Apontador para o início da lista de nodos.
	@param  codAdj - Valor do nodo a eliminar.
	@param  res    - Variável de controlo de sucesso.
	@retval        - Apontador para o início da lista de nodos.
**/
Node* DeleteAdjacenceAllNodes(Node* node, int codAdj, bool* res);

/**
	@brief  Função que insere uma adjacência.
	@param  listAdj - Apontador para o início da lista de adjacências.
	@param  idDest  - ID do vértice de destino.
	@param  weight  - Peso da aresta.
	@retval         - Apontador para o início da lista de adjacências.
**/
AdjListNode* InsertAdj(AdjListNode* listAdj, int idDest, int weight);

/**
	@brief Função que liberta a memória de um nodo de adjacência.
	@param node - Apontador para o nodo a eliminar.
**/
void AdjListNodeDestroy(AdjListNode* node);

#pragma endregion

#pragma region Gestão de Grafos

/**
	@brief  Função que insere um nodo num grafo.
	@param  graph - Apontador para o grafo.
	@param  node  - Apontador para o nodo a inserir no grafo.
	@param  res   - Variável de controlo de sucesso.
	@retval       - Apontador para o grafo.
**/
GR* InsertNodeGraph(GR* graph, Node* node, int res);

/**
	@brief  Função que elimina um nodo de um grafo.
	@param  graph   - Apontador para o grafo.
	@param  codNode - Código do nodo a eliminar.
	@param  res     - Variável de controlo de sucesso.
	@retval         - Apontador para o grafo.
**/
GR* DeleteNodeGraph(GR* graph, int codNode, bool* res);

/**
	@brief  Função que elimina uma adjacência de um grafo.
	@param  graph   - Apontador para o grafo.
	@param  origin  - ID do vértice de origem.
	@param  destiny - ID do vértice de destino
	@param  res     - Variável de controlo de sucesso.
	@retval         - Apontador para o grafo.
**/
GR* DeleteAdjGraph(GR* graph, int origin, int destiny, bool* res);

/**
	@brief  Função que procura um nodo num grafo.
	@param  graph  - Apontador para o grafo.
	@param  idNode - ID do nodo a procurar.
	@retval        - Retorna o nodo procurado, caso exista. Caso contrário, retorna NULL.
**/
Node* WhereIsNodeGraph(GR* graph, int idNode);

/**
	@brief  Função que insere uma adjacência num grafo.
	@param  graph     - Apontador para o grafo.
	@param  idOrigin  - ID do vértice de origem.
	@param  idDestiny - ID do vértice de destino.
	@param  weight    - Peso da aresta.
	@param  res       - Variáavel de controlo de sucesso.
	@retval           - Apontador para o grafo.
**/
GR* InsertAdjaGraph(GR* graph, int idOrigin, int idDestiny, int weight, bool* res);

/**
	@brief  Função que aloca memória para e inicia um grafo.
	@param  v - Número de vértices a incluir num grafo.
	@retval   - Apontador para o grafo.
**/
GR* CreateGraph(int v);

/**
	@brief  Função que verifica se um nodo existe num grafo.
	@param  graph  - Apontador para o grafo.
	@param  idNode - ID do nodo a procurar.
	@retval  true  - Caso o nodo exista.
	@retval  false  - Caso o nodo não exista.
**/
bool ExistNodeGraph(GR* graph, int idNode);

#pragma endregion