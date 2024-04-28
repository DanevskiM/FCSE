package lab06;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.NoSuchElementException;

interface Evaluate<E> {

    // Elementi na stekot se objekti od proizvolen tip.

    // Metodi za pristap:

    public boolean isEmpty ();
    // Vrakja true ako i samo ako stekot e prazen.

    public E peek ();
    // Go vrakja elementot na vrvot od stekot.

    // Metodi za transformacija:

    public void clear ();
    // Go prazni stekot.

    public void push (E x);
    // Go dodava x na vrvot na stekot.

    public E pop ();
    // Go otstranuva i vrakja elementot shto e na vrvot na stekot.
}

class ArrayEvaluate<E> implements Evaluate<E> {
    private E[] elems;
    private int depth;

    @SuppressWarnings("unchecked")
    public ArrayEvaluate(int maxDepth) {
        // Konstrukcija na nov, prazen stek.
        elems = (E[]) new Object[maxDepth];
        depth = 0;
    }


    public boolean isEmpty () {
        // Vrakja true ako i samo ako stekot e prazen.
        return (depth == 0);
    }


    public E peek () {
        // Go vrakja elementot na vrvot od stekot.
        if (depth == 0)
            throw new NoSuchElementException();
        return elems[depth-1];
    }


    public void clear () {
        // Go prazni stekot.
        for (int i = 0; i < depth; i++)  elems[i] = null;
        depth = 0;
    }


    public void push (E x) {
        // Go dodava x na vrvot na stekot.
        elems[depth++] = x;
    }


    public E pop () {
        // Go otstranuva i vrakja elementot shto e na vrvot na stekot.
        if (depth == 0)
            throw new NoSuchElementException();
        E topmost = elems[--depth];
        elems[depth] = null;
        return topmost;
    }
}

public class PostFixEvaluation {
    static void calculate(ArrayStack<Integer> numbers, ArrayStack<Character> operators){
        int num2 = numbers.pop();
        int num1 = numbers.pop();
        char operator = operators.pop();
        int rezultat = 0;
        if(operator == '+')
            rezultat = num1+num2;
        if(operator == '-')
            rezultat = num1-num2;
        if(operator == '/')
            rezultat = num1/num2;
        if(operator == '*')
            rezultat = num1*num2;
        numbers.push(rezultat);
    }
    static int evaluatePostfix(char [] izraz, int n)
    {
        ArrayStack<Integer> broevi = new ArrayStack<>(izraz.length);
        ArrayStack<Character> operators = new ArrayStack<>(izraz.length);
        for(int i=0;i<izraz.length;i++){
            if(Character.isDigit(izraz[i])){
                int broj = 0;
                while(i < izraz.length && Character.isDigit(izraz[i])){
                    broj = broj*10 + Character.getNumericValue(izraz[i]);
                    i++;
                }
                i--;
                broevi.push(broj);
            }
            else if(izraz[i]=='+' || izraz[i]=='-' || izraz[i]=='*' || izraz[i]=='/'){
                operators.push(izraz[i]);
                if(!broevi.isEmpty())
                    calculate(broevi,operators);
            }
        }
        return broevi.pop();
    }
    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String expression = br.readLine();
        char exp[] = expression.toCharArray();

        int rez = evaluatePostfix(exp, exp.length);
        System.out.println(rez);

        br.close();

    }

}