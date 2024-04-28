package lab06;

import java.util.NoSuchElementException;
import java.util.Scanner;

interface Queue<E> {

    // Elementi na redicata se objekti od proizvolen tip.

    // Metodi za pristap:

    public boolean isEmpty();
    // Vrakja true ako i samo ako redicata e prazena.

    public int size();
    // Ja vrakja dolzinata na redicata.

    public E peek();
    // Go vrakja elementot na vrvot t.e. pocetokot od redicata.

    // Metodi za transformacija:

    public void clear();
    // Ja prazni redicata.

    public void enqueue(E x);
    // Go dodava x na kraj od redicata.

    public E dequeue();
    // Go otstranuva i vrakja pochetniot element na redicata.
}

class ArrayQueue<E> implements Queue<E> {

    // Redicata e pretstavena na sledniot nacin:
    // length go sodrzi brojot na elementi.
    // Ako length > 0, togash elementite na redicata se zachuvani vo elems[front...rear-1]
    // Ako rear > front, togash vo  elems[front...maxlength-1] i elems[0...rear-1]
    E[] elems;
    int length, front, rear;

    // Konstruktor ...

    @SuppressWarnings("unchecked")
    public ArrayQueue(int maxlength) {
        elems = (E[]) new Object[maxlength];
        clear();
    }

    public boolean isEmpty() {
        // Vrakja true ako i samo ako redicata e prazena.
        return (length == 0);
    }

    public int size() {
        // Ja vrakja dolzinata na redicata.
        return length;
    }

    public E peek() {
        // Go vrakja elementot na vrvot t.e. pocetokot od redicata.
        if (length > 0)
            return elems[front];
        else
            throw new NoSuchElementException();
    }

    public void clear() {
        // Ja prazni redicata.
        length = 0;
        front = rear = 0;  // arbitrary
    }

    public void enqueue(E x) {
        // Go dodava x na kraj od redicata.
        elems[rear++] = x;
        if (rear == elems.length) rear = 0;
        length++;
    }

    public E dequeue() {
        // Go otstranuva i vrakja pochetniot element na redicata.
        if (length > 0) {
            E frontmost = elems[front];
            elems[front++] = null;
            if (front == elems.length) front = 0;
            length--;
            return frontmost;
        } else
            throw new NoSuchElementException();
    }
}

class Person {
    String name;
    int id;
    int passport;
    int license;

    public Person(String name, int id, int passport, int license) {
        this.name = name;
        this.id = id;
        this.passport = passport;
        this.license = license;
    }

    public String getName() {
        return name;
    }

    public int getPassport() {
        return passport;
    }

    public int getLicense() {
        return license;
    }

    @Override
    public String toString() {
        return String.format("%s", name);
    }
}

public class MVR {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        Queue<Person> queueId = new ArrayQueue<>(n);
        Queue<Person> queuePassport = new ArrayQueue<>(n);
        Queue<Person> queueLicense = new ArrayQueue<>(n);

        for (int i = 1; i <= n; i++) {
            String name = scanner.nextLine();
            int id = Integer.parseInt(scanner.nextLine());
            int passport = Integer.parseInt(scanner.nextLine());
            int license = Integer.parseInt(scanner.nextLine());
            Person person = new Person(name, id, passport, license);
            if (id == 1)
                queueId.enqueue(person);
            else if (passport == 1)
                queuePassport.enqueue(person);

            else if (license == 1)
                queueLicense.enqueue(person);

        }

        while (!queueId.isEmpty()) {
            Person next = queueId.peek();
            if (next.getPassport() == 1)
                queuePassport.enqueue(queueId.dequeue());
            else if (next.getLicense() == 1)
                queueLicense.enqueue(queueId.dequeue());
            else
                System.out.println(queueId.dequeue());
        }

        while (!queuePassport.isEmpty()) {
            Person next = queuePassport.peek();
            if (next.getLicense() == 1)
                queueLicense.enqueue(queuePassport.dequeue());
            else
                System.out.println(queuePassport.dequeue());
        }

        while (!queueLicense.isEmpty())
            System.out.println(queueLicense.dequeue());
    }
}
