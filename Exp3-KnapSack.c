#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight, value;
    double ratio;
};

int cmp(const void *a, const void *b) {
    struct Item *i1 = (struct Item*)a;
    struct Item *i2 = (struct Item*)b;
    if (i2->ratio > i1->ratio) return 1;
    else if (i2->ratio < i1->ratio) return -1;
    else return 0;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter weight and value for each item (w v):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    qsort(items, n, sizeof(struct Item), cmp);

    double totalValue = 0.0;
    int curWeight = 0;

    printf("\nItems taken:\n");
    for (int i = 0; i < n; i++) {
        if (curWeight + items[i].weight <= W) {
            curWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d: weight=%d, value=%d (100%% taken)\n",
                   i+1, items[i].weight, items[i].value);
        } else {
            int remain = W - curWeight;
            double fraction = (double)remain / items[i].weight;
            totalValue += items[i].value * fraction;
            curWeight = W;
            printf("Item %d: weight=%d, value=%d (%.2f%% taken)\n",
                   i+1, items[i].weight, items[i].value, fraction * 100);
            break;
        }
    }

    printf("\nMaximum value in knapsack = %.2f\n", totalValue);

    return 0;
}
