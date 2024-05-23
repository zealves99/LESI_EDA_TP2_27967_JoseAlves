/**

    @file      DFT.c
    @brief     Ficheiro que contém as funções necessárias às operações DFT de um grafo.
    @details   Travessia, Número de caminhos entre vértices, Vértice mais próximo, etc.
    @author    José António da Cunha Alves
    @date      22.05.2024
    @copyright © José António da Cunha Alves, 2024. All right reserved.

**/

#include <stdbool.h>
#include <malloc.h>
#include "Global.h"
#include "Stack.h"

//#define DEBUG

/**
    @brief Função que coloca todos os vértices de um grafo como 'não visitado'.
    @param graph - Apontador para a estrutura do grafo.
**/
void ResetVisitedNodes(GR* graph) {
    Node* aux = graph->headGraph;
    while (aux) {
        aux->visited = false;
        aux = aux->nextNode;
    }
}

/**
    @brief  Função que verifica qual o vértice adjacente mais próximo não visitado.
    @param  graph - Apontador para a estrutura do grafo.
    @param  v     - ID do vértice a procurar.
    @retval       - Vértice mais próximo.
**/
Node* GetClosestVerticeAdjUnvisited(GR* graph, int v) {
    if (!graph)return NULL;
    if (!ExistNodeGraph(graph, v)) return NULL;

    Node* aux = graph->headGraph;
    
    while (aux->value != v) {
        aux = aux->nextNode;
    }
    AdjListNode* auxAdj = aux->next;
    int weight = MAX_WEIGHT;
    int id = aux->next->value;
    Node* visited = WhereIsNodeGraph(graph, auxAdj->value);
    while (auxAdj->next) {
        if (auxAdj->weight < weight && visited->visited == false && auxAdj->weight != 0) {
            weight = auxAdj->weight;
            id = auxAdj->value;
        }
        if(auxAdj->next) auxAdj = auxAdj->next;
        visited = WhereIsNodeGraph(graph, auxAdj->value);
    }
    visited = WhereIsNodeGraph(graph, id);
    return visited;
}

/**
    @brief  Função que faz a travessia do grafo em profundidade.
    @param  graph  - Apontador para a estrutura do grafo.
    @param  origin - ID do vértice de origem.
    @retval        - 
**/
bool DepthFirstTraversal(GR* graph, int origin) {
    Node* aux = WhereIsNodeGraph(graph,origin);
    aux->visited = true;
    ShowNode(graph, aux);
    AdjListNode* adj = aux->next;
    Node* visited = WhereIsNodeGraph(graph, adj->value);
    while (adj) {
        if (adj->weight != 0 && visited->visited == false) {
            DepthFirstTraversal(graph, adj->value);
        }
        visited = visited->nextNode;
        adj = adj->next;
    }
    aux->visited = false;
}

/**
    @brief  Função que encontra um caminho em profundidade, de um determinado vértice até outro.
    @param  graph   - Apontador para a estrutura do grafo.
    @param  origin  - ID do vértice de origem.
    @param  destiny - ID do vértice de destino.
    @retval         - 
**/
bool DepthFirstSearch(GR* graph, int origin, int destiny) {
    Node* aux = WhereIsNodeGraph(graph, origin);
    AdjListNode* adj = aux->next;
    if (origin == destiny) {
            return true;
    }
    aux->visited = true;
    

    while (adj) {
        Node* aux2 = WhereIsNodeGraph(graph, adj->value);
        if (aux2->visited == false && adj->weight != 0) {
            #ifdef DEBUG 
                printf("vertice atual %d\n", aux2->value);
            #endif
            ShowAdjWeight(aux->value, adj->value, adj->weight);
            bool exist = DepthFirstSearch(graph, adj->value, destiny);
            if (exist) ResetVisitedNodes(graph);
            return exist;
        }
        else {
            adj = adj->next;
        }
    }
    ResetVisitedNodes(graph);
}

/**
    @brief  Função que conta o número de caminhos entre dois vértices de um grafo.
    @param  graph     - Apontador para a estrutura do grafo.
    @param  origin    - ID do vértice de origem.
    @param  destiny   - ID do vértice de destino.
    @param  pathCount - Número de caminhos entre os vértices.
    @retval           - 
**/
int CountPaths(GR* graph, int origin, int destiny, int pathCount) {
    if (graph == NULL) return -1;

    if (origin == destiny) return(++pathCount);

    else {
        Node* aux = WhereIsNodeGraph(graph, origin);
        AdjListNode* adj = aux->next;
        while (adj) {
            Node* v = WhereIsNodeGraph(graph, adj->value);
            pathCount = CountPaths(graph, v->value, destiny, pathCount);
            adj = adj->next;
        }
    }
    return pathCount;
}

/**
    @brief  Função que calcula o caminho mais curto entre dois vértices, usando o vértice mais próximo de cada um deles.
    @param  graph   - Apontador para a estrutura do grafo.
    @param  origin  - ID do vértice de origem.
    @param  destiny - ID do vértice de destino.
    @retval         - 
**/
int BruteForceShortestPath(GR* graph, int origin, int destiny) {
    if (graph == NULL) return -1;
    if (!ExistNodeGraph(graph, origin) || !ExistNodeGraph(graph, destiny)) return -2;
    Node* aux = WhereIsNodeGraph(graph, origin);
    aux->visited = true;
    while (origin != destiny) {
        aux = GetClosestVerticeAdjUnvisited(graph, origin);
        
        ShowNode(graph, aux);
        Node* next = BruteForceShortestPath(graph, aux->value, destiny);
        return 1;
    }
    
    ResetVisitedNodes(graph);
    
}