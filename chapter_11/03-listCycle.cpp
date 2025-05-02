#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
bool hasCycle(ListNode* head) {
  if (head == nullptr || head->next == nullptr) {
    return false;
  }

  ListNode* slow = head;
  ListNode* fast = head->next;

  while (fast != nullptr && fast->next != nullptr) {
    if (slow == fast) {
      return true;
    }
    slow = slow->next;
    fast = fast->next->next;
  }

  return false;
}

int main() {
  // Create a linked list with a cycle
  ListNode head(1);
  ListNode two(2);
  ListNode tail(3);

  head.next = &two;
  two.next = &tail;
  tail.next = &head;  // Creates a cycle

  if (hasCycle(&head)) {
    cout << "The linked list has a cycle." << endl;
  } else {
    cout << "The linked list does not have a cycle." << endl;
  }

  return 0;
}
