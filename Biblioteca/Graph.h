#pragma once
/**

	@file      Graph.c
	@brief     Ficheiro que cont�m �s cabe�alhos das fun��es de gest�o de grafos.
	@details   ~
	@author    Jos� Ant�nio da Cunha Alves
	@date      12.05.2024
	@copyright � Jos� Ant�nio da Cunha Alves, 2024. All right reserved.

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

#pragma region Gest�o de V�rtices

/**
	@brief  Fun��o que cria um nodo.
	@param  value - Valor a atribuir ao nodo.
	@retval       - Apontador para o nodo.
**/
Node* CreateNode(int value);

/**
	@brief  Fun��o que verifica se um nodo existe na mem�ria.
	@param  head  - Apontador para o in�cio da lista de nodos.
	@param  value - Valor do v�rtice a encontrar.
	@retval true - O nodo existe.
	@retval false - O nodo n�o existe.
**/
bool ExistNode(Node* head, int value);

/**
	@brief  Fun��o que insere um nodo na lista de nodos.
	@param  head    - Apontador para o in�cio da lista de nodos.
	@param  newNode - Apontador para o nodo a adicionar � lista.
	@param  res     - Vari�vel de controlo de sucesso.
	@retval         - Apontador para a lista de nodos.
**/
Node* InsertNode(Node* head, Node* newNode, bool* res);

/**
	@brief  Fun��o que elimina um nodo da lista de nodos.
	@param  head    - Apontador para o in�cio da lista de nodos.
	@param  codNode - Valor do nodo a eliminar.
	@param  res     - Vari�vel de controlo de sucesso.
	@retval         - Apontador para o in�cio da lista de nodos.
**/
Node* DeleteNode(Node* head, int codNode, bool* res);

/**
	@brief  Fun��o que procura a posi��o de um nodo na lista de nodos.
	@param  head  - Apontador para o in�cio da lista de nodos.
	@param  value - Valor do nodo a procurar.
	@retval       - Retorna o nodo procurado, caso exista. Caso contr�rio, retorna NULL.
**/
Node* WhereisNode(Node* head, int value);

/**
	@brief Fun��o que liberta a mem�ria de um nodo.
	@param node - Apontador para o nodo a eliminar.
**/
void DestroyNode(Node* node);

#pragma endregion

#pragma region Gest�o de Adjac�ncias

/**
	@brief  Fun��o que reserva lugar na mem�ria para uma nova adjac�ncia.
	@param  value  - Valor do v�rtice adjacente.
	@param  weight - Peso da aresta a criar.
	@retval        - Retorna um apontador para a adjac�ncia.
**/
AdjListNode* NewAdjacent(int value, int weight);

/**
	@brief  Fun��o que elimina uma adjac�ncia.
	@param  listAdj - Apontador para o in�cio da lista de adjac�ncias.
	@param  codAdj  - Valor do v�rtice a eliminar adjac�ncia.
	@param  res     - Vari�vel de controlo de sucesso.
	@retval         - Apontador para o in�cio da lista de adjac�ncias.
**/
AdjListNode* DeleteAdj(AdjListNode* listAdj, int codAdj, bool* res);

/**
	@brief  Fun��o que elimina todas as adjac�ncias de um v�rtice.
	@param  listAdj - Apontador para o in�cio da lista de adjac�ncias do v�rtice a eliminar.
	@param  res     - Vari�vel de controlo de sucesso.
	@retval         - Apontador para o in�cio da lista de adjac�ncias do v�rtice.
**/
AdjListNode* DeleteAllAdj(AdjListNode* listAdj, bool* res);

/**
	@brief  Fun��o que elimina a adjac�ncia de um nodo com todos os outros nodos.
	@param  node   - Apontador para o in�cio da lista de nodos.
	@param  codAdj - Valor do nodo a eliminar.
	@param  res    - Vari�vel de controlo de sucesso.
	@retval        - Apontador para o in�cio da lista de nodos.
**/
Node* DeleteAdjacenceAllNodes(Node* node, int codAdj, bool* res);

/**
	@brief  Fun��o que insere uma adjac�ncia.
	@param  listAdj - Apontador para o in�cio da lista de adjac�ncias.
	@param  idDest  - ID do v�rtice de destino.
	@param  weight  - Peso da aresta.
	@retval         - Apontador para o in�cio da lista de adjac�ncias.
**/
AdjListNode* InsertAdj(AdjListNode* listAdj, int idDest, int weight);

/**
	@brief Fun��o que liberta a mem�ria de um nodo de adjac�ncia.
	@param node - Apontador para o nodo a eliminar.
**/
void AdjListNodeDestroy(AdjListNode* node);

#pragma endregion

#pragma region Gest�o de Grafos

/**
	@brief  Fun��o que insere um nodo num grafo.
	@param  graph - Apontador para o grafo.
	@param  node  - Apontador para o nodo a inserir no grafo.
	@param  res   - Vari�vel de controlo de sucesso.
	@retval       - Apontador para o grafo.
**/
GR* InsertNodeGraph(GR* graph, Node* node, int res);

/**
	@brief  Fun��o que elimina um nodo de um grafo.
	@param  graph   - Apontador para o grafo.
	@param  codNode - C�digo do nodo a eliminar.
	@param  res     - Vari�vel de controlo de sucesso.
	@retval         - Apontador para o grafo.
**/
GR* DeleteNodeGraph(GR* graph, int codNode, bool* res);

/**
	@brief  Fun��o que elimina uma adjac�ncia de um grafo.
	@param  graph   - Apontador para o grafo.
	@param  origin  - ID do v�rtice de origem.
	@param  destiny - ID do v�rtice de destino
	@param  res     - Vari�vel de controlo de sucesso.
	@retval         - Apontador para o grafo.
**/
GR* DeleteAdjGraph(GR* graph, int origin, int destiny, bool* res);

/**
	@brief  Fun��o que procura um nodo num grafo.
	@param  graph  - Apontador para o grafo.
	@param  idNode - ID do nodo a procurar.
	@retval        - Retorna o nodo procurado, caso exista. Caso contr�rio, retorna NULL.
**/
Node* WhereIsNodeGraph(GR* graph, int idNode);

/**
	@brief  Fun��o que insere uma adjac�ncia num grafo.
	@param  graph     - Apontador para o grafo.
	@param  idOrigin  - ID do v�rtice de origem.
	@param  idDestiny - ID do v�rtice de destino.
	@param  weight    - Peso da aresta.
	@param  res       - Vari�avel de controlo de sucesso.
	@retval           - Apontador para o grafo.
**/
GR* InsertAdjaGraph(GR* graph, int idOrigin, int idDestiny, int weight, bool* res);

/**
	@brief  Fun��o que aloca mem�ria para e inicia um grafo.
	@param  v - N�mero de v�rtices a incluir num grafo.
	@retval   - Apontador para o grafo.
**/
GR* CreateGraph(int v);

/**
	@brief  Fun��o que verifica se um nodo existe num grafo.
	@param  graph  - Apontador para o grafo.
	@param  idNode - ID do nodo a procurar.
	@retval  true  - Caso o nodo exista.
	@retval  false  - Caso o nodo n�o exista.
**/
bool ExistNodeGraph(GR* graph, int idNode);

#pragma endregion