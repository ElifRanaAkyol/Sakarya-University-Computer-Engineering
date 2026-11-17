#include <stdio.h>
#include <stdlib.h>

int special_sum(int *mat, int satir, int sutun) {
    int sum = 0;

    //satir ve sütunları gezmek için iç içe döngü açtık
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            int current_element = *(mat + (i * sutun) + j);//şimdiki elemanın adresi üzerinden değeri alınır

            // ana köşegeni toplar
            if (i == j) {
                sum += current_element;
            } 
            // ikinci köşegen elemanlarını toplar
            else if (i + j == sutun - 1) {
                sum += current_element;
            }
            //else if bloğu sayesinde ortadaki eleman 2 kere hesaba katılmaz.
        }
    }
    return sum;
}

int main() {
    int N;
    int *matris = NULL;

    // matris boyutu girilir
    printf("matris boyutunu giriniz: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("geçersiz boyut!!\n");
        return 1;
    }

    // matris oluşturulur
    matris = (int *)malloc(N * N * sizeof(int));
    if (matris == NULL) {
        fprintf(stderr, "bellek tahsis edilemedi!\n");
        return 1;
    }
    // elemanlar girilir
    printf("matris elemanlarini giriniz (%d adet):\n", N * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // girilen değer adrese yazılır
            scanf("%d", (matris + (i * N) + j));
        }
    }
    // girilen değerler ile fonskiyon çalıştırılır
    int total = special_sum(matris, N, N);
    // sonuç yazdırılır
    printf("sonuç %d\n", total);

    // matris serbest bırakılır
    free(matris);
    matris = NULL;
    return 0;
}