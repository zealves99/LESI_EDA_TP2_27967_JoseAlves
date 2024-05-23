/**

    @file      DFT.c
    @brief     
    @details   ~
    @author    José António da Cunha Alves
    @date      22.05.2024
    @copyright © José António da Cunha Alves, 2024. All right reserved.

**/

#include <stdbool.h>
#include <malloc.h>
#include "Global.h"
#include "Stack.h"

void ResetVisitedNodes(GR* graph) {
    Node* aux = graph->headGraph;
    while (aux) {
        aux->visited = false;
        aux = aux->nextNode;
    }
}

/**
    @brief  Função que verifica qual o vértice adjacente mais próximo não visitado.
    @param  graph - 
    @param  v     - 
    @retval       - 
**/
int GetClosestVerticeAdjUnvisited(GR* graph, int v) {
    if (!graph)return -1;
    if (!ExistNodeGraph(graph, v)) return -2;

    Node* aux = graph->headGraph;
    AdjListNode* auxAdj = graph->headGraph->next;
    while (aux->value != v) {
        aux = aux->nextNode;
    }
    int weight = aux->next->weight;
    Node* visited = WhereIsNodeGraph(graph, auxAdj->value);
    while (auxAdj) {
        if (auxAdj->weight < weight && visited->visited==false) weight = auxAdj->weight;
        visited = WhereIsNodeGraph(graph, auxAdj->value);
        auxAdj = auxAdj->next;
    }
    return auxAdj->value;
}

/**
    @brief  Função que faz a travessia do grafo em profundidade.
    @param  graph  - 
    @param  origin - 
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
    @param  graph   - 
    @param  origin  - 
    @param  destiny - 
    @retval         - 
**/
bool DepthFirstSearch(GR* graph, int origin, int destiny) {
    Node* aux = WhereIsNodeGraph(graph, origin);
    AdjListNode* adj = aux->next;
    if (origin == destiny) {
        ShowNodeWeight(aux->value, adj->weight);
        return true;
    }
    aux->visited = true;

    ShowNodeWeight(aux->value, adj->weight);

    while (adj) {
        Node* aux2 = WhereIsNodeGraph(graph, adj->value);
        if (aux2->visited == false) {
            bool exist = DepthFirstSearch(graph, adj->value, destiny);
            return exist;
        }
        else {
            adj = adj->next;
        }
    }
    ResetVisitedNodes(graph);
}

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