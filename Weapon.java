public class Weapon {
    private final String name;
    private final int damage;

    public Weapon(String name, int damage) {
        this.name = name;
        this.damage = damage > 0 ? damage : 1;
    }
    public int attack() { return damage; }
    public String getName() { return name; }
}