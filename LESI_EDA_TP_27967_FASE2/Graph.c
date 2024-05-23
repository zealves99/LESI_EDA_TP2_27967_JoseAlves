/**

    @file      Graph.c
    @brief     Ficheiro que contém a implementação das funções de gestão de grafos.
    @details   ~
    @author    José António da Cunha Alves
    @date      12.05.2024
    @copyright © José António da Cunha Alves, 2024. All right reserved.

**/

#include "Global.h"
#include<malloc.h>
#include<string.h>

#pragma region Vertices
/**
    @brief  Função que cria um nodo.
    @param  value - Valor a atribuir ao nodo.
    @retval       - Apontador para o nodo.
**/
Node* CreateNode(int value) {
    Node* aux = (Node*)malloc(sizeof(Node));
    if (aux == NULL) return NULL;
    aux->value = value;
    aux->next = NULL;
    aux->nextNode = NULL;
    aux->visited = false;
    return aux;
}

/**
    @brief  Função que verifica se um nodo existe na memória.
    @param  head  - Apontador para o início da lista de nodos.
    @param  value - Valor do vértice a encontrar.
    @retval true - O nodo existe.
    @retval false - O nodo não existe.
**/
bool ExistNode(Node* head, int value) {
    if (head == NULL) return false;
    Node* aux = head;
    while (aux) {
        if (aux->value == value)return true;
        aux = aux->nextNode;
    }
    return false;
}

/**
    @brief Função que liberta a memória de um nodo.
    @param node - Apontador para o nodo a eliminar.
**/
void DestroyNode(Node* node) {
    free(node);
}

/**
    @brief  Função que insere um nodo na lista de nodos.
    @param  head    - Apontador para o início da lista de nodos.
    @param  newNode - Apontador para o nodo a adicionar à lista.
    @param  res     - Variável de controlo de sucesso.
    @retval         - Apontador para a lista de nodos.
**/
Node* InsertNode(Node* head, Node* newNode, bool* res) {
    *res = false;

    //Caso ainda não existam vértices, insere no início.
    if (head == NULL) {
        *res = 1;
        head = newNode;
        return head;
    }

    //Testa se já existe um vértice com esse valor.
    if (ExistNode(head, newNode->value) == true) return head;
    else {
        //Procura posição onde inserir o novo vértice. Insere no fim.
        Node* aux = head;
        while (aux->nextNode != NULL) {
            aux = aux->nextNode;
        }
        //Estando na posição correta, insere.
        *res = true;
        if (aux == NULL)//Este é o primeiro valor e, por isso, será o novo head.
        {
            head = newNode;
        }
        else {
            aux->nextNode = newNode;
        }
        return head;
    }
}

/**
    @brief  Função que elimina um nodo da lista de nodos.
    @param  head    - Apontador para o início da lista de nodos.
    @param  codNode - Valor do nodo a eliminar.
    @param  res     - Variável de controlo de sucesso.
    @retval         - Apontador para o início da lista de nodos.
**/
Node* DeleteNode(Node* head, int codNode, bool* res) {
    *res = false;
    if (head == NULL) return NULL;

    //Encontra o vértice a eliminar.
    Node* prev = NULL;
    Node* aux = head;
    while (aux->value != codNode) {
        prev = aux;
        aux = aux->nextNode;
    }
    if (!aux)return head; //Não existe o vértice a eliminar.
    
    //Caso o vértice a eliminar seja o primeiro.
    if (prev == NULL) {
        //Elimina as adjacências do vértice a eliminar.
        aux->nextNode = DeleteAllAdj(aux->nextNode, res);
        if (*res == false)return head;
        head = aux->nextNode;
    }
    else {
        prev->nextNode = aux->nextNode;
    }
    DestroyNode(aux);
    *res = true;
    return head;
}

/**
    @brief  Função que procura a posição de um nodo na lista de nodos.
    @param  head  - Apontador para o início da lista de nodos.
    @param  value - Valor do nodo a procurar.
    @retval       - Retorna o nodo procurado, caso exista. Caso contrário, retorna NULL. 
**/
Node* WhereisNode(Node* head, int value){
    if (head == NULL) return NULL;
    Node* aux = head;
    while (aux) {
        if (aux->value == value) return aux; //Devolve o vértice que procuramos.
        aux = aux->nextNode;
    }
    return NULL;
}
#pragma endregion

#pragma region Adjacencies
/**
    @brief  Função que reserva lugar na memória para uma nova adjacência.
    @param  value  - Valor do vértice adjacente.
    @param  weight - Peso da aresta a criar.
    @retval        - Retorna um apontador para a adjacência.
**/
AdjListNode* NewAdjacent(int value, int weight) {
    AdjListNode* adjacent = (AdjListNode*)malloc(sizeof(AdjListNode));
    if (adjacent == NULL) return NULL;
    adjacent->value = value;
    adjacent->next = NULL;
    adjacent->weight = weight;
    return adjacent;
}

/**
    @brief Função que liberta a memória de um nodo de adjacência.
    @param node - Apontador para o nodo a eliminar.
**/
void AdjListNodeDestroy(AdjListNode* node) {
    free(node);
}

/**
    @brief  Função que elimina uma adjacência.
    @param  listAdj - Apontador para o início da lista de adjacências.
    @param  codAdj  - Valor do vértice a eliminar adjacência.
    @param  res     - Variável de controlo de sucesso.
    @retval         - Apontador para o início da lista de adjacências.
**/
AdjListNode* DeleteAdj(AdjListNode* listAdj, int codAdj, bool* res) {
    *res = false;
    if (listAdj == NULL) return NULL;
    //Procura a adjacência a eliminar.
    AdjListNode* aux = listAdj;
    AdjListNode* prev = NULL;
    while (aux && aux->value != codAdj) {
        prev = aux;
        aux = aux->next;
    }
    if (!aux) return listAdj; //A adjacência que queremos eliminar já não existe.
    //A adjacência a eliminar é o início.
    if (prev == NULL) {
        listAdj = aux->next;
    }
    else {
        prev->next = aux->next;
    }
    AdjListNodeDestroy(aux);
    *res = true;
    return listAdj;
}

/**
    @brief  Função que elimina todas as adjacências de um vértice.
    @param  listAdj - Apontador para o início da lista de adjacências do vértice a eliminar.
    @param  res     - Variável de controlo de sucesso.
    @retval         - Apontador para o início da lista de adjacências do vértice.
**/
AdjListNode* DeleteAllAdj(AdjListNode* listAdj, bool* res) {
    *res = false;
    if (listAdj == NULL)return NULL;
    //Percorre a lista e elimina as adjacências.
    AdjListNode* aux = listAdj;
    while (aux) {
        if (aux){
            listAdj = aux->next;
            AdjListNodeDestroy(aux);
            aux = listAdj;
        }
    }
    listAdj = NULL;
    *res = true;
    return listAdj;
}

/**
    @brief  Função que elimina a adjacência de um nodo com todos os outros nodos.
    @param  node   - Apontador para o início da lista de nodos.
    @param  codAdj - Valor do nodo a eliminar.
    @param  res    - Variável de controlo de sucesso.
    @retval        - Apontador para o início da lista de nodos.
**/
Node* DeleteAdjacenceAllNodes(Node* node, int codAdj, bool* res) {
    *res = false;
    if (node == NULL) return NULL;
    Node* aux = node;
    while (aux) {
        aux->next = DeleteAdj(aux->next, codAdj, res);
        aux = aux->nextNode;
    }
    *res = true;
    return node;
}

/**
    @brief  Função que cria uma adjacência.
    @param  listAdj - Apontador para o início da lista de adjacências.
    @param  idDest  - ID do vértice de destino.
    @param  weight  - Peso da aresta.
    @retval         - Apontador para o início da lista de adjacências.
**/
AdjListNode* InsertAdj(AdjListNode* listAdj, int idDest, int weight) {
    AdjListNode* newAdj;
    if ((newAdj = NewAdjacent(idDest, weight)) == NULL) return listAdj; //Impossível criar a nova adjacência.
    //Caso ainda não existam adjacências na lista:
        if (listAdj == NULL) {
            listAdj = newAdj; //Insere no inicio.
        }
        else {//Insere a adjacência no fim.
            AdjListNode* aux = listAdj;
            while (aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = newAdj;
        }
        return listAdj;
}

#pragma endregion

#pragma region Graphs
/**
    @brief  Função que insere um nodo num grafo.
    @param  graph - Apontador para o grafo.
    @param  node  - Apontador para o nodo a inserir no grafo.
    @param  res   - Variável de controlo de sucesso.
    @retval       - Apontador para o grafo.
**/
GR* InsertNodeGraph(GR* graph, Node* node, int res) {
    res = 1;
    //Verificações:
    if (node == NULL) { //Vértice Inválido
        res = 0;
        return graph;
    }
    if (graph == NULL) { //Não existe grafo.
        res = -1;
        return NULL;
    }
    if (ExistNodeGraph(graph, node->value)) {
        res = -2;
        return graph;
    }
    graph->headGraph = InsertNode(graph->headGraph, node, &res);
    if (res == true)graph->numNodes++;
    return graph;
}

/**
    @brief  Função que elimina um nodo de um grafo.
    @param  graph   - Apontador para o grafo.
    @param  codNode - Código do nodo a eliminar.
    @param  res     - Variável de controlo de sucesso.
    @retval         - Apontador para o grafo.
**/
GR* DeleteNodeGraph(GR* graph, int codNode, bool* res) {
    *res = false;
    if (graph == NULL)return NULL;

    graph->headGraph = DeleteNode(graph->headGraph, codNode, res);
    graph->headGraph = DeleteAdjacenceAllNodes(graph->headGraph, codNode, res);
    if (*res == true) graph->numNodes--;
    return graph;
}

/**
    @brief  Função que elimina uma adjacência de um grafo.
    @param  graph   - Apontador para o grafo.
    @param  origin  - ID do vértice de origem.
    @param  destiny - ID do vértice de destino
    @param  res     - Variável de controlo de sucesso.
    @retval         - Apontador para o grafo.
**/
GR* DeleteAdjGraph(GR* graph, int origin, int destiny, bool* res) {
    *res = false;
    if (graph == NULL)return NULL;
    //Verificar se os vértices de origem e destino existem no grafo.
    Node* originNode = WhereIsNodeGraph(graph,origin);
    if (originNode == NULL)return graph;
    Node* destinyNode = WhereIsNodeGraph(graph, destiny);
    if (destinyNode == NULL)return graph;

    originNode->next = DeleteAdj(originNode->next, destiny, res);
    return graph;
}

/**
    @brief  Função que procura um nodo num grafo.
    @param  graph  - Apontador para o grafo.
    @param  idNode - ID do nodo a procurar.
    @retval        - Retorna o nodo procurado, caso exista. Caso contrário, retorna NULL.
**/
Node* WhereIsNodeGraph(GR* graph, int idNode){
    if (graph == NULL)return NULL;
    return(WhereisNode(graph->headGraph, idNode));
}

/**
    @brief  Função que insere uma adjacência num grafo.
    @param  graph     - Apontador para o grafo.
    @param  idOrigin  - ID do vértice de origem.
    @param  idDestiny - ID do vértice de destino.
    @param  weight    - Peso da aresta.
    @param  res       - Variáavel de controlo de sucesso.
    @retval           - Apontador para o grafo.
**/
GR* InsertAdjaGraph(GR* graph, int idOrigin, int idDestiny, int weight, bool* res) {
    *res = false;
    if (graph == NULL)return NULL;
    Node* originNode = WhereIsNodeGraph(graph, idOrigin);
    if (originNode == NULL)return graph;
    Node* destinyNode = WhereIsNodeGraph(graph, idDestiny);
    
    //Se não existir o vértice de destino, cria-o e insere-o no grafo.
    if (destinyNode == NULL) {
        destinyNode=CreateNode(idDestiny);
        graph=InsertNodeGraph(graph, destinyNode, res);
    }

    originNode->next = InsertAdj(originNode->next, idDestiny, weight);
    return graph;
}

/**
    @brief  Função que aloca memória para e inicia um grafo.
    @param  v - Número de vértices a incluir num grafo.
    @retval   - Apontador para o grafo.
**/
GR* CreateGraph(int v) {
    GR* aux = (GR*)malloc(sizeof(GR));;
    if (aux != NULL) {
        aux->headGraph = NULL;
        aux->numNodes = v;
    }
    return aux;
}

/**
    @brief  Função que verifica se um nodo existe num grafo.
    @param  graph  - Apontador para o grafo.
    @param  idNode - ID do nodo a procurar.
    @retval  true  - Caso o nodo exista.
    @retval  false  - Caso o nodo não exista.
**/
bool ExistNodeGraph(GR* graph, int idNode) {
    if (graph == NULL)return false;
    return(ExistNode(graph->headGraph, idNode));
}

#pragma endregion
/**
    @brief Função que mostra um grafo.
    @param graph - Apontador para o grafo a mostrar.
**/
void ShowGraph(GR* graph) {
    Node* current = graph->headGraph;
    while (current != NULL){

        printf("\nVertice %d->\n", current->value); //Mostra o vértice
        AdjListNode* adjacent = current->next;
        while (adjacent!=NULL)
        {
            printf("\t\t adjacent: %d \t  weight: %d\n", adjacent->value, adjacent->weight);
            adjacent = adjacent->next;
        }
        current = current->nextNode;
    }
}