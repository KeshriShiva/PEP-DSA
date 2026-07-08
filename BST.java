import java.util.*;

class BST {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int v) { val = v; }
    }

    TreeNode deleteNode(TreeNode r, int k) {
        if (r == null) return r;
        if (k < r.val) r.left = deleteNode(r.left, k);
        else if (k > r.val) r.right = deleteNode(r.right, k);
        else {
            if (r.left == null) return r.right;
            if (r.right == null) return r.left;
            TreeNode t = r.right;
            while (t.left != null) t = t.left;
            r.val = t.val;


            r.right = deleteNode(r.right, t.val);
        }
        
        return r;
    }

    static void inorder(TreeNode r) {
        if (r != null) {
            inorder(r.left);
            System.out.print(r.val + " ");
            inorder(r.right);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        TreeNode r = new TreeNode(5);
        r.left = new TreeNode(3);
        r.right = new TreeNode(6);
        r.left.left = new TreeNode(2);
        r.left.right = new TreeNode(4);
        r.right.right = new TreeNode(7);

        int k = sc.nextInt();
        BST b = new BST();
        r = b.deleteNode(r, k);
        inorder(r);
    }
}