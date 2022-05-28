#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


struct node {
    char first_name[100];
    int danger_category;
    float  attack_prob;
    struct node *prox;
};

void insertar_lista(struct node **table, int N, char *first_name, int danger_category, float attack_prob){
    int hash =danger_category% N;
    int index=hash;
    struct node *new_node = malloc(sizeof(struct node));
    strcpy(new_node->first_name, first_name);
    new_node->danger_category = danger_category;
    new_node->attack_prob = attack_prob;
    new_node->prox = NULL;
    if (table[index] == NULL){
        table[index] = new_node;
    }
    else{
        struct node *aux = table[index];
        while(table[index] != NULL){
            aux = aux->prox;
        }
        aux->prox = new_node;
    }
}


int main(int argc, char *argv[]) {
    FILE *file;
    file = fopen("mensaje.txt", "r");
    if(file == NULL){
        printf("Error opening file\n");
        return 1;
    }
    struct node *head = NULL;
    struct node *current = NULL;
    char line[100];
    while(fgets(line, 100, file) != NULL){
        char *token = strtok(line, ",");
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        strcpy(new_node->first_name, token);
        token = strtok(NULL, ",");
        new_node->danger_category = atoi(token);
        token = strtok(NULL, ",");
        new_node->attack_prob = atof(token);
        if(new_node->attack_prob == 0){
            new_node->attack_prob = -1;
        }
        new_node->prox = NULL;
        if(head == NULL){
            head = new_node;
            current = new_node;
        }
        else{
            current->prox = new_node;
            current = new_node;
        }
    }
    fclose(file);

    struct node *list1 = NULL;
    struct node *lista1_c = NULL;
    current = head;
    while(current != NULL){
        if(current->danger_category == 1){
            struct node *new_node = (struct node*)malloc(sizeof(struct node));
            strcpy(new_node->first_name, current->first_name);
            new_node->danger_category = current->danger_category;
            new_node->attack_prob = current->attack_prob;
            new_node->prox = NULL;
            if(list1 == NULL){
                list1 = new_node;
                lista1_c = new_node;
            }
            else{
                lista1_c->prox = new_node;
                lista1_c = new_node;
            }
        }
        current = current->prox;
    }

    struct node *list2 = NULL;
    struct node *lista2_c = NULL;
    current = head;
    while(current != NULL){
        if(current->danger_category == 2){
            struct node *new_node = (struct node*)malloc(sizeof(struct node));
            strcpy(new_node->first_name, current->first_name);
            new_node->danger_category = current->danger_category;
            new_node->attack_prob = current->attack_prob;
            new_node->prox = NULL;
            if(list2 == NULL){
                list2 = new_node;
                lista2_c = new_node;
            }
            else{
                lista2_c->prox = new_node;
                lista2_c = new_node;
            }
        }
        current = current->prox;
    }
    struct node *list3 = NULL;
    struct node *lista3_c = NULL;
    current = head;
    while(current != NULL){
        if(current->danger_category == 3){
            struct node *new_node = (struct node*)malloc(sizeof(struct node));
            strcpy(new_node->first_name, current->first_name);
            new_node->danger_category = current->danger_category;
            new_node->attack_prob = current->attack_prob;
            new_node->prox = NULL;
            if(list3 == NULL){
                list3 = new_node;
                lista3_c = new_node;
            }
            else{
                lista3_c->prox = new_node;
                lista3_c = new_node;
            }
        }
        current = current->prox;
    }
    struct node *list4 = NULL;
    struct node *lista4_c = NULL;
    current = head;
    while(current != NULL){
        if(current->danger_category == 4){
            struct node *new_node = (struct node*)malloc(sizeof(struct node));
            strcpy(new_node->first_name, current->first_name);
            new_node->danger_category = current->danger_category;
            new_node->attack_prob = current->attack_prob;
            new_node->prox = NULL;
            if(list4 == NULL){
                list4 = new_node;
                lista4_c = new_node;
            }
            else{
                lista4_c->prox = new_node;
                lista4_c = new_node;
            }
        }
        current = current->prox;
    }
    struct node *list5 = NULL;
    struct node *list5_c = NULL;
    current = head;
    while(current != NULL){
        if(current->danger_category == 5){
            struct node *new_node = (struct node*)malloc(sizeof(struct node));
            strcpy(new_node->first_name, current->first_name);
            new_node->danger_category = current->danger_category;
            new_node->attack_prob = current->attack_prob;
            new_node->prox = NULL;
            if(list5 == NULL){
                list5 = new_node;
                list5_c = new_node;
            }
            else{
                list5_c->prox = new_node;
                list5_c = new_node;
            }
        }
        current = current->prox;
    }

    struct node *lista1_ordenada = NULL;
    struct node *lista1_ordenada_c = NULL;
    struct node *lista1_c_aux = NULL;
    lista1_c = list1;
    while(lista1_c != NULL){
        lista1_c_aux = lista1_c->prox;
        lista1_c->prox = NULL;
        if(lista1_ordenada == NULL){
            lista1_ordenada = lista1_c;
            lista1_ordenada_c = lista1_c;
        }
        else{
            if(lista1_c->attack_prob > lista1_ordenada_c->attack_prob){
                lista1_c->prox = lista1_ordenada;
                lista1_ordenada = lista1_c;
                lista1_ordenada_c = lista1_c;
            }
            else{
                lista1_ordenada_c->prox = lista1_c;
                lista1_ordenada_c = lista1_c;
            }
        }
        lista1_c = lista1_c_aux;
    }

    struct node *lista2_ordenada = NULL;
    struct node *lista2_ordenada_c = NULL;
    struct node *lista2_c_aux = NULL;
    lista2_c = list2;
    while(lista2_c != NULL){
        lista2_c_aux = lista2_c->prox;
        lista2_c->prox = NULL;
        if(lista2_ordenada == NULL){
            lista2_ordenada = lista2_c;
            lista2_ordenada_c = lista2_c;
        }
        else{
            if(lista2_c->attack_prob > lista2_ordenada_c->attack_prob){
                lista2_c->prox = lista2_ordenada;
                lista2_ordenada = lista2_c;
                lista2_ordenada_c = lista2_c;
            }
            else{
                lista2_ordenada_c->prox = lista2_c;
                lista2_ordenada_c = lista2_c;
            }
        }
        lista2_c = lista2_c_aux;
    }

    struct node *lista3_ordenada = NULL;
    struct node *lista3_ordenada_c = NULL;
    struct node *lista3_c_aux = NULL;
    lista3_c = list3;
    while(lista3_c != NULL){
        lista3_c_aux = lista3_c->prox;
        lista3_c->prox = NULL;
        if(lista3_ordenada == NULL){
            lista3_ordenada = lista3_c;
            lista3_ordenada_c = lista3_c;
        }
        else{
            if(lista3_c->attack_prob > lista3_ordenada_c->attack_prob){
                lista3_c->prox = lista3_ordenada;
                lista3_ordenada = lista3_c;
                lista3_ordenada_c = lista3_c;
            }
            else{
                lista3_ordenada_c->prox = lista3_c;
                lista3_ordenada_c = lista3_c;
            }
        }
        lista3_c = lista3_c_aux;
    }


    struct node *lista4_ordenada = NULL;
    struct node *lista4_ordenada_c = NULL;
    struct node *lista4_c_aux = NULL;
    lista4_c = list4;
    while(lista4_c != NULL){
        lista4_c_aux = lista4_c->prox;
        lista4_c->prox = NULL;
        if(lista4_ordenada == NULL){
            lista4_ordenada = lista4_c;
            lista4_ordenada_c = lista4_c;
        }
        else{
            if(lista4_c->attack_prob > lista4_ordenada_c->attack_prob){
                lista4_c->prox = lista4_ordenada;
                lista4_ordenada = lista4_c;
                lista4_ordenada_c = lista4_c;
            }
            else{
                lista4_ordenada_c->prox = lista4_c;
                lista4_ordenada_c = lista4_c;
            }
        }
        lista4_c = lista4_c_aux;
    }

    struct node *list5_ordenada = NULL;
    struct node *list5_ordenada_c = NULL;
    struct node *list5_c_aux = NULL;
    list5_c = list5;
    while(list5_c != NULL){
        list5_c_aux = list5_c->prox;
        list5_c->prox = NULL;
        if(list5_ordenada == NULL){
            list5_ordenada = list5_c;
            list5_ordenada_c = list5_c;
        }
        else{
            if(list5_c->attack_prob > list5_ordenada_c->attack_prob){
                list5_c->prox = list5_ordenada;
                list5_ordenada = list5_c;
                list5_ordenada_c = list5_c;
            }
            else{
                list5_ordenada_c->prox = list5_c;
                list5_ordenada_c = list5_c;
            }
        }
        list5_c = list5_c_aux;
    }

    struct node *hash_table[5];

    insertar_lista(hash_table, 5, lista1_ordenada->first_name,lista1_ordenada->danger_category, lista1_ordenada->attack_prob);
    insertar_lista(hash_table, 5, lista2_ordenada->first_name,lista2_ordenada->danger_category, lista2_ordenada->attack_prob);
    insertar_lista(hash_table, 5, lista3_ordenada->first_name,lista3_ordenada->danger_category, lista3_ordenada->attack_prob);
    insertar_lista(hash_table, 5, lista4_ordenada->first_name,lista4_ordenada->danger_category, lista4_ordenada->attack_prob);
    insertar_lista(hash_table, 5, list5_ordenada->first_name,list5_ordenada->danger_category, list5_ordenada->attack_prob);
  
 

      for(int i = 0; i < 5; i++){
        printf("\n");
        printf("%d\n", i);
        struct node *aux = hash_table[i];
        while(aux != NULL){
            printf("%s\n", aux->first_name);
            printf("%f\n", aux->attack_prob);
            aux = aux->prox;
        }
    }

    FILE *output_hash = fopen("salida_hash.txt", "w");
    for (int i = 0; i < 5; i++) {
        struct node *current = hash_table[i];
        while(current != NULL){
            fputs(current->first_name, output_hash);
            fputs("\n", output_hash);
            current = current->prox;
        }
    }
    fclose(output_hash);

}
