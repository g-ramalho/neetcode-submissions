class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
private:
    void heapify(vector<int>& a, int n, int i){
        while(true){
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < n && a[l] > a[largest]) largest = l;
            if (r < n && a[r] > a[largest]) largest = r;
            if (largest == i) break;

            swap(a[i], a[largest]);
            i = largest;
        }
    }

    void buildMaxHeap(vector<int>& a){
        int n = a.size();
        for (int i = n/2 - 1; i >= 0; --i)
            heapify(a, n, i);
    }

    void heapSort(vector<int>& a){
        int n = a.size();
        if (n <= 1) return;
        buildMaxHeap(a);
        for (int end = n - 1; end > 0; --end){
            swap(a[0], a[end]);
            heapify(a, end, 0);
        }
    }
};