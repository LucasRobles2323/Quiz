#include "quiz.h"

char *idString(int id){
    char num[4];
    int unidad, decena, centena;
    char u,d,c;

    centena = id /100;
    decena = id - (centena*100);
    decena = decena/10;
    unidad = id % 10;
    c = centena +'0';
    d = decena + '0';
    u = unidad +'0';

    strcpy(num, c);
    strcat(num, d);
    strcat(num, u);

    return num;
}

int idNum(char* id){
    int num = atoi(id);
    return num;
}