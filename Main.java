import java.io.PrintStream;
import java.nio.charset.StandardCharsets;

public class Main {
    // Функция, работающая через интерфейс (демонстрация полиморфизма)
    public static void applyDamage(IAttackable target, int damage) {
        System.out.println("[Система] Наносим урон через интерфейс IAttackable...");
        target.receiveDamage(damage);
    }

    public static void main(String[] args) {
        // Пытаемся настроить вывод, чтобы русские буквы отображались в VS Code
        try {
            System.setOut(new PrintStream(System.out, true, StandardCharsets.UTF_8.name()));
        } catch (Exception e) {
            // Если не получилось, продолжаем работу
        }

        System.out.println("=== ЛР 5: Полиморфизм в Java ===\n");

        try {
            // 1. Создание объектов (демонстрация интерфейсов и наследования)
            Player hero = new Player("Hero", 100, 1, Weapon.Type.SWORD, "Excalibur", 20);
            Boss boss = new Boss("Dragon", 200, 45, hero);

            System.out.println("\n--- 1. Интерфейсы и полиморфизм ---");
            // Передаем объекты через интерфейс IAttackable
            applyDamage(hero, 10);
            applyDamage(boss, 50);

            System.out.println("\n--- 2. Раннее и позднее связывание ---");
            BaseEntity ptr = hero;
            // Раннее связывание (вызывается метод базового класса, так как он final)
            System.out.println("Раннее: " + ptr.getEarlyBindingType());
            // Позднее связывание (вызывается переопределенный метод Player)
            System.out.println("Позднее: " + ptr.getTypeName());

            System.out.println("\n--- 3. Проверка типа (instanceof) ---");
            BaseEntity[] entities = { hero, boss };
            for (BaseEntity e : entities) {
                if (e instanceof IAttackable) {
                    System.out.println(e.getName() + " умеет получать урон (реализует IAttackable).");
                }
            }

            System.out.println("\n--- 4. Конфигурирование (смена поведения) ---");
            System.out.println("Обычная атака:");
            hero.attack(); // Урон 20

            System.out.println("Меняем тактику на критическую:");
            hero.setStrategy(new CriticalDamageStrategy());
            hero.attack(); // Урон 40

            System.out.println("\n--- 5. Исключения ---");
            System.out.println("Используем зелье (оно есть):");
            hero.usePotion(); // Успешно

            System.out.println("Используем зелье еще раз (их нет):");
            hero.usePotion(); // Здесь должно вылететь исключение!

        } catch (GameRuleException e) {
            // Перехват частного (кастомного) исключения
            System.err.println("\n[ОШИБКА ИГРЫ]: " + e.getMessage());
        } catch (Exception e) {
            // Перехват общего исключения (идет после частного)
            System.err.println("\n[СИСТЕМНАЯ ОШИБКА]: " + e.getMessage());
        }

        System.out.println("\n=== Конец программы ===");
    }
}