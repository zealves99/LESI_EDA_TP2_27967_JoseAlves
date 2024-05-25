/**

    @file      Function.c
    @brief     Ficheiro que cont�m a implementa��o de funcionalidades de soma do programa.
    @details   ~
    @author    Jos� Ant�nio da Cunha Alves
    @date      21.05.2024
    @copyright � Jos� Ant�nio da Cunha Alves, 2024. All right reserved.

**/

#include"Global.h"

/**
    @brief  Fun��o que calcula a soma de uma linha.
    @param  graph      - Apontador para o grafo.
    @param  lineNumber - N�mero da linha a somar.
    @retval            - Soma.
**/
int LineSum(GR* graph, int lineNumber) {
    if (graph == NULL) return -1;
    if (lineNumber<0 || lineNumber>graph->numNodes) return -2;
    Node* node = graph->headGraph;
    AdjListNode* aux = graph->headGraph->next;
    int sum = 0;
    
    while (node) {
        if (node->value == lineNumber) {
            aux = node->next;
            while (aux) {
                sum += aux->weight;
                aux = aux->next;
            }
            return sum;
        }
        node = node->nextNode;
    }
    return -3;
}

//int ColumnSum(GR* graph, int columnNumber) {
//    if (graph == NULL) return -1;
//    if (columnNumber<0 || columnNumber>graph->numNodes) return -2;
//    Node* node = graph->headGraph;
//    AdjListNode* aux = graph->headGraph->next;
//    int sum = 0;
//    int column = 0;
//    while (node) {
//        aux = node->next;
//        for (int i = 0; i < columnNumber; i++) {
//            aux = aux->next;
//        }
//        sum += aux->weight;
//        node = node->nextNode;
//        
//    }
//    return sum;
//}