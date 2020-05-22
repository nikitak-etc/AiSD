package com.company;

import java.util.Scanner;
import java.lang.Thread;


public class Main {

    public static void main(String[] args) throws InterruptedException {

        //Набор билетов stack,т.к. они берутся только с начала
        Stack<Integer> tasks = new Stack<>();
        for (int i = 0; i < 30; i++) {
            tasks.push(i);
        }

        //Набор билетов deque,т.к. они берутся или с начала или с конца
        Deque<Integer> tickets = new Deque<>();
        for (int i = 0; i < 30; i++) {
            tickets.push(i);
        }

        //Студенты queue,т.к. ответ по очереди
        Queue<Integer> waitingStud = new Queue<>();

        //Отвечающие студенты
        Queue<Integer> studAnswer = new Queue<>();
        Queue<Integer> studAnswerTask = new Queue<>();
        Queue<Integer> studAnswerTicket = new Queue<>();

        while (true) {
            //выбор действия
            int choice = (int) (Math.random() * 3);
            switch(choice){
                case 0:
                    System.out.println("Добавление студента");
                    break;
                case 1:
                    System.out.println("Вытягивание билета и задачи");
                    break;
                case 2:
                    System.out.println("Проверка и принятие решения");
                    break;
            }
            Thread.sleep(3000);
            switch (choice) {

                case 0: {
                    int StudID = (int) ((Math.random() * 100 + 1));
                    System.out.println(StudID);
                    waitingStud.enqueue(StudID);
                    break;
                }

                case 1: {

                    //вызываем студента отвечать
                    if (waitingStud.isEmpty()) {
                        System.out.println("Студентов нет(боятся)");
                        break;
                    }

                    int StudF = waitingStud.peek();

                    //Студент берет билет
                    int ticketNum = 0;

                    //если нет прерываем
                    if (tickets.isEmpty()) {
                        System.out.println("Билетов нет");
                        break;
                    }
                    int ili = (int) (Math.random() * 2); //0 с начала / 1 с конца

                    if (ili == 0) {
                        ticketNum = tickets.peekFirst();
                        System.out.println("Студент " + StudF + " взял билет №" + ticketNum);
                        System.out.println("Тянул с начала");
                        tickets.pop();
                    }
                    if (ili == 1) {

                        ticketNum = tickets.peekLast();
                        System.out.println("Студент " + StudF + " взял билет №" + ticketNum);
                        System.out.println("Тянул с конца");
                        tickets.eject();
                    }

                    //берет задачу
                    //если нет прерываем
                    if (tasks.isEmpty()) {
                        System.out.println("Задач нет");
                        break;
                    }

                    int zd_tmp = tasks.peek();
                    System.out.println("Студент " + StudF + " взял задачу №" + zd_tmp);
                    tasks.pop();

                    //заносим в очередь отвечаюищих
                    // студент билет задача

                    studAnswer.enqueue(StudF);
                    studAnswerTask.enqueue(zd_tmp);
                    studAnswerTicket.enqueue(ticketNum);

                    waitingStud.dequeue(); //и убираем из ожидающих

                    break;
                }

                case 2: {
                    //вызываем отвечающего
                    if (studAnswer.isEmpty()) {
                        System.out.println("Отвечать некому(не готовы)");
                        break;
                    }

                    int ans = studAnswer.peek();
                    int ansTask = studAnswerTask.peek();
                    int ansTicket = studAnswerTicket.peek();
                    System.out.println("Отвечает студент №" + ans + " билет №" + ansTicket + " задача №" + ansTask);

                    int result = (int) (Math.random() * 2); //0 - не сдал / 1 сдал

                    if (result == 0) {
                        //Сдал билеты и вернулся в конец очереди ожидающих
                        System.out.println("Не сдал(");
                        waitingStud.enqueue(ans);
                    }

                    if (result == 1) {
                        //Сдал билеты и пошёл отмечать
                        System.out.println("Сдал)");
                    }

                    tickets.push(ansTicket); //для определенности в начало списка
                    tasks.push(ansTask); //задачу в верх стека
                    studAnswer.dequeue(); //удаляем из очереди отвечающих задачи, билеты и самих отвечающих
                    studAnswerTask.dequeue();
                    studAnswerTicket.dequeue();

                    break;
                }

            }
        }
    }
}
