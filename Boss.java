public class Boss extends BaseEntity {
    private final int damage;

    public Boss(String name, int health, int damage) {
        super(name, health);
        this.damage = damage > 0 ? damage : 1;
    }

    public Boss(Boss other) {
        super(other);
        this.damage = other.damage;
    }

    @Override
    public void takeDamage(int damage) {
        if (damage <= 0) return;
        this.health = Math.max(0, this.health - damage);
        System.out.println("[Boss] " + name + " получил урон " + damage + ". ОЗ: " + health);
    }

    @Override
    public BaseEntity cloneEntity() {
        return new Boss(this);
    }

    @Override
    public String describe() {
        return "БОСС: " + name + " (Урон: " + damage + ")"; 
    }

    // Атакует того, кого ему передали
    public void attackTarget(Player target) {
        if (target == null || !target.isAlive()) {
            System.out.println("[Boss] Отказ: цель мертва или отсутствует.");
            return;
        }
        System.out.println("[Boss] " + name + " атакует " + target.getName() + " на " + damage + " урона.");
        target.takeDamage(damage);
    }
}