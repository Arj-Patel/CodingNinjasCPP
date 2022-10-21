#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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

    bool add(TrieNode *root, string word)
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
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

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words)
    {

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                for (int k = j; k <= words[i].size(); k++)
                {
                    add(words[i].substr(j, k));
                }
            }
        }

        bool ans = false;

        // cout<<search("abba")<<endl;

        for (int i = 0; i < words.size(); i++)
        {
            reverse(words[i].begin(), words[i].end());
            ans = search(words[i]);
            if (ans == true)
            {
                return ans;
            }
        }

        return false;
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}