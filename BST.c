#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode * SearchTree;
typedef struct TreeNode * Node;
typedef int ElementType;

struct TreeNode{

    ElementType Element;
    SearchTree Left;
    SearchTree Right;

}node;

Node Find(ElementType X, SearchTree T){

    if (T == NULL)
        return NULL;

    if (X < T->Element)
        return Find(X, T->Left);
    else if (X > T->Element)
        return Find(X, T->Right);
    else /* X == T->Element */
        return T;
}

//[임찬오] --(는 재학중이다)--> [한양대]

Node FindMax(SearchTree T){

    while(T->Right != NULL)
        T = T->Right;

    return T;
}

Node FindMin(SearchTree T){

    while(T->Left != NULL)
        T = T->Left;

    return T;
}

SearchTree Insert(ElementType X, SearchTree T){



    if(T == NULL){
        T = (SearchTree)malloc(sizeof(node));
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
    else if (X < T->Element)
        T->Left = Insert(X, T->Left);
    else if (X > T->Element)
        T->Right = Insert(X, T->Right);

    return T;

}

SearchTree Delete(ElementType X, SearchTree T){

    Node tmp;

    if(T == NULL){
        printf("Element not found.");
    }
    else if(X < T->Element)
        T->Left = Delete(X, T->Left);
    else if(X > T->Element)
        T->Right = Delete(X, T->Right);
    else if (T->Left && T->Right){
        tmp = FindMin(T->Right);
        T->Element = tmp->Element;
        T->Right = Delete(T->Element,T->Right);
    }
    else{
        tmp = T;
        if (T->Left == NULL)
            T = T->Right;
        else if (T->Right == NULL)
            T = T->Left;
        free(tmp);
    }
    return T;

}

void PrintTree(SearchTree T){

    if(T != NULL){
        PrintTree(T->Left);
        printf("%d ", T->Element);
        PrintTree(T->Right);
    }

}

void PrintTreeStructure(SearchTree T, int depth){

    if(T != NULL){
        PrintTreeStructure(T->Right, depth + 1);
        for(int i=0; i<depth; i++)
            printf("    ");
        printf("%02d\n", T->Element);
        PrintTreeStructure(T->Left, depth + 1);
    }

}

int main() {
    SearchTree T = NULL;

    T = Insert(20, T);
    T = Insert(10, T);
    T = Insert(30, T);
    T = Insert(5, T);
    T = Insert(15, T);
    T = Insert(25, T);
    T = Insert(35, T);
    T = Insert(3, T);
    T = Insert(8, T);
    T = Insert(13, T);
    T = Insert(18, T);


    printf("Tree elements in sorted order: ");
    PrintTree(T);
    printf("\n");

    int target = 13;
    Node findNode = Find(target,T);
    if(findNode != NULL)
        printf("Target: %d Found: %d\n",target,findNode->Element);
    else
        printf("Target Element is not found!\n");

    Node minNode = FindMin(T);
    if(minNode != NULL)
        printf("Minimum element: %d\n", minNode->Element);

    Node maxNode = FindMax(T);
    if(maxNode != NULL)
        printf("Minimum element: %d\n", maxNode->Element);

    Delete(20,T);
    printf("Tree elements after deleting 20: ");
    PrintTree(T);
    printf("\n");

    printf("Tree structure:\n\n");
    PrintTreeStructure(T,0);

}
