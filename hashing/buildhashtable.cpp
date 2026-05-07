#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string key;
    int value;
    Node *next;

    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

class HashTable
{

    int totalsize;
    int currsize;
    Node **table;
    int hashfunction(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.size(); i++)
        {
            sum += key[i] * key[i];
        }
        return sum % totalsize;
    }

    void rehash()
    {
        int oldsize = totalsize;
        totalsize *= 2;
        Node **oldtable = table;
        table = new Node *[totalsize];
        for (int i = 0; i < totalsize; i++)
        {
            table[i] = NULL;
        }
        currsize = 0;

        for (int i = 0; i < oldsize; i++)
        {
            Node *temp = oldtable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }
        }

        for (int i = 0; i < oldsize; i++)
        {
            Node *temp = oldtable[i];
            while (temp != NULL)
            {
                Node *nodeToDelete = temp;
                temp = temp->next;
                delete nodeToDelete;
            }
        }
        delete[] oldtable;
    }

public:
    HashTable(int size = 5)
    {
        totalsize = size;
        currsize = 0;
        table = new Node *[totalsize];
        for (int i = 0; i < totalsize; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, int value)
    {
        int index = hashfunction(key);
        Node *newnode = new Node(key, value);
        if (table[index] == NULL)
        {
            table[index] = newnode;
            currsize++;
        }
        else
        {
            Node *temp = table[index];
            while (temp->next != NULL)
            {
                if (temp->key == key)
                {
                    temp->value = value;
                    return;
                }
                temp = temp->next;
            }
            if (temp->key == key)
            {
                temp->value = value;
                return;
            }
            temp->next = newnode;
            currsize++;
        }

        int lambda=currsize/totalsize;
        if(lambda>1){
            rehash();
        }

    }
    void remove(string key)
    {
        int index = hashfunction(key);
        if (table[index] == NULL)
        {
            return;
        }
        if (table[index]->key == key)
        {
            Node *temp = table[index];
            table[index] = table[index]->next;
            delete temp;
            currsize--;
            return;
        }
        Node *temp = table[index];
        while (temp->next != NULL)
        {
            if (temp->next->key == key)
            {
                Node *nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
                currsize--;
                return;
            }
            temp = temp->next;
        }
    }
    int search(string key)
    {
        int index = hashfunction(key);
        Node *temp = table[index];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return -1; // Key not found
    }
};

int main()
{
    HashTable ht(7);
    ht.insert("apple", 10);
    ht.insert("banana", 20);
    ht.insert("orange", 30);
    cout << ht.search("apple") << endl;  // Output: 10
    cout << ht.search("banana") << endl; // Output: 20
    cout << ht.search("grape") << endl;  // Output: -1 (not found)
    ht.remove("banana");
    cout << ht.search("banana") << endl; // Output: -1 (not found)
    cout << ht.search("orange") << endl; // Output: 30
    cout << ht.search("apple") << endl;  // Output: 10
    for (int i = 0; i < 10; i++)
    {
        ht.insert("key" + to_string(i), i);
    }
    return 0;
}