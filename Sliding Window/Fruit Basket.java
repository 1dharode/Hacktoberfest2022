class Solution {

    public int totalFruit(int[] arr) {
        
        int si = 0; int ei = 0; int n = arr.length;
        int count = 0; int c = 0; int len = -1;
        int freq[] = new int[(int) 1e5];

        while(ei<n){

            if(freq[arr[ei]]==0) count++;
            freq[arr[ei]]++;
            ei++;

            if(count>2) c++;

            while(c>0){

                if(freq[arr[si]]==1){
                    count--;
                    c--;
                }

                freq[arr[si]]--;
                si++;

            }

            len = Math.max(len,ei-si);
        }

        return len;
    }
} 