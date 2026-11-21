import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        try {
            System.setOut(new java.io.PrintStream(System.out, true, "Cp866"));
        } catch (Exception e) {}

        System.out.println("=== ЛР 4: Наследование (Java) ===\n");

        System.out.println("--- Создание объектов ---");
        Player hero = new Player("Hero", 100, 2, "Excalibur", 25);
        Boss boss = new Boss("Dragon", 200, 45);

        System.out.println("\n--- Полиморфизм (через базовый класс) ---");
        List<BaseEntity> entities = new ArrayList<>();
        entities.add(hero.cloneEntity());
        entities.add(boss.cloneEntity());

        for (BaseEntity e : entities) {
            System.out.println(e.describe());
        }

        System.out.println("\n--- Бой через GameWorld ---");
        GameWorld world = new GameWorld(hero, boss);
        world.startCombat();

        System.out.println("\n=== Конец программы ===");
    }
}