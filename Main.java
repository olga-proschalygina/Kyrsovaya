import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        System.out.println("=== ЛР 3. Часть 1. Java (Управляемая память) ===\n");

        // ==========================================
        // 1. Ссылки и копии
        // ==========================================
        System.out.println("\n[1. Ссылки и копии: переменная хранит ссылку]");
        Player p1 = new Player("Hero1", 100, 1, Weapon.Type.SWORD, "Excalibur", 25);
        Player p2 = p1; // Копируется ССЫЛКА, а не объект!

        p2.takeDamage(40); // Наносим урон через "вторую" переменную
        System.out.println("Состояние p1: " + p1); // ОЗ p1 тоже уменьшилось, т.к. это один объект
        System.out.println("p1 == p2 ? " + (p1 == p2)); // true

        // ==========================================
        // 2. Освобождение ресурса (try-with-resources)
        // ==========================================
        System.out.println("\n[2. Освобождение ресурса без деструктора]");
        try (Battlelog log = new Battlelog("Битва с Драконом")) {
            log.write("Игрок входит в арену");
            log.write("Босс атакует");
        } // Здесь автоматически вызывается log.close()
        System.out.println("Вышли из блока try. Ресурс освобожден.");

        // ==========================================
        // 3. Работа композиции и агрегации
        // ==========================================
        System.out.println("\n[3. Композиция и агрегация]");
        Player hero = new Player("Hero", 100, 2, Weapon.Type.SWORD, "Sword", 20);
        Boss boss = new Boss("Dragon", 200, 45, hero); // hero создан вне босса и передан ему

        System.out.println(hero);
        System.out.println(boss);

        boss.attackTarget();
        hero.attack();

        // ==========================================
        // 4. Сборщик мусора (Garbage Collector)
        // ==========================================
        System.out.println("\n[4. Сборщик мусора (GC)]");
        // Создаем объект и слабую ссылку на него
        Player temp = new Player("Ghost", 10, 0, Weapon.Type.BOW, "Bow", 5);
        WeakReference<Player> watcher = new WeakReference<>(temp);
        
        System.out.println("Объект жив? " + (watcher.get() != null)); // true
        
        temp = null; // Убираем последнюю обычную ссылку
        System.out.println("temp = null. Просим GC собрать мусор...");
        
        System.gc(); // Просим сборщик мусора запуститься (не гарантируется, но в учебных целях сработает)
        try { Thread.sleep(100); } catch (InterruptedException e) {} // Даем GC время
        
        System.out.println("Объект жив после GC? " + (watcher.get() != null)); // false

        // ==========================================
        // 5. Массив объектов (аналог из C++)
        // ==========================================
        System.out.println("\n[5. Массив объектов в куче]");
        List<Player> players = new ArrayList<>();
        players.add(new Player("P1", 50, 1, Weapon.Type.SWORD, "Sword1", 10));
        players.add(new Player("P2", 60, 1, Weapon.Type.BOW, "Bow1", 12));

        for (Player p : players) {
            System.out.println("Игрок в массиве: " + p.getName() + ", ОЗ: " + p.getHealth());
        }
        // Память очистится сборщиком мусора автоматически, никаких delete нет

        System.out.println("\n=== Конец программы ===");
    }
}