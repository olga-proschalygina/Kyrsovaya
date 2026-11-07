public class Battlelog implements AutoCloseable {
    private final String title;

    public Battlelog(String title) {
        this.title = title;
        System.out.println("[+] Журнал боя открыт: " + title);
    }

    public void write(String line) {
        System.out.println("    [Log] " + line);
    }

    @Override
    public void close() {
        System.out.println("[-] Журнал боя закрыт: " + title);
    }
}