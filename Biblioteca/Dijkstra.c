/**

    @file      Dijkstra.c
    @brief     Ficheiro que cont�m as fun��es necess�rias � implementa��o do algoritmo de Dijkstra.
    @details   ~
    @author    Jos� Ant�nio da Cunha Alves
    @date      25.05.2024
    @copyright � Jos� Alves, 2024. All right reserved.

**/

#include"Global.h"
#include"Dijkstra.h"

#define DEBUG

/**
    @brief  Fun��o que utiliza uma varia��o do algoritmo de Dijkstra para encontrar o maior caminho a partir de um v�rtice.
    @param  graph  - Apontador para o grafo.
    @param  origin - ID do v�rtice de origem.
    @param  parents   - Array de 'pais'
    @param  weights  - Array dos pesos dos v�rtices.
    @retval        - N�mero de v�rtices no caminho.
**/
int Dijkstra(GR* graph, int origin, int parents[], int weights[]) {
	int r, i, cor[NV], orla[NV], tam;
	
	AdjListNode* x;
	Node* aux = graph->headGraph;

	//Inicializa��es
	for (i = 0; i < NV; i++) {
		parents[i] = -2;
		cor[i] = 0; //N�o visitado
	}

	r = 0;
	orla[0] = origin;
	tam = 1;
	weights[origin] = 0;
	parents[origin] = -1;
	cor[origin] = 1; //Na orla

	while (tam > 0) {
		//Selecionar o v�rtice de maior peso
		i = MaxIndWeight(orla, weights, tam);
		Swap(orla, i, --tam);
		/*PrintArray(orla, tam);*/
		int v = orla[tam];
		r++;
		aux = WhereIsNodeGraph(graph, v);
		x = aux->next;

		bool control = false;

		//for (int j = 0; j < tam; j++) {
		//	Node* temp = WhereIsNodeGraph(graph, orla[j]);
		//	AdjListNode* adjTemp = temp->next;
		//	while (adjTemp) {
		//		if (adjTemp->value == v) {
		//			if (weights[v] < weights[temp->value] + adjTemp->weight) {
		//				int id = parents[v];
		//				cor[id] = 1;
		//				weights[v] = weights[temp->value] + adjTemp->weight;
		//				parents[v] = temp->value;
		//			}
		//		}
		//		adjTemp = adjTemp->next;
		//	}
		//}
		cor[v] = 2; //Visitado;;
		
		
		
		for (x; x != NULL; x = x->next) {
			if (cor[x->value] == 0) {
				cor[x->value] = 1;
				orla[tam++] = x->value;

				#ifdef DEBUG
					PrintArray(orla, tam-1);
				#endif

				parents[x->value] = v;
				weights[x->value] = weights[v] + x->weight;
			}
			else if (cor[x->value] == 1 && weights[v] + x->weight > weights[x->value]) {
				parents[x->value] = v;
				weights[x->value] = weights[v] + x->weight;

				#ifdef DEBUG
					PrintArray(cor, NV);
				#endif

			}		
		}
		
	}
	return r;
}


/**
    @brief  Fun��o que encontra �ndice do v�rtice da soma do maior caminho atual.
    @param  orla    - Array dos IDs dos v�rtices nas redondezas.
    @param  weights - Array de pesos de cada v�rtice.
    @param  size    - Tamanho dos arrays.
    @retval         - 
**/
int MaxIndWeight(int orla[], int weights[], int size) {
	int max = 0;
	int	r = 0;
	for (int i = 0; i < size; i++) {
		if (weights[orla[i]] > max) {
			max = weights[orla[i]];
			r = i;
		}
	}
	return r;
}

/**
    @brief Fun��o que troca dois valores num array.
    @param array - Array onde trocar os valores.
    @param value - Valor 1.
    @param pos   - Valor 2.
**/
void Swap(int array[], int value, int pos) {
	int aux = array[value];
	array[value] = array[pos];
	array[pos] = aux;
}

/**
    @brief Fun��o que mostra o array das redondezas.
    @param array - Array a mostrar.
    @param t     - Tamanho do array.
**/
void PrintArray(int array[], int t) {
	printf("Orla: ");
	for (int i = 1; i < t-1; i++) {
		printf("%d -> ", array[i]);
	}
	printf("%d\n", array[t-1]);
}

/**
    @brief  Fun��o que encontra o valor m�ximo um array.
    @param  array - Array a procurar
    @param  size  - Tamanho do array.
    @retval       - Valor m�ximo encontrado
**/
int SearchMaxArray(int array[], int size) {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] > max)max = array[i];
	}
	return max;
}

/**
    @brief  Fun��o que ordena os v�rtices de um caminho.
    @param  parents     - Array de pais.
    @param  weights     - Array de pesos
    @param  size        - Tamanho do array.
    @param  numberNodes - N�mero de v�rtices no caminho.
**/
void OrderPath(int parents[], int weights[], int size, int numberNodes) {
	int aux[NV] = { -1 };
	int weightAux = 0;
	int index = 0;
	int j = 0;
	
	//Encontrar o �ndice do v�rtice com maior peso
	for (int i=0; i < size; i++) {
		if (weights[i] > weightAux) {
			weightAux = weights[i];
			j = i;
		}
	}

	aux[0] =j;
	int pos = 1;
	for (int a = 1; a < numberNodes; a++) {
			aux[a] = parents[aux[a - 1]];
	}

	ShowPath(aux, numberNodes);
}

/**
    @brief Fun��o que mostra o caminho percorrido.
    @param path        - Array do caminho.
    @param numberNodes - N�mero de v�rtices no caminho.
**/
void ShowPath(int path[], int numberNodes) {
	for (int i = numberNodes; i > 1; i--) {
		printf("%d ->", path[i - 1]);
	}
	printf("%d", path[0]);
}