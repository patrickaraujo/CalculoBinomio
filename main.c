#include <stdio.h>

// Versão recursiva (original)
int binomio_recursivo(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return binomio_recursivo(n - 1, k) + binomio_recursivo(n - 1, k - 1);
}

// Versão iterativa (mais eficiente)
int binomio_iterativo(int n, int k) {
    if (k < 0 || k > n)
        return 0; // Caso inválido
    
    // Reduzimos o número de multiplicações aproveitando a simetria: C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
    
    int resultado = 1;
    for (int i = 1; i <= k; i++) {
        resultado *= (n - k + i);
        resultado /= i;
    }
    return resultado;
}

int main() {
    int n, k;
    
    printf("Calculadora de Coeficiente Binomial (n escolhe k)\n");
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    printf("Digite o valor de k: ");
    scanf("%d", &k);
    
    if (n < 0 || k < 0) {
        printf("Erro: n e k devem ser nao-negativos.\n");
        return 1;
    }
    
    if (k > n) {
        printf("Erro: k deve ser menor ou igual a n.\n");
        return 1;
    }
    
    // Usando a versão iterativa (mais eficiente)
    int resultado_iterativo = binomio_iterativo(n, k);
    printf("(Iterativo) O coeficiente binomial C(%d, %d) eh: %d\n", n, k, resultado_iterativo);
    
    // Usando a versão recursiva (para comparação)
    int resultado_recursivo = binomio_recursivo(n, k);
    printf("(Recursivo) O coeficiente binomial C(%d, %d) eh: %d\n", n, k, resultado_recursivo);
    
    return 0;
}
