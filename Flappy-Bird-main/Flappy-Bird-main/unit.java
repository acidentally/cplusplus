import java.awt.Image;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;

public class unit {

    int x;
    int y;
    int imageWidth;
    int imageHeight;
    Image image;

    public BufferedImage midFlap, downFlap, upFlap,
            pipe, gameOver, background,
            message, floor;

    protected void setX(int x) {
        this.x = x;
    }

    int getX() {
        return x;
    }

    protected void setY(int y) {
        this.y = y;
    }

    int getY() {
        return y;
    }

    int getImageWidth() {
        return imageWidth;
    }

    int getImageHeight() {
        return imageHeight;
    }

    Image getImage() {
        return image;
    }

    Rectangle getRect() {
        return new Rectangle(x, y, image.getWidth(null), image.getHeight(null));
    }

    void getImageDimension() {
        imageWidth = image.getWidth(null);
        imageHeight = image.getHeight(null);
    }
}
