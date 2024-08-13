class Solution {
    private boolean[] visited; // To keep track of visited nodes

    public boolean validPath(int n, int[][] edges, int start, int end) {
        // ToDo: Write Your Code Here.
        Map<Integer, ArrayList<Integer>> neighbors = new HashMap<>();
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            neighbors.computeIfAbsent(u, k -> new ArrayList<Integer>());
            neighbors.computeIfAbsent(v, k -> new ArrayList<Integer>());
            neighbors.get(u).add(v);
            neighbors.get(v).add(u);

        }
                
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