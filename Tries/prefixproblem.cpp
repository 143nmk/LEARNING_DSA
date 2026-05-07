
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children;
    bool isEnd;
    int freq;
    Node()
    {
        isEnd = false;
        freq = 0;
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
        temp->freq = -1;
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
                temp->freq++;
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

    string helper(string word)
    {
        string prefix = "";
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            prefix += word[i];
            if (temp->children[word[i]]->freq == 1)
            {
                return prefix;
            }
            temp = temp->children[word[i]];
        }
        return prefix;
    }

    void prefix(vector<string> &words)
    {
        for (string word : words)
        {
            cout << helper(word) << endl;
        }
    }
};

int main()
{
    vector<string> words = {"zebra", "dog", "duck", "dove"};
    Trie trie;
    trie.insert(words);
    trie.prefix(words);
    return 0;
}