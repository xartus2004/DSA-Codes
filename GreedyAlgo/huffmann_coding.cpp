// #include <bits/stdc++.h>
// using namespace std;

// class Node {
// public:
//     char ch;
//     int freq;
//     Node* left;
//     Node* right;
    
//     Node(char _ch, int _freq) {
//         ch = _ch;
//         freq = _freq;
//         left = nullptr;
//         right = nullptr;
//     }
// };

// class CompareNodes {
// public:
//     bool operator()(Node* a, Node* b) {
//         return a->freq > b->freq;
//     }
// };

// class Huffman {
// public:
//     Node* buildTree(priority_queue<Node*, vector<Node*>, CompareNodes>& pq) {
//         while (pq.size() > 1) {
//             Node* l = pq.top(); pq.pop();
//             Node* r = pq.top(); pq.pop();
//             int f = l->freq + r->freq;
//             Node* n = new Node(' ', f);
//             n->left = l;
//             n->right = r;
//             pq.push(n);
//         }
//         return pq.top();
//     }

//     void generateCodes(Node* r, string c, unordered_map<char, string>& codes) {
//         if (!r) return;
//         if (r->ch != ' ') codes[r->ch] = c;
//         generateCodes(r->left, c + "0", codes);
//         generateCodes(r->right, c + "1", codes);
//     }
// };

// int main() {
//     string s;
//     cout << "Enter input string: "; cin >> s;

//     unordered_map<char, int> freq;
//     for (char c : s) freq[c]++;

//     priority_queue<Node*, vector<Node*>, CompareNodes> pq;
//     for (auto e : freq) pq.push(new Node(e.first, e.second));

//     Huffman huffman;
//     Node* root = huffman.buildTree(pq);

//     unordered_map<char, string> codes;
//     huffman.generateCodes(root, "", codes);

//     cout << "Huffman Codes:\n";
//     for (auto e : codes) cout << e.first << ": " << e.second << "\n";

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char ch;
    int freq;
    Node* left;
    Node* right;
    
    Node(char _ch, int _freq) {
        ch = _ch;
        freq = _freq;
        left = nullptr;
        right = nullptr;
    }
};

class CompareNodes {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

class Huffman {
public:
    Node* buildTree(priority_queue<Node*, vector<Node*>, CompareNodes>& pq) {
        while (pq.size() > 1) {
            Node* l = pq.top(); pq.pop();
            Node* r = pq.top(); pq.pop();
            int f = l->freq + r->freq;
            Node* n = new Node(' ', f);
            n->left = l;
            n->right = r;
            pq.push(n);
        }
        return pq.top();
    }

    void generateCodes(Node* r, string c, unordered_map<char, string>& codes) {
        if (!r) return;
        if (r->ch != ' ') codes[r->ch] = c;
        generateCodes(r->left, c + "0", codes);
        generateCodes(r->right, c + "1", codes);
    }
};

int main() {
    string s;
    cout << "Enter input string: "; cin >> s;

    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    priority_queue<Node*, vector<Node*>, CompareNodes> pq;
    for (auto e : freq) pq.push(new Node(e.first, e.second));

    Huffman huffman;
    Node* root = huffman.buildTree(pq);

    unordered_map<char, string> codes;
    huffman.generateCodes(root, "", codes);

    cout << "Huffman Codes:\n";
    for (auto e : codes) cout << e.first << ": " << e.second << "\n";

    return 0;
}

