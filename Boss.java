public class Boss extends BaseEntity {
    private final int damage;
    private Player target;

    public Boss(String name, int health, int damage, Player target) {
        super(name, health);
        if (damage <= 0) {
            throw new GameRuleException("Урон босса не может быть <= 0");
        }
        this.damage = damage;
        this.target = target;
    }

    public Boss(Boss other) {
        super(other);
        this.damage = other.damage;
        this.target = other.target;
    }

    @Override
    public BaseEntity cloneEntity() {
        return new Boss(this);
    }

    @Override
    public String describe() {
        return "БОСС: " + name + " (Урон: " + damage + ")";
    }

    @Override
    public String getTypeName() { return "Босс"; }

    @Override
    public String getAttackMessage() { return "Босс атакует!"; }

    public void attackTarget() {
        if (target == null || !target.isAlive()) {
            throw new GameRuleException("Босс не может атаковать: цель мертва или отсутствует.");
        }
        System.out.println("[Boss] " + name + " атакует " + target.getName() + "!");
        target.receiveDamage(damage);
    }

    public void setTarget(Player target) { this.target = target; }
}