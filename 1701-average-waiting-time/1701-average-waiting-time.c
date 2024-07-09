double averageWaitingTime(int** customers, int customersSize, int* customersColSize) {
    double totalWaitingTime = 0;
    int currentTime = 0;
    
    for (int i = 0; i < customersSize; i++) {
        int arrivalTime = customers[i][0];
        int preparationTime = customers[i][1];
        
        if (currentTime <= arrivalTime) {
            currentTime = arrivalTime + preparationTime;
        } else {
            currentTime += preparationTime;
        }
        
        totalWaitingTime += currentTime - arrivalTime;
    }
    
    return totalWaitingTime / customersSize;
}
