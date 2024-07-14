#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_company_rating(int n, const vector<int> &a, const vector<int> &b)
{
    int liked_a = 0, neutral_a = 0, disliked_a = 0;
    int liked_b = 0, neutral_b = 0, disliked_b = 0;

    // Count the likes, neutrals, and dislikes for both movies
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1)
            liked_a++;
        else if (a[i] == 0)
            neutral_a++;
        else
            disliked_a++;

        if (b[i] == 1)
            liked_b++;
        else if (b[i] == 0)
            neutral_b++;
        else
            disliked_b++;
    }

    int total_likes = liked_a + liked_b;
    int total_dislikes = disliked_a + disliked_b;
    int min_rating = min(liked_a - disliked_a, liked_b - disliked_b);

    return min_rating;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
        }

        cout << max_company_rating(n, a, b) << endl;
    }

    return 0;
}
