import java.awt.Image;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import java.awt.Graphics;

public class floor extends unit {

    public floor() {
        loadImage();
        getImageDimension();
    }

    public void loadImage() {
        try {
            floor = ImageIO.read(getClass().getResourceAsStream("/images/floor.png"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        Image scaled = floor.getScaledInstance(375, 125, Image.SCALE_SMOOTH);
        var ii = new ImageIcon(scaled);
        image = ii.getImage();
    }

    public void renderFloor(Graphics g, int xPos, gameEngine gEngine) {
        g.drawImage(getImage(), xPos, 550, getImageWidth(), getImageHeight(), gEngine); // screen height - 125 (the
                                                                                        // height of the floor) = 475
    }

    // create another floor for the animations
    public void renderBackupFloor(Graphics g, int xPos, gameEngine gEngine) {
        g.drawImage(getImage(), xPos, 550, getImageWidth(), getImageHeight(), gEngine);
    }

}
