package lab02;

import java.util.Scanner;

public class MysticalCardGame {
    public static void startDuel(SLL<Card> firstSorcererCards, SLL<Card> secondSorcererCards) {
        SLLNode<Card> first = firstSorcererCards.getFirst();
        SLLNode<Card> second = secondSorcererCards.getFirst();
        SLLNode<Card> max = null;
        int most = 0;
        while (first!=null){
            if (first.element.significance()>most){
                most = first.element.significance();
                max = first;
            }
            first = first.succ;
        }
        Card deleted = firstSorcererCards.delete(max);
        for (int i=0;i<secondSorcererCards.size()/2;i++){
            second = second.succ;
        }
        secondSorcererCards.insertBefore(deleted,second);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        SLL<Card> firstSorcererCards = new SLL<Card>();
        SLL<Card> secondSorcererCards = new SLL<Card>();

        for (int i = 0; i < 8; i++) {
            String line = scanner.nextLine();
            String[] parts = line.split("\\s+");
            firstSorcererCards.insertLast(new Card(Integer.parseInt(parts[0]), Integer.parseInt(parts[1]), Integer.parseInt(parts[2])));
        }

        for (int i = 0; i < 8; i++) {
            String line = scanner.nextLine();
            String[] parts = line.split("\\s+");
            secondSorcererCards.insertLast(new Card(Integer.parseInt(parts[0]), Integer.parseInt(parts[1]), Integer.parseInt(parts[2])));
        }

        startDuel(firstSorcererCards, secondSorcererCards);
        System.out.println(firstSorcererCards);
        System.out.println(secondSorcererCards);
    }
}
