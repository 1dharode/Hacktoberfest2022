class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []

def dfs(node):
    if node is None:
        return
    
    # Process the current node
    print(node.value, end=' ')
    
    # Recursively visit each child
    for child in node.children:
        dfs(child)

def build_tree():
    n = int(input("Enter the number of nodes in the tree: "))
    
    if n <= 0:
        print("The tree must have at least one node.")
        return None
    
    # Create all nodes first
    nodes = {}
    for i in range(n):
        value = int(input(f"Enter value for node {i + 1}: "))
        nodes[i] = TreeNode(value)

    # Build the tree structure
    for i in range(n):
        children_count = int(input(f"Enter number of children for node with value {nodes[i].value}: "))
        for _ in range(children_count):
            child_index = int(input("Enter the index of the child node (1-based): ")) - 1
            if 0 <= child_index < n:
                nodes[i].children.append(nodes[child_index])
            else:
                print("Invalid index, child not added.")

    return nodes[0]  # Return the root node (first entered node)

if __name__ == "__main__":
    # Build the tree from user input
    root = build_tree()
    
    # Perform DFS
    print("DFS Traversal:")
    if root is not None:
        dfs(root)
    else:
        print("No tree to traverse.")
