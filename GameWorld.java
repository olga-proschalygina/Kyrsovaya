public class GameWorld {
    private Player player;
    private Boss boss;

    public GameWorld(Player player, Boss boss) {
        this.player = player;
        this.boss = boss;
    }

    public void startCombat() {
        if (player == null || boss == null) return;
        
        System.out.println("--- Бой начался! ---");
        boss.attackTarget(player); // Босс бьет игрока
        int dmg = player.attack(); // Игрок бьет босса
        boss.takeDamage(dmg);
        System.out.println("--------------------");
    }
}