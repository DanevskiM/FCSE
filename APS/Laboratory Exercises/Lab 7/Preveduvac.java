package lab07;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class MapEntry<K extends Comparable<K>, E> implements Comparable<K> {
    K key;
    E value;

    public MapEntry(K key, E val) {
        this.key = key;
        this.value = val;
    }

    public int compareTo(K that) {
        @SuppressWarnings("unchecked")
        MapEntryThree<K, E> other = (MapEntryThree<K, E>) that;
        return this.key.compareTo(other.key);
    }

    public String toString() {
        return "<" + key + "," + value + ">";
    }
}


class OBHT<K extends Comparable<K>, E> {

    private MapEntryThree<K, E>[] buckets;

    static final int NONE = -1;

    @SuppressWarnings({"rawtypes", "unchecked"})
    private static final MapEntryThree former = new MapEntryThree(null, null);

    private int occupancy = 0;

    @SuppressWarnings("unchecked")
    public OBHT(int m) {
        buckets = (MapEntryThree<K, E>[]) new MapEntryThree[m];
    }

    private int hash(K key) {
        return Math.abs(key.hashCode()) % buckets.length;
    }

    public MapEntryThree<K, E> getBucket(int i) {
        return buckets[i];
    }


    public int search(K targetKey) {
        int b = hash(targetKey);
        for (; ; ) {
            MapEntryThree<K, E> oldEntry = buckets[b];
            if (oldEntry == null)
                return NONE;
            else if (targetKey.equals(oldEntry.key))
                return b;
            else
                b = (b + 1) % buckets.length;
        }
    }


    public void insert(K key, E val) {
        MapEntryThree<K, E> newEntry = new MapEntryThree<K, E>(key, val);
        int b = hash(key);
        for (; ; ) {
            MapEntryThree<K, E> oldEntry = buckets[b];
            if (oldEntry == null) {
                if (++occupancy == buckets.length) {
                    System.out.println("Hash tabelata e polna!!!");
                }
                buckets[b] = newEntry;
                return;
            } else if (oldEntry == former
                    || key.equals(oldEntry.key)) {
                buckets[b] = newEntry;
                return;
            } else
                b = (b + 1) % buckets.length;
        }
    }


    @SuppressWarnings("unchecked")
    public void delete(K key) {
        int b = hash(key);
        for (; ; ) {
            MapEntryThree<K, E> oldEntry = buckets[b];
            if (oldEntry == null)
                return;
            else if (key.equals(oldEntry.key)) {
                buckets[b] = former;
                return;
            } else {
                b = (b + 1) % buckets.length;
            }
        }
    }


    public String toString() {
        String temp = "";
        for (int i = 0; i < buckets.length; i++) {
            temp += i + ":";
            if (buckets[i] == null)
                temp += "\n";
            else if (buckets[i] == former)
                temp += "former\n";
            else
                temp += buckets[i] + "\n";
        }
        return temp;
    }


    public OBHT<K, E> clone() {
        OBHT<K, E> copy = new OBHT<K, E>(buckets.length);
        for (int i = 0; i < buckets.length; i++) {
            MapEntryThree<K, E> e = buckets[i];
            if (e != null && e != former)
                copy.buckets[i] = new MapEntryThree<K, E>(e.key, e.value);
            else
                copy.buckets[i] = e;
        }
        return copy;
    }
}


public class Preveduvac {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());
        OBHT<String, String> hash = new OBHT<>(128);
        for (int i = 0; i < n; i++) {
            String input = bf.readLine();
            String[] array = input.split(" ");
            hash.insert(array[1], array[0]);
        }
        while (true) {
            String line = bf.readLine();
            if (line.equals("KRAJ"))
                break;
            int a = hash.search(line);
            if (a != -1)
                System.out.println(hash.getBucket(a).value);
            else
                System.out.println("/");
        }
    }
}
