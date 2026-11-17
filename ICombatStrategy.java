public interface ICombatStrategy {
    int calculateDamage(int baseDamage);
}

class NormalDamageStrategy implements ICombatStrategy {
    @Override
    public int calculateDamage(int baseDamage) {
        return baseDamage;
    }
}

class CriticalDamageStrategy implements ICombatStrategy {
    @Override
    public int calculateDamage(int baseDamage) {
        return baseDamage * 2;
    }
}