
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
    bool helper(Trie &trie, string key)
    {
        if (key.size() == 0)
        {
            return true;
        }
        for (int i = 0; i < key.size(); i++)
        {
            string first = key.substr(0, i + 1);
            string second = key.substr(i + 1);
            if (trie.search(first) && helper(trie, second))
            {
                return true;
            }
        }
        return false;
    }

    bool wordBreak(vector<string> &words, string key)
    {
        Trie trie;
        trie.insert(words);
        return helper(trie, key);
    }
};

int main()
{
    vector<string> words = {"i", "like", "sam", "samsung", "mobile"};
    Trie trie;
    string key = "ilikesamsong";
    cout << trie.wordBreak(words, key) << endl;
    return 0;
}