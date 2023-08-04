#include <stdio.h>
#include <stdlib.h>

int minCoins(int coins[], int m, int amount) {
    int dp[amount + 1];

    // Initialize the dp array
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    dp[0] = 0; // Base case

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i) {
                if (dp[i - coins[j]] != amount + 1 && dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    if (dp[amount] > amount) {
        return -1;
    } else {return dp[amount];}
}

int main() {
    int numCoins, amount;

    printf("Number of values of coins:\n");
    scanf("%d", &numCoins);

    int* coins = (int*)malloc(numCoins * sizeof(int));

    printf("Coins:\n");
    for (int i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Amount:\n");
    scanf("%d", &amount);

    int result = minCoins(coins, numCoins, amount);
    if (result == -1) {
        // printf("-1");
        return -1;
    } else {
        printf("Answer:\n%d", result);
    }

    free(coins);
    return 0;
}
