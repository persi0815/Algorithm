#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    char left, right;
};

unordered_map<char, Node> tree;  // 트리 저장

// 전위 순회 (Preorder Traversal)
void preorder(char root) {
    if (root == '.') return;
    cout << root;            // root
    preorder(tree[root].left);  // left
    preorder(tree[root].right); // right
}

// 중위 순회 (Inorder Traversal)
void inorder(char root) {
    if (root == '.') return;
    inorder(tree[root].left);  // left
    cout << root;            // root
    inorder(tree[root].right); // right
}

// 후위 순회 (Postorder Traversal)
void postorder(char root) {
    if (root == '.') return;
    postorder(tree[root].left);  // left
    postorder(tree[root].right); // right
    cout << root;            // root
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        tree[root] = {left, right};  // 트리 저장
    }

    // 순회 출력
    preorder('A'); cout << endl;
    inorder('A'); cout << endl;
    postorder('A'); cout << endl;

    return 0;
}
