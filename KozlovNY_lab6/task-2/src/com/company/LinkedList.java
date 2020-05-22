package com.company;

public class LinkedList<List> {
    //Структура связного списка,для использования его в Stack и Queue
    public Node<List> first = null;
    public Node<List> last = null;

    public void addFirst(List data) {
        Node<List> n = new Node<>(data);
        n.next = first;
        first = n;

    }

    public List deleteFirst() {
        Node<List> temp = first;
        if (first.next == null)
            last = null;
        first = first.next;
        return temp.data;
    }

    public void addLast(List data) {
        Node<List> n = new Node<>(data);
        if (isEmpty()) {
            first = n;
        }
        else {
            last.next = n;
        }
        last = n;
        last.next = null;
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