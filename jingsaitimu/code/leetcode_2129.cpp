class Solution {
public:
    string capitalizeTitle(string title) {
        int l = 0;
        int r = 0;
        title.push_back(' ');
        while (r <= title.size() - 1)
        {
            while (title[r] != ' ')
            {
                r++;
            }
            if ((r - l) > 2)
            {
                title[l] = tolower(title[l]);
            }
            while (l < r)
            {
                title[l] = toupper(title[l]);
            }
            l = r + 1;
            r++;
        }
        title.pop_back();
        return title;
    }
};