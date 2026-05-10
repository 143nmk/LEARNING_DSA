/* Cpp code to count unique substrings using Trie */

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

    int countNodesHelper(Node *node)
    {
        int count = 0;
        for (auto child : node->children)
        {
            count += countNodesHelper(child.second);
        }
        return count + 1; // Count the current node
    }

    int countNodes()
    {
        return countNodesHelper(root);
    }
};

int countUniqueSubstrings(string &s)
{
    Trie trie;
    vector<string> words;
    for (int i = 0; i < s.size(); i++)
    {
        string suffix = s.substr(i);
        words.push_back(suffix);
    }
    trie.insert(words);
    return trie.countNodes();
}

int main()
{
    string s = "ababa";
    cout << countUniqueSubstrings(s) << endl;
    return 0;
}