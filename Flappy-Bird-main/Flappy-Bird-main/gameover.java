import java.awt.Image;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;

public class gameover extends unit {

    public final int SCREEN_WIDTH = 375;
    public final int SCREEN_HEIGHT = 650;

    gameover() {
        loadImage();
        getImageDimension();
    }

    public void loadImage() {
        try {
            gameOver = ImageIO.read(getClass().getResourceAsStream("/images/gameover.png"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        Image scaled = gameOver.getScaledInstance(250, 55, Image.SCALE_SMOOTH);
        var ii = new ImageIcon(scaled);
        image = ii.getImage();
    }
}