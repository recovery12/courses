// Don't place your source in a package

import java.util.*;

import java.lang.*;

import java.io.*;



// Please name your class Main

class Main {

    public static void main (String[] args) throws java.lang.Exception {

        Scanner in = new Scanner(System.in);

        int townNum = in.nextInt();

        int[] prices = new int[townNum];

        Graph g = new Graph();

        for (int i = 0; i < townNum; i++) {

            prices[i] = in.nextInt();

        }



        //add road

        for (int i = 0; i < townNum-1; i++) {

            int start = in.nextInt();

            int end = in.nextInt();

            g.addEdge(start, end, prices[start] - prices[end]);

        }



        //add merchant

        int k = in.nextInt();

        int[] loc = new int[k];

        for (int i = 0; i < k; i++) {

            loc[i] = in.nextInt();

        }



        int profit = 0;



    }





    private static class Graph {



        /* Maps vertices to a list of its neighboring vertices. */

        private HashMap<Integer, Set<Integer>> neighbors = new HashMap<>();

        /* Maps vertices to a list of its connected edges. */

        private HashMap<Integer, Set<Edge>> edges = new HashMap<>();

        /* A sorted set of all edges. */

        private TreeSet<Edge> allEdges = new TreeSet<>();



        /* Returns the vertices that neighbor V. */

        public TreeSet<Integer> getNeighbors(int v) {

            return new TreeSet<Integer>(neighbors.get(v));

        }



        /* Returns all edges adjacent to V. */

        public TreeSet<Edge> getEdges(int v) {

            return new TreeSet<Edge>(edges.get(v));

        }



        /* Returns a sorted list of all vertices. */

        public TreeSet<Integer> getAllVertices() {

            return new TreeSet<Integer>(neighbors.keySet());

        }



        /* Returns a sorted list of all edges. */

        public TreeSet<Edge> getAllEdges() {

            return new TreeSet<Edge>(allEdges);

        }



        /* Adds vertex V to the graph. */

        public void addVertex(Integer v) {

            if (neighbors.get(v) == null) {

                neighbors.put(v, new HashSet<Integer>());

                edges.put(v, new HashSet<Edge>());

            }

        }



        /* Creates an Edge between V1 and V2 with no weight. */

        public void addEdge(int v1, int v2) {

            addEdgeHelper(v1, v2, 0);

        }



        /* Creates an Edge between V1 and V2 with weight WEIGHT. */

        public void addEdge(int v1, int v2, int weight) {

            addEdgeHelper(v1, v2, weight);

        }



        /* Returns true if V1 and V2 are connected by an edge. */

        public boolean isNeighbor(int v1, int v2) {

            return neighbors.get(v1).contains(v2) && neighbors.get(v2).contains(v1);

        }



        /* Returns true if the graph contains V as a vertex. */

        public boolean containsVertex(int v) {

            return neighbors.get(v) != null;

        }



        /* Returns true if the graph contains the edge E. */

        public boolean containsEdge(Edge e) {

            return allEdges.contains(e);

        }



        /* Returns if this graph spans G. */

        public boolean spans(Graph g) {

            TreeSet<Integer> all = getAllVertices();

            if (all.size() != g.getAllVertices().size()) {

                return false;

            }

            Set<Integer> visited = new HashSet<>();

            Queue<Integer> vertices = new ArrayDeque<>();

            Integer curr;



            vertices.add(all.first());

            while ((curr = vertices.poll()) != null) {

                if (!visited.contains(curr)) {

                    visited.add(curr);

                    for (int n : getNeighbors(curr)) {

                        vertices.add(n);

                    }

                }

            }

            return visited.size() == g.getAllVertices().size();

        }



        /* Overrides objects equals method. */

        public boolean equals(Object o) {

            if (!(o instanceof Graph)) {

                return false;

            }

            Graph other = (Graph) o;

            return neighbors.equals(other.neighbors) && edges.equals(other.edges);

        }



        /* A helper function that adds a new edge from V1 to V2 with WEIGHT as the

           label. */

        private void addEdgeHelper(int v1, int v2, int weight) {

            addVertex(v1);

            addVertex(v2);



            neighbors.get(v1).add(v2);

            neighbors.get(v2).add(v1);



            Edge e1 = new Edge(v1, v2, weight);

            Edge e2 = new Edge(v2, v1, weight);

            edges.get(v1).add(e1);

            edges.get(v2).add(e2);

            allEdges.add(e1);

        }



    }



    private static class Edge {



        private int from;

        private int to;

        private int weight;



        Edge(int from, int to, int weight) {

            this.from = from;

            this.to = to;

            this.weight = weight;

        }



        public String toString() {

            return "(" + from + ", " + to + ", weight = " + weight + ")";

        }



    }





    public static HashMap<Integer, HashSet<Integer>> getPossibleRoads(Graph g, int[] loc) {

        HashMap<Integer, HashSet<Integer>> roads = new HashMap<>();

        for (int mer: loc) {

            ArrayDeque<Integer> fringe = new ArrayDeque<>();

            HashSet<Integer> area = new HashSet<>();

            fringe.add(mer);

            while (!fringe.isEmpty()) {

                int curr = fringe.poll();

                area.add(curr);

                for (int i : g.getNeighbors(curr)) {

                    area.add(i);

                }

            }

            roads.put(mer, area);

        }

        return roads;

    }



    public int maxProfit(int prices[]) {

        int maxprofit = 0;

        for (int i = 0; i < prices.length - 1; i++) {

            for (int j = i + 1; j < prices.length; j++) {

                int profit = prices[j] - prices[i];

                if (profit > maxprofit)

                    maxprofit = profit;

            }

        }

        return maxprofit; 

    }

}
