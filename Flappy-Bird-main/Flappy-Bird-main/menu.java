import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import java.awt.Image;
import java.awt.Graphics;
import java.io.IOException;

public class menu extends unit {

    menu() {
        loadImage();
        getImageDimension();
    }

    public void loadImage() {
        try {
            message = ImageIO.read(getClass().getResourceAsStream("/images/message.png"));
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        Image scaled = message.getScaledInstance(190, 275, Image.SCALE_SMOOTH);
        var ii = new ImageIcon(scaled);
        image = ii.getImage();
    }

    public void renderMenu(Graphics g, gameEngine gEngine) {
        g.drawImage(getImage(), 100, 170, getImageWidth(), getImageHeight(), gEngine);
    }
}
