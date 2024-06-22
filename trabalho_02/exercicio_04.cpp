#include <iostream>
using namespace std;

// Estrutura do nó da lista
struct Node {
    char data;
    Node* next;
};

void insert(Node*& head, char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(const Node* head) {
    const Node* temp = head;
    while (temp != nullptr) {
        cout << "Elemento: " << temp->data << "\n";
        cout << "Endereço do elemento: " << temp << "\n";
        cout << "Endereço do próximo: " << &(temp->next) << "\n\n";
        temp = temp->next;
    }
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    char value;

    cout << "Digite 10 caracteres:\n";
    for (int i = 0; i < 10; ++i) {
        cin >> value;
        insert(head, value);
    }

    cout << "\nLista encadeada:\n";
    printList(head);

    deleteList(head);
    return 0;
}
