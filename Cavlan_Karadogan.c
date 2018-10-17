/*
 * NAME: Cavlan Karadogan
 * Number: 17070001022
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct DLINKED_LIST_NODE_s*DLINKED_LIST_NODE;

typedef struct DLINKED_LIST_NODE_s{
	DLINKED_LIST_NODE next;
	DLINKED_LIST_NODE prev;
	void *data;
}DLINKED_LIST_NODE_t[1];

typedef struct DLINKED_LIST_s*DLINKED_LIST;

typedef struct DLINKED_LIST_s{
	DLINKED_LIST_NODE head;
}DLINKED_LIST_t[1];

DLINKED_LIST dlinked_list_init();
void dlinked_list_free(DLINKED_LIST list);
void dlinked_list_prepend(DLINKED_LIST list,void*data);
void dlinked_list_append(DLINKED_LIST list,void*data);
void dlinked_list_insert(DLINKED_LIST list,void*data,int idx);
void* dlinked_list_remove(DLINKED_LIST list,int idx);
void dlinked_list_search(DLINKED_LIST list, int* sarray, int arraysize);


DLINKED_LIST dlinked_list_init(){
	DLINKED_LIST new = (DLINKED_LIST)malloc(sizeof(DLINKED_LIST_t));
	if(new != NULL){
		new->head = NULL;
	}
	else{
		printf("Error @ dlinked_list_init: Memory allocation.\n");
		exit(1);
	}
	return new;
}

void dlinked_list_append(DLINKED_LIST list, void *data){//gg
	   DLINKED_LIST_NODE new=(DLINKED_LIST_NODE)malloc(sizeof(DLINKED_LIST_NODE_t));
	   DLINKED_LIST_NODE curr=(DLINKED_LIST_NODE)list;
	   //curr=list->head;
	   if(list->head==NULL){
	      new->next=NULL;
	      list->head=new;
	      new->data=data;
	      new->prev=list->head;
	   }
	   else{
	      while(curr->next!=NULL){
	         curr=curr->next;
	         }
	       }
	   new->next=NULL;
	   new->data=data;
	   curr->next=new;
	   new->prev=curr;
	   /*curr=list->head;
	   list->head=new;
	   new->next=curr;
	   curr->next=NULL;*/

}

void dlinked_list_prepend(DLINKED_LIST list, void *data){
	DLINKED_LIST_NODE new;
	new = (DLINKED_LIST_NODE) malloc(sizeof(DLINKED_LIST_NODE_t));
	DLINKED_LIST_NODE curr = (DLINKED_LIST_NODE) list;
	//new->data=data;
	if (curr->next == NULL) {
		curr->next = new;
		new->data = data;
		new->prev = list->head;
		new->next = NULL;
	}
	else {
		new->next = curr->next;
		new->prev = curr;
		curr->next->prev = new;
		new->data = data;
		curr->next = new;
	}
}

void dlinked_list_insert(DLINKED_LIST list, void *data, int idx) {
	DLINKED_LIST_NODE new =(DLINKED_LIST_NODE)malloc(sizeof(DLINKED_LIST_NODE_t));
	DLINKED_LIST_NODE curr =(DLINKED_LIST_NODE)list;
	new->data = data;
	int i;
	if (idx == 0) {
		dlinked_list_prepend(list, data);
	}
	else {
		for (i=0;i<=idx-1; i++) {
			curr=curr->next;
		}
		new->next=curr->next;
		curr->next->prev=new;
		new->prev=curr;
		curr->next=new;
	}
}

void *dlinked_list_remove(DLINKED_LIST list, int idx) { //QQ
	DLINKED_LIST_NODE curr = (DLINKED_LIST_NODE) list;
	int i;
	if(list->head == NULL) {
		printf("!No Node Here!");
		return;
	}
	else{
		for(i = 0; i <=idx; i++)
			curr=curr->next;
		if(curr->next != NULL){
			curr->next->prev = curr->prev;
		}
		if(curr->prev != NULL) {
			curr->prev->next = curr->next;
		}
		free(curr);
	}

}

void dlinked_list_free(DLINKED_LIST list){
	DLINKED_LIST_NODE curr=(DLINKED_LIST_NODE)list;
	while(curr->next!=NULL) {
		curr=curr->next;
		free(curr);
	}
	printf("!list is free!\n");
}

void dlinked_list_print(DLINKED_LIST list){
	DLINKED_LIST_NODE curr;
	curr = (DLINKED_LIST_NODE)list; /* or &list->head */
	while(curr->next != NULL){
		curr = curr->next;
		printf("%d< ", *((int *)curr->data));
	}
	printf("\n");
	fflush(stdout);
}

void dlinked_list_search(DLINKED_LIST list, int* sarray, int arraysize) {
//find the indexes of each number in the search array from the given.
	DLINKED_LIST_NODE curr = (DLINKED_LIST_NODE) list;
	int i, index = 0;
	printf("List 2/2: ");
	for (i=0;i<arraysize;i++){
		printf("%d ", sarray[i]);
	}
	printf("\n");
	printf("found at: ");
	curr=curr->next;
	for (i=0;i<arraysize;i++){
		if (sarray[i]>*((int*) curr->data)){
			curr=curr->next;
			index++;
		}
		else if(sarray[i]<*((int*)curr->data)){
			curr=curr->prev;
			index--;
		}
		if((*(int *)curr->data)==sarray[i]){
			printf("%d   ",index);

		}
		else{
			i--;
		}
		fflush(stdout);
	}
//double linked list and print it out.
}

void test_dlinked_list2() {
    DLINKED_LIST list2 = dlinked_list_init();
    int asize = 10;
    int i;
    int array[10] = { 10, 12, 15, 28, 46, 47, 60, 89, 91, 92 };
    printf("List 2/1: ");
    	for(i=0;i<10;i++){
    		printf("%d ",array[i]);
    	}
    	printf("\n");
    int sarray[10] = { 15, 47, 10, 28, 91, 12, 89, 92, 60, 46 };
    //insert all numbers in the array to the doubled linked list
    for(i=0;i<asize;i++){
    	dlinked_list_append(list2,&array[i]);
    }
    dlinked_list_search(list2, sarray, asize);
}

void test_dlinked_list(){
	int a, b, c, d, e, f;

	a=10; b=34; c=73; d=21; e=82; f=66;

	DLINKED_LIST list1 = dlinked_list_init();
	dlinked_list_remove(list1, 0);       dlinked_list_print(list1);
	dlinked_list_insert(list1, &a, 0);   dlinked_list_print(list1);
	dlinked_list_insert(list1, &c, 0);   dlinked_list_print(list1);
	dlinked_list_append(list1, &a);      dlinked_list_print(list1);
	dlinked_list_prepend(list1, &b);     dlinked_list_print(list1);
	dlinked_list_prepend(list1, &c);     dlinked_list_print(list1);
	dlinked_list_remove(list1, 2);       dlinked_list_print(list1);
	dlinked_list_remove(list1, 2);       dlinked_list_print(list1);
	dlinked_list_prepend(list1, &d);     dlinked_list_print(list1);
	dlinked_list_prepend(list1, &e);     dlinked_list_print(list1);
	dlinked_list_prepend(list1, &f);     dlinked_list_print(list1);

	dlinked_list_print(list1);
    dlinked_list_free(list1);
}

int main(){
	test_dlinked_list();
	test_dlinked_list2();
    return 1;
}


