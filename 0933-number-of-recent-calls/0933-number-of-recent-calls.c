


typedef struct {
    int *timestamps;
    int size;
    int capacity;
    int start;
    int end;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*) malloc(sizeof(RecentCounter));
    obj->capacity = 10000; // Assumed maximum number of pings to handle comfortably
    obj->timestamps = (int*) malloc(obj->capacity * sizeof(int));
    obj->size = 0;
    obj->start = 0;
    obj->end = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    // Add the new request timestamp
    if (obj->size == obj->capacity) {
        // Need to increase capacity if needed
        obj->capacity *= 2;
        obj->timestamps = (int*) realloc(obj->timestamps, obj->capacity * sizeof(int));
    }
    
    obj->timestamps[obj->end] = t;
    obj->end = (obj->end + 1) % obj->capacity;
    obj->size++;
    
    // Remove timestamps that are older than t - 3000
    while (obj->size > 0 && obj->timestamps[obj->start] < t - 3000) {
        obj->start = (obj->start + 1) % obj->capacity;
        obj->size--;
    }
    
    // The current size of the queue is the number of requests in the past 3000 milliseconds
    return obj->size;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->timestamps);
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/