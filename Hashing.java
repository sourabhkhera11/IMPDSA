import java.util.*;
public class Hashing {
    //Array Read and display methods 
    //Both for integer and characters
    static Scanner sc=new Scanner(System.in);
    static void readint(int ar[],int num){
        for(int i=0;i<num;i++){
            System.out.print("Enter at "+(i+1)+" location=");
            ar[i]=sc.nextInt();
        }
    }
    static void readchar(char ar[],int num){
        for(int i=0;i<num;i++){
            System.out.print("Enter at "+(i+1)+" location=");
            ar[i]=sc.next().charAt(0); //Input a character in java
        }
    }
    static void displayint(int ar[],int num){
        System.out.print("Array= ");
        for(int i=0;i<num;i++){
            System.out.print(ar[i]+" ");
        }
    }
    static void displaychar(char ar[],int num){
        System.out.print("Array= ");    
        for(int i=0;i<num;i++){
            System.out.print(ar[i]+" ");
        }
    }
    //Traditional way of calculating the frenquecy of elements (Brute force Approch)
    //For loop, for each character to find freq of 1 element TC: O(n)
    //To find the freq of Q elements TC: O(Q.n)
    static int freqint(int ar[],int num,int ele){
        int freq=0;
        for(int i=0;i<num;i++){
            if(ar[i]==ele){
                freq++;
            }
        }
        return freq;
    }
    static int freqchar(char ar[],int num,char ele){
        int freq=0;
        for(int i=0;i<num;i++){
            if(ar[i]==ele){
                freq++;
            }
        }
        return freq;
    }
    //Hashing (pre storing and fetching )
    //Main concept (value of element = index of hasharray)
    //pre storing assuming a max element (n) TC of pre storing O(n)
    //fetching TC :O(1)
    //The only limitation of hashing array is the limited size of the array
    //To solve that we use the concept of mapping / hashmap
    static void hashint(int ar[],int num, int hashar[]){
        for(int i=0;i<num;i++){
            hashar[ar[i]]++;
        }
    }
    static void hashchar(char ar[],int num, int hasharr[]){
        for(int i=0;i<num;i++){
            hasharr[ar[i]-'a']++;
        }
    }
    public static void main(String[] args) {
        //taking an array from user
        System.out.print("Enter the number of elements in the array=");
        int num=sc.nextInt();
        /* System.out.println("1)Integer array \n2)Character Array ");
        System.out.print("Enter your choice=");
        int choice=sc.nextInt();
        switch (choice) {
            case 1:
                int ar[]=new int[num];
                readint(ar, num);
                displayint(ar, num);
                int hashar[]=new int[13]; //assuming 12 be the max element present 
                hashint(ar, num, hashar); //passed by referece not need to return anything
                int ele;
                do{ //fetching
                    System.out.print("Enter the element you want freq of =");
                    ele=sc.nextInt();
                    try {
                        System.out.println("freq of "+ele+" = "+hashar[ele]);
                    } catch (ArrayIndexOutOfBoundsException e) {
                        break;
                    }
                }while(ele!=-1);
                break;
            
            case 2:
                char arr[]=new char[num];
                readchar(arr, num);
                displaychar(arr, num);
                int hasharr[]=new int[26]; //assuming lowercase alphabets 26
                hashchar(arr, num, hasharr); //passed by referece not need to return anything
                char elee;
                do{ //fetching 
                    System.out.print("Enter the element you want freq of =");
                    elee=sc.next().charAt(0);
                    try {
                        System.out.println("freq of "+elee+" = "+hasharr[elee-'a']);
                    } catch (ArrayIndexOutOfBoundsException e) {
                        break;
                    }
                }while(elee!=-1);
                break;
            default:
                break;
        } */
        //Hashing using HashMap(Underlying component is Hash Table)
        //Avg and best case TC O(1) in both storing and fetching 
        //WOrst case TC O(n) occur due to collision solve using chaining 
        Map<Integer,Integer> mapp= new HashMap<>();
        int ar[]=new int[num];
        readint(ar, num);
        displayint(ar, num);
        System.out.println(mapp); //Empty map {}
        for(int i=0;i<num;i++){
            int key=ar[i];
            int freq=0;
            if(mapp.containsKey(key)) freq=mapp.get(key);
            freq++;
            mapp.put(key, freq);
        }
        int Queries;
        System.out.print("Enter number of queries=");
        Queries=sc.nextInt();
        while (Queries-- >0) {
                int number;
                System.out.println("Enter the number whose freq you want to check=");
                number=sc.nextInt();
                if(mapp.containsKey(number)) System.out.println("freq= "+mapp.get(number));
                else System.out.println("freq="+0);
        }
        //Traversing in a HashMap
        int key=ar[0];
        Integer max=key;
        for (Map.Entry<Integer,Integer> entry : mapp.entrySet()) {
            if(mapp.get(max) < entry.getValue()){
                max=entry.getKey();
            }
        }
        System.out.print("Max freq is of element = "+max);
    }
}
