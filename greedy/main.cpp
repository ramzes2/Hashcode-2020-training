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

    sort(a.begin(), a.end());

    vector<int> res;
    int sum = 0;

    for (int i = 0; i < N && sum < M; i++)
    {
        if (sum + a[i].first <= M)
        {
            sum += a[i].first;
            res.push(a[i].second);
        }
    }

    cout << res.size() << endl;
    for(auto a: res)
        cout << a << " ";
    cout << endl;

    return 0;
}
