
#include <stdio.h>
#include <string.h>

#define MAX 20

char names[MAX][30];
int graph[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start, char target[]) {
    int queue[MAX], front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while (front < rear) {
        int v = queue[front++];
        printf("%s ", names[v]);

        if (strcmp(names[v], target) == 0)
            found = 1;

        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\nBFS Search: %s\n",
           found ? "File found" : "File not found");
}

void DFSUtil(int v, char target[], int *found) {
    visited[v] = 1;
    printf("%s ", names[v]);

    if (strcmp(names[v], target) == 0)
        *found = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            DFSUtil(i, target, found);
    }
}

void DFS(int start, char target[]) {
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFSUtil(start, target, &found);

    printf("\nDFS Search: %s\n",
           found ? "File found" : "File not found");
}

int main() {
    int start;
    char target[30];

    printf("Enter number of files/directories: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter file/directory names:\n");
    for (int i = 0; i < n; i++)
        scanf("%29s", names[i]);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("Enter starting node index (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting node.\n");
        return 1;
    }

    printf("Enter file/directory to search: ");
    scanf("%29s", target);

    BFS(start, target);
    DFS(start, target);

    return 0;
}
