class LinkNode {
    int val;
    LinkNode next;
    LinkNode(){}
    LinkNode(int val) {
        this.val = val;
    }
}

class MyLinkedList {
    int size;
    LinkNode head;

    public MyLinkedList() {
        size = 0;
        head = new LinkNode(0);
    }
    
    public int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        LinkNode cur = head;
        for (int i = 0; i <= index; i++) {
            cur = cur.next;
        }
        return cur.val;
    }
    
    public void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    public void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    public void addAtIndex(int index, int val) {
        if (index > size) {
            return ;
        }
        if (index < 0) {
            index = 0;
        }
        size++;
        LinkNode pre = head;
        for (int i = 0; i < index; i++) {
            pre = pre.next;
        }
        LinkNode cur = new LinkNode(val);
        cur.next = pre.next;
        pre.next = cur;
        return ;
    }
    
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return ;
        }
        size--;
        if (index == 0) {
            head = head.next;
            return ;
        }
        LinkNode cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur.next;
        }
        cur.next = cur.next.next;
        return ;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */