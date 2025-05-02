#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;

  Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

struct DoublyLinkedList {
  Node* head;
  Node* tail;
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}

  void append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {  // Is empty
      head = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
    }
    tail = newNode;
  }

  void prepend(int value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {  // Is empty
      tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
    }
    head = newNode;
  }

  void deleteNode(int value) {
    Node* current = head;
    while (current != nullptr) {
      if (current->data == value) {
        if (current->prev != nullptr)
          current->prev->next = current->next;
        else
          head = current->next;

        if (current->next != nullptr)
          current->next->prev = current->prev;
        else
          tail = current->prev;

        delete current;
        return;
      }
      current = current->next;
    }
  }

  void displayForward() const {
    Node* current = head;
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }

  void displayBackward() const {
    Node* current = tail;
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->prev;
    }
    cout << endl;
  }

  // Destructor to free memory.
  // This code was intentanionally left out in the book, since we wanted to
  // laser focus on data structure & algorithms rather than language
  // specific memory handling techniqus.

  ~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
      Node* nextNode = current->next;
      delete current;
      current = nextNode;
    }
  }
};

int main() {
  DoublyLinkedList list;
  list.append(1);
  list.append(2);
  list.append(3);
  list.prepend(0);

  cout << "List in forward order: ";
  list.displayForward();  // Output: 0 1 2 3

  cout << "List in backward order: ";
  list.displayBackward();  // Output: 3 2 1 0

  list.deleteNode(2);
  cout << "After deleting node with value 2: ";
  list.displayForward();  // Output: 0 1 3

  return 0; // Return 0 to indicate successful execution
}
