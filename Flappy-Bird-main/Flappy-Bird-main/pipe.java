import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import java.awt.Image;
import java.io.IOException;

public class pipe extends unit {

    pipe(int xPos, int yPos) {
        this.y = yPos;
        this.x = xPos;
        loadImage();
        getImageDimension();
    }

    public void loadImage() {
        try {
            pipe = ImageIO.read(getClass().getResourceAsStream("/images/column.png"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        Image scaled = pipe.getScaledInstance(95, 700, Image.SCALE_SMOOTH);
        var ii = new ImageIcon(scaled);
        image = ii.getImage();
    }

}
