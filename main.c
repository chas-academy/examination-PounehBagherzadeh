#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_ELEVER 5
#define NUM_PROV 13

typedef struct {
    char namn[11];
    int prov[NUM_PROV];
    float medel;
} Elev;

void kapitalisera(char *namn) {
    namn[0] = toupper(namn[0]);
    for (int i = 1; namn[i] != '\0'; i++) {
        namn[i] = tolower(namn[i]); 
    }
}

int main() {
    Elev elever[NUM_ELEVER];


    for (int i = 0; i < NUM_ELEVER; i++) {
        scanf("%s", elever[i].namn); 
        int summa = 0; 
        for (int j = 0; j < NUM_PROV; j++) {
            scanf("%d", &elever[i].prov[j]);
            summa += elever[i].prov[j]; 
        }
        elever[i].medel = summa / (float)NUM_PROV;
    }

    int max_index = 0;
    for (int i = 1; i < NUM_ELEVER; i++) {
        if (elever[i].medel > elever[max_index].medel) {
            max_index = i; 
        }
    }

    kapitalisera(elever[max_index].namn);
    printf("%s\n", elever[max_index].namn); 


    float total_medel = 0.0;
    for (int i = 0; i < NUM_ELEVER; i++) {
        total_medel += elever[i].medel; 

    }
    total_medel /= NUM_ELEVER;

    for (int i = 0; i < NUM_ELEVER; i++) {
        if (elever[i].medel < total_medel) {
            kapitalisera(elever[i].namn);
            printf("%s\n", elever[i].namn);
        
        }
    }

    return 0; 

}