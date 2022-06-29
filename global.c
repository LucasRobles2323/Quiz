#include "global.h"

// función para comparar claves de tipo string retorna 1 si son iguales
int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0) return 1;
    return 0;
}

// función para comparar claves de tipo string retorna 1 si son key1<key2
int lower_than_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2) < 0) return 1;
    return 0;
}

// función para comparar claves de tipo int retorna 1 si son iguales
int is_equal_int(void * key1, void * key2) {
    if(*(float*)key1 == *(float*)key2) return 1;
    return 0;
}

// función para comparar claves de tipo int retorna 1 si son key1<key2
int lower_than_int(void * key1, void * key2) {
    if(*(float*)key1 > *(float*)key2) return 1;
    return 0;
}

// función para comparar claves de tipo float retorna 1 si son iguales
int is_equal_float(void * key1, void * key2) {
    if(*(float*)key1 == *(float*)key2) return 1;
    return 0;
}

// función para comparar claves de tipo float retorna 1 si son key1>key2
int lower_than_float(void * key1, void * key2) {
    if(*(float*)key1 > *(float*)key2) return 1;
    return 0;
}


// función que retorna negativo si queremos que  key1 vaya antes que key2 en el mapa, retorna
// 0 si consideramos que las dos claves son iguales y positivo si key1 debe ir antes.
int compare(void * key1, void * key2) {
    const int* Key1 = key1;
    const int* Key2 = key2;
    return (*Key1 - *Key2);
}
//-----------------------------------------//


/*------- Copiar string en un nuevo espacio de memoria -------*/
char * _strdup(const char * str){
	// Recibe un string y la copia en una string nueva con una direccion de 
	// memoria nueva y retorna la nueva string.
    char * aux = (char *)malloc(strlen(str) + 1);
    strcpy(aux, str);
    return aux;
}
//-----------------------------------------//

/*----------------- Eliminar Salto de Linea -----------------*/
void deleteLineBreak(char *beta){
	//Elimina el salto de linea de la ultima palabra si es que lo contiene
	int len;
	len = strlen(beta);
	if (beta[len - 1] == '\n')
	{
		beta = strtok(beta, "\n");
	}
}
//-----------------------------------------//

/*----------------- Lista con los text a abrir -----------------*/
List *separateLine(char *line, char* excluir){
	//Crea una lista con las palabras separadas por el caracter excluido que se recibe (generalmente ';')
	List *newList = createList();
    char *Text = strtok(line, excluir);
	while (Text != NULL)
	{
        pushBack(newList, strdup(Text));
		Text = strtok(NULL, excluir);
	}
	Text = lastList(newList);
	deleteLineBreak(Text);

    return newList;
}
//-----------------------------------------//