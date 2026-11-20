public class Weapon {
    public enum Type { SWORD, BOW, SPEAR }
    private final Type type;
    private final String name;
    private final int damage;
    private boolean broken;

    public Weapon(Type type, String name, int damage) {
        this.type = type;
        this.name = name;
        this.damage = damage > 0 ? damage : 1;
        this.broken = false;
    }
    public int attack() {
        if (broken) return 0;
        return damage;
    }
    public void breakWeapon() { this.broken = true; }
    public String getName() { return name; }
    public int getDamage() { return damage; }
    public Type getType() { return type; }
}