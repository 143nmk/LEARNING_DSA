/* Cpp code to find the longest word with all prefixes present in the Trie */

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
    void helper(Node *root, string &ans, string temp)
    {
        for (auto it : root->children)
        {
            if (it.second->isEnd)
            {
                temp += it.first;
                if ((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size()))
                {
                    ans = temp;
                }
                helper(it.second, ans, temp);
                temp = temp.substr(0, temp.size() - 1);
            }
        }
    }

    string longeststringwitheow()
    {
        string ans = "";
        helper(root, ans, "");
        return ans;
    }
};

string longestWord(vector<string> &words, Trie &trie)
{
    return trie.longeststringwitheow();
}

int main()
{
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    Trie trie;
    trie.insert(words);
    cout << "Longest word with all prefixes present in the Trie is: " << longestWord(words, trie) << endl;
    return 0;
}