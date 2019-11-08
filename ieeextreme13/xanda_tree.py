
def dfs(node, parent, adj, vis):  
  
    # Base case  
    ans = 1
  
    # Mark as visited  
    vis[node] = True
  
    # Traverse for all children  
    for it in adj[node]:  
  
        # If not equal to parent  
        if it != parent:  
            ans += dfs(it, node, adj, vis)  
      
    return ans  
  
# Function that returns the  
# count of unique paths  
def countPaths(adj, k, maxn):  
  
    # An array that marks if  
    # the node is visited or not  
    vis = [False] * (maxn + 1)  
    ans = 0
  
    # Traverse till max value of node  
    for i in range(1, maxn+1):  
  
        # If not visited  
        if not vis[i]: 
  
            # Get the number of  
            # nodes in that tree  
            numNodes = dfs(i, 0, adj, vis)  
  
            # Total unique paths in the current  
            # tree where numNodes is the total  
            # nodes in the tree  
            ans += numNodes * (numNodes - 1) // 2
          
    return ans  
  
# Function to add edges to  
# tree if value is less than K  
def addEdge(adj, u, v, k):  
  
    if u > k and v > k: 
        adj[u].append(v)  
        adj[v].append(u)  

if __name__ == "__main__":
    maxn = 10**5
  
    adj = [[] for i in range(maxn + 1)]  
    k = 0

    n = int(input())
    for i in range(n):
        s, d, w = map(int, input().split())
        addEdge(adj, s, d, k)
  
    print(countPaths(adj, k, maxn))
