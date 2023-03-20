/* A ticket counter has a special queue which is used to serve the customers, the special queue holds customers who have a priority value given by the array cust[](where cust[i] denotes the priority value of ith customer). The number of customers in the queue is denoted by n. Customers with higher priority value are served first. If the customers in the queue have the same priority served then they are served on a first come first serve basis. Print the order in which the customers are served(i.e print the order of cust 0 to cust n-1) if the order of arrival of the customers is given by customer number (i.e customer i arrives before customer j if i<j). Solve the problem in nlogn time complexity.

Input Format

4 
3 2 4 2 

Output Format

2 0 1 3

Testcase 1
Input

4 
3 2 4 2
Output

2 0 1 3 */

////CODE-------->
#include<stdio.h>
#include<stdlib.h>

struct customer{
    int priority;
    int num;
};

int compare(const void* a, const void* b){
    struct customer* c1 = (struct customer*)a;
    struct customer* c2 = (struct customer*)b;
    if(c1->priority == c2->priority)
        return c1->num - c2->num;
    else if (c1->priority < c2-> priority)
        return 1;
    else    
        return -1;
}

void printOrder(int n, int* cust){
    struct customer* customers = (struct customer*)malloc(n*sizeof(struct customer));
    for(int i = 0; i<n; i++){
        customers[i].priority = cust[i];
        customers[i].num = i;
    }
    qsort(customers, n, sizeof(struct customer ), compare);
    for(int i = 0; i<n; i++){
        printf("%d ", customers[i].num);
    }
    printf("\n");
    free(customers);
}

int main(){
    int n;
    scanf("%d", &n);
    int* cust = (int*)malloc(n*sizeof(int));
    for(int i = 0; i<n ; i++){
        scanf("%d", &cust[i]);
    }

    printOrder(n, cust);
    free(cust);
    return 0;
}