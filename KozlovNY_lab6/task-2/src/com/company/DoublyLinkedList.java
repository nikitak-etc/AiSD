package com.company;

public class DoublyLinkedList<List> {
    //Структура двусвязного списка,для использования его в Deque
    public Node<List> first = null;
    public Node<List> last = null;

    public void addFirst(List data) {
        Node<List> n = new Node<>(data);
        if(first == null)
            last = first = n;
        else
        {
            n.next = first;
            first.previous = n;
            first = n;
        }
    }

    public void addLast(List data) {
        Node<List> n = new Node<>(data);
        if(last == null)
            first = last = n;
        else{
            n.previous = last;
            last.next = n;
            last = n;
        }
    }

    public void deleteFirst() {
        if(isEmpty())
            System.out.println("Underflow\n");
        else{
            first = first.next;
            if(first==null) last = null;
            else first.previous = null;
        }
    }

    public  void  deleteLast() {
        if(isEmpty())
            System.out.println("Underflow\n");
        else{
            last = last.previous;
            if(last ==null) first = null;
            else last.next = null;
        }
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        Node current = first;
        while (current != null) {
            builder.append(current).append(" ");
            current = current.next;
        }
        return builder.toString();
    }
    public boolean isEmpty() {
        return first == null;
    }

}
