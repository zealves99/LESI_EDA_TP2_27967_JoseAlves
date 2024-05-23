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