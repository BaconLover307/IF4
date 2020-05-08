public class SummonedMonster {
    private Monster monster;
    private boolean isOpen;
    private boolean isAttack;
    
    public SummonedMonster(Monster m, boolean open, boolean atk) {
        monster = m;
        isOpen = open;
        isAttack = atk;
    }

    // mengubah keadaan kartu dari tertutup jadi terbuka dan mengembalikan true
    // bila kartu sudah terbuka, tidak lakukan apa-apa dan kembalikan false
    public boolean flip() {
        if (this.isOpen) {
            return false;
        } else {
            this.isOpen = true;
            return true;
        }
    }
  
    // mengubah posisi karakter dari menyerang jadi bertahan, atau sebaliknya
    public void rotate() {
        this.isAttack = !this.isAttack;
    }
  
    // bila dalam posisi menyerang, mengembalikan attack.
    // bila dalam posisi bertahan, mengembalikan defense
    public int getPositionValue() {
        if (isAttack) return monster.getAttackValue();
        else return monster.getDefenseValue();
    }
  
    // menggambar kartu ke layar
    public void render() {
        System.out.print("Monster " + monster.getName() +" dalam keadaan ");
        if (isOpen) System.out.print("terbuka");
        else System.out.print("tertutup");
        System.out.print(" dengan posisi ");
        if (isAttack) System.out.println("menyerang");
        else System.out.println("bertahan");
    }

}