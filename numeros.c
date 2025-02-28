#include <stdio.h>

typedef struct{
    int lidos[4];
    int num[2];
} NUMS;

void le(int qtd, NUMS* nums);
void compara(int qtd, NUMS* nums);
void imprime(int qtd, NUMS* nums);

int main() {
    int qtd;
    printf("Quantidade de comparações: ");
    scanf("%d", &qtd);
    NUMS nums[qtd];
    le(qtd, nums);
    compara(qtd, nums);
    imprime(qtd, nums);

    return 0;
}

void le(int qtd, NUMS* nums) {
    for(int i=0; i<qtd; i++) {
        printf("Digite 4 numeros: ");
        scanf("%d %d %d %d", &nums[i].lidos[0], &nums[i].lidos[1], &nums[i].lidos[2], &nums[i].lidos[3]);
    }
}

void compara(int qtd, NUMS* nums) {
    for(int i=0; i<qtd; i++) {
        nums[i].num[0]=0;
        nums[i].num[1]=0;
        for (int j = 0; j < 4; j++) {
            if (nums[i].lidos[j] > nums[i].num[0]) {
                nums[i].num[1] = nums[i].num[0]; // O maior anterior vira o segundo maior
                nums[i].num[0] = nums[i].lidos[j]; // Atualiza o maior número
            } else if (nums[i].lidos[j] > nums[i].num[1]) {
                nums[i].num[1] = nums[i].lidos[j]; // Atualiza o segundo maior número
            }
        }
    }
}

void imprime(int qtd, NUMS* nums) {
    for(int i=0; i<qtd; i++) {
        printf("Maiores numeros do vetor %d: %d %d\n", i+1, nums[i].num[0], nums[i].num[1]);
    }
}
