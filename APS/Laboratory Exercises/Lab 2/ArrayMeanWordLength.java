package lab02;

import java.util.Scanner;

public class ArrayMeanWordLength {

    //TODO: implement function
    public static String wordClosestToAverageLength(Array<String> arr) {
        int n=arr.getSize();
        float sum = 0;
        for (int i=0;i<n;i++){
            sum+=arr.get(i).length();
        }
        float avg = sum/n;
        float diff2 = 1000;
        String max = arr.get(0);
        for (int i=0;i<n;i++){
            String nova = arr.get(i);
            float diff=Math.abs(avg-arr.get(i).length());
            if (diff<diff2){
                diff2=diff;
                max=nova;
            }
        }
        return max;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int N = input.nextInt();
        Array<String> arr = new Array<>(N);
        input.nextLine();

        for (int i = 0; i < N; i++) {
            arr.insertLast(input.nextLine());
        }

        System.out.println(wordClosestToAverageLength(arr));
    }
}
