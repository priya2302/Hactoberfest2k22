#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

LinkedList mergeSortedLists(LinkedList list1, LinkedList list2) {
    LinkedList mergedList;
    Node* l1 = list1.head;
    Node* l2 = list2.head;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data < l2->data) {
            mergedList.append(l1->data);
            l1 = l1->next;
        } else {
            mergedList.append(l2->data);
            l2 = l2->next;
        }
    }

    while (l1 != nullptr) {
        mergedList.append(l1->data);
        l1 = l1->next;
    }

    while (l2 != nullptr) {
        mergedList.append(l2->data);
        l2 = l2->next;
    }

    return mergedList;
}

int main() {
    LinkedList list1, list2;
    int n, m;

    cout << "Enter the number of elements in the first list: ";
    cin >> n;
    cout << "Enter the elements in ascending order for the first list: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        list1.append(value);
    }

    cout << "Enter the number of elements in the second list: ";
    cin >> m;
    cout << "Enter the elements in ascending order for the second list: ";
    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        list2.append(value);
    }

    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    LinkedList mergedList = mergeSortedLists(list1, list2);
    cout << "Merged List: ";
    mergedList.display();

    return 0;
}
