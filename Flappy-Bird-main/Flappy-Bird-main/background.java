import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import java.awt.Graphics;
import java.awt.Image;
import java.io.IOException;

public class background extends unit {

    public final int SCREEN_WIDTH = 375;
    public final int SCREEN_HEIGHT = 650;

    public background() {
        loadImage();
        getImageDimension();
    }

    public void loadImage() {
        try {
            background = ImageIO.read(getClass().getResourceAsStream("/images/background-night.png"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        Image scaled = background.getScaledInstance(SCREEN_WIDTH, SCREEN_HEIGHT, Image.SCALE_SMOOTH);
        var ii = new ImageIcon(scaled);
        image = ii.getImage();
    }

    public void renderBackground(Graphics g, int xPos, int yPos, gameEngine gEngine) {
        g.drawImage(getImage(), xPos, yPos, getImageWidth(), getImageHeight(), gEngine);
    }
}
