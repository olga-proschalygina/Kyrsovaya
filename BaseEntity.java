public abstract class BaseEntity {
    private static int nextId = 1;
    protected final int id;
    protected String name;
    protected int health;
    protected int maxHealth;

    public BaseEntity(String name, int health) {
        this.id = nextId++;
        this.name = name;
        this.health = health > 0 ? health : 1;
        this.maxHealth = this.health;
        System.out.println("[BaseEntity] Создан: " + name + " (ID: " + id + ")");
    }

    // Конструктор копирования
    public BaseEntity(BaseEntity other) {
        this.id = nextId++;
        this.name = other.name;
        this.health = other.health;
        this.maxHealth = other.maxHealth;
        System.out.println("[BaseEntity] Копия: " + name + " (Новый ID: " + id + ")");
    }

    public abstract void takeDamage(int damage);
    public abstract BaseEntity cloneEntity();

    public String describe() {
        return "[" + id + "] " + name + " (ОЗ: " + health + ")";
    }
    
    public int getId() { return id; }
    public String getName() { return name; }
    public int getHealth() { return health; }
    public boolean isAlive() { return health > 0; }
}