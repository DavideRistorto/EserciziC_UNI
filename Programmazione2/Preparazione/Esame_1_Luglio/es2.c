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
int count_ric(CharTree tree, int m, int n, int deep) {
	if (tree == NULL) {
		return 0;
	}
	if (m <= deep && deep <= n) {
		return 1 + count_ric(tree->left, m, n, deep + 1) + count_ric(tree->right, m, n, deep + 1);
	} else {
		return count_ric(tree->left, m, n, deep + 1) + count_ric(tree->right, m, n, deep + 1);
	}
}

int count(CharTree tree, int m, int n) {
	if (m < 0) m = 0;
	if (m > n) return 0;  // Se m > n, non ci sono profondità valide da considerare
	return count_ric(tree, m, n, 0);
}

// Funzione di utilità per creare un nuovo nodo dell'albero
CharTree createNode(char data) {
	CharTree newNode = (CharTree)malloc(sizeof(CharTreeNode));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->left = newNode->right = NULL;
	}
	return newNode;
}

int main() {
	// Costruzione dell'albero di esempio
	CharTree root = createNode('R');
	root->left = createNode('F');
	root->right = createNode('Z');
	root->left->left = createNode('D');
	root->right->right = createNode('H');
	root->left->left->left = createNode('G');
	root->right->right->right = createNode('L');
	root->left->left->left->left = createNode('I');
	root->right->right->right->right = createNode('M');

	int m = -2, n = 3;
	printf("Number of nodes between depth %d and %d: %d\n", m, n, count(root, m, n));
	return 0;
}
