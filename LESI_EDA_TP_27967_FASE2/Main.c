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

int main() {

    bool res;
    int resultado=0;
    GR* graph = NULL;

    /*res = OpenGraph("Graph.bin", graph);
    ShowGraph(graph);*/

    graph=ImportData("Lista.CSV", &res);
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
    sum = ColumnSum(graph, column);
    printf("Soma coluna %d = %d\n", line, sum);

    res = DepthFirstTraversal(graph, 1);
    res = DepthFirstSearch(graph, 1, 2);

    resultado = CountPaths(graph, 1, 3, resultado);
    printf("Numero de caminhos entre os vértices 0 e 3: %d\n", resultado);

    res = SaveGraph("Graph.bin", graph);
}