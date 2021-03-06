class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int lo=0,hi=n;
        while(lo<hi){
            int mi=(lo+hi)>>1;
            if(n-mi<=citations[mi])hi=mi;
            else lo=mi+1; }//assert lo==hi
        return n-lo;
    }
};

