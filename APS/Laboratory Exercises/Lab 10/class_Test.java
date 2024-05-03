import java.util.*;
class AdjacencyListGraph<T> {
    private Map<T, Set<T>> adjacencyList;
    public AdjacencyListGraph() {
        this.adjacencyList = new HashMap<>();
    }
    // Add a vertex to the graph
    public void addVertex(T vertex) {
        if (!adjacencyList.containsKey(vertex)) {
            adjacencyList.put(vertex, new HashSet<>());
        }
    }

    // Remove a vertex from the graph
    public void removeVertex(T vertex) {
        // Remove the vertex from all adjacency lists
        for (Set<T> neighbors : adjacencyList.values()) {
            neighbors.remove(vertex);
        }
        // Remove the vertex's own entry in the adjacency list
        adjacencyList.remove(vertex);
    }

    // Add an edge to the graph
    public void addEdge(T source, T destination) {
        addVertex(source);
        addVertex(destination);
        adjacencyList.get(source).add(destination);
        adjacencyList.get(destination).add(source); // for undirected graph
    }

    // Remove an edge from the graph
    public void removeEdge(T source, T destination) {
        if (adjacencyList.containsKey(source)) {
            adjacencyList.get(source).remove(destination);
        }
        if (adjacencyList.containsKey(destination)) {
            adjacencyList.get(destination).remove(source); // for undirected graph
        }
    }
    // Get all neighbors of a vertex
    public Set<T> getNeighbors (T vertex) {
        return adjacencyList.getOrDefault(vertex, new HashSet<>());
    }

    public void print()
    {
        adjacencyList.forEach((x,y) ->
                System.out.printf("%s: %s\n", x.toString(), new ArrayList<T>(y)));
    }

}

public class Test {
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String line, parts[];
        line=scanner.nextLine();
        AdjacencyListGraph<Integer> graph = new AdjacencyListGraph<Integer>();
        for(int i=0; i<n; i++)
        {
            line = scanner.nextLine();
            parts=line.split(" ");
            switch(parts[0])
            {
                case "CREATE" : graph = new AdjacencyListGraph<Integer>(); 
                break;
                case "PRINTGRAPH" : graph.print(); 
                System.out.println(); 
                break;
                case "ADDEDGE" : graph.addEdge(Integer.parseInt(parts[1]),Integer.parseInt(parts[2])); 
                break;
                case "DELETEEDGE" : graph.removeEdge(Integer.parseInt(parts[1]),Integer.parseInt(parts[2])); 
                break;
                default:
                    System.out.println(graph
                            .getNeighbors(Integer.parseInt(parts[1]) )
                            .contains(Integer.parseInt(parts[2])) ); 
                            break;
            }
        }
    }
}