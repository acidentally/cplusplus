import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;

public class controller implements MouseListener {

    gameEngine gEngine;

    public controller(gameEngine gEngine) {
        this.gEngine = gEngine;
    }

    @Override
    public void mousePressed(MouseEvent e) {
        if (gEngine.getState() == gameEngine.STATE.MENU) {
            gEngine.changeStateToGame();
        } else if (gEngine.getState() == gameEngine.STATE.GAME) {
            // creating the bird movement by adding value to the bird's y coords
            if (!gEngine.getPlayerAction()) {
                gEngine.setPlayerAction(true);
                gEngine.playSound(0);
            }
        }
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        // set the player's action to false when player release the mouse button
        if (gEngine.getPlayerAction()) {
            gEngine.setPlayerAction(false);
        }
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }
}
