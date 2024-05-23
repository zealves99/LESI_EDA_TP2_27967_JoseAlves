#pragma once

#define FILE_SEPARATOR ';'

typedef struct NodeFile {
    int value;
}NodeFile;

typedef struct AdjListNodeFile {
    int value;
    int weight;
}AdjListNodeFile;

typedef struct GrFile {
    int v; //Número de vértices no grafo.
}GrFile;

/**
    @brief  Função que importa dados de um ficheiro de texto e os coloca num grafo.
    @param  fileName - Nome do ficheiro a importar
    @param  res      - Variável de controlo de sucesso.
    @retval          - Apontador para o grafo.
**/
GR* ImportData(char fileName[], bool* res);

bool SaveGraph(char fileName[], GR* graph);

bool OpenGraph(char* fileName[], GR* graph);