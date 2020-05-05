import java.util.Stack;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class J_98_1 {
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        Stack<TreeNode> temp = new Stack<>();
        double inorder = Double.MIN_VALUE;
        while (!temp.isEmpty() || root != null) {
            while (root != null) {
                temp.push(root);
                root = root.left;
            }
            root = temp.pop();
            if (root.val <= inorder) return false;
            inorder = root.val;
            root = root.right;
        }
        return true;
    }
}