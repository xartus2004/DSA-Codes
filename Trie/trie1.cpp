#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26];
    bool flag=false;

    bool containsKey(char ch)
    {
        return(links[ch-'a']!=NULL);
    }

    void put(char ch,Node *node)
    {
        links[ch-'a']=node;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    void setEnd()
    {
        flag=true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:

    /*Constructor*/
    Trie(){
        root=new Node();
    }

    void insert(string word)
    {
        Node *node=root;
        for(int i=0 ; i<word.size() ; i++)
        {
            if(!node->containsKey(word[i]))
                node->put(word[i],new Node());
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node* node = root;
        for(int i=0 ; i<word.size() ; i++)
        {
            if(!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool search(string prefix)
    {
        Node* node = root;
        for(int i=0 ; i<prefix.size() ; i++)
        {
            if(!node->containsKey(prefix[i]))
                return false;
        }
        return true;
    }
};

int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}