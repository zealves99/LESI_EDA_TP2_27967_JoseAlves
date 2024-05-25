/**

    @file      FileManager.c
    @brief     Ficheiro que contém a implementação das funções de gestão de ficheiros de um programa de gestão de grafos.
    @details   ~
    @author    José António da Cunha Alves
    @date      13.05.2024
    @copyright © José António da Cunha Alves, 2024. All right reserved.

**/

#include<stdlib.h>
#include<string.h>
#include<basetsd.h>
#include"Global.h"
#include"FileManager.h"

#pragma warning (disable:4996)

/**
    @brief  Função que importa dados de um ficheiro de texto e os coloca num grafo.
    @param  fileName - Nome do ficheiro a importar
    @param  res      - Variável de controlo de sucesso.
    @retval          - Apontador para o grafo.
**/
GR* ImportData(char fileName[], bool* res) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        return NULL;
        *res = false;
    }
 
    GR* graph=CreateGraph(0);

    int weight = 0;
    char character;
    int vertex = 0;
    int column = 0;
    Node* aux = NULL;

    //variáveis de controlo
    bool resNode = false;
    bool resAdj = false;
    bool control = false;

    //posiciona o apontador no inicio do ficheiro.
    fseek(fp, 0, SEEK_SET);
    aux = CreateNode(vertex); //cria primeiro vertice
    graph = InsertNodeGraph(graph, aux, &resNode);
    while (!feof(fp)) {
        fscanf(fp, "%d%c", &weight, &character);
        if (character == FILE_SEPARATOR) {
            if (weight!=0) { 
                graph=InsertAdjaGraph(graph, vertex, column, weight, &resAdj);
            }
            /*else {
                graph = InsertAdjaGraph(graph, vertex, column, weight, &resAdj);
            }*/
            column++;
        }
        if (character == '\n') {
            if (weight!=0) {
                /*aux = CreateNode(vertex);*/
               /* graph = InsertNodeGraph(graph, aux, &resNode);*/
                graph = InsertAdjaGraph(graph, vertex, column, weight, &resAdj);
            }
            /*else {
                graph = InsertAdjaGraph(graph, vertex, column, weight, &resAdj);
            }*/
            column=0;
            vertex++;
            aux = CreateNode(vertex);
            graph = InsertNodeGraph(graph, aux, &resNode);
            //control = ExistNodeGraph(graph, vertex);
        }
    }

    if (resAdj == true && resNode == true) res = true;

    fclose(fp);
    return graph;
}

/**
    @brief  Função que guarda um grafo num ficheiro binário.
    @param  fileName - Nome do ficheiro a guardar.
    @param  graph    - Grafo a guardar.
    @retval          - True ou False, consoante haja sucesso ou insucesso.
**/
bool SaveGraph(char fileName[], GR* graph) {
    FILE* fp = fopen(fileName, "wb");
    if (fp == NULL) return false;
    /*GrFile graphFile;
    graphFile.v = graph->numNodes;
    fwrite(&graphFile, 1, sizeof(graphFile), fp);*/

    Node* aux = graph->headGraph;
    NodeFile node;
    AdjListNode* auxAdj = aux->next;
    AdjListNodeFile adj;

    while (aux != NULL) {
        auxAdj = aux->next;
        node.value = aux->value;
        node.numAdj = aux->numAdj;
        fwrite(&node, 1, sizeof(NodeFile), fp);
        while (auxAdj != NULL) {
            adj.value = auxAdj->value;
            adj.weight = auxAdj->weight;
            fwrite(&auxAdj, 1, sizeof(AdjListNodeFile), fp);
            auxAdj = auxAdj->next;
        }
        aux = aux->nextNode;
        
    }

    fclose(fp);
    return true;
}

/**
    @brief  Função que abre um grafo de um ficheiro binário e o carrega na memória.
    @param  fileName - Nome do ficheiro a lêr.
    @param  graph    - Apontador para a estrutura de grafo a importar.
    @retval          - True ou False, consoante conseguiu ou não importar o grafo.
**/
bool OpenGraph(char* fileName[], GR* graph) {
    FILE* fp = fopen(fileName, "rb");
    if (fp == NULL) return false;
    /*GrFile graphAux = (GrFile*)malloc(sizeof(GrFile));*/
    /*graphAux->v = 0;*/
    NodeFile nodeAux /*= (NodeFile*)malloc(sizeof(NodeFile))*/;
    /*nodeAux->value = -1;*/
    AdjListNodeFile adjAux /*= (AdjListNodeFile*)malloc(sizeof(AdjListNodeFile))*/;
    /*adjAux->value = -1;
    adjAux->weight = -1;*/

    /*Node* node= (Node*)malloc(sizeof(Node));
    AdjListNode* adj = (AdjListNode*)malloc(sizeof(AdjListNode));*/

    /*fread(&graphAux, 1, sizeof(GrFile), fp);*/
    /*graph=CreateGraph(graphAux.v);*/

    int res=false;
    bool result = false;

    while (!feof(fp)) {
        fread(&nodeAux, 1, sizeof(NodeFile), fp);
        Node* node = CreateNodeFromFile(nodeAux);
        graph = InsertNodeGraph(graph, node, res);

        for (int i = 0; i < node->numAdj; i++) {
            fread(&adjAux, sizeof(AdjListNodeFile), 1, fp);
            AdjListNode* adj = NewAdjacent(adjAux.value, adjAux.weight);
            graph = InsertAdjaGraph(graph, node->value, adj->value, adj->weight, &result);
        }

    }

    /*free(graphAux);*/
    /*free(nodeAux);
    free(adjAux);*/
}

/**
    @brief  Função que cria um nodo em memória, a partir de um nodo importado de um ficheiro.
    @param  nodeFile - Nodo importado.
    @retval          - Apontador para o nodo em memória.
**/
Node* CreateNodeFromFile(NodeFile nodeFile) {
    Node* node = CreateNode(nodeFile.value);
    node->numAdj = nodeFile.numAdj;
    return node;
}