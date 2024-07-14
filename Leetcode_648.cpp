

class Solution
{
public:
    struct Trie
    {
        trie *child[26];
        bool isEnd;
    };

    Trie *getNode()
    {
        Trie *newNode = new Trie();
        newNode->isEnd = false;

        for (int i = 0; i < 26; i++)
            newNode.child[i] = NULL;

        return newNode;
    }

    Trie *root;

    void insert(string word)
    {
        Trie *crwaler = root;

        for (int i = 0; i < word.length(); i++)
        {
            int idx = word[i] - 'a';
            if (crwaler->child[idx] == NULL)
                crwaler->child[idx] = getNode();

            crwaler = crwaler->child[idx];
        }
        crwaler->isEnd = true;
    }

    string search(string word)
    {
        Trie *crawler = root;

        for (auto i = 0; i < word.length(); i++)
        {
            int idx = word[i] - 'a';
            if (crawler->child[idx] == NULL)
                return word;

            crawler = crawler->child[idx];
            if (crawler->isEnd)
                return word.substr(0, i + 1);
        }
        return word;
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        root = getNode();
        for (string &word : dictionary)
        {
            insert(word);
        }

        stringstream ss(sentence);
        string word;
        string result;
        while (getline(ss, word, ' '))
        {
            result += search(word) + " ";
        }
        result.pop_back();

        return result;
    }
};