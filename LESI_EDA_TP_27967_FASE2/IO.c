/**

    @file      IO.c
    @brief     
    @details   ~
    @author    José António da Cunha Alves
    @date      22.05.2024
    @copyright © José António da Cunha Alves, 2024. All right reserved.

**/

#include"Global.h"
#include"IO.h"

void ShowNode(GR* graph, Node* node) {
    if (!ExistNodeGraph(graph, node->value)) {
        printf("Node not found!");
    }
    printf("%d ", node->value);
}

void ShowNodeWeight(int id, int weight) {
    if (weight == 0);
    else printf("Vertice: %d -> Peso: %d\n", id, weight);
}

void ShowAdjWeight(int origin, int destiny, int weight) {
    if (weight == 0);
    else printf("Vertice: %2d -> Vertice: %2d                    Peso: %d\n", origin, destiny, weight);
}

/**
    @brief Função que mostra um grafo.
    @param graph - Apontador para o grafo a mostrar.
**/
void ShowGraph(GR* graph) {
    Node* current = graph->headGraph;
    while (current != NULL) {

        printf("\nVertice %d->\n", current->value); //Mostra o vértice
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