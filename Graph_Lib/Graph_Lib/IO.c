/**

    @file      IO.c
    @brief     Função que contém a implementação das funções de IO do programa.
    @details   ~
    @author    José António da Cunha Alves
    @date      22.05.2024
    @copyright © José António da Cunha Alves, 2024. All right reserved.

**/

#include"Global.h"
#include"IO.h"

/**
    @brief Função que mostra o ID de um vértice.
    @param graph - Apontador para o grafo.
    @param node  - Apontador para o vértice a mostrar.
**/
void ShowNode(GR* graph, Node* node) {
    if (!ExistNodeGraph(graph, node->value)) {
        printf("Node not found!");
    }
    printf("%d ", node->value);
}

/**
    @brief Função que mostra o vértice de destino e o peso da respetiva adjacência.
    @param id     - ID do vértice de destino.
    @param weight - Peso da adjacência.
**/
void ShowNodeWeight(int id, int weight) {
    if (weight == 0);
    else printf("Vertice: %d -> Peso: %d\n", id, weight);
}

/**
    @brief Função que mostra os vértices de origem e destino, mais o peso da sua adjacência.
    @param origin  - ID do vértice de origem.
    @param destiny - ID do vértice de destino.
    @param weight  - Peso da adjacência.
**/
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