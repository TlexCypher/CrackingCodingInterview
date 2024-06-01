#include <iostream>
#include <vector>

using namespace std;

namespace useful {
struct Node {
  int data;
  Node *next;
  Node(int data) : data(data) {}
};

Node *buildLinkedList(vector<int> arr) {
  Node *root = new Node(arr[0]);
  Node *cur = root;
  for (int i = 1; i < (int)arr.size(); i++) {
    Node *newNode = new Node(arr[i]);
    cur->next = newNode;
    cur = newNode;
  }
  return root;
}

void walk(Node *root) {
  Node *cur = root;
  while (cur != nullptr) {
    cout << cur->data << endl;
    cur = cur->next;
  }
}

vector<int> getInputForLinkedList() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  return a;
}
}; // namespace useful

using namespace useful;

namespace solver {
Node *getLoopStart(Node *head) {
  Node *slow = head;
  Node *fast = head;
  while (fast != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      break;
    }
  }
  if (slow != fast) {
    // we don't have loop
    return nullptr;
  }
  slow = head;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}
}; // namespace solver
