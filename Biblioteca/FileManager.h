#pragma once
/**

    @file      FileManager.h
    @brief     Ficheiro que cont�m os cabe�alhos das fun��es de gest�o de ficheiros de um programa de gest�o de grafos.
    @details   ~
    @author    Jos� Ant�nio da Cunha Alves
    @date      13.05.2024
    @copyright � Jos� Ant�nio da Cunha Alves, 2024. All right reserved.

**/

#define FILE_SEPARATOR ';'

typedef struct NodeFile {  //Estrutura de um nodo para ficheiro.
    int value;
    int numAdj; //N�mero de adjac�ncias.
}NodeFile;

typedef struct AdjListNodeFile { //Estrutura de um nodo de adjac�ncia para ficheiro.
    int value;
    int weight;
}AdjListNodeFile;

//typedef struct GrFile {
//    int v; //N�mero de v�rtices no grafo.
//}GrFile;

/**
    @brief  Fun��o que importa dados de um ficheiro de texto e os coloca num grafo.
    @param  fileName - Nome do ficheiro a importar
    @param  res      - Vari�vel de controlo de sucesso.
    @retval          - Apontador para o grafo.
**/
GR* ImportData(char fileName[], bool* res);

/**
    @brief  Fun��o que guarda um grafo num ficheiro bin�rio.
    @param  fileName - Nome do ficheiro a guardar.
    @param  graph    - Grafo a guardar.
    @retval          - True ou False, consoante haja sucesso ou insucesso.
**/
bool SaveGraph(char fileName[], GR* graph);

/**
    @brief  Fun��o que abre um grafo de um ficheiro bin�rio e o carrega na mem�ria.
    @param  fileName - Nome do ficheiro a l�r.
    @param  graph    - Apontador para a estrutura de grafo a importar.
    @retval          - True ou False, consoante conseguiu ou n�o importar o grafo.
**/
bool OpenGraph(char* fileName[], GR* graph);

/**
    @brief  Fun��o que cria um nodo em mem�ria, a partir de um nodo importado de um ficheiro.
    @param  nodeFile - Nodo importado.
    @retval          - Apontador para o nodo em mem�ria.
**/
Node* CreateNodeFromFile(NodeFile nodeFile);