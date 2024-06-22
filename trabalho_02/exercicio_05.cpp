#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printList(const Node* head) {
    const Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

Node* getNodeAt(const Node* head, int index) {
    const Node* temp = head;
    int count = 0;
    while (temp != nullptr && count < index) {
        temp = temp->next;
        count++;
    }
    return const_cast<Node*>(temp);
}

int getListSize(const Node* head) {
    int size = 0;
    const Node* temp = head;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
    return size;
}

Node* binarySearch(Node* head, int target) {
    int left = 0;
    int right = getListSize(head) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        Node* midNode = getNodeAt(head, mid);

        if (midNode == nullptr) {
            return nullptr; // Element not found
        }

        if (midNode->data == target) {
            return midNode;
        } else if (midNode->data < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return nullptr; // Element not found
}

int main() {
    Node* head = nullptr;

    // Adicionar 20 itens à lista
    for (int i = 1; i <= 20; ++i) {
        insert(head, i);
    }

    // Imprimir a lista
    std::cout << "Lista duplamente encadeada:\n";
    printList(head);

    // Realizar busca binária
    int target;
    std::cout << "Digite o valor a ser buscado: ";
    std::cin >> target;

    Node* result = binarySearch(head, target);

    if (result != nullptr) {
        std::cout << "Elemento " << target << " encontrado na lista.\n";
    } else {
        std::cout << "Elemento " << target << " não encontrado na lista.\n";
    }

    // Liberar memória
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}