set<char> st;
int difference(const string &str)
{
    int vowels = 0, consonants = 0;
    for (char c : str)
    {
        if (st.find(c) != st.end())
        {
            vowels++;
        }
        else
        {
            consonants++;
        }
    }
    return vowels - consonants;
}

string valuableString(int n, vector<string> &arr)
{
    st.insert('a');
    st.insert('e');
    st.insert('i');
    st.insert('o');
    st.insert('u');
    int maxDifference = 0;
    string maxString;
    map<int, string> mp;

    for (const string &s : arr)
    {
        int diff = difference(s);
        mp.insert({diff, s});
    }

    auto it = mp.rbegin();
    return it.second;
}