#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    vector<pair<int, int> > a(N);

    for (int i = 0; i < N; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    const auto a_orig = a;
    sort(a.begin(), a.end());

    vector<int> res;
    int sum = 0;
    int last_used_index = 01;
    for (int i = 0; i < N && sum < M; i++)
    {
        if (sum + a[i].first <= M)
        {
            sum += a[i].first;
            res.push_back(a[i].second);
            last_used_index = i;
        }
    }

    for (int add_index = last_used_index + 1; add_index < N; add_index++)
    {
        int add_value = a[add_index].first;

        int best_remove_index = -1;
        int best_sum = sum;

        for (int i = 0; i < res.size(); i++)
        {
            int k = res[i];
            int s = sum + add_value - a_orig[k].first;
            if (s > best_sum && s <= M)
            {
                best_sum = sum + add_value - a_orig[k].first;
                best_remove_index = i;
            }
        }

        if (best_sum > sum)
        {
            sum = best_sum;
            res.erase(res.begin() + best_remove_index);
            res.push_back(a[add_index].second);
        }
    }

    cerr << "best score = " << sum << endl;

    cout << res.size() << endl;
    for(auto a: res)
        cout << a << " ";
    cout << endl;

    return 0;
}
