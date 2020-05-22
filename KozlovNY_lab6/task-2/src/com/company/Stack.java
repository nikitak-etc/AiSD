package com.company;

public class Stack<List> {
    Integer top = -1; //номер последнего добавленного элемента
    private LinkedList<List> list = new LinkedList<>();

    //добавление в вершину
    public void push(List data) {
        top++;
        list.addFirst(data);
    }
    //удаление последнего
    public List pop() {
        if (list.first == null) return null;
        else{
            top--;
            return list.deleteFirst();
        }
    }
    //извлечение первого элемента
    public List peek() {
        if (list.first == null) return null;
        return list.first.data;
    }
    //возвращаем последний номер последнего элемента + 1 - размер стека
    public Integer getSize(){
        return top + 1;
    }
    //проверка на пустоту
    public boolean isEmpty() {
        return list.first == null;
    }
    @Override
    //понимает, если выводим наш stack, то пишем toString или нет - сработает проверка
    public String toString() {
        if (list.isEmpty()){
            return "Empty";
        }
        return list.toString();
    }
}