// Helper function for the max-heap (profits)
int compareProfits(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

// Helper function for the min-heap (capital requirements)
int compareCapital(const void* a, const void* b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

// Max-Heap Insert
void maxHeapInsert(int* heap, int* heapSize, int value) {
    heap[*heapSize] = value;
    (*heapSize)++;
    int i = *heapSize - 1;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = heap[i];
        heap[i] = temp;
        i = (i - 1) / 2;
    }
}

// Max-Heap Extract
int maxHeapExtract(int* heap, int* heapSize) {
    int maxValue = heap[0];
    heap[0] = heap[*heapSize - 1];
    (*heapSize)--;
    int i = 0;
    while ((2 * i + 1) < *heapSize) {
        int j = 2 * i + 1;
        if (j + 1 < *heapSize && heap[j] < heap[j + 1]) j++;
        if (heap[i] >= heap[j]) break;
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
        i = j;
    }
    return maxValue;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    // Create an array to hold projects (capital, profit)
    int projects[profitsSize][2];
    for (int i = 0; i < profitsSize; i++) {
        projects[i][0] = capital[i];
        projects[i][1] = profits[i];
    }
    
    // Sort projects by the capital required
    qsort(projects, profitsSize, sizeof(projects[0]), compareCapital);
    
    // Max-Heap for profits
    int* maxHeap = (int*)malloc(profitsSize * sizeof(int));
    int maxHeapSize = 0;
    
    // Index for the sorted projects array
    int currentIndex = 0;
    
    for (int i = 0; i < k; i++) {
        // Add all projects that can be started with the current capital to the max-heap
        while (currentIndex < profitsSize && projects[currentIndex][0] <= w) {
            maxHeapInsert(maxHeap, &maxHeapSize, projects[currentIndex][1]);
            currentIndex++;
        }
        
        // If the max-heap is empty, we cannot proceed with any more projects
        if (maxHeapSize == 0) {
            break;
        }
        
        // Select the project with the maximum profit
        w += maxHeapExtract(maxHeap, &maxHeapSize);
    }
    
    // Free the allocated memory for maxHeap
    free(maxHeap);
    
    return w;
}