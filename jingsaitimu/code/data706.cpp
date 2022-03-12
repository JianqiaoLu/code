#include "headl.h" 
class MyHashMap {
public:
    vector<vector<pair<int, int>>> ans;
    int base = 765;
    MyHashMap() {
        vector<vector<pair<int, int>>> a(base);
        ans = a;
    }

    void put(int key, int value) {
        int has = key % base;
        for (int i = 0; i < ans[has].size(); i++)
        {
            if (ans[has][i].first == key)
            {
                ans[has][i].second = value;
                return;
            }
        }
        ans[has].push_back(make_pair(key, value));
    }

    int get(int key) {
        int has = key % base;
        for (int i = 0; i < ans[has].size(); i++)
        {
            if (ans[has][i].first == key)
            {
                return ans[has][i].second;
            }
        }
        return -1;

    }

    void remove(int key) {
        int has = key % base;
        for (int i = 0; i < ans[has].size(); i++)
        {
            if (ans[has][i].first == key)
            {
                ans[has][i].second = -1;
            }
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
