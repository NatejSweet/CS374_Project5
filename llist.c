#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

void ih(struct node **head, int val){
    if (*head == NULL){
        *head = malloc(sizeof(struct node));
        (*head)->data = val;
        (*head)->next = NULL;
    }else{
        struct node *new = malloc(sizeof(struct node));
        new->data = val;
        new->next = *head;
        *head = new;
    }
}

void it(struct node **head, int val){
    if (head == NULL || *head == NULL){
        *head = malloc(sizeof(struct node));
        (*head)->data = val;
        (*head)->next = NULL;
    }else{
        struct node *new = malloc(sizeof(struct node));
        new->data = val;
        new->next = NULL;
        struct node *temp = *head;
        while (temp != NULL && temp->next != NULL){
            temp = temp->next;
        }
        if (temp != NULL) {
            temp->next = new;
        }
    }
}

void dh(struct node **head){
    if (*head == NULL){
        return;
    }else{
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void f(struct node **head){
    while (*head != NULL){
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void p(struct node **head){    
    if (*head == NULL){
        printf("[empty]\n");
        return;
    }
    struct node *temp = *head;
    while (temp != NULL){
        printf("%d", temp->data);
        if (temp->next != NULL){
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    struct node *head = NULL;
    int i = 1;
    while (i<argc) {
        char *cmd = argv[i];
        int val = 0;
        if (i<argc-1){
            val = atoi(argv[i+1]);
        }
        if (strcmp(cmd, "ih") == 0){
            ih(&head, val);
            i = i+2;
        }else if (strcmp(cmd, "it") == 0){
            it(&head, val);
            i = i+2;
        }else if (strcmp(cmd, "dh") == 0){
            dh(&head);
            i=i+1;
        }else if (strcmp(cmd, "f") == 0){
            f(&head);
            i=i+1;
        }else if (strcmp(cmd, "p") == 0){
            p(&head);
            i=i+1;
        }else{
            i=i+1;
        }
        
    }
    exit(0);
}

