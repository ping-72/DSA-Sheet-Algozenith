class TrieNode
{
public:
    map<char, TrieNode *> children;
    bool isEnd;
    int minlen;
    int index;
    TrieNode()
    {
        isEnd = false;
        minlen = 1e9;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word, int i)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            if (curr->children.find(c) == curr->children.end())
            {
                curr->children[c] = new TrieNode();
            }
            if (curr->minlen > word.length())
            {
                curr->minlen = word.length();
                curr->index = i;
            }
            curr = curr->children[c];
        }
        if (curr->minlen > word.length())
        {
            curr->minlen = word.length();
            curr->index = i;
        }
        curr->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                return false;
            }
            current = current->children[ch];
        }
        return current != nullptr && current->isEnd;
    }

    int startsWith(string prefix)
    {
        TrieNode *current = root;
        int ans = -1;
        for (char ch : prefix)
        {
            if (current->children.find(ch) == current->children.end())
            {
                return current->index;
            }
            ans = current->index;
            current = current->children[ch];
        }
        return current->index;
    }
};

class Solution
{
public:
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        Trie trie;
        int k = 0;
        for (auto i : wordsContainer)
        {
            reverse(i.begin(), i.end());
            trie.insert(i, k);
            k++;
        }
        vector<int> ans;
        for (auto i : wordsQuery)
        {
            reverse(i.begin(), i.end());
            ans.push_back(trie.startsWith(i));
        }
        return ans;
    }
};