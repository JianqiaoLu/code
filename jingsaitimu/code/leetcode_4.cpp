#include "headl.h" 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (! ((nums1.size() + nums2.size()) % 2))
        {
            int k1 = (nums1.size() + nums2.size()) / 2;
            return findans2(nums1, nums2, k1);
        }
        else
        {
            int k1 = (nums1.size() + nums2.size()) / 2 + 1 ; 
            return findans1(nums1, nums2, k1);
        }
    }

    double findans2(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty())
        {
            return ((double)nums2[k - 1] + (double)nums2[k ]) / 2;
        }
        else if (nums2.empty())
        {
            return ((double)nums1[k - 1] + (double)nums1[k ]) / 2;
        }
        else if ( k == 1)
        {
            double ans1 = min((double)nums1[0] , (double)nums2[0]);
            double ans2 = max((double)nums1[0] , (double)nums2[0]);
            if (nums2.size() < 2)
            {
            return (ans1+ min(ans2, (double)nums1[1]) )/ 2;
            }
            else if (nums1.size() < 2)
            {
            return (ans1+ min(ans2, (double)nums2[1]) )/ 2;
            }
            else if( nums1.size() < 2 and nums2.size() < 2)
            {

            return ((double)nums1[0] + (double)nums2[0]) / 2;
            // return ((double)nums1[0] + (double)nums2[0]) / 2;
            }
            
            else
            {
            return (ans1+ min(ans2, min((double)nums2[1],(double) nums1[1]) ))/ 2;
            }
            
            // double ans2 = min((double)nums1[1] , (double)nums2[1]);

            // return ((double)nums1[0] + (double)nums2[0]) / 2;
        }
        int ans;
        int k1 = k /2, k2 = k / 2;
        double v1, v2;
        if (nums1.size() < k1)
        {
            v1 = nums1[nums1.size() - 1];
            k1 = nums1.size();
            v2 = nums2[k2 - 1];
        }
        else if (nums2.size() < k1)
        {
            v2 = nums2[nums2.size() - 1];
            k2 = nums1.size();
            v1 = nums1[k1 - 1];
        }
        else
        {
            v1 = nums1[max(k1 - 1,0)];
            v2 = nums2[max(k2 - 1,0)];
        }
        if (v1 > v2)
        {
            vector<int> nums2n(nums2.begin() + k2, nums2.end() );
            vector<int> nums1n(nums1.begin(), nums1.end());
            return findans2(nums1n, nums2n, k - k2);
        }
        else 
        {
            vector<int> nums1n(nums1.begin() + k1, nums1.end() );
            vector<int> nums2n(nums2.begin(), nums2.end());
            return findans2(nums1n, nums2n, k - k1);
        }
    }

    double findans1(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty())
        {
            return nums2[k - 1];
        }
        else if (nums2.empty())
        {
            return nums1[k - 1];
        }
        else if (k== 1)
        {
            return min(nums1[0],nums2[0]);
        }
        

        int ans;
        int k1 = k /2, k2 = k / 2;
        double v1, v2;
        if (nums1.size() < k1)
        {
            v1 = nums1[nums1.size() - 1];
            k1 = nums1.size();
            v2 = nums2[k2 - 1];
        }
        else if (nums2.size() < k1)
        {
            v2 = nums2[nums2.size() - 1];
            k2 = nums1.size();
            v1 = nums1[k1 - 1];
        }
        else
        {
            v1 = nums1[k1 - 1];
            v2 = nums2[k2 - 1];
        }
        if (v1 > v2)
        {
            vector<int> nums2n(nums2.begin() + k2, nums2.end() );
            vector<int> nums1n(nums1.begin(), nums1.end());
            return findans1(nums1n, nums2n, k - k2);
        }
        else if (v1 < v2)
        {
            vector<int> nums1n(nums1.begin() + k1, nums1.end());
            vector<int> nums2n(nums2.begin(), nums2.end());
            return findans1(nums1n, nums2n, k - k1);
        }
        else
        {
            return v1;
        }
    }

};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> a1 {1} ;
    vector<int> a2 {1} ;
    double ans1 = a->findMedianSortedArrays(a1,a2);
    int aa= 1;

}