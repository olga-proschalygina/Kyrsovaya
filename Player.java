public final class Player extends BaseEntity {
    private final Weapon weapon;
    private int potions;
    private ICombatStrategy strategy;

    public Player(String name, int health, int potions, Weapon.Type weaponType, String weaponName, int weaponDamage) {
        super(name, health);
        if (potions < 0) {
            throw new GameRuleException("Количество зелий не может быть отрицательным");
        }
        this.potions = potions;
        this.weapon = new Weapon(weaponType, weaponName, weaponDamage);
        this.strategy = new NormalDamageStrategy();
    }

    // Конструктор копирования
    public Player(Player other) {
        super(other);
        this.potions = other.potions;
        this.weapon = new Weapon(other.weapon.getType(), other.weapon.getName(), other.weapon.getDamage());
        this.strategy = new NormalDamageStrategy();
    }

    @Override
    public BaseEntity cloneEntity() {
        return new Player(this);
    }

    @Override
    public String describe() {
        return super.describe() + ", зелий: " + potions;
    }

    @Override
    public String getTypeName() { return "Игрок"; }

    @Override
    public String getAttackMessage() { return "Игрок атакует!"; }

    public void usePotion() {
        if (potions <= 0) {
            throw new GameRuleException("Нет зелий для использования!");
        }
        if (health >= maxHealth) {
            throw new GameRuleException("Здоровье уже максимальное!");
        }
        potions--;
        health = Math.min(maxHealth, health + 30);
        System.out.println("[Player] " + name + " использовал зелье. ОЗ: " + health);
    }

    public int attack() {
        int baseDamage = weapon.attack();
        int finalDamage = strategy.calculateDamage(baseDamage);
        System.out.println("[Player] " + name + " атакует на " + finalDamage + " урона.");
        return finalDamage;
    }

    public void setStrategy(ICombatStrategy strategy) {
        this.strategy = strategy;
    }
}