#include <stdio.h>
#include <stdlib.h>

// B-트리의 차수
#define T 3

// B-트리 노드 구조체 정의
typedef struct BTreeNode {
    int keys[2 * T - 1];  // 키 배열
    struct BTreeNode* children[2 * T];  // 자식 노드 배열
    int n;  // 현재 키의 개수
    int leaf;  // 리프 노드 여부 (1: 리프, 0: 내부 노드)
} BTreeNode;

// 새로운 노드 생성
BTreeNode* createNode(int leaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    for (int i = 0; i < 2 * T; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// B-트리 생성
BTreeNode* createBTree() {
    return createNode(1);
}

// 노드 분할
void splitChild(BTreeNode* x, int i) {
    BTreeNode* y = x->children[i];
    BTreeNode* z = createNode(y->leaf);
    z->n = T - 1;

    for (int j = 0; j < T - 1; j++) {
        z->keys[j] = y->keys[j + T];
    }

    if (!y->leaf) {
        for (int j = 0; j < T; j++) {
            z->children[j] = y->children[j + T];
        }
    }

    y->n = T - 1;
    for (int j = x->n; j >= i + 1; j--) {
        x->children[j + 1] = x->children[j];
    }

    x->children[i + 1] = z;
    for (int j = x->n - 1; j >= i; j--) {
        x->keys[j + 1] = x->keys[j];
    }

    x->keys[i] = y->keys[T - 1];
    x->n++;
}

// 삽입 비-가득 노드
void insertNonFull(BTreeNode* x, int k) {
    int i = x->n - 1;

    if (x->leaf) {
        while (i >= 0 && x->keys[i] > k) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = k;
        x->n++;
    } else {
        while (i >= 0 && x->keys[i] > k) {
            i--;
        }
        i++;
        if (x->children[i]->n == 2 * T - 1) {
            splitChild(x, i);
            if (x->keys[i] < k) {
                i++;
            }
        }
        insertNonFull(x->children[i], k);
    }
}

// B-트리에 키 삽입
void insert(BTreeNode** root, int k) {
    BTreeNode* r = *root;
    if (r->n == 2 * T - 1) {
        BTreeNode* s = createNode(0);
        *root = s;
        s->children[0] = r;
        splitChild(s, 0);
        insertNonFull(s, k);
    } else {
        insertNonFull(r, k);
    }
}

// B-트리 출력 (중위 순회)
void traverse(BTreeNode* root) {
    int i;
    for (i = 0; i < root->n; i++) {
        if (!root->leaf) {
            traverse(root->children[i]);
        }
        printf("%d ", root->keys[i]);
    }
    if (!root->leaf) {
        traverse(root->children[i]);
    }
}

// 키 탐색
BTreeNode* search(BTreeNode* root, int k) {
    int i = 0;
    while (i < root->n && k > root->keys[i]) {
        i++;
    }
    if (i < root->n && k == root->keys[i]) {
        return root;
    }
    if (root->leaf) {
        return NULL;
    }
    return search(root->children[i], k);
}

int main() {
    BTreeNode* root = createBTree();

    // B-트리에 키 삽입
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 30);
    insert(&root, 7);
    insert(&root, 17);

    // 중위 순회 출력
    printf("Traversal of B-tree: ");
    traverse(root);
    printf("\n");

    // 키 탐색
    int key = 6;
    BTreeNode* result = search(root, key);
    if (result != NULL) {
        printf("Key %d found in B-tree.\n", key);
    } else {
        printf("Key %d not found in B-tree.\n", key);
    }

    return 0;
}

