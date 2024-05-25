/**

    @file      Main.c
    @brief     Ficheiro main de um programa que gere grafos.
    @details   ~
    @author    José António da Cunha Alves
    @date      13.05.2024
    @copyright © José António da Cunha Alves, 2024. All right reserved.

**/

#include"Global.h"
#include"FileManager.h"
#include<malloc.h>
#include"Function.h"
#include"DFT.h"
#include<locale.h>
#include "Stack.h"
#include"Dijkstra.h"

int main() {

    setlocale(LC_ALL, "Portuguese");

    bool res;
    int resultado=0;
    GR* graph = CreateGraph(0);

    /*res = OpenGraph("Graph.bin", graph);
    ShowGraph(graph);*/

    graph=ImportData("Lista_1.CSV", &res);
    if (res == false) {
        printf("Erro ao Importar Dados!\n");
    }
    else {
        ShowGraph(graph);
    }

    int line = 2;
    int column = 1;
    int sum = LineSum(graph, line);
    printf("Soma linha %d = %d\n", line, sum);
    /*sum = ColumnSum(graph, column);
    printf("Soma coluna %d = %d\n", line, sum);*/

    /*res = DepthFirstTraversal(graph, 4);
    ResetVisitedNodes(graph);*/
    int pais[NV] = { 0 };
    int pesos[NV] = { 0 };

    int origem = 3;
    int verticesPercorridos = Dijkstra(graph, origem, pais, pesos);
    int pesoMax = SearchMaxArray(pesos, NV);
    printf("O maior caminho partindo de %d tem custo %d\n", origem, pesoMax);

    OrderPath(pais, pesos, NV, verticesPercorridos);

    printf("\n");
    int* soma = 0;
    res = DepthFirstSearch(graph, 1, 4, &soma);
    printf("soma: %d\n", &soma);

    Stack stack;

    /*sum = SearchRec(graph, 1, 4, &stack);*/

    /*resultado = CountPaths(graph, 1, 3, resultado);*/
    printf("Número de caminhos entre os vértices 0 e 3: %d\n", resultado);

    printf("Caminho mais curto: \n");
    /*resultado = BruteForceShortestPath(graph, 1, 13);*/

    res = SaveGraph("Graph.bin", graph);
}