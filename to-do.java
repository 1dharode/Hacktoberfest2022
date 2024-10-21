import java.util.ArrayList;
import java.util.Scanner;

public class ToDoList {
    private ArrayList<String> tasks;

    public ToDoList() {
        tasks = new ArrayList<>();
    }

    public void addTask(String task) {
        tasks.add(task);
        System.out.println("Task added: " + task);
    }

    public void removeTask(int index) {
        if (index < 0 || index >= tasks.size()) {
            System.out.println("Invalid task index.");
        } else {
            System.out.println("Task removed: " + tasks.remove(index));
        }
    }

    public void viewTasks() {
        if (tasks.isEmpty()) {
            System.out.println("No tasks available.");
            return;
        }
        System.out.println("Your tasks:");
        for (int i = 0; i < tasks.size(); i++) {
            System.out.println((i + 1) + ". " + tasks.get(i));
        }
    }

    public static void main(String[] args) {
        ToDoList toDoList = new ToDoList();
        Scanner scanner = new Scanner(System.in);
        String command;

        System.out.println("Welcome!");
        do {
            System.out.println("\nEnter a command (add, remove, view, exit):");
            command = scanner.nextLine().toLowerCase();

            switch (command) {
                case "add":
                    System.out.print("Enter the task: ");
                    String task = scanner.nextLine();
                    toDoList.addTask(task);
                    break;
                case "remove":
                    System.out.print("Enter number of the task to  remove: ");
                    int index = scanner.nextInt() - 1;
                    scanner.nextLine(); // Consume newline
                    toDoList.removeTask(index);
                    break;
                case "view":
                    toDoList.viewTasks();
                    break;
                case "exit":
                    System.out.println("Exiting!");
                    break;
                default:
                    System.out.println("Invalid! Please try again");
            }
        } while (!command.equals("exit"));

        scanner.close();
    }
}
