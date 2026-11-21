public final class Player extends BaseEntity {
    private final Weapon weapon;
    private int potions;

    public Player(String name, int health, int potions, String wName, int wDamage) {
        super(name, health);
        this.potions = potions > 0 ? potions : 0;
        this.weapon = new Weapon(wName, wDamage);
    }

    public Player(Player other) {
        super(other);
        this.potions = other.potions;
        this.weapon = new Weapon(other.weapon.getName(), other.weapon.attack());
    }

    @Override
    public void takeDamage(int damage) {
        if (damage <= 0) return;
        this.health = Math.max(0, this.health - damage);
        System.out.println("[Player] " + name + " получил урон " + damage + ". ОЗ: " + health);
    }

    @Override
    public BaseEntity cloneEntity() {
        return new Player(this);
    }

    @Override
    public String describe() {
        return super.describe() + ", зелий: " + potions; 
    }

    public boolean usePotion() {
        if (potions <= 0 || health >= maxHealth) return false;
        potions--;
        health = Math.min(maxHealth, health + 30);
        System.out.println("[Player] " + name + " использовал зелье. ОЗ: " + health);
        return true;
    }

    public int attack() { return weapon.attack(); }
}