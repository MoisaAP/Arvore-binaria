#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int dado;
	struct nodo *sad;
	struct nodo *sae;
};

struct nodo* novoNodo(int x) {
	struct nodo *p;
	p = malloc(sizeof(struct nodo));
	p->dado = x;
	p->sae = NULL;
	p->sad = NULL;
	return p;
}

int numeroNodos(struct nodo *raiz) {
	if (raiz == NULL) {
		return 0;
	}
	return (numeroNodos(raiz->sae) + 1 + numeroNodos(raiz->sad));
}

int exibirArvore(struct nodo *raiz) {
	if (raiz != NULL) {
		printf("%i", raiz->dado);
		printf("(");
		exibirArvore(raiz->sae);
		exibirArvore(raiz->sad);
		printf(")");
	}
	else {
		printf("()");
	}
}
	
struct nodo* inserir(struct nodo *raiz, int x) {
	if (raiz == NULL) {
		return novoNodo(x);
	}
	else if (x > raiz->dado) {
		raiz->sad = inserir(raiz->sad, x);
	}
	else {
		raiz->sae = inserir(raiz->sae, x);
	}
	return raiz;
}

int encontrarMaior(struct nodo *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->sad == NULL) {
        return raiz->dado;
    }
    return encontrarMaior(raiz->sad);
}

int exibirFolhas(struct nodo *raiz) {
    if (raiz == NULL) {
        return;
    }
    if (raiz->sae == NULL && raiz->sad == NULL) {
        printf("%i ", raiz->dado);
    }
    exibirFolhas(raiz->sae);
    exibirFolhas(raiz->sad);
}

int encontrarMenor(struct nodo *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->sae == NULL) {
        return raiz->dado;
    }
    return encontrarMenor(raiz->sae);
}

	
int main() {
	struct nodo *raiz;
	
	raiz = novoNodo(10);
	inserir(raiz, 15);
	inserir(raiz, 8);
	inserir(raiz, 3);
	inserir(raiz, 4);
	inserir(raiz, 12);
	inserir(raiz, 20);
	inserir(raiz, 9);
	
	printf("Estrutura de arvore: ");
	exibirArvore(raiz);
	
	printf("\n\n");
	
	printf("Total de nodos: %i \n\n", numeroNodos(raiz));
	printf("O Maior valor encontrado na arvore eh: %i\n\n", encontrarMaior(raiz));
	
	printf("Folhas da arvore: ");
	exibirFolhas(raiz);
	
	printf("\n\nO Menor valor encontrado na arvore eh: %i\n\n", encontrarMenor(raiz));

	
	return 0;
}
