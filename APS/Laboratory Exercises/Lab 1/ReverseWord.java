//За даден збор кој се внесува од стандарден влез, 
//да се испечати истиот превртен. На влез во првиот 
//ред се дава број на зборови кои ќе се внесуваат. 
//Во наредните линии се внесуваат самите зборови.

package lab01;

import java.util.Scanner;

public class ReverseWord {
    public static void printReversed(String word) {
        for (int i = word.length() - 1; i >= 0; i--) {
            System.out.print(word.charAt(i));
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int n;
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        for (int i = 0; i < n; i++) {
            String s = input.next();
            printReversed(s);
        }
    }
}
