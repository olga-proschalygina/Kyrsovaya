public class Player {
    private final String name;
    private int health;
    private final int maxHealth;
    private int potions;
    
    // КОМПОЗИЦИЯ: оружие является частью игрока, создается вместе с ним
    private final Weapon weapon;

    public Player(String name, int health, int potions, Weapon.Type weaponType, String weaponName, int weaponDamage) {
        this.name = name;
        
        // Проверка правила: здоровье должно быть > 0
        if (health <= 0) {
            System.err.println("[Player] Ошибка: здоровье не может быть <= 0. Установлено 1.");
            this.health = 1;
            this.maxHealth = 1;
        } else {
            this.health = health;
            this.maxHealth = health;
        }

        // Проверка правила: зелий не может быть < 0
        if (potions < 0) {
            System.err.println("[Player] Ошибка: зелий не может быть < 0. Установлено 0.");
            this.potions = 0;
        } else {
            this.potions = potions;
        }

        // Целое (Player) создает свою часть (Weapon) само!
        this.weapon = new Weapon(weaponType, weaponName, weaponDamage);
    }

    public void takeDamage(int damage) {
        if (damage <= 0) {
            System.err.println("[Player] Ошибка: урон не может быть <= 0.");
            return;
        }
        
        // Проверка правила: ОЗ не может стать меньше нуля
        if (health - damage < 0) {
            health = 0;
        } else {
            health -= damage;
        }
        System.out.println("[Player] " + name + " получил урон " + damage + ". ОЗ: " + health + "/" + maxHealth);
    }

    public boolean usePotion() {
        // Проверка правила: нельзя использовать зелье, если их нет
        if (potions <= 0) {
            System.err.println("[Player] Отказ: зелий нет.");
            return false;
        }
        if (health >= maxHealth) {
            System.err.println("[Player] Отказ: здоровье уже максимальное.");
            return false;
        }

        potions--;
        
        // Проверка правила: ОЗ не может стать больше максимума
        health += 30;
        if (health > maxHealth) {
            health = maxHealth;
        }
        System.out.println("[Player] " + name + " использовал зелье. ОЗ: " + health + "/" + maxHealth + ", зелий осталось: " + potions);
        return true;
    }

    public int attack() {
        int dmg = weapon.attack();
        System.out.println("[Player] " + name + " атакует оружием " + weapon.getName() + " на " + dmg + " урона.");
        return dmg;
    }

    public String getName() { return name; }
    public int getHealth() { return health; }
    public int getMaxHealth() { return maxHealth; }
    public int getPotions() { return potions; }
    public boolean isAlive() { return health > 0; }
    public Weapon getWeapon() { return weapon; }

    @Override
    public String toString() {
        return "Игрок: " + name + ", ОЗ: " + health + "/" + maxHealth + 
               ", зелий: " + potions + ", оружие: " + weapon.toString();
    }
}