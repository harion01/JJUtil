#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

struct HashData {
    int data;   
    int key;
};

struct HashData* hashArray[SIZE]; 
struct HashData* dummyItem;
struct HashData* item;

int hashCode(int key){
    //simple index genetate
    return key % SIZE;
}

struct HashData *Hash_search(int key){               
    //time complex : avg = O(1) / Worst :O(n)
    int count;
    count = 0;
    //get the hash 
    int hashIndex = hashCode(key);  

    //move in array until an empty 
    while(hashArray[hashIndex] != NULL){

        if(hashArray[hashIndex]->key == key)
            return hashArray[hashIndex]; 

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
        count++;
        if(count > SIZE){
            printf("hash search fail! \n");
            return NULL;
        }
    }        

    return NULL;        
}

int Hash_insert(int key,int data){
    //time complex : avg = O(1) / Worst :O(n)
    //create data struct
    int count;
    count = 0;
    struct HashData *item = (struct HashData*) malloc(sizeof(struct HashData));
    item->data = data;  
    item->key = key;     

    //get hash index
    int hashIndex = hashCode(key);

    //move in array until an empty or deleted cell
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){
        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
        count++;
        if(count > SIZE){
            printf("hash full! \n");
            return -1;
        }
    }
    hashArray[hashIndex] = item;        
    printf("Hash_inserted! \n");
    return 0;
}

struct HashData* Hash_delete(struct HashData* item){
    //time complex : avg = O(1) / Worst :O(n)
    int key = item->key;
    int count;
    count = 0;

    //get the hash 
    int hashIndex = hashCode(key);

    //move in array until an empty 
    while(hashArray[hashIndex] != NULL){

        if(hashArray[hashIndex]->key == key){
            struct HashData* temp = hashArray[hashIndex]; 


            //assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem; 
            return temp;
        }

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;

        count++;
        if(count > SIZE){
            printf("hash delete fail! \n");
            return NULL;
        }
    }      

    return NULL;        
}

void display(){
    int i = 0;

    for(i = 0; i<SIZE; i++) {

        if(hashArray[i] != NULL)
            printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
        else
            printf(" ~~ ");
    }

    printf("\n");
}


int main(){

    dummyItem = (struct HashData*) malloc(sizeof(struct HashData));
    dummyItem->data = -1;  
    dummyItem->key = -1; 

    
    Hash_insert(1, 20);
    Hash_insert(2, 70);
    Hash_insert(42, 80);
    Hash_insert(4, 25);
    Hash_insert(12, 44);
    Hash_insert(14, 32);
    Hash_insert(17, 11);
    Hash_insert(13, 78);
    Hash_insert(37, 97);

    display();

    printf("hash search 1\n");
    item = Hash_search(1);

    if(item != NULL){
        printf("Element found: %d\n", item->data);
    }else {
        printf("Element not found\n");
    }

    Hash_delete(item);
    printf("end delete\n");

    printf("hash search 37\n");
    item = Hash_search(37);

    if(item != NULL){
        printf("Element found: %d\n", item->data);
    }else {
        printf("Element not found\n");
    }
    printf("end\n");
    return 0;
}
