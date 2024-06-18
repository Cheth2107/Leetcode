#include <stdlib.h>

// Comparator function to sort jobs by difficulty (primary) and profit (secondary)
int compareJobs(const void* a, const void* b) {
    int* jobA = (int*)a;
    int* jobB = (int*)b;
    if (jobA[0] != jobB[0])
        return jobA[0] - jobB[0]; // sort by difficulty
    return jobB[1] - jobA[1];     // if difficulty is the same, sort by profit
}

// Comparator function to sort workers by their ability
int compareWorkers(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    // Pair jobs with their profits
    int jobs[difficultySize][2];
    for (int i = 0; i < difficultySize; i++) {
        jobs[i][0] = difficulty[i];
        jobs[i][1] = profit[i];
    }

    // Sort jobs by difficulty (and by profit in case of tie)
    qsort(jobs, difficultySize, sizeof(jobs[0]), compareJobs);
    // Sort workers by their ability
    qsort(worker, workerSize, sizeof(int), compareWorkers);

    int maxProfit = 0;
    int currentMaxProfit = 0;
    int jobIndex = 0;

    for (int i = 0; i < workerSize; i++) {
        while (jobIndex < difficultySize && jobs[jobIndex][0] <= worker[i]) {
            if (jobs[jobIndex][1] > currentMaxProfit) {
                currentMaxProfit = jobs[jobIndex][1];
            }
            jobIndex++;
        }
        maxProfit += currentMaxProfit;
    }

    return maxProfit;
}
