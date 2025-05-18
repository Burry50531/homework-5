#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    struct Node* prev;
    int value;
} Node;

Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

int main() {
    // Створюємо три вузли, які замикаються у цикл
    Node* a = create_node(1);
    Node* b = create_node(2);
    Node* c = create_node(3);

    // Формуємо циклічну структуру
    a->next = b;
    b->next = c;
    c->next = a;

    a->prev = c;
    b->prev = a;
    c->prev = b;

    // Видаляємо зовнішні покажчики — вузли вже не доступні
    a = NULL;
    b = NULL;
    c = NULL;

    // Пам'ять для вузлів не звільнена
    // Через циклічні посилання вони взаємно утримують один одного живими
    return 0;
}
