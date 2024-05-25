/**

    @file      DFT.c
    @brief     Ficheiro que cont�m as fun��es necess�rias �s opera��es DFT de um grafo.
    @details   Travessia, N�mero de caminhos entre v�rtices, V�rtice mais pr�ximo, etc.
    @author    Jos� Ant�nio da Cunha Alves
    @date      22.05.2024
    @copyright � Jos� Ant�nio da Cunha Alves, 2024. All right reserved.

**/

#include <stdbool.h>
#include <malloc.h>
#include "Global.h"
#include "Stack.h"

//#define DEBUG

/**
    @brief Fun��o que coloca todos os v�rtices de um grafo como 'n�o visitado'.
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
    @brief  Fun��o que verifica qual o v�rtice adjacente mais pr�ximo n�o visitado.
    @param  graph - Apontador para a estrutura do grafo.
    @param  v     - ID do v�rtice a procurar.
    @retval       - V�rtice mais pr�ximo.
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
    @brief  Fun��o que faz a travessia do grafo em profundidade.
    @param  graph  - Apontador para a estrutura do grafo.
    @param  origin - ID do v�rtice de origem.
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
    /*aux->visited = false;*/
}

/**
    @brief  Fun��o que encontra um caminho em profundidade, de um determinado v�rtice at� outro.
    @param  graph   - Apontador para a estrutura do grafo.
    @param  origin  - ID do v�rtice de origem.
    @param  destiny - ID do v�rtice de destino.
    @retval         - 
**/
bool DepthFirstSearch(GR* graph, int origin, int destiny, int* sum) {
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
            *sum = SumAdj(adj, &sum);
            bool exist = DepthFirstSearch(graph, adj->value, destiny,sum);
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
    @brief  Fun��o que conta o n�mero de caminhos entre dois v�rtices de um grafo.
    @param  graph     - Apontador para a estrutura do grafo.
    @param  origin    - ID do v�rtice de origem.
    @param  destiny   - ID do v�rtice de destino.
    @param  pathCount - N�mero de caminhos entre os v�rtices.
    @retval           - N�mero de caminhos.
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
    @brief  Fun��o que calcula o caminho mais curto entre dois v�rtices, usando o v�rtice mais pr�ximo de cada um deles.
    @param  graph   - Apontador para a estrutura do grafo.
    @param  origin  - ID do v�rtice de origem.
    @param  destiny - ID do v�rtice de destino.
    @retval         - Sucesso ou Erro
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

/**
    @brief  Fun��o que calcula a soma das das adjac�ncias.
    @param  adj - Apontador para a lista de adjac�ncias.
    @param  sum - Apontador para a soma atual.
    @retval     - Novo valor da soma.
**/
int SumAdj(AdjListNode* adj, int* sum) {
    return (*sum + adj->weight);
}

//int Search(GR* graph, int origin, int dest) {
//    Stack* stack = CreateStack(origin);
//
//}

//int SearchRec(GR* graph, int origin, int dest, Stack* stack) {
//    int found = 0;
//    if (origin == dest)found = 1;
//    else {
//        Node* aux = WhereIsNodeGraph(graph, origin);
//        AdjListNode* auxAdj = aux->next;
//        aux->visited = true;
//        stack = Push(stack, aux->value);
//        for(auxAdj; auxAdj!=NULL&&!found;auxAdj=auxAdj->next)
//            if (auxAdj->value != dest) {
//                found = SearchRec(graph, auxAdj->value, dest, stack);
//            }
//    }
//    return found;
//    
//}