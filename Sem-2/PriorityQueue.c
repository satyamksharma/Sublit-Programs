/*Write functions for the following
1)Initialization
2)Enqueue
3)Dequeue
4)Display

Input Format

1. insert
2. delete
3. display
4. Exit

Output Format

Display Appropriately

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct component
{
    char details[20];
    int priority;
};
typedef struct component compo_t;
struct node
{
    compo_t c;
    struct node *link;
};
typedef struct node node_t;
struct priority_queue
{
    struct node *head;
};
typedef struct priority_queue prio_t;
void init_queue(prio_t *pq);
void enqueue(prio_t *pq, compo_t *c);
void dequeue(prio_t *pq);
void display(const prio_t *pq);

int main()
{
    prio_t q;
    init_queue(&q);
    compo_t c;
    int choice,ele;
    //printf("enter ur choice\n1.insert 2.delete 3.display 4.exit\n");
    scanf("%d",&choice);
    do
    {
        switch(choice)
        {
            case 1: //printf("enter the detail and priority\n");
                scanf("%s %d",c.details, &(c.priority));
                enqueue(&q, &c);
                break;
            case 2: dequeue(&q);
                break;
            case 3: display(&q);
                break;

        }
        //printf("enter ur choice\n1.insert 2.delete 3.display 4.exit\n");
        scanf("%d",&choice);
    }while(choice<4);
    return 0; 
}
void init_queue(prio_t *pq)
{
    pq->head = NULL;
}
void enqueue(prio_t *pq, compo_t *c)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    strcpy(temp->c.details, c->details);
    temp->c.priority = c->priority;
    //temp->link = NULL;
    temp->link = pq->head;
    pq->head = temp;
}
void dequeue(prio_t *pq)
{
    if(pq->head == NULL)
        printf("no elements to delete\n");
    else
    {
        node_t *present = pq->head;
        node_t *prev = NULL;
        node_t *prev_max = NULL;
        int max = 0;
        while(present !=NULL)
        {
            if(present->c.priority>=max)
            {
                max = present->c.priority;
                prev_max = prev;
            }
            prev = present;
            present = present->link;
        }
        compo_t compo;
        if(prev_max != NULL)
        {
            node_t *temp = prev_max->link;
            prev_max->link = temp->link;
            strcpy(compo.details, temp->c.details);
            compo.priority = temp->c.priority;
            free(temp);
        }
        else
        {
            node_t *temp = pq->head;
            pq->head = pq->head->link;
            strcpy(compo.details,temp->c.details);
            compo.priority = temp->c.priority;
            free(temp);
        
        }
        //printf("deleted the node detail is %s with priority%d\n",compo.details,compo.priority);

    }

}   
void display(const prio_t *pq)
{
    node_t *p = pq->head;
    if(p==NULL)
        printf("No element to display\n");
    else{
        while(p != NULL)
        {
            printf("%s %d\n",(p->c).details, (p->c).priority);
            p = p->link;
        }
    }
}