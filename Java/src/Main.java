import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        ArrayList<Foods> foodList = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        boolean sorted = false;
        int choice = 0;
        System.out.println("Welcome to the food database!");
        System.out.println("Start by adding food first!");
        while (choice != 7) {
            System.out.println("1. Add food");
            System.out.println("2. Remove food");
            System.out.println("3. Display all foods");
            System.out.println("4. Find and print food by name");
            System.out.println("5. Sort foods");
            System.out.println("6. Save to file");
            System.out.println("7. Exit");
            System.out.println("Enter your choice: ");
            choice = scanner.nextInt();
            if (choice < 1 || choice > 7) {
                System.out.println("Error! You need to enter a number between 1 and 7!");
                continue;
            }
            switch (choice) {
                case 1:
                    // Add new food to array list
                    foodList.add(NewFood());
                    sorted = false;
                    break;
                case 2:
                    // Remove food from array list
                    System.out.println("Enter food name to remove: ");
                    String foodName = scanner.next();
                    for (Foods food : foodList) {
                        if (food.getName().equals(foodName)) {
                            foodList.remove(food);
                            System.out.println("Food " + foodName + " removed!");
                            break;
                        }
                    }
                    break;
                case 3:
                    // Print all foods
                    if (foodList.size() == 0) {
                        System.out.println("\n\nFOOD LIST IS EMPTY\n\n");
                    } else {
                        System.out.println("\n------Foods------");
                        System.out.println("FOOD LIST SORTED: " + sorted);
                        for (Foods food : foodList) {
                            System.out.println("------------");
                            food.printFood();
                            System.out.println("------------\n");
                        }
                    }
                    break;
                case 4:
                    // Find from arraylist by name
                    System.out.println("Enter food name: ");
                    // New scanner to read next line
                    String foodToFind = scanner.next().toLowerCase();
                    int foodNameToShowLength = foodToFind.length();
                    boolean found = false;
                    int index = 0;
                    for (Foods food : foodList) {
                        if (food.getName().toLowerCase().equals(foodToFind)) {
                            found = true;
                            index = foodList.indexOf(food);
                        }
                    }
                    // Print index of food if found
                    if (found) {
                        System.out.println("Food " + foodToFind.toUpperCase() + " is at index: " + index);
                        Foods foodToShow = foodList.get(index);
                        PrintLine(foodNameToShowLength, true);
                        foodToShow.printFood();
                        PrintLine(foodNameToShowLength, true);
                    } else {
                        PrintLine(foodNameToShowLength, false);
                        System.out.println("FOOD WITH NAME " + foodToFind + " NOT FOUND!");
                        PrintLine(foodNameToShowLength, false);
                    }
                    break;

                case 5:
                    // Sort arraylist by calories
                    System.out.println("\n\nFOODS SORTED BY CALORIES LOWEST TO HIGHEST\n\n");
                    sorted = true;
                    for (int i = 0; i < foodList.size(); i++) {
                        for (int j = i + 1; j < foodList.size(); j++) {
                            if (foodList.get(i).getCalories() > foodList.get(j).getCalories()) {
                                Foods temp = foodList.get(i);
                                foodList.set(i, foodList.get(j));
                                foodList.set(j, temp);
                            }
                        }
                    }
                    break;
                case 6:
                    // Write arraylist to file
                    System.out.println("Enter file name: ");
                    // Get file name
                    String fileName = scanner.next();
                    SaveToFile(foodList, fileName);
                    break;
                case 7:
                    System.out.println("Goodbye!");
                    break;
                default:
                    System.out.println("Invalid input!");
            }
        }
    }

    public static void SaveToFile(ArrayList<Foods> foodList, String fileName) {
        // Create file
        try {
            String fullName = fileName + ".json";
            File file = new File(fullName);
            FileWriter fileWriter = new FileWriter(file);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
            bufferedWriter.write("{" + '"' + "food_list" + '"' + ":[");
            for (Foods food : foodList) {
                // Jsonify food
                bufferedWriter.write("{");
                bufferedWriter.write(JsonifyStringName("food_name", food.getName()));
                bufferedWriter.write(JsonifyIntValue("protein", food.getProtein(), false));
                bufferedWriter.write(JsonifyIntValue("carbs", food.getCarbs(), false));
                bufferedWriter.write(JsonifyIntValue("fat", food.getFat(), false));
                bufferedWriter.write(JsonifyIntValue("calories", food.getCalories(), true));
                bufferedWriter.write("}");
                if (food != foodList.get(foodList.size() - 1)) {
                    bufferedWriter.write(",");
                }
                bufferedWriter.newLine();
            }
            bufferedWriter.write("]}");
            // Close buffered writer
            bufferedWriter.close();
            System.out.println("Foods saved to file '" + fileName + "' successfully!\n\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static String JsonifyStringName(String key, String value) {
        return '"' + key + '"' + ":" + '"' + value + '"' + ",";
    }

    public static String JsonifyIntValue(String key, int value, boolean isLast) {
        if (isLast) {
            return '"' + key + '"' + ":" + value;
        } else {
            return '"' + key + '"' + ":" + value + ",";
        }
    }

    public static Foods NewFood() {
        String[] macroTypes = {"Enter protein: ", "Enter carbohydrate: ", "Enter fat: "};
        System.out.println("Enter name: ");
        String foodName = new Scanner(System.in).nextLine();
        int foodProtein = InputChecker(macroTypes[0], 0, 200);
        int foodCarbohydrate = InputChecker(macroTypes[1], 0, 300);
        int foodFat = InputChecker(macroTypes[2], 0, 200);
        return new Foods(foodName, foodProtein, foodCarbohydrate, foodFat);

    }

    public static int InputChecker(String macrotype, int min, int max) {
        Scanner scanner = new Scanner(System.in);
        System.out.println(macrotype);
        int macro = scanner.nextInt();
        while (macro < min || macro > max) {
            System.out.println("Error! You need to enter a number between " + min + " and " + max);
            System.out.println(macrotype);
            macro = scanner.nextInt();
        }
        return macro;
    }

    public static void PrintLine(int stringLength, boolean found) {
        String firstPart = "FOOD WITH NAME ";
        String secondPart;
        if (found) {
            secondPart = "FOUND!";
        } else {
            secondPart = "NOT FOUND!";
        }
        int firstPartLength = firstPart.length();
        int secondPartLength = secondPart.length();
        int totalLength = firstPartLength + secondPartLength + stringLength;
        for (int i = 0; i < totalLength; i++) {
            System.out.print("-");
        }
        System.out.println();

    }
}

