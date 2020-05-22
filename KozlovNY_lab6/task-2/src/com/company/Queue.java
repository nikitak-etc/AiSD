package com.company;

public class Queue<List> {
    Integer top = -1; //номер последнего добавленного элемента
    LinkedList<List> list = new LinkedList<>();
    //при создании чтобы был пустой как и нужно
    public Queue() {
        list.first = list.last = null;
    }
    //добавление
    void enqueue(List data) {
        top++;
        list.addLast(data);
    }
    //удаление с начала
    List dequeue() {
        if(!list.isEmpty()){
            List first = list.first.data;
            list.deleteFirst();
            top--;
            return first;
        }
        else
            return null;
    }
    //возвращаем последний номер последнего элемента + 1 - размер стека
    public Integer getSize(){
        return top+1;
    }
    //выборка вершины
    List peek() {
        if (list.isEmpty())
            return null;
        return list.first.data;
    }
    //проверка на пустоту
    public boolean isEmpty() {
        return list.last == null;
    }
    //понимает, если выводим наш queue, то пишем toString или нет - сработает проверка
    @Override
    public String toString() {
        return list.toString();
    }
}
