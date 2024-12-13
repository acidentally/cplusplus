import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Color;
import javax.swing.JPanel;
import java.awt.Graphics;
import javax.swing.Timer;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.Rectangle;

public class gameEngine extends JPanel implements ActionListener {
    // game values
    public final int SCREEN_WIDTH = 375;
    public final int SCREEN_HEIGHT = 250;
    public final int DELAY = 1000 / 60;
    public boolean running = false;
    private int score = 0;

    sound Sound;
    bird Bird;
    Timer timer;
    background Background;
    floor Floor;
    menu Menu;
    pipe[] bottomPipe, topPipe;
    gameover gameOver;

    // menu variables
    public enum STATE {
        MENU,
        GAME
    };

    private STATE state = STATE.MENU;

    // a value that check if the player clicked or not
    public boolean playerAction = false;
    // pipe values
    int pipeDistance = 300;
    int pipeYPos;
    int pipeOffset = 700; // set the location of the first pipe
    int pipeSpace = 130; // space between pipes
    // floor values
    int floorXPos = 0;
    int backupFloorXPos = floorXPos + SCREEN_WIDTH;
    // bird values
    int birdXPos = 80; // default bird position value
    int birdYPos = 275; // default bird position value
    int birdVelocity = 0;
    int birdSpeed = -70;
    double gravity = 5.5; // gravity acceleration constant
    double t = 0.1; // time use in y = v0t + 1/2*g*t^2

    gameEngine() {
        init();
        this.setPreferredSize(new Dimension(SCREEN_WIDTH, SCREEN_HEIGHT));
        this.setFocusable(true);
        this.setBackground(Color.BLACK);
        this.addMouseListener(new controller(this));
        startGame();
    }

    public void init() {
        Bird = new bird();
        Background = new background();
        Floor = new floor();
        Menu = new menu();
        gameOver = new gameover();
        Sound = new sound();
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        draw(g);
    }

    public void createPipe() {
        bottomPipe = new pipe[3];
        topPipe = new pipe[3];
        for (int i = 0; i < bottomPipe.length; i++) {
            pipeYPos = (int) (Math.random() * (450 - 250 + 1)) + 250; // lowest value allowed 250 highest 450
            bottomPipe[i] = new pipe(i * pipeDistance + pipeOffset, pipeYPos);
            topPipe[i] = new pipe(i * pipeDistance + pipeOffset, pipeYPos - 700 - pipeSpace);
        }
    }

    public void movePipe() {
        for (int i = 0; i < bottomPipe.length; i++) {
            int pipeX = bottomPipe[i].getX(); // get the current X position of the pipe
            bottomPipe[i].setX(pipeX -= 5);
            topPipe[i].setX(pipeX -= 5);
        }
    }

    public void draw(Graphics g) {
        // draw background
        Background.renderBackground(g, 0, 0, this);
        // draw bird
        if (state == STATE.MENU) {
            Menu.renderMenu(g, this);
        }
        if (state == STATE.GAME) {
            Bird.draw(g, birdXPos, birdYPos, this);
            // draw pipe
            drawPipe(g);
            // draw score
            drawScore(g);
            if (!running) {
                g.drawImage(gameOver.getImage(), (SCREEN_WIDTH / 2) - (gameOver.getImageWidth() / 2),
                        (SCREEN_HEIGHT / 2) - (gameOver.getImageHeight() / 2),
                        gameOver.getImageWidth(), gameOver.getImageHeight(), this);
            }
            // draw floor
            drawFloor(g);
        }
    }

    // draw the score on the screen
    public void drawScore(Graphics g) {
        g.setColor(Color.WHITE);
        g.setFont(new Font("Story Element", Font.CENTER_BASELINE, 35));
        FontMetrics metrics = getFontMetrics(g.getFont());
        g.drawString("" + score + "", (SCREEN_WIDTH - metrics.stringWidth("   ")) / 2,
                g.getFont().getSize() + 30);
    }

    // calculate the score when the bird goes over the pipe
    public void scoreCalc() {
        for (int i = 0; i < bottomPipe.length; i++) {
            // the variable 9837use for score adding, the X position is the right side of
            // the
            // pipe
            int scoreX = bottomPipe[i].getX() + bottomPipe[i].getImageWidth();
            if (birdXPos == scoreX) {
                score++;
                playSound(2);
            }
        }
    }

    // draw pipes top and bottom
    public void drawPipe(Graphics g) {
        for (int i = 0; i < bottomPipe.length; i++) {
            g.drawImage(bottomPipe[i].getImage(), bottomPipe[i].getX(), bottomPipe[i].getY(),
                    bottomPipe[i].getImageWidth(), bottomPipe[i].getImageHeight(),
                    this);
            g.drawImage(topPipe[i].getImage(), topPipe[i].getX(), topPipe[i].getY(), topPipe[i].getImageWidth(),
                    topPipe[i].getImageHeight(),
                    this);
            // check if the pipe goes off the screen teleport it back to the beginning
            if (bottomPipe[i].getX() + bottomPipe[i].getImageWidth() < 0) {
                bottomPipe[i].setX(3 * pipeDistance - bottomPipe[i].getImageWidth());
                topPipe[i].setX(3 * pipeDistance - topPipe[i].getImageWidth());
                // generate a new Y location for the pipe
                int newPipeY = (int) (Math.random() * (450 - 250 + 1)) + 250;
                bottomPipe[i].setY(newPipeY);
                topPipe[i].setY(newPipeY - 700 - pipeSpace);
            }
        }
    }

    // floor drawing method and creating the animations, use 2 floors and change the
    // position of them over time
    public void drawFloor(Graphics g) {
        Floor.renderFloor(g, floorXPos, this);
        if (floorXPos == -SCREEN_WIDTH) {
            floorXPos = SCREEN_WIDTH;
        }

        Floor.renderBackupFloor(g, backupFloorXPos, this);
        if (backupFloorXPos == -SCREEN_WIDTH) {
            backupFloorXPos = SCREEN_WIDTH;
        }
    }

    // start the timer
    public void startGame() {
        createPipe();
        running = true;
        timer = new Timer(DELAY, this);
        timer.start();
    }

    // moving the bird over time by increasing the Y position
    public void movingDown() {
        birdYPos += birdVelocity * t + 0.5 * gravity * Math.pow(t, 2); // y = y0 + v0.t + 1/2.g.t^2 (t = 1)
        birdVelocity += gravity;
        if (playerAction) {
            birdVelocity = birdSpeed;
        }
    }

    // use for the movement of the bird
    public boolean getPlayerAction() {
        return playerAction;
    }

    public void setPlayerAction(boolean value) {
        playerAction = value;
    }

    // use for the menu input
    public STATE getState() {
        return this.state;
    }

    public void changeStateToGame() {
        state = STATE.GAME;
    }

    public void changeStateToMenu() {
        state = STATE.MENU;
    }

    // use for adding sound effects
    public void playSound(int i) {
        Sound.setFile(i);
        Sound.play();
    }

    public void stopSound() {
        Sound.stop();
    }

    // decreasing the floorXPos to create animations over time
    public void floorAnimations() {
        floorXPos -= 5;
        backupFloorXPos -= 5;
    }

    public void gameOver() {
        running = false;
        playSound(1);
    }

    // check the game state, if the bird Y position is lower than the floor -> the
    // game ended
    public void checkCollisions() {
        int birdBottom = birdYPos + Bird.getImageHeight();
        if (birdBottom >= 500) {
            gameOver();
        }
        if (birdYPos <= 0) {
            birdYPos = 0;
        }

        Rectangle birdRect = new Rectangle(birdXPos, birdYPos, Bird.scaledX, Bird.scaledY);
        for (int i = 0; i < bottomPipe.length; i++) {
            if (birdRect.intersects(bottomPipe[i].getRect())
                    || birdRect.intersects(topPipe[i].getRect())) {
                gameOver();
            }
        }

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (state == STATE.GAME) {
            int frame = 0;
            frame++;

            if (frame % 60 == 0) {
                frame = 0;
                createPipe();
            }
            if (!playerAction) {
                movingDown();
            }
            if (running) {
                // floor
                floorAnimations();
                // pipe
                movePipe();
                // check the collision between the bird and the floor
                checkCollisions();
                // bird
                movingDown();
                Bird.increasingCounter();
                Bird.update();
                // calculate score
                scoreCalc();
                this.repaint();
            }
        }
    }
}
