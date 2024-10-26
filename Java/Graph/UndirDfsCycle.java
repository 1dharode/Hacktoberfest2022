import java.util.*;
public class UndirDfsCycle {
    static class Edge{
        int src;
        int dest;
        Edge(int s,int d){
            this.src=s;
            this.dest=d;
        }
    } 


    public static void create(ArrayList<Edge>graph[]){
        for(int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<Edge>();
        }

        graph[2].add(new Edge(2,3));

        graph[3].add(new Edge(3,1));

        graph[4].add(new Edge(4,0));
        graph[4].add(new Edge(4,1));

        graph[5].add(new Edge(5,0));
        graph[5].add(new Edge(5,2));     
    }

    public static boolean isCycleUndirected(ArrayList<Edge>graph[],int curr,boolean vis[],int par){//O(V+E)
        vis[curr]=true;
        for(int i=0;i<graph[curr].size();i++){
            Edge e=graph[curr].get(i);
            if(vis[e.dest]&&e.dest!=par){
                  return true;
            }else if(!vis[e.dest]){
                if(isCycleUndirected(graph, e.dest, vis, curr)){
                    return true;
                }
            }
        }
        return false;
    }
    public static void main(String args[]){
        int V=6;
        @SuppressWarnings("unchecked")
        ArrayList<Edge>graph[]=new ArrayList[V];
        create(graph);
        System.out.println(isCycleUndirected(graph,0,new boolean[V], -1));
    } 
}

