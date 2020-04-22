import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class J_199_1 {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ret = new ArrayList<Integer>();
        if (root == null) return ret;
        Queue<TreeNode> nodeQueue = new LinkedList<TreeNode>();
        int current = 0, next = 0;
        nodeQueue.add(root);
        current++;
        while (!nodeQueue.isEmpty()) {
            if (nodeQueue.element().left != null) {
                nodeQueue.add(nodeQueue.element().left);
                next++;
            }
            if (nodeQueue.element().right != null) {
                nodeQueue.add(nodeQueue.element().right);
                next++;
            }
            if (current == 1) ret.add(nodeQueue.element().val);
            nodeQueue.remove();
            current--;
            if (current == 0) {
                current = next;
                next = 0;
            }
        }
        return ret;
    }
}