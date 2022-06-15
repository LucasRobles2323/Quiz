#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    HashNode ** buckets;
    long size; //cantidad de datos/HashNodes en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

HashNode * createHashNode( char * key,  void * value) {
    HashNode * new = (HashNode *)malloc(sizeof(HashNode));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
    char * ptr;

    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    double aux = 3.14159265359;
    aux *= hash;
    hash = (unsigned long) aux;
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertHashMap(HashMap * map, char * key, void * value) {
    if(key==NULL) return;
    long index = hash(key, map->capacity);

    while ((map->buckets[index] != NULL) && (map->buckets[index]->key != NULL))
    {
       if(is_equal(key, map->buckets[index]->key))
       {
           return;
       }
       index = (index + 1) % map->capacity;
    
    }

    if(map->buckets[index] != NULL){
        map->buckets[index]->key =key;
        map->buckets[index]->value = value;
    }
    else{
        map->buckets[index] = createHashNode(key, value);
        map->size++;
    }
    if((double) map->size/(double) map->capacity > 0.75){enlarge(map);}

}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)
    HashNode **aux = (HashNode**) calloc(map->capacity ,sizeof(HashNode*));

    for (size_t i = 0; i < map->capacity; i++)
    {
        aux[i] = map->buckets[i];
    }

    map->capacity *= 2;
    map->buckets = (HashNode**) calloc (map->capacity, sizeof(HashNode*));
    map->size = 0;
    map->current = -1;

    for (size_t i = 0; i < (map->capacity/2); i++)
    {
        if(aux[i] != NULL && aux[i]->key != NULL){
            insertHashMap(map, aux[i]->key, aux[i]->value);
        }
    }
    
    free(aux);
}


HashMap * createHashMap(long capacity) {
    HashMap *Map = (HashMap*) malloc (sizeof(HashMap));
    Map->capacity = capacity;
    Map->current = -1;
    Map->size = 0;
    Map->buckets = (HashNode**) calloc (Map->capacity, sizeof(HashNode*));
    
    return Map;
}

void eraseHashMap(HashMap * map,  char * key) {    
    if(key==NULL) return;
    long index = hash(key, map->capacity);

    while ((map->buckets[index] != NULL) && (map->buckets[index]->key != NULL))
    {
       if(is_equal(key, map->buckets[index]->key))
       {
           map->buckets[index]->key = NULL;
           map->size--;
           return;
       }
       index = (index + 1) % map->capacity;
    
    }

}

void *searchHashMap(HashMap * map,  char * key) {   
    long indice = hash(key, map->capacity);

    while (map->buckets[indice] != NULL)
    {
        if (is_equal(key, map->buckets[indice]->key))
        {
            map->current = indice;
            return map->buckets[indice]->value;
        }
        if(indice < map->capacity){indice++;}
        else{indice = 0;}
    }
    return NULL;
}

void * firstHashMap(HashMap * map) {
    map->current = 0;

    while (map->current < map->capacity)
    {
        if( (map->buckets[map->current] != NULL) && (map->buckets[map->current]->key != NULL) ) {
            return map->buckets[map->current]->value;
        }
        map->current++;
    }
    
    return NULL;
}

void * nextHashMap(HashMap * map) {
    map->current++;
    while (map->current < map->capacity)
    {
        if( (map->buckets[map->current] != NULL) && (map->buckets[map->current]->key != NULL) ) {
            return map->buckets[map->current]->value;
        }
        map->current++;
    }
    
    return NULL;
}