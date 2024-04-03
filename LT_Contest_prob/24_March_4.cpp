class Solution
{
public:
    const int ALPHABET_SIZE = 26;

    // trie node
    struct TrieNode
    {
        struct TrieNode *children[ALPHABET_SIZE];
        bool isEndOfWord;
    };

    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode = new TrieNode;

        pNode->isEndOfWord = false;

        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;

        return pNode;
    }

    void insert(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root;

        for (int i = key.length() - 1; i >= 0; i--)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();

            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }

    bool search(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return false;

            pCrawl = pCrawl->children[index];
        }

        return (pCrawl->isEndOfWord);
    }

    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        struct TrieNode *root = getNode();
        for (int i = 0; i < wordsContainer.size(); i++)
        {
            insert(root, wordsContainer[i]);
        }

        for (int i = 0; i < wordsQuery.size(); i++)
        {
            string word = wordsQuery[i];
            int n = word.length();
            TrieNode *curr_node = root;
            for (int j = n - 1; j >= 0; j--)
            {
            }
        }
    }
};