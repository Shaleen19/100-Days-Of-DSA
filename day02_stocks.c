// Best time to buy and sell stock

#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int bestBuy = prices[0], maxP = 0;
    
    for(int i = 1; i<pricesSize; i++){

        if(prices[i] > bestBuy){

            int profit = prices[i] -bestBuy;
            if(profit > maxP)
                maxP = profit;
        }
        else{
            bestBuy = prices[i];
        }
    }

    if(maxP != 0)
        return maxP;
    else
        return 0;
}

int main(){
    int prices[] = {7,1,5,3,6,4};
    int size = sizeof(prices)/sizeof(prices[0]);
    int result = maxProfit(prices, size);
    printf("Maximum Profit: %d\n", result);
    return 0;
}