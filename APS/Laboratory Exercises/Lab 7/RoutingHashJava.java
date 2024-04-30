package lab07;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class MapEntryThree<K extends Comparable<K>, E> implements Comparable<K> {
    K key;
    E value;

    public MapEntryThree(K key, E val) {
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

class SLLNode<E> {
    protected E element;
    protected SLLNodeFour<E> succ;

    public SLLNode(E elem, SLLNodeFour<E> succ) {
        this.element = elem;
        this.succ = succ;
    }

    @Override
    public String toString() {
        return element.toString();
    }
}

class CBHT<K extends Comparable<K>, E> {
    private SLLNodeFour<MapEntryThree<K, E>>[] buckets;

    @SuppressWarnings("unchecked")
    public CBHT(int m) {
        buckets = (SLLNodeFour<MapEntryThree<K, E>>[]) new SLLNodeFour[m];
    }

    private int hash(K key) {
        return Math.abs(key.hashCode()) % buckets.length;
    }

    public SLLNodeFour<MapEntryThree<K, E>> search(K targetKey) {
        int b = hash(targetKey);
        for (SLLNodeFour<MapEntryThree<K, E>> curr = buckets[b]; curr != null; curr = curr.succ) {
            if (targetKey.equals(((MapEntryThree<K, E>) curr.element).key))
                return curr;
        }
        return null;
    }

    public void insert(K key, E val) {
        MapEntryThree<K, E> newEntry = new MapEntryThree<K, E>(key, val);
        int b = hash(key);
        for (SLLNodeFour<MapEntryThree<K, E>> curr = buckets[b]; curr != null; curr = curr.succ) {
            if (key.equals(((MapEntryThree<K, E>) curr.element).key)) {
                curr.element = newEntry;
                return;
            }
        }
        buckets[b] = new SLLNodeFour<MapEntryThree<K, E>>(newEntry, buckets[b]);
    }

    public void delete(K key) {
        int b = hash(key);
        for (SLLNodeFour<MapEntryThree<K, E>> pred = null, curr = buckets[b]; curr != null; pred = curr, curr = curr.succ) {
            if (key.equals(((MapEntryThree<K, E>) curr.element).key)) {
                if (pred == null)
                    buckets[b] = curr.succ;
                else
                    pred.succ = curr.succ;
                return;
            }
        }
    }

    public String toString() {
        String temp = "";
        for (int i = 0; i < buckets.length; i++) {
            temp += i + ":";
            for (SLLNodeFour<MapEntryThree<K, E>> curr = buckets[i]; curr != null; curr = curr.succ) {
                temp += curr.element.toString() + " ";
            }
            temp += "\n";
        }
        return temp;
    }
}

public class RoutingHashJava {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        HashClass<String, String[]> hash = new HashClass<>(128);
        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            String[] array = br.readLine().split(",");
            hash.insert(input, array);
        }
        int m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; i++) {
            String staticIp = br.readLine();
            String ip = br.readLine();
            SLLNodeFour<MapEntryThree<String, String[]>> node = hash.search(staticIp);
            if (node == null) {
                System.out.println("ne postoi");
                continue;
            }
            String[] targetIp = node.element.value;
            boolean valid = false;
            for (int j = 0; j < targetIp.length; j++) {
                String a = targetIp[j].substring(0, targetIp[j].lastIndexOf('.'));
                if (a.equals(ip.substring(0, ip.lastIndexOf('.')))) {
                    valid = true;
                    break;
                }
            }
            if (valid)
                System.out.println("postoi");
            else
                System.out.println("ne postoi");
        }
    }
}