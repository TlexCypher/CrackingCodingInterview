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
Node *addLinkedList(Node *node1, Node *node2) {
  Node *dummyHead = new Node(-1);
  Node *cur = dummyHead;
  int carryUp = 0;
  while (node1 != nullptr and node2 != nullptr) {
    int sum = node1->data + node2->data + carryUp;
    int div = sum % 10;
    Node *newNode = new Node(div);
    cur->next = newNode;
    carryUp = sum / 10;
    cur = newNode;
    node1 = node1->next;
    node2 = node2->next;
  }
  while (node1 != nullptr) {
    int sum = node1->data + carryUp;
    int div = sum % 10;
    Node *newNode = new Node(div);
    cur->next = newNode;
    carryUp = sum / 10;
    cur = newNode;
    node1 = node1->next;
  }
  while (node2 != nullptr) {
    int sum = node2->data + carryUp;
    int div = sum % 10;
    Node *newNode = new Node(div);
    cur->next = newNode;
    carryUp = sum / 10;
    cur = newNode;
    node2 = node2->next;
  }
  if (carryUp != 0) {
    cur->next = new Node(carryUp);
  }
  return dummyHead->next;
}
}; // namespace solver

int main(void) {
  Node *node1 = buildLinkedList(getInputForLinkedList());
  Node *node2 = buildLinkedList(getInputForLinkedList());
  Node *ans = solver::addLinkedList(node1, node2);
  walk(ans);
}
