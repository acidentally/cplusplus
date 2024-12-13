import java.awt.Image;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.Graphics;

public class bird extends unit {
    // an animation variables use in bird class
    int counter = 0;
    int state = 1;
    // width and height of the bird
    int scaledX = 50;
    int scaledY = 34;

    public bird() {
        loadImage();
    }

    public void loadImage() {
        try {
            midFlap = ImageIO.read(getClass().getResourceAsStream("/images/yellowbird-midflap.png"));
            upFlap = ImageIO.read(getClass().getResourceAsStream("/images/yellowbird-upflap.png"));
            downFlap = ImageIO.read(getClass().getResourceAsStream("/images/yellowbird-downflap.png"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void increasingCounter() {
        counter++;
    }

    // use for animations by change bird's image overtime
    public void update() {
        if (counter > 4) {
            if (state == 1) {
                state = 2;
            } else if (state == 2) {
                state = 3;
            } else if (state == 3) {
                state = 1;
            }
            counter = 0;
        }
    }

    public void draw(Graphics g, int xPos, int yPos, gameEngine gEngine) {
        BufferedImage currentImage = null;
        switch (state) {
            case 1 -> currentImage = downFlap;
            case 2 -> currentImage = midFlap;
            case 3 -> currentImage = upFlap;
        }
        Image image = currentImage.getScaledInstance(scaledX, scaledY, Image.SCALE_SMOOTH);
        g.drawImage(image, xPos, yPos, 50, 34, gEngine);
    }
}
