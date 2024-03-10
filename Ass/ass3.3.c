//Nitis Jadipang 66070501020

// Reverse Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int val;
    struct node *next;
} node;

node* create(int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insert(node **start, int val){
    node *newNode = create(val);

    if(*start == NULL){
        *start = newNode;
    } else{
        node *ptr = *start;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void print(node *start){
    node *ptr =start;
    while(ptr != NULL){
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}

void reverse(node **head,int start,int end){
	node *ptr=*head,*prev=NULL,*next,*startre,*prestart;
	int i,j;
	for(i=1;i<start;i++){
		prev = ptr;
		ptr=ptr->next;
	}
	startre = ptr;
	prestart = prev;
	
	for(i=0;i<end-start;i++){
		prev = prestart;
		ptr = startre;
		next = ptr->next;
		for(j=i;j<end-start;j++){
			
			if(j==i){
				startre = next;
				if(prestart != NULL){
					prestart->next = startre;
				}
			}
			
			ptr->next = next->next;
			next->next = ptr;
			
			if(prev == NULL){
				prev = NULL;
			}else{
				prev->next = next;
			}

			
			ptr = next;
			prev = ptr;
			ptr = ptr->next;
			next = ptr->next;
		}
		
	}
		if(prestart == NULL){
			*head = startre;
		}

}

int main(){
	
	node *head=NULL;
	while(1){
		char input[10];
		scanf(" %s",input);
		if(strcmp(input ,"END") == 0){
			break;
		}else{
			int val = atoi(input);
			insert(&head,val);
		}
	}
	
	int start,end;
	scanf("%d %d",&start,&end);
	
	reverse(&head,start,end);
	print(head);
	
	return 0;
}

