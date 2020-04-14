import java.util.Stack;

class J_455_1 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> s1 = new Stack<Integer>();
        Stack<Integer> s2 = new Stack<Integer>();
        while (l1 != null) {
        	s1.push(l1.val);
        	l1 = l1.next;
        }
        while (l2 != null) {
        	s2.push(l2.val);
        	l2 = l2.next;
        }
        int carry = 0;
        ListNode ret = null;
        while (!s1.isEmpty() || !s2.isEmpty() || carry != 0) {
        	int sum = carry;
        	sum += s1.isEmpty() ? 0 : s1.pop();
        	sum += s2.isEmpty() ? 0 : s2.pop();
        	ListNode temp = new ListNode(sum % 10);
        	carry = sum / 10;
        	temp.next = ret;
        	ret = temp;
        }
        return ret;
    }
}