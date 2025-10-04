//
// Created by rahul on 06-09-2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "stack.h"
#include "queue.h"

struct GraphNode {
    int vertex;
    GraphNode* next;
};

struct Graph {
    int numVertices;
    int isDirected;
    LinkedList** adjLists;
};


GraphNode* createGraphNode(int vertex) {
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}


Graph* createGraph(int numVertices, int isDirected) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (!graph) return NULL;

    graph->numVertices = numVertices;
    graph->isDirected = isDirected;
    graph->adjLists = (LinkedList**)malloc(numVertices * sizeof(LinkedList*));

    for (int i = 0; i < numVertices; i++)
        graph->adjLists[i] = createLinkedList();

    return graph;
}


void addEdge(Graph* graph, int src, int dest) {
    if (!graph || src >= graph->numVertices || dest >= graph->numVertices) return;

    insertAtEnd(graph->adjLists[src], dest);

    if (!graph->isDirected)
        insertAtEnd(graph->adjLists[dest], src);
}// Gaurav Shukla and Gurmeet work till here


void bfs(Graph* graph, int startVertex) {
    if (!graph || startVertex >= graph->numVertices) return;

    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    Queue* queue = createQueue();

    enqueue(queue, startVertex);
    visited[startVertex] = 1;

    while (!isQueueEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex]->head;
        while (temp) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                enqueue(queue, adjVertex);
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }

    printf("\n");
    free(visited);
    freeQueue(queue);
}


void dfsUtil(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex]->head;
    while (temp) {
        int adjVertex = temp->data;
        if (!visited[adjVertex])
            dfsUtil(graph, adjVertex, visited);
        temp = temp->next;
    }
}

void dfs(Graph* graph, int startVertex) {
    if (!graph || startVertex >= graph->numVertices) return;

    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    dfsUtil(graph, startVertex, visited);
    printf("\n");
    free(visited);
}

//devansh harshit
int detectCycleUtil(Graph* graph, int vertex, int* visited, int parent) {
    visited[vertex] = 1;

    Node* temp = graph->adjLists[vertex]->head;
    while (temp) {
        int adjVertex = temp->data;

        if (!visited[adjVertex]) {
            if (detectCycleUtil(graph, adjVertex, visited, vertex))
                return 1;
        }
        else if (adjVertex != parent)
            return 1;

        temp = temp->next;
    }
    return 0;
}
//Gaurav and Devansh
int detectCycle(Graph* graph) {
    if (!graph || graph->isDirected) return 0;

    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (detectCycleUtil(graph, i, visited, -1)) {
                free(visited);
                return 1;
            }
        }
    }
    free(visited);
    return 0;
}


void freeGraph(Graph* graph) {
    if (!graph) return;

    for (int i = 0; i < graph->numVertices; i++)
        freeLinkedList(graph->adjLists[i]);

    free(graph->adjLists);
    free(graph);
}
//code review by Gurmeet and Gaurav
//test cases by Jitendra

