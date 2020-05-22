package com.company;

public class Deque<List> {
    Integer top = -1; //номер последнего добавленного элемента
    DoublyLinkedList<List> doublyLinkedList;
    //при создании чтобы был пустой как и нужно
    Deque() {
        doublyLinkedList = new DoublyLinkedList<>();
    }
    //добавляет в начало
    void push(List data) {
        top++;
        doublyLinkedList.addFirst(data);
    }
    //добавляет в конец
    void inject(List data) {
        top++;
        doublyLinkedList.addLast(data);
    }

    //удаляет из начала
    void  pop() {
        doublyLinkedList.deleteFirst();
    }
    //удаляет из конца
    void  eject() {
        doublyLinkedList.deleteLast();
    }
    //возвращаем последний номер последнего элемента + 1 - размер стека
    public Integer getSize(){
        return top+1;
    }
    //возвращает элемент в начало
    List peekFirst() {
        return doublyLinkedList.first.data;
    }
    //возвращает последний элемент
    List peekLast() {
        return doublyLinkedList.last.data;
    }
    //проверка на пустоту
    boolean isEmpty() {
        return doublyLinkedList.isEmpty();
    }
    //понимает, если выводим наш deque, то пишем toString или нет - сработает проверка
    @Override
    public String toString() {
        return doublyLinkedList.toString();
    }
}




