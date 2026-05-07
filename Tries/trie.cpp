/* Cpp code to build a trie data structure*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children;
    bool isEnd;
    Node()
    {
        isEnd = false;
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

    void insert(vector<string> &words)
    {
        Node *temp = root;
        for (string word : words)
        {
            for (int i = 0; i < word.size(); i++)
            {
                char ch = word[i];
                if (temp->children.count(ch) == 0)
                {
                    temp->children[ch] = new Node();
                }
                temp = temp->children[ch];
            }
            temp->isEnd = true;
            temp = root;
        }
    }

    bool search(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (temp->children.count(ch) != 0)
            {
                temp = temp->children[ch];
            }
            else
            {
                return false;
            }
        }
        return temp->isEnd;
    }
};

int main()
{
    vector<string> words = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    Trie trie;
    trie.insert(words);
    cout << trie.search("the") << endl;   // Output: 1 (true)
    cout << trie.search("these") << endl; // Output: 0 (false)
    return 0;
}