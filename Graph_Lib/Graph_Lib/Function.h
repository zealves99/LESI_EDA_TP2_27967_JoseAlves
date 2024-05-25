#pragma once
/**

    @file      Function.c
    @brief     Ficheiro que contém os cabeçalhos das funções de funcionalidades de soma do programa.
    @details   ~
    @author    José António da Cunha Alves
    @date      21.05.2024
    @copyright © José António da Cunha Alves, 2024. All right reserved.

**/

#include"Global.h"

/**
    @brief  Função que calcula a soma de uma linha.
    @param  graph      - Apontador para o grafo.
    @param  lineNumber - Número da linha a somar.
    @retval            - Soma.
**/
int LineSum(GR* graph, int lineNumber);

//int ColumnSum(GR* graph, int columnNumber);