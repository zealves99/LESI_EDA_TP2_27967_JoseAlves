#pragma once
/**

    @file      Function.c
    @brief     Ficheiro que cont�m os cabe�alhos das fun��es de funcionalidades de soma do programa.
    @details   ~
    @author    Jos� Ant�nio da Cunha Alves
    @date      21.05.2024
    @copyright � Jos� Ant�nio da Cunha Alves, 2024. All right reserved.

**/

#include"Global.h"

/**
    @brief  Fun��o que calcula a soma de uma linha.
    @param  graph      - Apontador para o grafo.
    @param  lineNumber - N�mero da linha a somar.
    @retval            - Soma.
**/
int LineSum(GR* graph, int lineNumber);

//int ColumnSum(GR* graph, int columnNumber);