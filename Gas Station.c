int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int idx=0;
    int sumgas = 0, sumcost = 0, total=0, start_idx = 0;
    for(int i=0;i<gasSize;i++) {
        sumgas+=gas[i];
        sumcost +=cost[i];
    }
    if(sumcost>sumgas)
        return -1;
    for(int i=0;i<gasSize;i++) {
        total+=gas[i]-cost[i];
        if(total<0) {
            total=0;
            start_idx = i+1;
        }
    }
    return start_idx;
}
