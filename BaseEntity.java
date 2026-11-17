public abstract class BaseEntity implements IAttackable {
    private static int nextId = 1;
    protected final int id;
    protected String name;
    protected int health;
    protected int maxHealth;

    public BaseEntity(String name, int health) {
        if (health <= 0) {
            throw new GameRuleException("Здоровье при создании не может быть <= 0");
        }
        this.id = nextId++;
        this.name = name;
        this.health = health;
        this.maxHealth = health;
        System.out.println("[BaseEntity] Создан: " + name + " (ID: " + id + ")");
    }

    // Конструктор копирования (для Clone)
    public BaseEntity(BaseEntity other) {
        this.id = nextId++;
        this.name = other.name;
        this.health = other.health;
        this.maxHealth = other.maxHealth;
        System.out.println("[BaseEntity] Копирование: " + name + " (Новый ID: " + id + ")");
    }

    @Override
    public void receiveDamage(int damage) {
        if (damage <= 0) {
            throw new GameRuleException("Урон не может быть отрицательным или нулевым");
        }
        this.health = Math.max(0, this.health - damage);
        System.out.println("[BaseEntity] " + name + " получил урон " + damage + ". ОЗ: " + health);
    }

    public abstract BaseEntity cloneEntity();
    public String describe() { return "[" + id + "] " + name; }
    public String getTypeName() { return "Сущность"; }
    
    // Раннее связывание (не виртуальный метод)
    public final String getEarlyBindingType() { return "Базовая сущность (раннее)"; }

    public int getId() { return id; }
    public String getName() { return name; }
    public int getHealth() { return health; }
    public boolean isAlive() { return health > 0; }
}