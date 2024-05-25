#pragma once
/**

    @file      FileManager.h
    @brief     Ficheiro que contém os cabeçalhos das funções de gestão de ficheiros de um programa de gestão de grafos.
    @details   ~
    @author    José António da Cunha Alves
    @date      13.05.2024
    @copyright © José António da Cunha Alves, 2024. All right reserved.

**/

#define FILE_SEPARATOR ';'

typedef struct NodeFile {  //Estrutura de um nodo para ficheiro.
    int value;
    int numAdj; //Número de adjacências.
}NodeFile;

typedef struct AdjListNodeFile { //Estrutura de um nodo de adjacência para ficheiro.
    int value;
    int weight;
}AdjListNodeFile;

//typedef struct GrFile {
//    int v; //Número de vértices no grafo.
//}GrFile;

/**
    @brief  Função que importa dados de um ficheiro de texto e os coloca num grafo.
    @param  fileName - Nome do ficheiro a importar
    @param  res      - Variável de controlo de sucesso.
    @retval          - Apontador para o grafo.
**/
GR* ImportData(char fileName[], bool* res);

/**
    @brief  Função que guarda um grafo num ficheiro binário.
    @param  fileName - Nome do ficheiro a guardar.
    @param  graph    - Grafo a guardar.
    @retval          - True ou False, consoante haja sucesso ou insucesso.
**/
bool SaveGraph(char fileName[], GR* graph);

/**
    @brief  Função que abre um grafo de um ficheiro binário e o carrega na memória.
    @param  fileName - Nome do ficheiro a lêr.
    @param  graph    - Apontador para a estrutura de grafo a importar.
    @retval          - True ou False, consoante conseguiu ou não importar o grafo.
**/
bool OpenGraph(char* fileName[], GR* graph);

/**
    @brief  Função que cria um nodo em memória, a partir de um nodo importado de um ficheiro.
    @param  nodeFile - Nodo importado.
    @retval          - Apontador para o nodo em memória.
**/
Node* CreateNodeFromFile(NodeFile nodeFile);