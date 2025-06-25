class Solution {
public:
    long long countLessEqual(vector<int>& A, vector<int>& B, long long mid)
    {
        long long count = 0;
        int n = B.size();
        for(int a : A)
        {
            if(a == 0)
            {
                if(mid >= 0)
                {
                    count += n;
                }
            }
            else if(a > 0)
            {
                long long t = mid / a;
                if(mid < 0 && mid % a != 0)
                {
                    t--;
                }
 
                count += upper_bound(B.begin(), B.end(), t) - B.begin();
            }
            else
            {
                long long t = mid / a;
                if(mid < 0 && mid % a != 0)
                {
                    t++;
                }
                count += B.end() - lower_bound(B.begin(), B.end(), t);
            }
        }
        return count;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) 
    {
        long long low = -1e10;
        long long high = 1e10;
        while(low < high)
        {
            long long mid = low + (high - low) / 2;
            long long cnt = countLessEqual(nums1, nums2, mid);
            if(cnt >= k)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
