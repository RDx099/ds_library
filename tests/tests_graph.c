// =============================
// TEST CASES BY Jitendra Kumar Sharma
// =============================

int main() {
    printf("===== TEST CASE 1 =====\n");
    struct Graph* g1 = createGraph(5, 0); // Undirected Graph

    addEdge(g1, 0, 1);
    addEdge(g1, 0, 4);
    addEdge(g1, 1, 2);
    addEdge(g1, 1, 3);
    addEdge(g1, 1, 4);
    addEdge(g1, 2, 3);
    addEdge(g1, 3, 4);

    bfs(g1, 0);
    dfs(g1, 0);
    printf("Cycle Detected: %s\n", detectCycle(g1) ? "Yes" : "No");
    freeGraph(g1);

    printf("\n===== TEST CASE 2 =====\n");
    struct Graph* g2 = createGraph(4, 1); // Directed Graph

    addEdge(g2, 0, 1);
    addEdge(g2, 0, 2);
    addEdge(g2, 1, 2);
    addEdge(g2, 2, 3);

    bfs(g2, 0);
    dfs(g2, 0);
    printf("Cycle Detected: %s\n", detectCycle(g2) ? "Yes" : "No");
    freeGraph(g2);

    printf("\n===== TEST CASE 3 =====\n");
    struct Graph* g3 = createGraph(3, 0); // Small Undirected Cycle

    addEdge(g3, 0, 1);
    addEdge(g3, 1, 2);
    addEdge(g3, 2, 0);

    bfs(g3, 0);
    dfs(g3, 0);
    printf("Cycle Detected: %s\n", detectCycle(g3) ? "Yes" : "No");
    freeGraph(g3);

    printf("\nAll test cases executed successfully.\n");
    return 0;
}
