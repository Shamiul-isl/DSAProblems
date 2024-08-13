class Solution {
    private boolean[] visited; // To keep track of visited nodes

    public boolean validPath(int n, int[][] edges, int start, int end) {
        // ToDo: Write Your Code Here.
        Map<Integer, LinkedList<Integer>> neighbors = new HashMap<>();
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            neighbors.computeIfAbsent(u, k -> new LinkedList<Integer>());
            neighbors.computeIfAbsent(v, k -> new LinkedList<Integer>());
            neighbors.get(u).push(v);
            neighbors.get(v).push(u);

        }
        
//         List<List<Integer>> graph = new ArrayList<>();
        
//         // Initialize the graph
//         for (int i = 0; i < n; i++) {
//             graph.add(new ArrayList<>());
//         }
        
//         // Populate the graph from edges
//         for (int[] edge : edges) {
//             graph.get(edge[0]).add(edge[1]);
//             graph.get(edge[1]).add(edge[0]); // Because it's an undirected graph
//         }
                
        LinkedList<Integer> seen = new LinkedList<>();
        visited = new boolean[n];
        seen.push(start);
        visited[start] = true;
        while (!seen.isEmpty()) {
            int cur = seen.pop();
            if (cur == end) {
                return true;
            }
            
            for (int neighbor: neighbors.get(cur)) {
                if (visited[neighbor] != true) {
                    seen.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return false;
    }

}