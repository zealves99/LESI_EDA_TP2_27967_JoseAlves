#pragma once
/**

    @file      Dijkstra.h
    @brief     Ficheiro que cont�m os cabe�alhos das fun��es necess�rias � implementa��o do algoritmo de Dijkstra.
    @details   ~
    @author    Jos� Ant�nio da Cunha Alves
    @date      25.05.2024
    @copyright � Jos� Alves, 2024. All right reserved.

**/


/**
    @brief  Fun��o que utiliza uma varia��o do algoritmo de Dijkstra para encontrar o maior caminho a partir de um v�rtice.
    @param  graph  - Apontador para o grafo.
    @param  origin - ID do v�rtice de origem.
    @param  parents   - Array de 'pais'
    @param  weights  - Array dos pesos dos v�rtices.
    @retval        - N�mero de v�rtices no caminho.
**/
int Dijkstra(GR* graph, int origin, int pais[], int pesos[]);

/**
    @brief  Fun��o que encontra �ndice do v�rtice da soma do maior caminho atual.
    @param  orla    - Array dos IDs dos v�rtices nas redondezas.
    @param  weights - Array de pesos de cada v�rtice.
    @param  size    - Tamanho dos arrays.
    @retval         -
**/
int MaxIndWeight(int orla[], int pesos[], int tam);

/**
    @brief Fun��o que troca dois valores num array.
    @param array - Array onde trocar os valores.
    @param value - Valor 1.
    @param pos   - Valor 2.
**/
void Swap(int array[], int value, int pos);

/**
    @brief Fun��o que mostra o array das redondezas.
    @param array - Array a mostrar.
    @param t     - Tamanho do array.
**/
void PrintArray(int array[], int t);

/**
    @brief  Fun��o que encontra o valor m�ximo um array.
    @param  array - Array a procurar
    @param  size  - Tamanho do array.
    @retval       - Valor m�ximo encontrado
**/
int SearchMaxArray(int array[], int size);

/**
    @brief  Fun��o que ordena os v�rtices de um caminho.
    @param  parents     - Array de pais.
    @param  weights     - Array de pesos
    @param  size        - Tamanho do array.
    @param  numberNodes - N�mero de v�rtices no caminho.
**/
void OrderPath(int parents[], int weights[], int size, int numberNodes);

/**
    @brief Fun��o que mostra o caminho percorrido.
    @param path        - Array do caminho.
    @param numberNodes - N�mero de v�rtices no caminho.
**/
void ShowPath(int path[], int numberNodes);