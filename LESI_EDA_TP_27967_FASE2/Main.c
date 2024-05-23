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

int main() {

    setlocale(LC_ALL, "Portuguese");

    bool res;
    int resultado=0;
    GR* graph = NULL;

    /*res = OpenGraph("Graph.bin", graph);
    ShowGraph(graph);*/

    graph=ImportData("graph_edges.CSV", &res);
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

    //res = DepthFirstTraversal(graph, 1);

    printf("\n");
    res = DepthFirstSearch(graph, 1, 10);

    //resultado = CountPaths(graph, 1, 3, resultado);
    printf("Número de caminhos entre os vértices 0 e 3: %d\n", resultado);

    res = SaveGraph("Graph.bin", graph);
}