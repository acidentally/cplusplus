import javax.swing.JFrame;

public class frame extends JFrame {

    gameEngine gEngine = new gameEngine();

    frame() {
        this.setTitle("flappy bird");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.add(new gameEngine());
        this.pack();
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }
}
