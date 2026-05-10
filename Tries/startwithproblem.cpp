/* Cpp code to implement the startwith a prefix problem */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children;
    bool endOfWord;
    Node()
    {
        endOfWord = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (temp->children.count(ch) == 0)
            {
                temp->children[ch] = new Node();
            }
            temp = temp->children[ch];
        }
        temp->endOfWord = true;
    }

    bool search(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (temp->children.count(ch) == 0)
            {
                return false;
            }
            temp = temp->children[ch];
        }
        return temp->endOfWord;
    }
    bool startsWith(string prefix)
    {
        Node *temp = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            char ch = prefix[i];
            if (temp->children.count(ch) == 0)
            {
                return false;
            }
            temp = temp->children[ch];
        }
        return true;
    }
};

int main()
{
    vector<string> words = {"apple", "app", "mango", "man", "woman"};
    Trie trie;
    for (string word : words)
    {
        trie.insert(word);
    }
    cout << trie.startsWith("app") << endl;  // true
    cout << trie.startsWith("mong") << endl; // true
    return 0;
}