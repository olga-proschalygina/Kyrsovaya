public class Player {
    private final String name;
    private int health;
    private final int maxHealth;
    private int potions;
    private final Weapon weapon;

    public Player(String name, int health, int potions, Weapon.Type type, String wName, int wDamage) {
        this.name = name;
        this.health = health > 0 ? health : 1;
        this.maxHealth = this.health;
        this.potions = potions > 0 ? potions : 0;
        this.weapon = new Weapon(type, wName, wDamage);
    }
    public void takeDamage(int damage) {
        if (damage <= 0) return;
        this.health = Math.max(0, this.health - damage);
        System.out.println("[Player] " + name + " получил урон " + damage + ". ОЗ: " + health);
    }
    public boolean usePotion() {
        if (potions <= 0 || health >= maxHealth) return false;
        potions--;
        health = Math.min(maxHealth, health + 30);
        System.out.println("[Player] " + name + " использовал зелье. ОЗ: " + health);
        return true;
    }
    public int attack() { return weapon.attack(); }
    public String getName() { return name; }
    public int getHealth() { return health; }
    public boolean isAlive() { return health > 0; }
    public Weapon getWeapon() { return weapon; }
}