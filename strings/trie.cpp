struct TrieNode
{
    TrieNode *children[26];
    int is_leaf;
    int count;

    TrieNode()
    {
        is_leaf = 0;
        count = 0;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

void insert(TrieNode *root, const string &key)
{
    TrieNode *curr = root;
    for (char c : key)
    {
        if (curr->children[c - 'a'] == nullptr)
        {
            TrieNode *newNode = new TrieNode();
            curr->children[c - 'a'] = newNode;
        }
        curr = curr->children[c - 'a'];
        curr->count++;
    }
    curr->is_leaf++;
}

int num_prefix(TrieNode *root, const string &key)
{
    TrieNode *curr = root;
    for (char c : key)
    {
        if (curr->children[c - 'a'] == nullptr)
            return 0;
        curr = curr->children[c - 'a'];
    }
    return curr->count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    TrieNode *root = new TrieNode();
    return 0;
}
