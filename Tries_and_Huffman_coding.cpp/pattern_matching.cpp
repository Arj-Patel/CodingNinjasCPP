#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool search(TrieNode *root, string word)
    {

        if (word.size() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';

        bool ans;
        if (root->children[index] != NULL)
        {
            ans = search(root->children[index], word.substr(1));
        }
        else
        {
            ans = false;
        }

        return ans;
    }

    bool search(string word)
    {
        return search(root, word);
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        if (insertWord(root, word))
        {
            this->count++;
        }
    }

    bool patternMatching(vector<string> vect, string pattern)
    {

        for (int i = 0; i < vect.size(); i++)
        {

            for (int j = 0; j < vect[i].size(); j++)
            {
                for (int k = j; k < vect[i].size(); k++)
                {
                    insertWord(vect[i].substr(j, k));
                }
            }
        }

        return search(pattern);
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i)
    {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;

    cout << (t.patternMatching(vect, pattern) ? "true" : "false");
}