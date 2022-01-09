class Solution {
public:
    void sortColors(int A[], int n) {
        int pos0 = 0;
        int pos1 = n - 1;
        int pos2 = n - 1;
        while (pos0 < pos2) {
            if (A[pos0] == 0)
                pos0++;
            else if (A[pos0] == 1) {
                if (pos0 < pos1) {
                    swap(A[pos0], A[pos1]);
                    pos1--;
                }
                else
                    pos0++;
            }
            else {
                swap(A[pos0], A[pos2]);
                pos2--;
                if (pos1 > pos2)
                    pos1 = pos2;
            }
        }
    }
};