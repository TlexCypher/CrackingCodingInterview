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

namespace solver {
useful::Node *divideList(useful::Node *node, int border) {
  int count = 0;
  useful::Node *cur = node;
  while (cur != nullptr) {
    if (cur->data < border) {
      count++;
    }
    cur = cur->next;
  }

  useful::Node *head = node;
  useful::Node *last = node;
  for (int i = 0; i < count; i++) {
    last = last->next;
  }
  for (int i = 0; i < count; i++) {
    if (head->data >= border) {
      while (last != nullptr && last->data >= border) {
        last = last->next;
      }
      swap(head->data, last->data);
    }
    head = head->next;
  }
  return node;
}
}; // namespace solver

int main(void) {
  useful::Node *root = useful::buildLinkedList(useful::getInputForLinkedList());
  int border;
  cin >> border;
  useful::Node *head = solver::divideList(root, border);
  useful::walk(head);
}
