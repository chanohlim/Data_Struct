#include <stdio.h>
#include <stdlib.h>

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;
typedef int ElementType;

struct AVLNode { // 노드 구조체 정의

    ElementType Element;
    AVLTree Left;
    AVLTree Right;
    int Height;
    int Index;

}node;

int Height(Position P){ // 높이 구하는 함수

    if (P == NULL)
        return -1;
    else
        return P->Height;
}

int Max(int a, int b){ // 최대값 구하는 함수

    return a > b ? a : b;
}

Position SingleRotatedWithLeft(Position K2){ // LL

    Position K1;

    K1 = K2->Left;

    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), K2->Height) + 1;

    return K1;
}

Position SingleRotatedWithRight(Position K2){ // RR

    Position K1;

    K1 = K2->Right;

    K2->Right = K1->Left;
    K1->Left = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), K2->Height) + 1;

    return K1;
}

static Position DoubleRotatedWithLeft(Position K3){ // LR = RR -> LL

    K3->Left = SingleRotatedWithRight(K3->Left);

    return SingleRotatedWithLeft(K3);
}

static Position DoubleRotatedWithRight(Position K3){ // RL = LL -> RR

    K3->Right = SingleRotatedWithLeft(K3->Right);

    return SingleRotatedWithRight(K3);
}

AVLTree Insert(ElementType X, AVLTree T){ // 삽입 함수


    if(T == NULL){
        T = (AVLTree)malloc(sizeof(node));
        if(T == NULL){
            printf("FatalError: Out of Space!");
            return T;
        }
        else {
            T->Element = X;
            T->Left = NULL;
            T->Right = NULL;
        }
    }
    else if (X < T->Element){
        T->Left = Insert(X, T->Left);
        if(Height(T->Left) - Height(T->Right) == 2) {
            if (X < T->Left->Element)
                T = SingleRotatedWithLeft(T);
            else
                T = DoubleRotatedWithLeft(T);
        }
    }
    else if (X > T->Element){
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2){
            if (X > T->Right->Element)
                T = SingleRotatedWithRight(T);
            else
                T = DoubleRotatedWithRight(T);
        }
    }
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;

    return T;
}

Position Find(ElementType X, AVLTree T){

    if (T == NULL)
        return NULL;

    if (X < T->Element)
        return Find(X, T->Left);
    else if (X > T->Element)
        return Find(X, T->Right);
    else /* X == T->Element */
        return T;
}

Position FindMax(AVLTree T){

    while(T->Right != NULL)
        T = T->Right;

    return T;
}

Position FindMin(AVLTree T){

    while(T->Left != NULL)
        T = T->Left;

    return T;
}

void PrintTree(AVLTree T){

    if(T != NULL){
        PrintTree(T->Left);
        printf("%c ", T->Element);
        PrintTree(T->Right);
    }
}

void PrintTreeStructure(AVLTree T, int depth){

    if(T != NULL){
        PrintTreeStructure(T->Right, depth + 1);
        for(int i = 0; i < depth; i++)
            printf("    ");
        printf("%c\n", T->Element);
        PrintTreeStructure(T->Left, depth+1);

    }

}

void PrintTreeIndexStructure(AVLTree T, int depth){

    if(T != NULL){
        PrintTreeIndexStructure(T->Right, depth + 1);
        for(int i = 0; i < depth; i++)
            printf("    ");
        printf("%d\n", T->Index);
        PrintTreeIndexStructure(T->Left, depth+1);

    }

}

int main() {

    AVLTree T = NULL;
    Position tmp;

    char input[5];
    int i = 0;
    printf("input: ");
    scanf("%s",input);

    while(input[0] != 'e'&& input[1] != 'n' && input[2] != 'd'){
        T = Insert(input[0], T);
        tmp = Find(input[0],T);
        tmp->Index = i;
        i++;
        printf("input: ");
        scanf("%s",input);
    }

    printf("\nTree structure:\n\n");
    PrintTreeStructure(T, 0);

    printf("\nTree Index structure:\n\n");
    PrintTreeIndexStructure(T, 0);

    printf("MAX: %c\n", FindMax(T)->Element);
    printf("MIN: %c\n", FindMin(T)->Element);

    return 0;
}