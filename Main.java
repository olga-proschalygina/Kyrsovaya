public class Main {
    public static void main(String[] args) {
        try {
            System.setOut(new java.io.PrintStream(System.out, true, "Cp866"));
        } catch (Exception e) {}

        System.out.println("=== ЛР 3: Управляемая память (Java) ===\n");

        // 1. Ссылки
        Player p1 = new Player("Hero1", 100, 1, Weapon.Type.SWORD, "Excalibur", 25);
        Player p2 = p1; // Копирование ссылки
        p2.takeDamage(40);
        System.out.println("ОЗ p1 после урона по p2: " + p1.getHealth());

        // 2. GameWorld
        System.out.println("\n[Взаимодействие через GameWorld]");
        Player hero = new Player("SharedHero", 100, 2, Weapon.Type.SWORD, "Excalibur", 25);
        Boss boss = new Boss("Dragon", 200, 45);
        
        GameWorld world = new GameWorld(hero, boss);
        world.startCombat();
        
        // Обнуляем ссылки в main, но объекты живы, пока на них ссылается GameWorld
        hero = null;
        boss = null;
        
        System.out.println("\nМир продолжает работать после обнуления ссылок:");
        world.startCombat();
    }
}