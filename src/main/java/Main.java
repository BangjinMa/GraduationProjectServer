import common.MessageDispatcherManager;
import netty.GameServer;

public class Main {
    public static void main(String[] args) throws Exception {
        int port = 12345;
        if (args.length != 0)
            port = Integer.parseInt(args[0]);
        MessageDispatcherManager.getInstance();
        new GameServer().bind(port);
    }
}