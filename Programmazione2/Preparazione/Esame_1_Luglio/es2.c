#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode CharTreeNode, *CharTree;
struct treeNode {
	CharTree left;
	char data;
	CharTree right;
};

/** 
 * @brief Restituisce il numero di nodi dell'albero binario tree di profondità
 * compresa tra m e n (si ricorda che il nodo radice ha profondità 0).
 * ESEMPIO: dato
 *               R
 *             /   \
 *            F     Z
 *           /       \
 *          D         H
 *         /           \
 *        G             L
 *       /               \
 *      I                 M
 * e gli interi -2 e 3 restituisce 7.
 */
int count_ric(CharTree tree, int m, int n, int depth){
	//caso base ricorsivo
	if(tree == NULL){
		return 0;
	}
	int val = 0;
	//caso in cui ci troviamo come profondità nell' intervallo (m,n)
	if(m<=depth && depth<=n){
		val = 1;
	}
	//chiamo la ricorsione per i diversi rami
	return val + count_ric(tree->left, m, n, depth+1) + count_ric(tree->right, m, n, depth+1);
}

int count(CharTree tree, int m, int n) {
	//non serve cercare elementi a profondità negativa
	if(m<0){
		m = 0;
	}
	return count_ric(tree, m, n, 0);
} 
