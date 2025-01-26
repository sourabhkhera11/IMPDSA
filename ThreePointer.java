public class ThreePointer{
    public void sort012brute(int[] arr) {
        //Brute force approch
        //Time complexity O(2*N)
        int c0=0,c1=0,c2=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]==0){
                c0++;
            }
            else if(arr[i]==1){
                c1++;
            }
            else{
                c2++;
            }
        }
        int index=0;
        for(int i=0;i<c0;i++){
            arr[index++]=0;
        }
        for(int i=0;i<c1;i++){
            arr[index++]=1;
        }
        for(int i=0;i<c2;i++){
            arr[index++]=2;
        }
    }
    // Function to sort an array of 0s, 1s, and 2s
    //Optimised approch 
    //Three pointer approch (Dutch national falg problem)
    //TC : O(n) SC: O(1)
    //No need to increment in case of swap with a high 
    public void sort012opti(int[] arr) {
        int l=0;
        int h=arr.length-1;
        int mid=0;
        while(mid<=h){
            if(arr[mid]==0){
                int temp=arr[l];
                arr[l]=arr[mid];
                arr[mid]=temp;
                l++;
                mid++;
            }
            else if(arr[mid]==2){
                int temp=arr[h];
                arr[h]=arr[mid];
                arr[mid]=temp;
                h--;
            }
            else{
                mid++;
            }
        }
    }
}