package lab03;

import lab02.Array;

import java.util.Scanner;

public class CountWordPairs {
    public static int countWordPairs(String [] words) {
        int counter = 0;
        for (int current=0;current<words.length-1;current++){
            for (int next=current+1;next<words.length;next++){
                if (words[current].charAt(0) == words[next].charAt(0)){
                    counter++;
                }
            }
        }
        return counter;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();

        String words[] = new String[N];

        for(int i=0;i<N;i++) {
            words[i] = input.next();
        }

        System.out.println(countWordPairs(words));

    }
}
