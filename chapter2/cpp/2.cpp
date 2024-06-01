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
int getLastK(useful::Node *head, int k) {
  useful::Node *ahead = head;
  for (int i = 0; i < k; i++) {
    ahead = ahead->next;
  }
  useful::Node *last = head;
  while (ahead != nullptr) {
    ahead = ahead->next;
    last = last->next;
  }
  return last->data;
}
} // namespace solver

int main(void) {
  useful::Node *head = useful::buildLinkedList(useful::getInputForLinkedList());
  int k;
  cin >> k;
  cout << solver::getLastK(head, k) << endl;
}
