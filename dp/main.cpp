#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class ActionType : uint8_t
{
    Impossible,
    TakePizza,
    SkipPizza
};

int main()
{
//    freopen("../a_example.in", "r", stdin);

    int M, N;
    cin >> M >> N;
    vector<int> a(N);

    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<vector<ActionType>> dp(N + 1, vector<ActionType>(M + 1, ActionType::Impossible)); // N*M

    for (int i = 0; i <= N; i++)
        dp[i][0] = ActionType::SkipPizza;

    for (int i = 0; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (i > 0 && dp[i - 1][j] != ActionType::Impossible)
                dp[i][j] = ActionType::SkipPizza;

            if (i > 0 && a[i - 1] <= j && dp[i - 1][j - a[i - 1]] != ActionType::Impossible)
                dp[i][j] = ActionType::TakePizza;
        }

    int best_score = 0;
    for (int i = M; i >= 0; i--)
    {
        if (dp[N][i] != ActionType::Impossible)
        {
            best_score = i;
            break;
        }
    }

    cerr << "best score: " << best_score << endl;

    int pos = N;
    vector<int> res;
    while(pos > 0)
    {
        if (dp[pos][best_score] == ActionType::TakePizza)
        {
            res.push_back(pos - 1);
            best_score -= a[pos - 1];
            pos--;
        }
        else if (dp[pos][best_score] == ActionType::SkipPizza)
        {
            pos--;
        }
        else
        {
            cerr << "!!! " << pos << " " << best_score << endl;
            return -1;
        }
    }

    cout << res.size() << endl;
    for (int value: res)
        cout << value << " ";
    cout << endl;

    return 0;
}
