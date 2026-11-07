public class Boss {
    private final String name;
    private int health;
    private final int damage;
    
    // АГРЕГАЦИЯ: босс использует игрока, созданного извне
    private Player target;

    public Boss(String name, int health, int damage, Player target) {
        this.name = name;
        if (health <= 0) {
            System.err.println("[Boss] Ошибка: здоровье не может быть <= 0. Установлено 1.");
            this.health = 1;
        } else {
            this.health = health;
        }
        
        if (damage <= 0) {
            System.err.println("[Boss] Ошибка: урон не может быть <= 0. Установлено 1.");
            this.damage = 1;
        } else {
            this.damage = damage;
        }
        this.target = target;
    }

    public boolean attackTarget() {
        // Проверка правила: нельзя атаковать без цели
        if (target == null) {
            System.err.println("[Boss] Отказ: цель не задана.");
            return false;
        }
        // Проверка правила: нельзя атаковать мертвую цель
        if (!target.isAlive()) {
            System.err.println("[Boss] Отказ: цель уже мертва.");
            return false;
        }

        System.out.println("[Boss] " + name + " атакует " + target.getName() + " на " + damage + " урона.");
        target.takeDamage(damage);
        return true;
    }

    public void takeDamage(int damage) {
        if (damage <= 0) {
            System.err.println("[Boss] Ошибка: урон не может быть <= 0.");
            return;
        }
        if (health - damage < 0) {
            health = 0;
        } else {
            health -= damage;
        }
        System.out.println("[Boss] " + name + " получил урон " + damage + ". ОЗ: " + health);
    }

    public String getName() { return name; }
    public int getHealth() { return health; }
    public boolean isAlive() { return health > 0; }
    public void setTarget(Player target) { this.target = target; }

    @Override
    public String toString() {
        return "Босс: " + name + ", ОЗ: " + health;
    }
}