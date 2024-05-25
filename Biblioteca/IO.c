/**

    @file      IO.c
    @brief     Fun��o que cont�m a implementa��o das fun��es de IO do programa.
    @details   ~
    @author    Jos� Ant�nio da Cunha Alves
    @date      22.05.2024
    @copyright � Jos� Ant�nio da Cunha Alves, 2024. All right reserved.

**/

#include"Global.h"
#include"IO.h"

/**
    @brief Fun��o que mostra o ID de um v�rtice.
    @param graph - Apontador para o grafo.
    @param node  - Apontador para o v�rtice a mostrar.
**/
void ShowNode(GR* graph, Node* node) {
    if (!ExistNodeGraph(graph, node->value)) {
        printf("Node not found!");
    }
    printf("%d ", node->value);
}

/**
    @brief Fun��o que mostra o v�rtice de destino e o peso da respetiva adjac�ncia.
    @param id     - ID do v�rtice de destino.
    @param weight - Peso da adjac�ncia.
**/
void ShowNodeWeight(int id, int weight) {
    if (weight == 0);
    else printf("Vertice: %d -> Peso: %d\n", id, weight);
}

/**
    @brief Fun��o que mostra os v�rtices de origem e destino, mais o peso da sua adjac�ncia.
    @param origin  - ID do v�rtice de origem.
    @param destiny - ID do v�rtice de destino.
    @param weight  - Peso da adjac�ncia.
**/
void ShowAdjWeight(int origin, int destiny, int weight) {
    if (weight == 0);
    else printf("Vertice: %2d -> Vertice: %2d                    Peso: %d\n", origin, destiny, weight);
}

/**
    @brief Fun��o que mostra um grafo.
    @param graph - Apontador para o grafo a mostrar.
**/
void ShowGraph(GR* graph) {
    Node* current = graph->headGraph;
    while (current != NULL) {

        printf("\nVertice %d->\n", current->value); //Mostra o v�rtice
        AdjListNode* adjacent = current->next;
        while (adjacent != NULL)
        {
            if (adjacent->weight == 0);

            else {
                printf("\t\t adjacent: %d \t  weight: %d\n", adjacent->value, adjacent->weight);
            }
            adjacent = adjacent->next;
        }
        current = current->nextNode;
    }
}