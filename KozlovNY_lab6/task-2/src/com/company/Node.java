package com.company;

public class Node<List> {
    //Node интерфейс является основным типом данных для всей объектной модели документа,который представляет единственный узел в дереве документов.
    public List data;
    public Node<List> next;
    public Node<List> previous;
    //возврат значения
    public Node(List data) {
        this.data = data;
    }
    @Override
    public String toString() {
        return data.toString();
    }
}