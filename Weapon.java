public class Weapon {
    public enum Type {
        SWORD, BOW, SPEAR
    }

    private final Type type;
    private final String name;
    private final int damage;
    private boolean broken;

    public Weapon(Type type, String name, int damage) {
        this.type = type;
        this.name = name;
        // Проверка правила: урон не может быть <= 0
        if (damage <= 0) {
            System.err.println("[Weapon] Ошибка: урон не может быть <= 0. Установлено 1.");
            this.damage = 1;
        } else {
            this.damage = damage;
        }
        this.broken = false;
    }

    public int attack() {
        // Проверка правила: нельзя атаковать сломанным оружием
        if (broken) {
            System.err.println("[Weapon] Отказ: оружие сломано, атака невозможна.");
            return 0;
        }
        return damage;
    }

    public void breakWeapon() {
        this.broken = true;
        System.out.println("[Weapon] Оружие " + name + " сломано.");
    }

    public String getName() {
        return name;
    }

    public int getDamage() {
        return damage;
    }

   @Override
    public String toString() {
        return name + " (" + damage + ")";
    }
}