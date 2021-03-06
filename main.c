#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct myNode{

    int amount;
    char word[50];
    struct myNode *next;

}myNode;
myNode *newNode, *first = NULL, *temp;
void add(int amount1,char word1[]) {

    if (first == NULL) {
         addToTheHead(amount1,word1);
    }
    else if(searchLinkedList(word1)==0){ //2. gelen 1. den küçük 1. yi basa al ve onu 1.(first) yap
        if ((first->amount) < amount1) {
            addToTheHead(amount1,word1);
        }
        else {
                temp = first;
            while (temp != NULL) { //sona ekleme
                //temp elemaninin next null ise ve son elemandan buyukse
                if (temp->next == NULL && (temp->amount) >= amount1) {
                   addAtTheEnd(amount1,word1);
                    break;
                }
                //Araya Ekleme
                if ((temp->next->amount) < amount1) {
                   interleaving(amount1,word1);
                    break;
                }
                temp = temp->next;
            }
        }
    }
}
int searchLinkedList(char word1[]) {
    int ctrl = 0;
    temp = first;
    while (temp != NULL) {
        if (!strcmp(word1,temp->word)) {
            ctrl = 1;
        }
        temp = temp->next;
    }
    if (ctrl == 1)
        return 1;
    else
        return 0;
}
void addToTheHead(int amount1,char word1[]){

    if (first == NULL) {
        first = (myNode*) malloc(sizeof (myNode));
        first->amount=amount1;
        memcpy(first->word, word1, 50);
        first->next = NULL;
    }
    else{
    newNode = (myNode*) malloc(sizeof (myNode));
    newNode->amount=amount1;
    memcpy(newNode->word, word1, 50);
    newNode->next = first;
    first = newNode;
    }
}
void addAtTheEnd(int amount1,char word1[]){
            newNode = (myNode*) malloc(sizeof (myNode));
            newNode->amount = amount1;
            memcpy(newNode->word, word1, 50);
            newNode->next = NULL;
            temp->next = newNode;

};
void interleaving(int amount1,char word1[]){
            newNode = (myNode*) malloc(sizeof (myNode));
            newNode->amount = amount1;
            memcpy(newNode->word, word1, 50);
            newNode->next = temp->next;
            temp->next = newNode;

};

int calAmount(FILE *f1,char word[]){
     int amount=0;
    f1=fopen("sentence.txt", "r");
    while(!feof(f1)){
              char read[100];
              fscanf(f1,"%s",read);
            if (strcmp(read, word) == 0) {
                amount++;
         }
    }
    fclose(f1);
   return amount;
}
int main() {

    FILE *f1;
    f1=fopen("sentence.txt", "r");
	if (f1 == NULL) return 1;
	while(!feof(f1))
	{   char word1[100];
        fscanf(f1,"%s",word1);
        add(calAmount(f1,word1),word1);

	}

	fclose(f1);

    int j=1;
    struct myNode *list=first;
    while(list!=NULL)
    {
        printf("%d. %d : %s \n",j,list->amount,list->word);
        list=list->next;
        j++;
    }
    return 0;
}
