#include <iostream>
#include <stack>
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
Node *reversedClone(Node *node) {
  Node *head = nullptr;
  while (node != nullptr) {
    Node *newNode = new Node(node->data);
    newNode->next = head;
    head = newNode;
    node = node->next;
  }
  return head;
}

bool isEqual(Node *node1, Node *node2) {
  while (node1 != nullptr) {
    if (node1->data != node2->data) {
      return false;
    }
    node1 = node1->next;
    node2 = node2->next;
  }
  return true;
}

bool stackSolution(Node *node) {
  stack<int> box;
  Node *slow = node;
  Node *fast = node;
  while (fast != nullptr) {
    slow = slow->next;
    fast = fast->next;
    box.push(slow->data);
  }
  if (fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }
  while (slow != nullptr) {
    if (slow->data != box.top()) {
      return false;
    }
    slow = slow->next;
    box.pop();
  }
  return true;
}
} // namespace solver
