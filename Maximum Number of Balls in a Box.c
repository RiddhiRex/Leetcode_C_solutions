int countBalls(int lowLimit, int highLimit) {
        int boxes[55] ={0}; // Maximum sum of digits for a number from 1 to 10^5 is 45, so we need a box of size 55 (0-54)
        int maxballs = 0, total = 0;
        
        for(int i=lowLimit;i<=highLimit;i++) {
            int n = i;
            total=0;
            while(n>0) {
                total+=n%10;
                n=n/10;
            }
            boxes[total-1]+=1;
            if(maxballs<boxes[total-1]) {
                maxballs = boxes[total-1];
            }
        } 
        return maxballs;
        
}
