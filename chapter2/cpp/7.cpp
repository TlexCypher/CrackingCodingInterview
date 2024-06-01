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
struct Result {
  Node *node;
  int length;
  Result(Node *node, int length) : node(node), length(length){};
};
struct Result2 {
  Node *intersectStart;
  bool hasIntersect;
  Result2(Node *intersectStart, bool hasIntersect)
      : intersectStart(intersectStart), hasIntersect(hasIntersect) {}
};
Result getTailAndLength(Node *node) {
  int length = 1;
  while (node->next != nullptr) {
    node = node->next;
    length++;
  }
  return Result(node, length);
}
Node *goAhead(Node *node, int k) {
  int cnt = k;
  while (cnt-- && node != nullptr) {
    node = node->next;
  }
  return node;
}

Result2 hasIntersectNode(Node *node1, Node *node2) {
  Result res1 = getTailAndLength(node1);
  Result res2 = getTailAndLength(node2);
  if (res1.node != res2.node) {
    return Result2(nullptr, false);
  }
  Node *shorter = (res1.length < res2.length ? node1 : node2);
  Node *longer = (res1.length >= res2.length ? node1 : node2);
  longer = goAhead(longer, abs(res1.length - res2.length));
  while (shorter != longer) {
    shorter = shorter->next;
    longer = longer->next;
  }
  return Result2(shorter, true);
}
}; // namespace solver
