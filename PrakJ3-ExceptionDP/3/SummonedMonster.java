// Nama     : Gregorius Jovan Kresnadi
// NIM      : 13518135
// Tanggal  : 02-04-2020
// Topik    : Design Pattern

public class SummonedMonster implements ISummoned {
    private Monster monster;
    private boolean open;
    private boolean attack; 
    public SummonedMonster(Monster m, boolean open, boolean attack) {
        this.open = open;
        this.attack = attack;
        this.monster = m;
    }
    
    public boolean flip() {
        if(!this.open) {
            this.open = true;
            return true;
        } else return false;
    }
    public void rotate() {
        this.attack = !this.attack;
    }

    public int getPositionValue() {
        if(attack) return this.monster.getAttackValue();
        else return this.monster.getDefenseValue();
    }

    public void render() {
        System.out.print("Monster " + monster.getName() + " dalam keadaan ");
        if (open) System.out.print("terbuka");
        else System.out.print("tertutup");
        System.out.print(" dengan posisi ");
        if (attack) System.out.println("menyerang");
        else System.out.println("bertahan");
    }
}