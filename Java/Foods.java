public class Foods {

    private String name;
    private int calories;
    private int fat;
    private int carbs;
    private int protein;

    public Foods(String name, int fat, int carbs, int protein) {
        // Foods per 100g
        this.name = name;
        this.fat = fat;
        this.carbs = carbs;
        this.protein = protein;
        this.calories = fat * 9 + carbs * 4 + protein * 4;
    }

    // Getters
    public String getName() {
        return name;
    }

    public int getCalories() {
        return calories;
    }

    public int getFat() {
        return fat;
    }

    public int getCarbs() {
        return carbs;
    }

    public int getProtein() {
        return protein;
    }

    // Setters
    public void setName(String name) {
        this.name = name;
    }

    public void setProtein(int protein) {
        this.protein = protein;
    }

    public void setCarbs(int carbs) {
        this.carbs = carbs;
    }

    public void setFat(int fat) {
        this.fat = fat;
    }

    public void setCalories(int calories) {
        this.calories = calories;
    }

    public void printFood() {
        System.out.println("Name: " + getName());
        System.out.println("Protein: " + getProtein() + "g");
        System.out.println("Carbs: " + getCarbs() + "g");
        System.out.println("Fat: " + getFat() + "g");
        System.out.println("Calories: " + getCalories());
    }
}

