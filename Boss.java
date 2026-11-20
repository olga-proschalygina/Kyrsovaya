public class Boss {
    private final String name;
    private int health;
    private final int damage;

    // Босс больше не хранит ссылку на игрока
    public Boss(String name, int health, int damage) {
        this.name = name;
        this.health = health > 0 ? health : 1;
        this.damage = damage > 0 ? damage : 1;
    }

    public void attackTarget(Player target) {
        if (target == null || !target.isAlive()) {
            System.err.println("[Boss] Отказ: цель мертва или отсутствует.");
            return;
        }
        System.out.println("[Boss] " + name + " атакует " + target.getName());
        target.takeDamage(damage);
    }

    public void takeDamage(int damage) {
        if (damage <= 0) return;
        this.health = Math.max(0, this.health - damage);
        System.out.println("[Boss] " + name + " получил урон " + damage + ". ОЗ: " + health);
    }
    public String getName() { return name; }
    public int getHealth() { return health; }
    public boolean isAlive() { return health > 0; }
}