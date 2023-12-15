#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    int cntEndsWith=0; 
    int cntPrefix=0;

    bool containsKey(char ch){
        return(links[ch-'a']!=NULL);
    }

    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void increaseEnd(){
        cntEndsWith++;
    }

    void increasePrefix(){
        cntPrefix++;
    }

    void deleteEnds(){
        cntEndsWith--;
    }

    void reducePrefix(){
        cntPrefix--;
    }

    int getEnd(){
        return cntEndsWith;
    }
    
    int getPrefix(){
        return cntPrefix;
    }
};

class Trie{
private:
    Node* root;
public:
    /*Constructor*/
    Trie(){
        root=new Node();
    }

    void insert(string word)
    {
        Node* node=root;
        for(int i=0 ; i<word.size() ; i++)
        {
            if(!node->containsKey(word[i]))
                node->put(word[i],new Node());
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word){
        Node* node=root;
        for(int i=0 ; i<word.length() ; i++)
        {
            if(node->containsKey(word[i]))
                node=node->get(word[i]);
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string word)
    {
        Node* node = root;
        for(int i=0 ; i<word.length() ; i++)
        {
            if(node->containsKey(word[i]))
                node=node->get(word[i]);
            else
                return 0;
        }
        return node->getPrefix();
    }

    void erase(string word)
    {
        Node* node=root;

        /*To check if word is even present or not*/
        if(!countWordsEqualTo(word))
            return;
        for(int i=0 ; i<word.length() ; i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else
                return;
        }
        node->deleteEnds();
    }
};

int main() 
{
  Trie T;
  T.insert("apple");
  T.insert("apple");
  T.insert("apps");
  T.insert("apps");
  string word1 = "apps";
  cout<<"Count Words Equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  string word2 = "abc";
  cout<<"Count Words Equal to "<< word2<<" "<<T.countWordsEqualTo(word2)<<endl;
  string word3 = "ap";
  cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)<<endl;
  string word4 = "appl";
  cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)<<endl;
  T.erase(word1);
  cout<<"Count Words equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  return 0;
}