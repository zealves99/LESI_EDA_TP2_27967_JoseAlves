#pragma once
/**

    @file      Dijkstra.h
    @brief     Ficheiro que contém os cabeçalhos das funções necessárias à implementação do algoritmo de Dijkstra.
    @details   ~
    @author    José António da Cunha Alves
    @date      25.05.2024
    @copyright © José Alves, 2024. All right reserved.

**/


/**
    @brief  Função que utiliza uma variação do algoritmo de Dijkstra para encontrar o maior caminho a partir de um vértice.
    @param  graph  - Apontador para o grafo.
    @param  origin - ID do vértice de origem.
    @param  parents   - Array de 'pais'
    @param  weights  - Array dos pesos dos vértices.
    @retval        - Número de vértices no caminho.
**/
int Dijkstra(GR* graph, int origin, int pais[], int pesos[]);

/**
    @brief  Função que encontra índice do vértice da soma do maior caminho atual.
    @param  orla    - Array dos IDs dos vértices nas redondezas.
    @param  weights - Array de pesos de cada vértice.
    @param  size    - Tamanho dos arrays.
    @retval         -
**/
int MaxIndWeight(int orla[], int pesos[], int tam);

/**
    @brief Função que troca dois valores num array.
    @param array - Array onde trocar os valores.
    @param value - Valor 1.
    @param pos   - Valor 2.
**/
void Swap(int array[], int value, int pos);

/**
    @brief Função que mostra o array das redondezas.
    @param array - Array a mostrar.
    @param t     - Tamanho do array.
**/
void PrintArray(int array[], int t);

/**
    @brief  Função que encontra o valor máximo um array.
    @param  array - Array a procurar
    @param  size  - Tamanho do array.
    @retval       - Valor máximo encontrado
**/
int SearchMaxArray(int array[], int size);

/**
    @brief  Função que ordena os vértices de um caminho.
    @param  parents     - Array de pais.
    @param  weights     - Array de pesos
    @param  size        - Tamanho do array.
    @param  numberNodes - Número de vértices no caminho.
**/
void OrderPath(int parents[], int weights[], int size, int numberNodes);

/**
    @brief Função que mostra o caminho percorrido.
    @param path        - Array do caminho.
    @param numberNodes - Número de vértices no caminho.
**/
void ShowPath(int path[], int numberNodes);